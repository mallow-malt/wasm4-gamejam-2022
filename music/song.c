struct project proj = {
  .instrumentCount = 2,
  .instruments = (struct instrument[]){
    {
      .envelopeCount = 0,
      .envelopes = (struct envelope[]){
      }
    }
    {
      .envelopeCount = 2,
      .envelopes = (struct envelope[]){
        { .type = Volume, .length = 1,
          .valueCount = 1,
          .values = (struct int[]){
            9,
          },
        },
        { .type = DutyCycle, .length = 1,
          .valueCount = 1,
          .values = (struct int[]){
            3,
          },
        },
      }
    }
  }
  .songCount = 1
  .songs = (struct song[]){
    {
      .length = 16,
      .loopPoint = 0,
      .patternLength = 16,
      .beatLength = 4,
      .noteLength = 10,
      .channelCount = 5,
      .channels = (struct channel[]){
        {
          .type = Square1,
          .patternCount = 5,
          .patterns = (struct pattern[]){
            {
              .noteCount = 4,
              .notes = (struct note[]){
                { .time = 0, .value = 67, .duration = 5, .instrument = 0 },
                { .time = 5, .value = 71, .duration = 15, .instrument = 0 },
                { .time = 80, .value = 62, .duration = 5, .instrument = 0 },
                { .time = 85, .value = 66, .duration = 10, .instrument = 0 },
              }
            },
            {
              .noteCount = 5,
              .notes = (struct note[]){
                { .time = 0, .value = 72, .duration = 20, .instrument = 0 },
                { .time = 80, .value = 79, .duration = 5, .instrument = 0 },
                { .time = 85, .value = 78, .duration = 5, .instrument = 0 },
                { .time = 95, .value = 74, .duration = 10, .instrument = 0 },
                { .time = 155, .value = 71, .duration = 5, .instrument = 0 },
              }
            },
            {
              .noteCount = 2,
              .notes = (struct note[]){
                { .time = 0, .value = 69, .duration = 20, .instrument = 0 },
                { .time = 80, .value = 76, .duration = 20, .instrument = 0 },
              }
            },
            {
              .noteCount = 4,
              .notes = (struct note[]){
                { .time = 0, .value = 74, .duration = 20, .instrument = 0 },
                { .time = 80, .value = 66, .duration = 5, .instrument = 0 },
                { .time = 85, .value = 71, .duration = 10, .instrument = 0 },
                { .time = 100, .value = 72, .duration = 20, .instrument = 0 },
              }
            },
            {
              .noteCount = 5,
              .notes = (struct note[]){
                { .time = 0, .value = 74, .duration = 20, .instrument = 0 },
                { .time = 80, .value = 79, .duration = 5, .instrument = 0 },
                { .time = 85, .value = 74, .duration = 14, .instrument = 0 },
                { .time = 100, .value = 79, .duration = 15, .instrument = 0 },
                { .time = 140, .value = 78, .duration = 20, .instrument = 0 },
              }
            },
          }
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
          .type = Square2,
          .patternCount = 2,
          .patterns = (struct pattern[]){
            {
              .noteCount = 4,
              .notes = (struct note[]){
                { .time = 20, .value = 43, .duration = 5, .instrument = 1 },
                { .time = 60, .value = 43, .duration = 5, .instrument = 1 },
                { .time = 100, .value = 43, .duration = 5, .instrument = 1 },
                { .time = 140, .value = 43, .duration = 5, .instrument = 1 },
              }
            },
            {
              .noteCount = 4,
              .notes = (struct note[]){
                { .time = 20, .value = 43, .duration = 20, .instrument = 1 },
                { .time = 60, .value = 43, .duration = 10, .instrument = 1 },
                { .time = 100, .value = 43, .duration = 20, .instrument = 1 },
                { .time = 140, .value = 43, .duration = 10, .instrument = 1 },
              }
            },
          }
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
                { .time = 0, .value = 55, .duration = 9, .instrument = 0 },
                { .time = 10, .value = 59, .duration = 9, .instrument = 0 },
                { .time = 20, .value = 62, .duration = 9, .instrument = 0 },
                { .time = 30, .value = 59, .duration = 9, .instrument = 0 },
                { .time = 40, .value = 55, .duration = 9, .instrument = 0 },
                { .time = 50, .value = 59, .duration = 9, .instrument = 0 },
                { .time = 60, .value = 62, .duration = 9, .instrument = 0 },
                { .time = 70, .value = 59, .duration = 9, .instrument = 0 },
                { .time = 80, .value = 55, .duration = 9, .instrument = 0 },
                { .time = 90, .value = 59, .duration = 9, .instrument = 0 },
                { .time = 100, .value = 62, .duration = 9, .instrument = 0 },
                { .time = 110, .value = 59, .duration = 9, .instrument = 0 },
                { .time = 120, .value = 55, .duration = 9, .instrument = 0 },
                { .time = 130, .value = 59, .duration = 9, .instrument = 0 },
                { .time = 140, .value = 62, .duration = 9, .instrument = 0 },
                { .time = 150, .value = 59, .duration = 9, .instrument = 0 },
              }
            },
            {
              .noteCount = 16,
              .notes = (struct note[]){
                { .time = 0, .value = 60, .duration = 9, .instrument = 0 },
                { .time = 10, .value = 64, .duration = 9, .instrument = 0 },
                { .time = 20, .value = 67, .duration = 9, .instrument = 0 },
                { .time = 30, .value = 64, .duration = 9, .instrument = 0 },
                { .time = 40, .value = 60, .duration = 9, .instrument = 0 },
                { .time = 50, .value = 64, .duration = 9, .instrument = 0 },
                { .time = 60, .value = 67, .duration = 9, .instrument = 0 },
                { .time = 70, .value = 64, .duration = 9, .instrument = 0 },
                { .time = 80, .value = 60, .duration = 9, .instrument = 0 },
                { .time = 90, .value = 64, .duration = 9, .instrument = 0 },
                { .time = 100, .value = 67, .duration = 9, .instrument = 0 },
                { .time = 110, .value = 64, .duration = 8, .instrument = 0 },
                { .time = 120, .value = 60, .duration = 9, .instrument = 0 },
                { .time = 130, .value = 64, .duration = 9, .instrument = 0 },
                { .time = 140, .value = 67, .duration = 9, .instrument = 0 },
                { .time = 150, .value = 64, .duration = 9, .instrument = 0 },
              }
            },
            {
              .noteCount = 16,
              .notes = (struct note[]){
                { .time = 0, .value = 57, .duration = 9, .instrument = 0 },
                { .time = 10, .value = 60, .duration = 9, .instrument = 0 },
                { .time = 20, .value = 64, .duration = 9, .instrument = 0 },
                { .time = 30, .value = 60, .duration = 9, .instrument = 0 },
                { .time = 40, .value = 57, .duration = 9, .instrument = 0 },
                { .time = 50, .value = 60, .duration = 9, .instrument = 0 },
                { .time = 60, .value = 64, .duration = 9, .instrument = 0 },
                { .time = 70, .value = 60, .duration = 9, .instrument = 0 },
                { .time = 80, .value = 57, .duration = 9, .instrument = 0 },
                { .time = 90, .value = 60, .duration = 9, .instrument = 0 },
                { .time = 100, .value = 64, .duration = 9, .instrument = 0 },
                { .time = 110, .value = 60, .duration = 9, .instrument = 0 },
                { .time = 120, .value = 57, .duration = 9, .instrument = 0 },
                { .time = 130, .value = 60, .duration = 9, .instrument = 0 },
                { .time = 140, .value = 64, .duration = 9, .instrument = 0 },
                { .time = 150, .value = 60, .duration = 9, .instrument = 0 },
              }
            },
            {
              .noteCount = 16,
              .notes = (struct note[]){
                { .time = 0, .value = 62, .duration = 9, .instrument = 0 },
                { .time = 10, .value = 66, .duration = 9, .instrument = 0 },
                { .time = 20, .value = 69, .duration = 9, .instrument = 0 },
                { .time = 30, .value = 61, .duration = 9, .instrument = 0 },
                { .time = 40, .value = 62, .duration = 9, .instrument = 0 },
                { .time = 50, .value = 66, .duration = 9, .instrument = 0 },
                { .time = 60, .value = 69, .duration = 9, .instrument = 0 },
                { .time = 70, .value = 61, .duration = 9, .instrument = 0 },
                { .time = 80, .value = 62, .duration = 9, .instrument = 0 },
                { .time = 90, .value = 66, .duration = 9, .instrument = 0 },
                { .time = 100, .value = 69, .duration = 9, .instrument = 0 },
                { .time = 110, .value = 61, .duration = 9, .instrument = 0 },
                { .time = 120, .value = 62, .duration = 9, .instrument = 0 },
                { .time = 130, .value = 66, .duration = 9, .instrument = 0 },
                { .time = 140, .value = 69, .duration = 9, .instrument = 0 },
                { .time = 150, .value = 61, .duration = 9, .instrument = 0 },
              }
            },
            {
              .noteCount = 16,
              .notes = (struct note[]){
                { .time = 0, .value = 55, .duration = 9, .instrument = 0 },
                { .time = 10, .value = 59, .duration = 9, .instrument = 0 },
                { .time = 20, .value = 62, .duration = 9, .instrument = 0 },
                { .time = 30, .value = 59, .duration = 9, .instrument = 0 },
                { .time = 40, .value = 55, .duration = 9, .instrument = 0 },
                { .time = 50, .value = 59, .duration = 9, .instrument = 0 },
                { .time = 60, .value = 62, .duration = 9, .instrument = 0 },
                { .time = 70, .value = 59, .duration = 8, .instrument = 0 },
                { .time = 80, .value = 55, .duration = 9, .instrument = 0 },
                { .time = 90, .value = 59, .duration = 9, .instrument = 0 },
                { .time = 100, .value = 62, .duration = 9, .instrument = 0 },
                { .time = 110, .value = 59, .duration = 9, .instrument = 0 },
                { .time = 120, .value = 55, .duration = 9, .instrument = 0 },
                { .time = 130, .value = 62, .duration = 9, .instrument = 0 },
                { .time = 140, .value = 59, .duration = 9, .instrument = 0 },
                { .time = 150, .value = 67, .duration = 9, .instrument = 0 },
              }
            },
          }
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
          .patternCount = 4,
          .patterns = (struct pattern[]){
            {
              .noteCount = 5,
              .notes = (struct note[]){
                { .time = 0, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 40, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 80, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 120, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 130, .value = 58, .duration = 10, .instrument = 0 },
              }
            },
            {
              .noteCount = 9,
              .notes = (struct note[]){
                { .time = 0, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 20, .value = 61, .duration = 10, .instrument = 0 },
                { .time = 40, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 60, .value = 61, .duration = 10, .instrument = 0 },
                { .time = 80, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 100, .value = 61, .duration = 10, .instrument = 0 },
                { .time = 120, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 130, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 140, .value = 61, .duration = 10, .instrument = 0 },
              }
            },
            {
              .noteCount = 10,
              .notes = (struct note[]){
                { .time = 0, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 20, .value = 61, .duration = 10, .instrument = 0 },
                { .time = 40, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 60, .value = 61, .duration = 10, .instrument = 0 },
                { .time = 80, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 100, .value = 61, .duration = 10, .instrument = 0 },
                { .time = 120, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 130, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 140, .value = 61, .duration = 10, .instrument = 0 },
                { .time = 150, .value = 62, .duration = 10, .instrument = 0 },
              }
            },
            {
              .noteCount = 9,
              .notes = (struct note[]){
                { .time = 0, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 20, .value = 61, .duration = 10, .instrument = 0 },
                { .time = 40, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 60, .value = 61, .duration = 10, .instrument = 0 },
                { .time = 80, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 100, .value = 61, .duration = 10, .instrument = 0 },
                { .time = 120, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 130, .value = 58, .duration = 10, .instrument = 0 },
                { .time = 140, .value = 61, .duration = 10, .instrument = 0 },
              }
            },
          }
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
              .pattern = 3,
            },
          }
        },
        {
          .type = DPCM,
          .patternCount = 0,
          .patterns = (struct pattern[]){
          }
          .patternInstanceCount = 0,
          .patternInstances = (struct patternInstance[]){
          }
        },
      }
    },
  }
};
