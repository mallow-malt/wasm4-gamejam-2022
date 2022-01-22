#ifndef TILECOLLIDER_H
#define TILECOLLIDER_H

#include <stdlib.h>
#include "collider.h"

struct tc_context
{
  char* map;
  size_t width;
  size_t height;
  int tileWidth;
  int tileHeight;
};

struct rect
{
  int32_t x;
  int32_t y;
  uint32_t width;
  uint32_t height;
};

struct tc_coord
{
  uint8_t x;
  uint8_t y;
};

#define TC_NULLSTATE ' '

char tc_getState(struct tc_context context, size_t x, size_t y);
struct rect tc_getRect(struct tc_context context, struct tc_coord coords);
struct tc_coord tc_posToCoord(struct tc_context context, struct vec pos);
char tc_getStateAtPos(struct tc_context context, struct vec pos);

#endif /* TILECOLLIDER_H */
