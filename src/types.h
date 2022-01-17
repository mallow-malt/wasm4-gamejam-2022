#include "wasm4.h"

#ifndef TYPES_H
#define TYPES_H

struct Sprite {
   uint32_t  height;
   uint32_t  width;
   uint32_t  flag;
   uint8_t   sprite[];
};

struct MapTile {
    struct Sprite* sprite;
    signed short posX;
    signed short posY;
    uint32_t rotation;
};

struct Map {
    struct MapTile* tiles;
    unsigned short tileSize;
    struct MapTile* decals;
    unsigned short decalSize;
    char startX;
    char startY;
    signed short minX;
    signed short maxX;
    signed short minY;
    signed short maxY;
};

#endif /* TYPES_H */