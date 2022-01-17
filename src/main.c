#include "wasm4.h"
#include "sprites.h"
#include "LevelOne.h"

void start () {
    PALETTE[0] = 0x000000;
    PALETTE[1] = 0x32cd32;
    PALETTE[2] = 0x8b0000;
    PALETTE[3] = 0xadd8e6;
    *DRAW_COLORS = 0x4321;
}

signed short camX = 0;
signed short camY = 0;
unsigned char speed = 1;
uint8_t previousGamepad;

signed short clampSS(signed short x, signed short min, signed short max) {
  const signed short t = x < min ? min : x;
  return t > max ? max : t;
}

unsigned char clampUC(unsigned char x, unsigned char min, unsigned char max) {
  const unsigned char t = x < min ? min : x;
  return t > max ? max : t;
}

void update () {
    uint8_t gamepad = *GAMEPAD1;
    uint8_t pressedThisFrame = gamepad & (gamepad ^ previousGamepad);
    previousGamepad = gamepad;

    if (pressedThisFrame & BUTTON_1) {
        trace("Increase speed");
        speed = clampUC(speed + 1, 1, 16);
    } else if (pressedThisFrame & BUTTON_2) {
        trace("Decrease speed");
        speed = clampUC(speed - 1, 1, 16);
    } else if (pressedThisFrame & BUTTON_LEFT) {
        trace("Move left");
        camX = clampSS(camX - speed, LevelOne.minX, LevelOne.maxX);
    } else if (pressedThisFrame & BUTTON_RIGHT) {
        trace("Move right");
        camX = clampSS(camX + speed, LevelOne.minX, LevelOne.maxX);
    } else if (pressedThisFrame & BUTTON_UP) {
        trace("Move up");
        camY = clampSS(camY - speed, LevelOne.minY, LevelOne.maxY);
    } else if (pressedThisFrame & BUTTON_DOWN) {
        trace("Move down");
        camY = clampSS(camY + speed, LevelOne.minY, LevelOne.maxY);
    }

    for (int i = 0; i < LevelOne.tileSize; i++) {
        blit(LevelOne.tiles[i].sprite->sprite, LevelOne.tiles[i].posX - camX, LevelOne.tiles[i].posY - camY, 16, 16, LevelOne.tiles[i].rotation);
    }

    for (int i = 0; i < LevelOne.decalSize; i++) {
        blit(LevelOne.decals[i].sprite->sprite, LevelOne.decals[i].posX - camX, LevelOne.decals[i].posY - camY, 16, 16, LevelOne.decals[i].rotation);
    }
}
