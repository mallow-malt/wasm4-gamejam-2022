#include "types.h"

const struct tc_context LevelOneCollisionMap = {
  .map =
    "###############################################################################"
    "#.............................................................................#"
    "#............................................G................................#"
    "#............................................###.......#......................#"
    "#...............................................>......#......................#"
    "#...........................................G..#.......#......................#"
    "#....................G.........................#......<.......................#"
    "#....................#.G............>..........#..............................#"
    "#....................#.#........................>......#......................#"
    "#....................#.................................#......................#"
    "#................###^#.........###^........G..........<........G.......G......#"
    "#.....................................................................###.....#"
    "#....G.............G...........................................#...G..#W......#"
    "###########>################^####################>#########################^###"
,
  .width = 79,
  .height = 14,
  .tileWidth = 16,
  .tileHeight = 16
};

const struct vec LevelOnePlayerStart = {
    .x = 1,
    .y = 12
};

const struct vec LevelOneCamStart = {
    .x = 0,
    .y = 64
};

const struct vec LevelOneCamMax = {
    .x = 1104,
    .y = 64
};
