#include "wasm4.h"
#include <math.h>
#include "game.h"
#include "sprites.h"
#include "LevelOne.h"
#include "utils.h"
#include "gamepad.h"
#include "tilecollider.h"
#include <stdbool.h>

#define MAX_SPEED 0.5f
#define WALK_SPEED 0.1f
#define PLAYER_UPRIGHT_WIDTH 13.0f/16.0f
#define PLAYER_UPRIGHT_HEIGHT 16.0f/16.0f
#define PLAYER_TILTED_WIDTH 15.0f/16.0f
#define PLAYER_TILTED_HEIGHT 15.0f/16.0f
#define PEDDLE_SPEED 0.002f
#define AIR_SPEED 0.02f

unsigned short camXDeadZone = 50;
unsigned short camYDeadZone = 50;

struct vec playerPos;
struct vec camPos;
struct vec playerVel;

void drawTileStates()
{
  for (size_t x = 0; x < LevelOneCollisionMap.width; ++x) {
    for (size_t y = 0; y < LevelOneCollisionMap.height; ++y) {
      uint8_t drawColors = 0;
      char tileState = tc_getState(LevelOneCollisionMap, x, y);
      switch (tileState) {
      case '.': {
        drawColors = 1;
        break;
      }
      case '#': {
        drawColors = 2;
        break;
      }
      case '/': {
        drawColors = 3;
        break;
      }
      default:
        drawColors = 4;
        break;
      }
      *DRAW_COLORS = drawColors;
      struct rect rct = tc_getRect(LevelOneCollisionMap, (struct tc_coord){ x, y });
      rect(rct.x - camPos.x, rct.y - camPos.y, rct.width, rct.height);
    }
  }
}

void game_start () {
  PALETTE[0] = 0x000000;
  PALETTE[1] = 0x32cd32;
  PALETTE[2] = 0x8b0000;
  PALETTE[3] = 0xadd8e6;

  playerPos.x = LevelOne.minX / LevelOneCollisionMap.tileWidth + LevelOne.startX / LevelOneCollisionMap.tileWidth;
  playerPos.y = LevelOne.minY / LevelOneCollisionMap.tileHeight + LevelOne.startY / LevelOneCollisionMap.tileHeight;
  tracef("%f",playerPos.x);
  camPos.x = LevelOne.minX;
  camPos.y = LevelOne.minY;
}


// void game_update () {
//   // Gamepad
//   gamepad_update();
//   uint8_t pressedThisFrame = gamepad_getPressedThisFrame();
//   uint8_t gamepad = gamepad_getPressed();

//   if (gamepad & BUTTON_LEFT)
//     {
//       xVel = clampF(xVel - playerAcc, -maxPlayerSpeed, maxPlayerSpeed);
//     }
//   if (gamepad & BUTTON_RIGHT)
//     {
//       xVel = clampF(xVel + playerAcc, -maxPlayerSpeed, maxPlayerSpeed);
//     }
//   // if (gamepad & BUTTON_UP)
//   //   {
//   //     player.pos.y -= 0.5f;
//   //     yVel = clampF(yVel + g, )
//   //   }
//   if (grounded && gamepad & BUTTON_DOWN)
//     {
//       if (xVel < 0) {
//         xVel = clampF(xVel + playerAcc * 2, -maxPlayerSpeed, 0);
//       } else if (xVel > 0) {
//         xVel = clampF(xVel - playerAcc * 2, 0, maxPlayerSpeed);
//       }
//     }

//   if (!grounded) {
//     yVel = clampF(yVel += g, -1, 1);
//   } else {
//     yVel = 0;
//     if (xVel < 0) {
//       xVel = clampF(xVel + friction, -maxPlayerSpeed, 0);
//     } else if (xVel > 0) {
//       xVel = clampF(xVel - friction, 0, maxPlayerSpeed);
//     }
//   }

//   player.pos.x += xVel;
//   player.pos.y += yVel;

//   signed short oldVal = 0;
//   if (player.pos.x < 80 - camXDeadZone) {
//     // Move Cam Left
//     oldVal = camX;
//     camX = clampSS(camX - (80 - camXDeadZone - player.pos.x), LevelOne.minX, LevelOne.maxX);
//     if (oldVal != camX)
//       player.pos.x = 80 - camXDeadZone;
//   } else if (player.pos.x > 80 + camXDeadZone) {
//     // Move Cam Right
//     oldVal = camX;
//     camX = clampSS(camX + (player.pos.x - (80 + camXDeadZone)), LevelOne.minX, LevelOne.maxX);
//     if (oldVal != camX)
//       player.pos.x = camXDeadZone + 80;
//   }

//   if (player.pos.y < 80 - camYDeadZone) {
//     // Move Cam Up
//     oldVal = camY;
//     camY = clampSS(camY - (80 - camYDeadZone - player.pos.y), LevelOne.minY, LevelOne.maxY);
//     if (oldVal != camY)
//       player.pos.y = 80 - camYDeadZone;
//   } else if (player.pos.y > 80 + camYDeadZone) {
//     // Move Cam Down
//     oldVal = camY;
//     camY = clampSS(camY + (player.pos.y - (80 + camYDeadZone)), LevelOne.minY, LevelOne.maxY);
//     if (oldVal != camY)
//       player.pos.y = camYDeadZone + 80;
//   }

