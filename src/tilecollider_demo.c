#include "tilecollider_demo.h"
#include "tilecollider.h"
#include "wasm4.h"
#include "collider.h"
#include "gamepad.h"


#define PLAYER_SIZE 0.5f
#define WALK_SPEED 0.03f
#define MAX_SPEED 0.5f

const struct tc_context ctx = {
  .map =
  ".........."
  ".........."
  ".......#.#"
  "...#...#.#"
  ".........."
  "........#."
  ".........."
  "........#."
  ".../......"
  "####......",
  
  .width = 10,
  .height = 10,
  .tileWidth = 16,
  .tileHeight = 16
};

struct vec playerPos;

struct vec playerVel;

/* const uint8_t playerSprite[60] = { 0x00,0x05,0x00,0x00,0x00,0x10,0x40,0x00,0x00,0x05,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x05,0x54,0x00,0x00,0x04,0x05,0x00,0x00,0x04,0x0a,0x80,0x00,0x05,0x02,0x00,0x00,0x09,0x8a,0x00,0x00,0x02,0x68,0x00,0x0a,0x82,0x6a,0x80,0x20,0x2a,0x60,0x20,0x20,0x21,0x20,0x20,0x20,0x24,0x20,0x20,0x0a,0x80,0x0a,0x80 }; */

void drawTileStates()
{
  for (size_t x = 0; x < ctx.width; ++x) {
    for (size_t y = 0; y < ctx.height; ++y) {
      uint8_t drawColors = 0;
      char tileState = tc_getState(ctx, x, y);
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
      struct rect rct = tc_getRect(ctx, (struct tc_coord){ x, y });
      rect(rct.x, rct.y, rct.width, rct.height);
    }
  }
}

void tcdemo_start()
{
  playerPos.x = 4;
  playerPos.y = 4;
}

void tcdemo_update()
{
  // Gamepad
  gamepad_update();
  uint8_t pressedThisFrame = gamepad_getPressedThisFrame();
  uint8_t gamepad = gamepad_getPressed();


  // Jump
  if (pressedThisFrame & BUTTON_1) {
    playerVel.y += -0.5f;
  }


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


  // Calc next position
  float newPlayerX = playerPos.x + playerVel.x;
  float newPlayerY = playerPos.y + playerVel.y;



  if (gamepad & BUTTON_LEFT)
    {
      newPlayerX += -WALK_SPEED;
    }
  if (gamepad & BUTTON_RIGHT)
    {
      newPlayerX += WALK_SPEED;
    }


  // Collisions
  if (newPlayerX - playerPos.x < 0) // going left
    {
      char topLeftState = tc_getState(ctx, newPlayerX, playerPos.y);
      char bottomLeftState = tc_getState(ctx, newPlayerX, playerPos.y + (0.9f * PLAYER_SIZE));
      if (bottomLeftState != '.' || topLeftState != '.')
        {
          newPlayerX = (int)newPlayerX + 1;
          playerVel.x = 0;
        }
    }

  if (newPlayerX - playerPos.x > 0) // going right
    {
      char topRightState = tc_getState(ctx, newPlayerX + PLAYER_SIZE, playerPos.y);
      char bottomRightState = tc_getState(ctx, newPlayerX + PLAYER_SIZE, playerPos.y + (0.9f * PLAYER_SIZE));
      if (bottomRightState != '.' || topRightState != '.')
        {
          newPlayerX = (int)newPlayerX + (1.0f - PLAYER_SIZE);
          playerVel.x = 0;
        }
    }

  if (newPlayerY - playerPos.y < 0) // going up
    {
      char topLeftState = tc_getState(ctx, newPlayerX, newPlayerY);
      char topRightState = tc_getState(ctx, newPlayerX + (0.9f * PLAYER_SIZE), newPlayerY);
      if (topLeftState != '.' || topRightState != '.')
        {
          newPlayerY = (int)newPlayerY + 1;
          playerVel.y = 0;
        }
    }

  if (newPlayerY - playerPos.y > 0) // going down
    {
      char bottomLeftState = tc_getState(ctx, newPlayerX, newPlayerY + PLAYER_SIZE);
      char bottomRightState = tc_getState(ctx, newPlayerX + (0.9f * PLAYER_SIZE), newPlayerY + PLAYER_SIZE);
      if (bottomLeftState != '.' || bottomRightState != '.')
        {
          newPlayerY = (int)newPlayerY + (1.0f - PLAYER_SIZE);
          playerVel.y = 0;
          // on ground
        }
    }


  // Apply new position
  playerPos.x = newPlayerX;
  playerPos.y = newPlayerY;


  
  // Draw tiles
  drawTileStates();

  
  // Draw player
  *DRAW_COLORS = 0x32;
  rect(playerPos.x*ctx.tileWidth,
       playerPos.y*ctx.tileHeight,
       PLAYER_SIZE*ctx.tileWidth,
       PLAYER_SIZE*ctx.tileHeight);
}
