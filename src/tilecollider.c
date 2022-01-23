#include "tilecollider.h"
#include "wasm4.h"
#include "types.h"


char tc_getState(struct tc_context context, size_t x, size_t y)
{
  if (x < 0 || x >= context.width || y < 0 || y >= context.height)
    {
      return TC_NULLSTATE;
    }
  return context.map[x + y*context.width];
}

struct rect tc_getRect(struct tc_context context, struct tc_coord coords)
{
  struct rect res = {
    .x = coords.x*context.tileWidth,
    .y = coords.y*context.tileHeight,
    .width = context.tileWidth,
    .height = context.tileHeight
  };
  return res;
}

struct tc_coord tc_posToCoord(struct tc_context context, struct vec pos)
{
  struct tc_coord res;
  res.x = pos.x/context.tileWidth;
  res.x = (res.x > 9) ? 9 : res.x;
  res.y = pos.y/context.tileHeight;
  res.y = (res.y > 9) ? 9 : res.y;
  return res;
}

char tc_getStateAtPos(struct tc_context context, struct vec pos)
{
  struct tc_coord coord = tc_posToCoord(context, pos);
  return tc_getState(context, coord.x, coord.y);
}