//   *DRAW_COLORS = 0x4321;

//   bool currentlyOnGround = false;
//   for (int i = 0; i < LevelOne.tileSize; i++) {
    
//     struct polygon collider = makeSquare();
//     collider.pos.x = LevelOne.tiles[i].posX - camX - 1;
//     collider.pos.y = LevelOne.tiles[i].posY - camY - 1;
//     collider.scale = 17;
//     // collide(&player, &collider);
//     groundedProbe.pos.x = player.pos.x;
//     groundedProbe.pos.y = player.pos.y + 12;
//     leftProbe.pos.x = player.pos.x - 3;
//     leftProbe.pos.y = player.pos.y + 7;
//     rightProbe.pos.x = player.pos.x + 12;
//     rightProbe.pos.y = player.pos.y + 7;
//     if(overlapP(groundedProbe, collider)) {
//       player.pos.y = collider.pos.y - 11;
//       yVel = 0;
//       currentlyOnGround = true;
//     } else if (overlapP(leftProbe, collider)) {
//       player.pos.x = collider.pos.x + 18;
//       xVel = 0;
//     }
//     *DRAW_COLORS = 0x4321;
//     blit(LevelOne.tiles[i].sprite->sprite, LevelOne.tiles[i].posX - camX, LevelOne.tiles[i].posY - camY, 16, 16, LevelOne.tiles[i].rotation);
//     *DRAW_COLORS = 0x1203;
//     drawPolygon(collider);
//   }
//   *DRAW_COLORS = 0x4321;

//   // tracef("%f", xVel);

  
//   // for (int i = 0; i < LevelOne.tileSize; i++) {
//   //   struct polygon collider = makeSquare();
//   //   collider.pos.x = LevelOne.tiles[i].posX - camX;
//   //   collider.pos.y = LevelOne.tiles[i].posY - camY;
//   //   collider.scale = 16;
    
//   //   if (overlapP(groundedProbe, collider))
//   //     currentlyOnGround = true;
//   //   if(overlapP(leftProbe, collider) || overlapP(rightProbe, collider))
//   //     xVel = 0;
//   // }

  

//   for (int i = 0; i < LevelOne.decalSize; i++) {
//     blit(LevelOne.decals[i].sprite->sprite, LevelOne.decals[i].posX - camX, LevelOne.decals[i].posY - camY, 16, 16, LevelOne.decals[i].rotation);
//   }

//   blit(PlayerFlatA.sprite, player.pos.x - 2, player.pos.y - 5, PlayerFlatA.width, PlayerFlatA.height, PlayerFlatA.flag);

//   *DRAW_COLORS = 0x1203;
//   // drawPolygon(player);
//   drawPolygon(groundedProbe);
//   drawPolygon(leftProbe);
//   drawPolygon(rightProbe);

//   // trace(overlapP(player, groundedProbe) ? "true" : "false");
// }

