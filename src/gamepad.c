#include "gamepad.h"
#include "wasm4.h"
#include <stdlib.h>

uint8_t previousGamepad;
uint8_t pressedThisFrame;

void gamepad_update()
{
  uint8_t gamepad = *GAMEPAD1;
  pressedThisFrame = gamepad & (gamepad ^ previousGamepad);
  previousGamepad = gamepad;
}

uint8_t gamepad_getPressedThisFrame()
{
  return pressedThisFrame;
}

uint8_t gamepad_getPressed()
{
  return previousGamepad;
}
