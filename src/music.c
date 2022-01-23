#include "music.h"
#include "song.h"
#include "wasm4.h"

int currentPattern = 0;
int patternProgress = 0;

int ResolveChannel(enum channelType tp)
{
  switch (tp) {
  case Square1: {
    return TONE_PULSE1;
  }
  case Square2: {
    return TONE_PULSE2;
  }
  case Noise: {
    return TONE_NOISE;
  }
  case Triangle: {
    return TONE_TRIANGLE;
  }
  default:
    return TONE_PULSE1;
  }
}

void music_update()
{
  struct song song = proj.songs[0];
  int patternFrames = song.patternLength * song.noteLength;

  for (int i = 0; i < song.channelCount; ++i) {
    struct channel channel = song.channels[i];
    for (int j = 0; j < channel.patternInstanceCount; ++i) {
      struct patternInstance patInst = channel.patternInstances[j];
      if (patInst.time == currentPattern)
        {
          struct pattern pattern = channel.patterns[patInst.pattern];
          for (int k = 0; k < pattern.noteCount; ++k) {
            struct note note = pattern.notes[k];
            if (patternProgress == note.time)
              {
                tone(note.value, note.duration, 50, ResolveChannel(channel.type));
              }
          }
        }
    }
  }
  patternProgress++;
  if (patternProgress >= patternFrames)
    {
      patternProgress = 0;
      currentPattern++;

      if (currentPattern >= song.length)
        {
          currentPattern = 0;
        }
    }
}
