#include "wasm4.h"
#include <math.h>

#define TILE_MAP_WIDTH 10
#define TILE_MAP_HEIGHT 10

#define TILE_SIZE 16
#define PLAYER_SIZE 0.5f
#define FLY_SPEED 0.03f
#define MAX_SPEED 0.9f

const char* MapData =
  ".........."
  ".........."
  ".......#.#"
  "...#...#.#"
  ".........."
  "........#."
  ".........."
  "........#."
  ".../......"
  "####......"
  ;

struct Vect
{
  float x;
  float y;
};

struct TileCoord
{
  uint8_t x;
  uint8_t y;
};

struct Vect playerPos;

struct Vect playerVel;

uint8_t previousGamepad;

char GetTileState(size_t x, size_t y)
{
  if (x < 0 || x >= TILE_MAP_WIDTH || y < 0 || y >= TILE_MAP_HEIGHT)
    {
      return ' ';
    }
  return MapData[x + y*TILE_MAP_WIDTH];
}


// player
const uint8_t player[60] = { 0x00,0x05,0x00,0x00,0x00,0x10,0x40,0x00,0x00,0x05,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x05,0x54,0x00,0x00,0x04,0x05,0x00,0x00,0x04,0x0a,0x80,0x00,0x05,0x02,0x00,0x00,0x09,0x8a,0x00,0x00,0x02,0x68,0x00,0x0a,0x82,0x6a,0x80,0x20,0x2a,0x60,0x20,0x20,0x21,0x20,0x20,0x20,0x24,0x20,0x20,0x0a,0x80,0x0a,0x80 };


void DrawTileStates()
{
  for (int x = 0; x < TILE_MAP_WIDTH; ++x) {
    for (int y = 0; y < TILE_MAP_HEIGHT; ++y) {
      uint8_t drawColors = 0;
      char tileState = GetTileState(x, y);
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
      rect(x*TILE_SIZE, y*TILE_SIZE, TILE_SIZE, TILE_SIZE);
    }
  }
}

struct TileCoord MouseTileCoord()
{
  struct TileCoord res;
  res.x = *MOUSE_X/TILE_SIZE;
  res.x = (res.x > 9) ? 9 : res.x;
  res.y = *MOUSE_Y/TILE_SIZE;
  res.y = (res.y > 9) ? 9 : res.y;
  return res;
}

void start () {
  playerPos.x = 4;
  playerPos.y = 4;
}


void update () {
  // Gamepad
  uint8_t gamepad = *GAMEPAD1;
  uint8_t pressedThisFrame = gamepad & (gamepad ^ previousGamepad);
  previousGamepad = gamepad;

  
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


  // Fly Controls
  if (gamepad & BUTTON_LEFT)
    {
      newPlayerX += -FLY_SPEED;
    }
  if (gamepad & BUTTON_RIGHT)
    {
      newPlayerX += FLY_SPEED;
    }
  if (gamepad & BUTTON_DOWN)
    {
      newPlayerY += FLY_SPEED;
    }
  if (gamepad & BUTTON_UP)
    {
      newPlayerY += -FLY_SPEED;
    }

  
  
  // Collisions
  if (newPlayerX - playerPos.x < 0) // going left
    {
      char topLeftState = GetTileState(newPlayerX, playerPos.y);
      char bottomLeftState = GetTileState(newPlayerX, playerPos.y + (0.9f * PLAYER_SIZE));
      /* tracef("npx: %f  bl: %c  tl: %c", newPlayerX, bottomLeftState, topLeftState); */
      if (bottomLeftState != '.' || topLeftState != '.')
        {
          newPlayerX = (int)newPlayerX + 1;
          playerVel.x = 0;
        }
    }

  if (newPlayerX - playerPos.x > 0) // going right
    {
      char topRightState = GetTileState(newPlayerX + PLAYER_SIZE, playerPos.y);
      char bottomRightState = GetTileState(newPlayerX + PLAYER_SIZE, playerPos.y + (0.9f * PLAYER_SIZE));
      if (bottomRightState != '.' || topRightState != '.')
        {
          newPlayerX = (int)newPlayerX + (1.0f - PLAYER_SIZE);
          playerVel.x = 0;
        }
    }

  if (newPlayerY - playerPos.y < 0) // going up
    {
      char topLeftState = GetTileState(newPlayerX, newPlayerY);
      char topRightState = GetTileState(newPlayerX + (0.9f * PLAYER_SIZE), newPlayerY);
      if (topLeftState != '.' || topRightState != '.')
        {
          newPlayerY = (int)newPlayerY + 1;
          playerVel.y = 0;
        }
    }

  if (newPlayerY - playerPos.y > 0) // going down
    {
      char bottomLeftState = GetTileState(newPlayerX, newPlayerY + PLAYER_SIZE);
      char bottomRightState = GetTileState(newPlayerX + (0.9f * PLAYER_SIZE), newPlayerY + PLAYER_SIZE);
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
  DrawTileStates();

  // Draw player
  *DRAW_COLORS = 0x32;
  uint16_t playerPixelSize = PLAYER_SIZE*TILE_SIZE;
  rect(playerPos.x*TILE_SIZE, playerPos.y*TILE_SIZE, playerPixelSize, playerPixelSize);

  // Draw mouse
  *DRAW_COLORS = 4;
  rect(*MOUSE_X, *MOUSE_Y, 4, 4);
}
