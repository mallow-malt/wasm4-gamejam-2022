#ifndef SONG_H
#define SONG_H

enum envelopeType { Volume, DutyCycle };

enum channelType { Square1, Square2, Triangle, Noise, DPCM };

struct envelope {
  enum envelopeType type;
  int length;
  int valueCount;
  int* values;
};

struct instrument {
  int envelopeCount;
  struct envelope* envelopes;
};

struct note {
  int time;
  int value;
  int duration;
  int instrument;
};

struct pattern {
  int noteCount;
  struct note* notes;
};

struct patternInstance {
  int time;
  int pattern;
};

struct channel {
  enum channelType type;
  int patternCount;
  struct pattern* patterns;
  int patternInstanceCount;
  struct patternInstance* patternInstances;
};

struct song {
  int length;
  int loopPoint;
  int patternLength;
  int beatLength;
  int noteLength;
  int channelCount;
  struct channel* channels;
};

struct project {
  int instrumentCount;
  struct instrument* instruments;
  int songCount;
  struct song* songs;
};

extern struct project proj;

#endif /* SONG_H */
