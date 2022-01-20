#include "wasm4.h"
#include <math.h>
#include "collider.h"
#include "sprites.h"
#include "LevelOne.h"

signed short clampSS(signed short x, signed short min, signed short max) {
  const signed short t = x < min ? min : x;
  return t > max ? max : t;
}

unsigned char clampUC(unsigned char x, unsigned char min, unsigned char max) {
  const unsigned char t = x < min ? min : x;
  return t > max ? max : t;
}

uint8_t previousGamepad;
signed short camX = 0;
signed short camY = 0;
unsigned char speed = 1;
unsigned short camXDeadZone = 50;
unsigned short camYDeadZone = 50;

struct polygon triangle;

void start () {
  PALETTE[0] = 0x000000;
  PALETTE[1] = 0x32cd32;
  PALETTE[2] = 0x8b0000;
  PALETTE[3] = 0xadd8e6;

  triangle = makeTriangle();
  triangle.pos.x = 30;
  triangle.pos.y = 30;
  triangle.scale = 20;
}


void update () {
  // Gamepad
  uint8_t gamepad = *GAMEPAD1;
  uint8_t pressedThisFrame = gamepad & (gamepad ^ previousGamepad);
  previousGamepad = gamepad;

  if (gamepad & BUTTON_LEFT)
    {
      triangle.angle += -0.05f;
    }
  if (gamepad & BUTTON_RIGHT)
    {
      triangle.angle += 0.05f;
    }
  if (gamepad & BUTTON_UP)
    {
      triangle.pos.x += cosf(triangle.angle) * 0.5f;
      triangle.pos.y += sinf(triangle.angle) * 0.5f;
    }
  if (gamepad & BUTTON_DOWN)
    {
      triangle.pos.x += cosf(triangle.angle) * -0.5f;
      triangle.pos.y += sinf(triangle.angle) * -0.5f;
    }

  *DRAW_COLORS = 0x4321;

  for (int i = 0; i < LevelOne.tileSize; i++) {
    struct polygon collider = makeSquare();
    collider.pos.x = LevelOne.tiles[i].posX - camX;
    collider.pos.y = LevelOne.tiles[i].posY - camY;
    collider.scale = 16;
    collide(&triangle, &collider);
    blit(LevelOne.tiles[i].sprite->sprite, LevelOne.tiles[i].posX - camX, LevelOne.tiles[i].posY - camY, 16, 16, LevelOne.tiles[i].rotation);
  }

  for (int i = 0; i < LevelOne.decalSize; i++) {
    blit(LevelOne.decals[i].sprite->sprite, LevelOne.decals[i].posX - camX, LevelOne.decals[i].posY - camY, 16, 16, LevelOne.decals[i].rotation);
  }

  *DRAW_COLORS = 0x1203;
  drawPolygon(triangle);
}
