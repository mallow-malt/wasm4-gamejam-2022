#include "wasm4.h"
#include <math.h>
#include "collider.h"
#include "sprites.h"
#include "LevelOne.h"
#include "utils.h"
#include "game.h"


uint8_t previousGamepad;
signed short camX = 0;
signed short camY = 0;
unsigned char speed = 1;
unsigned short camXDeadZone = 50;
unsigned short camYDeadZone = 50;

struct polygon player;

float xVel = 0;
float yVel = 0;
float g = 0.1f;
float playerAcc = .05f;
float maxPlayerSpeed = 3;
struct polygon groundedProbe;
struct polygon leftProbe;
struct polygon rightProbe;
bool grounded;
float friction = 0.01f;

void game_start () {
  PALETTE[0] = 0x000000;
  PALETTE[1] = 0x32cd32;
  PALETTE[2] = 0x8b0000;
  PALETTE[3] = 0xadd8e6;

  player = makeSquare();
  player.pos.x = LevelOne.startX;
  player.pos.y = 80 - 8;
  player.scale = 10;

  groundedProbe = makeLine();
  groundedProbe.pos.x = player.pos.x + 2;
  groundedProbe.pos.y = player.pos.y + 16;
  groundedProbe.scale = 12;

  leftProbe = makeLine();
  leftProbe.pos.x = player.pos.x;
  leftProbe.pos.y = player.pos.y + 12;
  leftProbe.scale = 2;
  leftProbe.angle = 1.5707963267948966;

  rightProbe = makeLine();
  rightProbe.pos.x = player.pos.x + 14;
  rightProbe.pos.y = player.pos.y + 12;
  rightProbe.scale = 2;
  rightProbe.angle = 1.5707963267948966;
}


void game_update () {
  // Gamepad
  uint8_t gamepad = *GAMEPAD1;
  uint8_t pressedThisFrame = gamepad & (gamepad ^ previousGamepad);
  previousGamepad = gamepad;

  if (gamepad & BUTTON_LEFT)
    {
      xVel = clampF(xVel - playerAcc, -maxPlayerSpeed, maxPlayerSpeed);
    }
  if (gamepad & BUTTON_RIGHT)
    {
      xVel = clampF(xVel + playerAcc, -maxPlayerSpeed, maxPlayerSpeed);
    }
  // if (gamepad & BUTTON_UP)
  //   {
  //     player.pos.y -= 0.5f;
  //     yVel = clampF(yVel + g, )
  //   }
  if (grounded && gamepad & BUTTON_DOWN)
    {
      if (xVel < 0) {
        xVel = clampF(xVel + playerAcc * 2, -maxPlayerSpeed, 0);
      } else if (xVel > 0) {
        xVel = clampF(xVel - playerAcc * 2, 0, maxPlayerSpeed);
      }
    }

  if (!grounded) {
    yVel = clampF(yVel += g, -1, 1);
  } else {
    yVel = 0;
    if (xVel < 0) {
      xVel = clampF(xVel + friction, -maxPlayerSpeed, 0);
    } else if (xVel > 0) {
      xVel = clampF(xVel - friction, 0, maxPlayerSpeed);
    }
  }

  player.pos.x += xVel;
  player.pos.y += yVel;

  signed short oldVal = 0;
  if (player.pos.x < 80 - camXDeadZone) {
    // Move Cam Left
    oldVal = camX;
    camX = clampSS(camX - (80 - camXDeadZone - player.pos.x), LevelOne.minX, LevelOne.maxX);
    if (oldVal != camX)
      player.pos.x = 80 - camXDeadZone;
  } else if (player.pos.x > 80 + camXDeadZone) {
    // Move Cam Right
    oldVal = camX;
    camX = clampSS(camX + (player.pos.x - (80 + camXDeadZone)), LevelOne.minX, LevelOne.maxX);
    if (oldVal != camX)
      player.pos.x = camXDeadZone + 80;
  }

  if (player.pos.y < 80 - camYDeadZone) {
    // Move Cam Up
    oldVal = camY;
    camY = clampSS(camY - (80 - camYDeadZone - player.pos.y), LevelOne.minY, LevelOne.maxY);
    if (oldVal != camY)
      player.pos.y = 80 - camYDeadZone;
  } else if (player.pos.y > 80 + camYDeadZone) {
    // Move Cam Down
    oldVal = camY;
    camY = clampSS(camY + (player.pos.y - (80 + camYDeadZone)), LevelOne.minY, LevelOne.maxY);
    if (oldVal != camY)
      player.pos.y = camYDeadZone + 80;
  }

  *DRAW_COLORS = 0x4321;

  bool currentlyOnGround = false;
  for (int i = 0; i < LevelOne.tileSize; i++) {
    
    struct polygon collider = makeSquare();
    collider.pos.x = LevelOne.tiles[i].posX - camX - 1;
    collider.pos.y = LevelOne.tiles[i].posY - camY - 1;
    collider.scale = 17;
    // collide(&player, &collider);
    groundedProbe.pos.x = player.pos.x;
    groundedProbe.pos.y = player.pos.y + 12;
    leftProbe.pos.x = player.pos.x - 3;
    leftProbe.pos.y = player.pos.y + 7;
    rightProbe.pos.x = player.pos.x + 12;
    rightProbe.pos.y = player.pos.y + 7;
    if(overlapP(groundedProbe, collider)) {
      player.pos.y = collider.pos.y - 11;
      yVel = 0;
      currentlyOnGround = true;
    } else if (overlapP(leftProbe, collider)) {
      player.pos.x = collider.pos.x + 18;
      xVel = 0;
    }
    *DRAW_COLORS = 0x4321;
    blit(LevelOne.tiles[i].sprite->sprite, LevelOne.tiles[i].posX - camX, LevelOne.tiles[i].posY - camY, 16, 16, LevelOne.tiles[i].rotation);
    *DRAW_COLORS = 0x1203;
    drawPolygon(collider);
  }
  *DRAW_COLORS = 0x4321;

  // tracef("%f", xVel);

  
  // for (int i = 0; i < LevelOne.tileSize; i++) {
  //   struct polygon collider = makeSquare();
  //   collider.pos.x = LevelOne.tiles[i].posX - camX;
  //   collider.pos.y = LevelOne.tiles[i].posY - camY;
  //   collider.scale = 16;
    
  //   if (overlapP(groundedProbe, collider))
  //     currentlyOnGround = true;
  //   if(overlapP(leftProbe, collider) || overlapP(rightProbe, collider))
  //     xVel = 0;
  // }

  

  for (int i = 0; i < LevelOne.decalSize; i++) {
    blit(LevelOne.decals[i].sprite->sprite, LevelOne.decals[i].posX - camX, LevelOne.decals[i].posY - camY, 16, 16, LevelOne.decals[i].rotation);
  }

  blit(PlayerFlatA.sprite, player.pos.x - 2, player.pos.y - 5, PlayerFlatA.width, PlayerFlatA.height, PlayerFlatA.flag);

  *DRAW_COLORS = 0x1203;
  // drawPolygon(player);
  drawPolygon(groundedProbe);
  drawPolygon(leftProbe);
  drawPolygon(rightProbe);

  // trace(overlapP(player, groundedProbe) ? "true" : "false");
}
