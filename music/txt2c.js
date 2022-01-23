#!/usr/bin/node

const fs = require('fs')
const np = require('note-parser')


if (process.argv.length != 4) {
  console.log("txt2c.js <input-file> <output-file>");
}

const inputFile = process.argv[2];
const outputFile = process.argv[3];

const data = fs.readFileSync(inputFile, 'utf8')

const lines = data.split(/\r?\n/)

const current = {
  project: null,
  instrument: null,
  song: null,
  channel: null,
  pattern: null
}


for(const line of lines) {
  if (line) {
    const objectPattern = /^\s*([^\s]+)/y;
    const attributePattern = / ([^\s=]+)="((?:[^"]|"")+)"/y;
    const objMatch = objectPattern.exec(line);
    if (objMatch === null) {
      throw "Could not find object for line\n" + line;
    }
    const objectName = objMatch[1];
    attributePattern.lastIndex = objectPattern.lastIndex;
    let attrMatch;
    const attributes = {};
    while((attrMatch = attributePattern.exec(line)) !== null) {
      const key = attrMatch[1];
      const val = attrMatch[2];
      attributes[key] = val;
    }

    // console.log(objectName, attributes);

    if (objectName === "Project") {
      current.project = {
        type: "project",
        instruments: [],
        songs: [],
        ...attributes
      };
    }
    else if (objectName === "Instrument") {
      current.instrument = {
        type: "instrument",
        envelopes: [],
        ...attributes
      };
      current.project.instruments.push(current.instrument);
    }
    else if (objectName === "Envelope") {
      current.envelope = {
        type: "envelope",
        ...attributes
      };
      current.instrument.envelopes.push(current.envelope);
    }
    else if (objectName === "Song") {
      current.song = {
        type: "song",
        channels: [],
        ...attributes
      };
      current.project.songs.push(current.song);
    }
    else if (objectName === "Channel") {
      current.channel = {
        type: "channel",
        patterns: [],
        patternInstances: [],
        ...attributes
      };
      current.song.channels.push(current.channel);
    }
    else if (objectName === "Pattern") {
      current.pattern = {
        type: "pattern",
        notes: [],
        ...attributes
      };
      current.channel.patterns.push(current.pattern);
    }
    else if (objectName === "Note") {
      current.pattern.notes.push({
        type: "note",
        ...attributes
      });
    }
    else if (objectName === "PatternInstance") {
      current.channel.patternInstances.push({
        type: "patternInstance",
        ...attributes
      });
    }
    else {
      throw new "Unknown object name: " + objectName;
    }
  }
}

const src = [];

{
  let instrumentInd = 0;
  let instrumentIDs = {};

  src.push("#include \"song.h\"")
  
  src.push("struct project proj = {");

  src.push(`.instrumentCount = ${current.project.instruments.length},`);
  src.push(".instruments = (struct instrument[]){");
  for(let instrument of current.project.instruments) {
    instrumentIDs[instrument.Name] = instrumentInd++;

    src.push(`{`);
    src.push(`.envelopeCount = ${instrument.envelopes.length},`);
    src.push(".envelopes = (struct envelope[]){");
    for(let envelope of instrument.envelopes) {
      const vals = envelope.Values.split(',')
      src.push(`{ .type = ${envelope.Type}, .length = ${envelope.Length},`);
      src.push(`.valueCount = ${vals.length},`);
      src.push(`.values = (int[]){`);
      for(let val of vals) {
        src.push(`${val},`);
      }
      src.push(`},`);
      src.push(`},`);
    }
    src.push("},");
    src.push(`},`);
  }
  src.push("},");

  src.push(`.songCount = ${current.project.songs.length},`);
  src.push(".songs = (struct song[]){");
  for(let song of current.project.songs) {
    src.push("{");
    src.push(`.length = ${song.Length},`);
    src.push(`.loopPoint = ${song.LoopPoint},`);
    src.push(`.patternLength = ${song.PatternLength},`);
    src.push(`.beatLength = ${song.BeatLength},`);
    src.push(`.noteLength = ${song.NoteLength},`);

    src.push(`.channelCount = ${song.channels.length},`);
    src.push(".channels = (struct channel[]){");
    for(let channel of song.channels) {
      src.push("{");
      src.push(`.type = ${channel.Type},`);

      let patternIDSource = 0;
      let patternIDs = {};

      src.push(`.patternCount = ${channel.patterns.length},`);
      src.push(".patterns = (struct pattern[]){");
      for(let pattern of channel.patterns) {
        patternIDs[pattern.Name] = patternIDSource++;
        src.push(`{`);

        src.push(`.noteCount = ${pattern.notes.length},`);        
        src.push(".notes = (struct note[]){");
        for(let note of pattern.notes) {
          const midi = np.parse(note.Value).midi;
          const instreID = instrumentIDs[note.Instrument];
          src.push(`{ .time = ${note.Time}, .value = ${midi}, .duration = ${note.Duration}, .instrument = ${instreID} },`);
        }
        src.push("}");
        
        src.push(`},`);
      }
      src.push("},");

      src.push(`.patternInstanceCount = ${channel.patternInstances.length},`);        
      src.push(".patternInstances = (struct patternInstance[]){");
      for(let patternInstance of channel.patternInstances) {
        const patID = patternIDs[patternInstance.Pattern];
        src.push(`{`);
        src.push(`.time = ${patternInstance.Time},`);
        src.push(`.pattern = ${patID},`);
        src.push("},");
      }
      src.push("}");
      
      src.push("},");
    }
    src.push("}");
    
    src.push("},");
  }
  src.push("}");
  
  src.push("};");
}

fs.writeFileSync(outputFile, src.join("\n"));

// console.log(JSON.stringify(current.project, null, 4));