void game_update()
{
  // Gamepad
  gamepad_update();
  uint8_t pressedThisFrame = gamepad_getPressedThisFrame();
  uint8_t gamepad = gamepad_getPressed();


  // Gravity
  playerVel.y += 0.03f;
  
  
  // Clamp velocities
  if (playerVel.x > MAX_SPEED)
    playerVel.x = MAX_SPEED;

  if (playerVel.x < -MAX_SPEED)
    playerVel.x = -MAX_SPEED;

  if (playerVel.y > MAX_SPEED)
    playerVel.y = MAX_SPEED;

  if (playerVel.y < -MAX_SPEED)
    playerVel.y = -MAX_SPEED;


  // Store current player size
  float currentPlayerWidth = PLAYER_UPRIGHT_WIDTH;
  float currentPlayerHeight = PLAYER_UPRIGHT_HEIGHT;

  

  // Get grounded status
  bool grounded =
    tc_getState(LevelOneCollisionMap,
                playerPos.x,
                playerPos.y + currentPlayerHeight + (1.0f/16.0f)) == '#' ||
    tc_getState(LevelOneCollisionMap,
                playerPos.x + currentPlayerWidth,
                playerPos.y + currentPlayerHeight + (1.0f/16.0f)) == '#';


  // Jump
  if (grounded)
    {
      if (pressedThisFrame & BUTTON_UP) {
        playerVel.y += -0.5f;
      }
    }



  // Peddling
  if (grounded)
    {
      if (gamepad & BUTTON_LEFT) // peddle left
        {
          playerVel.x -= PEDDLE_SPEED;
        }
      else if (gamepad & BUTTON_RIGHT) // peddle right
        {
          playerVel.x += PEDDLE_SPEED;
        }
      else if (gamepad & BUTTON_DOWN) // break
        {
          playerVel.x += (PEDDLE_SPEED*3) * (playerVel.x > 0 ? -1 : 1);
          playerVel.x = (fabs(playerVel.x) <= PEDDLE_SPEED*3) ? 0 : playerVel.x;
        }
      else // release peddle
        {
          playerVel.x += (PEDDLE_SPEED) * (playerVel.x > 0 ? -1 : 1);
          playerVel.x = (fabs(playerVel.x) <= PEDDLE_SPEED) ? 0 : playerVel.x;
        }
    }


  
  // Air control
  if (!grounded)
    {
      if (gamepad & BUTTON_LEFT) // left
        {
          playerPos.x -= AIR_SPEED;
        }
      else if (gamepad & BUTTON_RIGHT) // right
        {
          playerPos.x += AIR_SPEED;
        }
    }

  

  // Calc next position
  float newPlayerX = playerPos.x + playerVel.x;
  float newPlayerY = playerPos.y + playerVel.y;


  

  // Collisions
  if (newPlayerX - playerPos.x < 0) // going left
  {
    char topLeftState = tc_getState(LevelOneCollisionMap, newPlayerX, playerPos.y);
    char bottomLeftState = tc_getState(LevelOneCollisionMap, newPlayerX, playerPos.y + (0.9f * currentPlayerHeight));
    if (bottomLeftState != '.' || topLeftState != '.')
      {
        newPlayerX = (int)newPlayerX + 1;
        playerVel.x = 0;
      }
  }

  if (newPlayerX - playerPos.x > 0) // going right
  {
    char topRightState = tc_getState(LevelOneCollisionMap, newPlayerX + currentPlayerWidth, playerPos.y);
    char bottomRightState = tc_getState(LevelOneCollisionMap, newPlayerX + currentPlayerWidth, playerPos.y + (0.9f * currentPlayerHeight));
    if (bottomRightState != '.' || topRightState != '.')
      {
        newPlayerX = (int)newPlayerX + (1.0f - currentPlayerWidth);
        playerVel.x = 0;
      }
  }

  if (newPlayerY - playerPos.y < 0) // going up
  {
    char topLeftState = tc_getState(LevelOneCollisionMap, newPlayerX, newPlayerY);
    char topRightState = tc_getState(LevelOneCollisionMap, newPlayerX + (0.9f * currentPlayerWidth), newPlayerY);
    if (topLeftState != '.' || topRightState != '.')
      {
        newPlayerY = (int)newPlayerY + 1;
        playerVel.y = 0;
      }
  }

  if (newPlayerY - playerPos.y > 0) // going down
  {
    char bottomLeftState = tc_getState(LevelOneCollisionMap, newPlayerX, newPlayerY + currentPlayerHeight);
    char bottomRightState = tc_getState(LevelOneCollisionMap, newPlayerX + (0.9f * currentPlayerWidth), newPlayerY + currentPlayerHeight);
    if (bottomLeftState != '.' || bottomRightState != '.')
      {
        newPlayerY = (int)newPlayerY + (1.0f - currentPlayerHeight);
        playerVel.y = 0;
        // on ground
      }
  }


  // Apply new position
  playerPos.x = newPlayerX;
  playerPos.y = newPlayerY;

  // Calculate Camera Position
  if (playerPos.x *LevelOneCollisionMap.tileWidth < camPos.x + 80 - camXDeadZone) {
    // shift camera left
    camPos.x = clampF(camPos.x - (camPos.x + 80 - camXDeadZone - playerPos.x * LevelOneCollisionMap.tileWidth), 0, 160);
  } else if (playerPos.x *LevelOneCollisionMap.tileWidth > camPos.x + 80 + camXDeadZone) {
    // shift camera right
    camPos.x = clampF(camPos.x + (playerPos.x *LevelOneCollisionMap.tileWidth - (camPos.x + 80 + camXDeadZone)), 0, 160);
  }

  if (playerPos.y *LevelOneCollisionMap.tileHeight < camPos.y + 80 - camYDeadZone) {
    // shift camera up
    camPos.y = clampF(camPos.y - (camPos.y + 80 - camYDeadZone - playerPos.y *LevelOneCollisionMap.tileHeight), 0, 160);
  } else if (playerPos.y *LevelOneCollisionMap.tileHeight > camPos.y + 80 + camYDeadZone) {
    // shift camera down
    camPos.y = clampF(camPos.y + (playerPos.y *LevelOneCollisionMap.tileHeight - (camPos.y + 80 + camYDeadZone)), 0, 160);
  } 

  // Draw tiles
  drawTileStates();

  // Draw player
  *DRAW_COLORS = grounded ? 0x32 : 0x34;
  rect((playerPos.x*LevelOneCollisionMap.tileWidth) - camPos.x,
       (playerPos.y*LevelOneCollisionMap.tileHeight) - camPos.y,
       currentPlayerWidth*LevelOneCollisionMap.tileWidth,
       currentPlayerHeight*LevelOneCollisionMap.tileHeight);
}
