#include "wasm4.h"

#ifndef TYPES_H
#define TYPES_H

struct Sprite {
   uint32_t  height;
   uint32_t  width;
   uint32_t  flag;
   uint8_t   sprite[];
};

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

struct vec
{
  float x;
  float y;
};

#endif /* TYPES_H */