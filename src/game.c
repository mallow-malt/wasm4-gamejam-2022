#include "wasm4.h"
#include <math.h>
#include "game.h"
#include "sprites.h"
#include "levels.h"
#include "utils.h"
#include "tilecollider.h"
#include <stdbool.h>
#include "music.h"
#include "score.h"

#define MAX_SPEED 0.5f
#define WALK_SPEED 0.1f
#define PLAYER_UPRIGHT_WIDTH 13.0f/16.0f
#define PLAYER_UPRIGHT_HEIGHT 16.0f/16.0f
#define PLAYER_TILTED_WIDTH 15.0f/16.0f
#define PLAYER_TILTED_HEIGHT 15.0f/16.0f
#define PEDDLE_SPEED 0.002f
#define AIR_SPEED 0.001f

unsigned short camXDeadZone = 0;
unsigned short camYDeadZone = 0;

struct vec playerPos;
struct vec camPos;
struct vec playerVel;

// Used for player animation
bool facingRight = true;
bool wheelsRotated = true;
unsigned char framesSinceSpin = 0;

// Used for gift animation
unsigned char framesSinceGift = 0;
bool giftUp = true;

uint8_t frameCounter = 0;

// Is the block of this state solid?
bool solidp(char state)
{
  return state == '^' || state == '<' || state == '>' || state == '#' || state == 'v';
}

void drawTileStates()
{
  for (size_t x = 0; x < LevelOneCollisionMap.width; ++x) {
    for (size_t y = 0; y < LevelOneCollisionMap.height; ++y) {
      *DRAW_COLORS = 0x4320;
      char tileState = tc_getState(LevelOneCollisionMap, x, y);
      struct rect rct = tc_getRect(LevelOneCollisionMap, (struct tc_coord){ x, y });
      switch (tileState) {
      case '#': blit(Block, rct.x - camPos.x, rct.y - camPos.y, 16, 16, BLIT_2BPP);
        break;
      case '^': blit(VerticalJumpBlock, rct.x - camPos.x, rct.y - camPos.y, 16, 16, BLIT_2BPP);
        break;
      case '>': blit(HorizontalJumpBlock, rct.x - camPos.x, rct.y - camPos.y, 16, 16, BLIT_2BPP);
        break;
      case 'v': blit(VerticalJumpBlock, rct.x - camPos.x, rct.y - camPos.y, 16, 16, BLIT_2BPP | BLIT_FLIP_Y);
        break;
      case '<': blit(HorizontalJumpBlock, rct.x - camPos.x, rct.y - camPos.y, 16, 16, BLIT_2BPP | BLIT_FLIP_X);
        break;
      case 'G': blit(Gift, rct.x - camPos.x, rct.y - camPos.y + (giftUp ? 0 : 2), 16, 16, BLIT_2BPP);
        break;
      case 'W': blit(Mailbox, rct.x - camPos.x, rct.y - camPos.y, 16, 16, BLIT_2BPP);
        break;
      }
    }
  }
}

void game_start () {
  PALETTE[0] = 0x000000;
  PALETTE[1] = 0x32cd32;
  PALETTE[2] = 0x8b0000;
  PALETTE[3] = 0xadd8e6;

  *DRAW_COLORS = 0x4320;

  playerPos = LevelOnePlayerStart;
  camPos = LevelOneCamStart;
}

