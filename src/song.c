#include "song.h"
struct project proj = {
  .instrumentCount = 2,
  .instruments = (struct instrument[]){
    {
      .envelopeCount = 0,
      .envelopes = (struct envelope[]){
      },
    },
    {
      .envelopeCount = 2,
      .envelopes = (struct envelope[]){
        { .type = Volume, .length = 1,
          .valueCount = 1,
          .values = (int[]){
            9,
          },
        },
        { .type = DutyCycle, .length = 1,
          .valueCount = 1,
          .values = (int[]){
            3,
          },
        },
      },
    },
  },
  .songCount = 1,
  .songs = (struct song[]){
    {
      .length = 8,
      .loopPoint = 0,
      .patternLength = 16,
      .beatLength = 4,
      .noteLength = 10,
      .channelCount = 5,
      .channels = (struct channel[]){
        {
          .type = Square1,
          .patternCount = 6,
          .patterns = (struct pattern[]){
            {
              .noteCount = 4,
              .notes = (struct note[]){
                { .time = 0, .value = 196, .duration = 5, .instrument = 0 },
                { .time = 5, .value = 247, .duration = 15, .instrument = 0 },
                { .time = 80, .value = 147, .duration = 5, .instrument = 0 },
                { .time = 85, .value = 185, .duration = 10, .instrument = 0 },
              }
            },
            {
              .noteCount = 5,
              .notes = (struct note[]){
                { .time = 0, .value = 262, .duration = 20, .instrument = 0 },
                { .time = 80, .value = 392, .duration = 5, .instrument = 0 },
                { .time = 85, .value = 370, .duration = 5, .instrument = 0 },
                { .time = 95, .value = 294, .duration = 20, .instrument = 0 },
                { .time = 150, .value = 392, .duration = 10, .instrument = 0 },
              }
            },
            {
              .noteCount = 2,
              .notes = (struct note[]){
                { .time = 0, .value = 440, .duration = 20, .instrument = 0 },
                { .time = 80, .value = 330, .duration = 20, .instrument = 0 },
              }
            },
            {
              .noteCount = 4,
              .notes = (struct note[]){
                { .time = 0, .value = 294, .duration = 20, .instrument = 0 },
                { .time = 80, .value = 185, .duration = 5, .instrument = 0 },
                { .time = 85, .value = 247, .duration = 10, .instrument = 0 },
                { .time = 100, .value = 262, .duration = 20, .instrument = 0 },
              }
            },
            {
              .noteCount = 3,
              .notes = (struct note[]){
                { .time = 0, .value = 440, .duration = 20, .instrument = 0 },
                { .time = 80, .value = 415, .duration = 20, .instrument = 0 },
                { .time = 120, .value = 392, .duration = 10, .instrument = 0 },
              }
            },
            {
              .noteCount = 6,
              .notes = (struct note[]){
                { .time = 0, .value = 294, .duration = 20, .instrument = 0 },
                { .time = 40, .value = 262, .duration = 20, .instrument = 0 },
                { .time = 80, .value = 247, .duration = 5, .instrument = 0 },
                { .time = 85, .value = 294, .duration = 14, .instrument = 0 },
                { .time = 100, .value = 392, .duration = 30, .instrument = 0 },
                { .time = 140, .value = 370, .duration = 20, .instrument = 0 },
              }
            },
          },
          .patternInstanceCount = 8,
          .patternInstances = (struct patternInstance[]){
            {
              .time = 0,
              .pattern = 0,
            },
            {
              .time = 1,
              .pattern = 1,
            },
            {
              .time = 2,
              .pattern = 2,
            },
            {
              .time = 3,
              .pattern = 3,
            },
            {
              .time = 4,
              .pattern = 0,
            },
            {
              .time = 5,
              .pattern = 1,
            },
            {
              .time = 6,
              .pattern = 4,
            },
            {
              .time = 7,
              .pattern = 5,
            },
          }
        },
        {
          .type = Square2,
          .patternCount = 2,
          .patterns = (struct pattern[]){
            {
              .noteCount = 4,
              .notes = (struct note[]){
                { .time = 20, .value = 98, .duration = 5, .instrument = 1 },
                { .time = 60, .value = 98, .duration = 5, .instrument = 1 },
                { .time = 100, .value = 98, .duration = 5, .instrument = 1 },
                { .time = 140, .value = 98, .duration = 5, .instrument = 1 },
              }
            },
            {
              .noteCount = 4,
              .notes = (struct note[]){
                { .time = 20, .value = 98, .duration = 20, .instrument = 1 },
                { .time = 60, .value = 98, .duration = 10, .instrument = 1 },
                { .time = 100, .value = 98, .duration = 20, .instrument = 1 },
                { .time = 140, .value = 98, .duration = 10, .instrument = 1 },
              }
            },
          },
          .patternInstanceCount = 8,
          .patternInstances = (struct patternInstance[]){
            {
              .time = 0,
              .pattern = 0,
            },
            {
              .time = 1,
              .pattern = 0,
            },
            {
              .time = 2,
              .pattern = 1,
            },
            {
              .time = 3,
              .pattern = 1,
            },
            {
              .time = 4,
              .pattern = 1,
            },
            {
              .time = 5,
              .pattern = 1,
            },
            {
              .time = 6,
              .pattern = 1,
            },
            {
              .time = 7,
              .pattern = 0,
            },
          }
        },
        {
          .type = Triangle,
          .patternCount = 5,
          .patterns = (struct pattern[]){
            {
              .noteCount = 16,
              .notes = (struct note[]){
                { .time = 0, .value = 196, .duration = 9, .instrument = 0 },
                { .time = 10, .value = 247, .duration = 9, .instrument = 0 },
                { .time = 20, .value = 294, .duration = 9, .instrument = 0 },
                { .time = 30, .value = 247, .duration = 9, .instrument = 0 },
                { .time = 40, .value = 196, .duration = 9, .instrument = 0 },
                { .time = 50, .value = 247, .duration = 9, .instrument = 0 },
                { .time = 60, .value = 294, .duration = 9, .instrument = 0 },
                { .time = 70, .value = 247, .duration = 9, .instrument = 0 },
                { .time = 80, .value = 196, .duration = 9, .instrument = 0 },
                { .time = 90, .value = 247, .duration = 9, .instrument = 0 },
                { .time = 100, .value = 294, .duration = 9, .instrument = 0 },
                { .time = 110, .value = 247, .duration = 9, .instrument = 0 },
                { .time = 120, .value = 196, .duration = 9, .instrument = 0 },
                { .time = 130, .value = 247, .duration = 9, .instrument = 0 },
                { .time = 140, .value = 294, .duration = 9, .instrument = 0 },
                { .time = 150, .value = 247, .duration = 9, .instrument = 0 },
              }
            },
            {
              .noteCount = 16,
              .notes = (struct note[]){
                { .time = 0, .value = 262, .duration = 9, .instrument = 0 },
                { .time = 10, .value = 330, .duration = 9, .instrument = 0 },
                { .time = 20, .value = 392, .duration = 9, .instrument = 0 },
                { .time = 30, .value = 330, .duration = 9, .instrument = 0 },
                { .time = 40, .value = 262, .duration = 9, .instrument = 0 },
                { .time = 50, .value = 330, .duration = 9, .instrument = 0 },
                { .time = 60, .value = 392, .duration = 9, .instrument = 0 },
                { .time = 70, .value = 330, .duration = 9, .instrument = 0 },
                { .time = 80, .value = 262, .duration = 9, .instrument = 0 },
                { .time = 90, .value = 330, .duration = 9, .instrument = 0 },
                { .time = 100, .value = 392, .duration = 9, .instrument = 0 },
                { .time = 110, .value = 330, .duration = 8, .instrument = 0 },
                { .time = 120, .value = 262, .duration = 9, .instrument = 0 },
                { .time = 130, .value = 330, .duration = 9, .instrument = 0 },
                { .time = 140, .value = 392, .duration = 9, .instrument = 0 },
                { .time = 150, .value = 330, .duration = 9, .instrument = 0 },
              }
            },
            {
              .noteCount = 16,
              .notes = (struct note[]){
                { .time = 0, .value = 220, .duration = 9, .instrument = 0 },
                { .time = 10, .value = 262, .duration = 9, .instrument = 0 },
                { .time = 20, .value = 330, .duration = 9, .instrument = 0 },
                { .time = 30, .value = 262, .duration = 9, .instrument = 0 },
                { .time = 40, .value = 220, .duration = 9, .instrument = 0 },
                { .time = 50, .value = 262, .duration = 9, .instrument = 0 },
                { .time = 60, .value = 330, .duration = 9, .instrument = 0 },
                { .time = 70, .value = 262, .duration = 9, .instrument = 0 },
                { .time = 80, .value = 220, .duration = 9, .instrument = 0 },
                { .time = 90, .value = 262, .duration = 9, .instrument = 0 },
                { .time = 100, .value = 330, .duration = 9, .instrument = 0 },
                { .time = 110, .value = 262, .duration = 9, .instrument = 0 },
                { .time = 120, .value = 220, .duration = 9, .instrument = 0 },
                { .time = 130, .value = 262, .duration = 9, .instrument = 0 },
                { .time = 140, .value = 330, .duration = 9, .instrument = 0 },
                { .time = 150, .value = 262, .duration = 9, .instrument = 0 },
              }
            },
            {
              .noteCount = 16,
              .notes = (struct note[]){
                { .time = 0, .value = 294, .duration = 9, .instrument = 0 },
                { .time = 10, .value = 370, .duration = 9, .instrument = 0 },
                { .time = 20, .value = 440, .duration = 9, .instrument = 0 },
                { .time = 30, .value = 277, .duration = 9, .instrument = 0 },
                { .time = 40, .value = 294, .duration = 9, .instrument = 0 },
                { .time = 50, .value = 370, .duration = 9, .instrument = 0 },
                { .time = 60, .value = 440, .duration = 9, .instrument = 0 },
                { .time = 70, .value = 277, .duration = 9, .instrument = 0 },
                { .time = 80, .value = 294, .duration = 9, .instrument = 0 },
                { .time = 90, .value = 370, .duration = 9, .instrument = 0 },
                { .time = 100, .value = 440, .duration = 9, .instrument = 0 },
                { .time = 110, .value = 277, .duration = 9, .instrument = 0 },
                { .time = 120, .value = 294, .duration = 9, .instrument = 0 },
                { .time = 130, .value = 370, .duration = 9, .instrument = 0 },
                { .time = 140, .value = 440, .duration = 9, .instrument = 0 },
                { .time = 150, .value = 277, .duration = 9, .instrument = 0 },
              }
            },
            {
              .noteCount = 16,
              .notes = (struct note[]){
                { .time = 0, .value = 196, .duration = 9, .instrument = 0 },
                { .time = 10, .value = 247, .duration = 9, .instrument = 0 },
                { .time = 20, .value = 294, .duration = 9, .instrument = 0 },
                { .time = 30, .value = 247, .duration = 9, .instrument = 0 },
                { .time = 40, .value = 196, .duration = 9, .instrument = 0 },
                { .time = 50, .value = 247, .duration = 9, .instrument = 0 },
                { .time = 60, .value = 294, .duration = 9, .instrument = 0 },
                { .time = 70, .value = 247, .duration = 8, .instrument = 0 },
                { .time = 80, .value = 196, .duration = 9, .instrument = 0 },
                { .time = 90, .value = 247, .duration = 9, .instrument = 0 },
                { .time = 100, .value = 294, .duration = 9, .instrument = 0 },
                { .time = 110, .value = 247, .duration = 9, .instrument = 0 },
                { .time = 120, .value = 196, .duration = 9, .instrument = 0 },
                { .time = 130, .value = 294, .duration = 9, .instrument = 0 },
                { .time = 140, .value = 247, .duration = 9, .instrument = 0 },
                { .time = 150, .value = 392, .duration = 9, .instrument = 0 },
              }
            },
          },
          .patternInstanceCount = 8,
          .patternInstances = (struct patternInstance[]){
            {
              .time = 0,
              .pattern = 0,
            },
            {
              .time = 1,
              .pattern = 1,
            },
            {
              .time = 2,
              .pattern = 2,
            },
            {
              .time = 3,
              .pattern = 3,
            },
            {
              .time = 4,
              .pattern = 0,
            },
            {
              .time = 5,
              .pattern = 1,
            },
            {
              .time = 6,
              .pattern = 2,
            },
            {
              .time = 7,
              .pattern = 4,
            },
          }
        },
        {
          .type = Noise,
          .patternCount = 3,
          .patterns = (struct pattern[]){
            {
              .noteCount = 5,
              .notes = (struct note[]){
                { .time = 0, .value = 233, .duration = 10, .instrument = 0 },
                { .time = 40, .value = 233, .duration = 10, .instrument = 0 },
                { .time = 80, .value = 233, .duration = 10, .instrument = 0 },
                { .time = 120, .value = 233, .duration = 10, .instrument = 0 },
                { .time = 130, .value = 233, .duration = 10, .instrument = 0 },
              }
            },
            {
              .noteCount = 9,
              .notes = (struct note[]){
                { .time = 0, .value = 233, .duration = 10, .instrument = 0 },
                { .time = 20, .value = 277, .duration = 10, .instrument = 0 },
                { .time = 40, .value = 233, .duration = 10, .instrument = 0 },
                { .time = 60, .value = 277, .duration = 10, .instrument = 0 },
                { .time = 80, .value = 233, .duration = 10, .instrument = 0 },
                { .time = 100, .value = 277, .duration = 10, .instrument = 0 },
                { .time = 120, .value = 233, .duration = 10, .instrument = 0 },
                { .time = 130, .value = 233, .duration = 10, .instrument = 0 },
                { .time = 140, .value = 277, .duration = 10, .instrument = 0 },
              }
            },
            {
              .noteCount = 10,
              .notes = (struct note[]){
                { .time = 0, .value = 233, .duration = 10, .instrument = 0 },
                { .time = 20, .value = 277, .duration = 10, .instrument = 0 },
                { .time = 40, .value = 233, .duration = 10, .instrument = 0 },
                { .time = 60, .value = 277, .duration = 10, .instrument = 0 },
                { .time = 80, .value = 233, .duration = 10, .instrument = 0 },
                { .time = 100, .value = 277, .duration = 10, .instrument = 0 },
                { .time = 120, .value = 233, .duration = 10, .instrument = 0 },
                { .time = 130, .value = 233, .duration = 10, .instrument = 0 },
                { .time = 140, .value = 277, .duration = 10, .instrument = 0 },
                { .time = 150, .value = 294, .duration = 10, .instrument = 0 },
              }
            },
          },
          .patternInstanceCount = 8,
          .patternInstances = (struct patternInstance[]){
            {
              .time = 0,
              .pattern = 0,
            },
            {
              .time = 1,
              .pattern = 0,
            },
            {
              .time = 2,
              .pattern = 1,
            },
            {
              .time = 3,
              .pattern = 2,
            },
            {
              .time = 4,
              .pattern = 1,
            },
            {
              .time = 5,
              .pattern = 1,
            },
            {
              .time = 6,
              .pattern = 1,
            },
            {
              .time = 7,
              .pattern = 0,
            },
          }
        },
        {
          .type = DPCM,
          .patternCount = 0,
          .patterns = (struct pattern[]){
          },
          .patternInstanceCount = 0,
          .patternInstances = (struct patternInstance[]){
          }
        },
      }
    },
  }
};
