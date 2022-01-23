#include "soundfx.h"
#include "wasm4.h"
#include <stdbool.h>
#include <stdlib.h>

int crashTimeout = 0;

void sfx_crash()
{
  tone(160, 60 | (120 << 8), 90, TONE_NOISE);
  crashTimeout = 180;
}

bool fire = false;
int fireDur = 0;

#define WIN_SOUND_DUR 25

int winSoundProgress = 0;

void sfx_fire_enable()
{
  fire = true;
}

void sfx_fire_disable()
{
  fire = false;
  fireDur = 0;
}

void sfx_update()
{
  if (crashTimeout > 0)
    {
      crashTimeout -= 1;
    }
  if (crashTimeout <= 0 && fire)
    {
      if (fireDur <= 0)
        {
          rand();
          tone(80 + rand() % 30, 10, 20, TONE_NOISE);
          fireDur = 10;
        }
      fireDur -= 1;
    }

  if (winSoundProgress > 0)
    {
      if (winSoundProgress == WIN_SOUND_DUR*4)
        {
          tone(392, WIN_SOUND_DUR, 80, TONE_PULSE1);
        }
      else if (winSoundProgress == WIN_SOUND_DUR*3)
        {
          tone(622, WIN_SOUND_DUR, 80, TONE_PULSE1);
        }
      else if (winSoundProgress == WIN_SOUND_DUR*2)
        {
          tone(659, WIN_SOUND_DUR, 80, TONE_PULSE1);
        }
      else if (winSoundProgress == WIN_SOUND_DUR*1)
        {
          tone(784, WIN_SOUND_DUR, 80, TONE_PULSE1);
        }
      winSoundProgress--;
    }
}

void sfx_win()
{
  winSoundProgress = WIN_SOUND_DUR*4;
}