uint8_t game_update(uint8_t pressedThisFrame, uint8_t gamepad)
{
  music_update();
  
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
                playerPos.x + (1.0f/16.0f),
                playerPos.y + currentPlayerHeight + (1.0f/16.0f)) == '#' ||
    tc_getState(LevelOneCollisionMap,
                playerPos.x + currentPlayerWidth - (1.0f/16.0f),
                playerPos.y + currentPlayerHeight + (1.0f/16.0f)) == '#';


  // Jump
  if (grounded)
    {
      if (pressedThisFrame & BUTTON_UP) {
        playerVel.y += -0.5f;
      }
    }



  // Air control
  if (!grounded)
    {
      if (gamepad & BUTTON_LEFT) // left
        {
          playerVel.x -= AIR_SPEED;
        }
      else if (gamepad & BUTTON_RIGHT) // right
        {
          playerVel.x += AIR_SPEED;
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


  

  // Calc next position
  float newPlayerX = playerPos.x + playerVel.x;
  float newPlayerY = playerPos.y + playerVel.y;



  // Hard collisions
  if (newPlayerX - playerPos.x < 0) // going left
  {
    char topLeftState = tc_getState(LevelOneCollisionMap, newPlayerX, playerPos.y);
    char bottomLeftState = tc_getState(LevelOneCollisionMap, newPlayerX, playerPos.y + (0.9f * currentPlayerHeight));
    if (solidp(bottomLeftState) || solidp(topLeftState))
      {
        newPlayerX = (int)newPlayerX + 1;
        playerVel.x = 0;
      }
  }

  if (newPlayerX - playerPos.x > 0) // going right
  {
    char topRightState = tc_getState(LevelOneCollisionMap, newPlayerX + currentPlayerWidth, playerPos.y);
    char bottomRightState = tc_getState(LevelOneCollisionMap, newPlayerX + currentPlayerWidth, playerPos.y + (0.9f * currentPlayerHeight));
    if (solidp(bottomRightState) || solidp(topRightState))
      {
        newPlayerX = (int)newPlayerX + (1.0f - currentPlayerWidth);
        playerVel.x = 0;
      }
  }

  if (newPlayerY - playerPos.y < 0) // going up
  {
    char topLeftState = tc_getState(LevelOneCollisionMap, newPlayerX, newPlayerY);
    char topRightState = tc_getState(LevelOneCollisionMap, newPlayerX + (0.9f * currentPlayerWidth), newPlayerY);


    if (topLeftState == 'v' || topRightState == 'v')
      {
        playerVel.y += 0.6f;
      }
    
    else if (solidp(topLeftState) || solidp(topRightState))
      {
        newPlayerY = (int)newPlayerY + 1;
        playerVel.y = 0;
      }
  }

  if (newPlayerY - playerPos.y > 0) // going down
  {
    char bottomLeftState = tc_getState(LevelOneCollisionMap, newPlayerX, newPlayerY + currentPlayerHeight);
    char bottomRightState = tc_getState(LevelOneCollisionMap, newPlayerX + (0.9f * currentPlayerWidth), newPlayerY + currentPlayerHeight);

    if (bottomLeftState == '^' || bottomRightState == '^')
      {
        playerVel.y = -1.2f;
      }
    else if (bottomLeftState == '<' || bottomRightState == '<')
      {
        playerVel.y = -0.6f;
        playerVel.x = -0.6f;
      }
    else if (bottomLeftState == '>' || bottomRightState == '>')
      {
        playerVel.y = -0.6f;
        playerVel.x = 0.6f;
      }

    else if (solidp(bottomLeftState) || solidp(bottomRightState))
      {
        newPlayerY = (int)newPlayerY + (1.0f - currentPlayerHeight);
        playerVel.y = 0;
        // on ground
      }
  }


  // Soft collisions
  {
    struct vec topLeftPos = {
      newPlayerX + (0.1f * currentPlayerWidth),
      newPlayerY + (0.1f * currentPlayerHeight)};
    struct vec bottomLeftPos = {
      newPlayerX + (0.1f * currentPlayerWidth),
      newPlayerY + (0.9f * currentPlayerHeight)};
    struct vec topRightPos = {
      newPlayerX + (0.9f * currentPlayerWidth),
      newPlayerY + (0.1f * currentPlayerHeight)};
    struct vec bottomRightPos = {
      newPlayerX + (0.9f * currentPlayerWidth),
      newPlayerY + (0.9f * currentPlayerHeight)};
    
    char topLeftState = tc_getState(LevelOneCollisionMap, topLeftPos.x, topLeftPos.y);
    char bottomLeftState = tc_getState(LevelOneCollisionMap, bottomLeftPos.x, bottomLeftPos.y);
    char topRightState = tc_getState(LevelOneCollisionMap, topRightPos.x, topRightPos.y);
    char bottomRightState = tc_getState(LevelOneCollisionMap, bottomRightPos.x, bottomRightPos.y);

    if (topLeftState == 'G')
      {
        tc_setState(LevelOneCollisionMap, topLeftPos.x, topLeftPos.y, '.');
        giftCounter++;
      }
    else if (bottomLeftState == 'G')
      {
        tc_setState(LevelOneCollisionMap, bottomLeftPos.x, bottomLeftPos.y, '.');
        giftCounter++;
      }
    else if (topRightState == 'G')
      {
        tc_setState(LevelOneCollisionMap, topRightPos.x, topRightPos.y, '.');
        giftCounter++;
      }
    else if (bottomRightState == 'G')
      {
        tc_setState(LevelOneCollisionMap, bottomRightPos.x, bottomRightPos.y, '.');
        giftCounter++;
      }

    if (topLeftState == 'W' || bottomLeftState == 'W' || topRightState == 'W' || bottomRightState == 'W')
      {
        return 2;
      }
  }  

  

  // Apply new position
  playerPos.x = newPlayerX;
  playerPos.y = newPlayerY;

  // Calculate Camera Position
  if (playerPos.x *LevelOneCollisionMap.tileWidth < camPos.x + 80 - camXDeadZone) {
    // shift camera left
    camPos.x = clampF(camPos.x - (camPos.x + 80 - camXDeadZone - playerPos.x * LevelOneCollisionMap.tileWidth), 0, LevelOneCamMax.x);
  } else if (playerPos.x *LevelOneCollisionMap.tileWidth > camPos.x + 80 + camXDeadZone) {
    // shift camera right
    camPos.x = clampF(camPos.x + (playerPos.x *LevelOneCollisionMap.tileWidth - (camPos.x + 80 + camXDeadZone)), 0, LevelOneCamMax.x);
  }

  if (playerPos.y *LevelOneCollisionMap.tileHeight < camPos.y + 80 - camYDeadZone) {
    // shift camera up
    camPos.y = clampF(camPos.y - (camPos.y + 80 - camYDeadZone - playerPos.y *LevelOneCollisionMap.tileHeight), 0, LevelOneCamMax.y);
  } else if (playerPos.y *LevelOneCollisionMap.tileHeight > camPos.y + 80 + camYDeadZone) {
    // shift camera down
    camPos.y = clampF(camPos.y + (playerPos.y *LevelOneCollisionMap.tileHeight - (camPos.y + 80 + camYDeadZone)), 0, LevelOneCamMax.y);
  } 

  // Draw tiles
  if(framesSinceGift == 60) {
    giftUp = !giftUp;
    framesSinceGift = 0;
  } else {
    framesSinceGift++;
  }

  drawTileStates();

  // Draw player
  if(playerVel.x < 0)
    facingRight = false;
  if(playerVel.x > 0)
    facingRight = true;

  if (playerVel.x == 0)
    framesSinceSpin = 0;
  else if (framesSinceSpin == 15) {
    wheelsRotated = !wheelsRotated;
    framesSinceSpin = 0;
  }
  else
    framesSinceSpin++;

  if (grounded) {
    blit(wheelsRotated ? PlayerFlatA : PlayerFlatB, (playerPos.x*LevelOneCollisionMap.tileWidth) - camPos.x - (facingRight ? 1 : 2), (playerPos.y*LevelOneCollisionMap.tileHeight) - camPos.y, 16, 16, facingRight ? BLIT_2BPP : BLIT_2BPP | BLIT_FLIP_X);
  } else {
    blit(wheelsRotated ? PlayerTiltA : PlayerTiltB, (playerPos.x*LevelOneCollisionMap.tileWidth) - camPos.x, (playerPos.y*LevelOneCollisionMap.tileHeight) - camPos.y, 16, 16, facingRight ? BLIT_2BPP : BLIT_2BPP | BLIT_FLIP_X);
  }
  // *DRAW_COLORS = 0x30;
  // rect((playerPos.x*LevelOneCollisionMap.tileWidth) - camPos.x,
  //      (playerPos.y*LevelOneCollisionMap.tileHeight) - camPos.y,
  //      currentPlayerWidth*LevelOneCollisionMap.tileWidth,
  //      currentPlayerHeight*LevelOneCollisionMap.tileHeight);
  char str[3];
  *DRAW_COLORS = 0x4321;
  text(intToString(giftCounter, str), 136, 0);

  if (frameCounter == 60) {
    frameCounter = 0;
    timeCounter = clampUI(timeCounter + 1, 0, 999);
  } else
    frameCounter++;

  if (timeCounter > 120)
    *DRAW_COLORS = 0x32;
  text(intToString(timeCounter, str), 0, 0);

  return 1;
}
