#include "wasm4.h"
#include <math.h>
#include "collider.h"

uint8_t previousGamepad;

struct polygon triangle;
struct polygon triangle2;

void start () {
  triangle = makeTriangle();
  triangle.pos.x = 30;
  triangle.pos.y = 30;
  triangle.scale = 20;
  
  triangle2 = makeSquare();
  triangle2.pos.x = 70;
  triangle2.pos.y = 70;
  triangle2.scale = 20;
}


void update () {
  // Gamepad
  uint8_t gamepad = *GAMEPAD1;
  uint8_t pressedThisFrame = gamepad & (gamepad ^ previousGamepad);
  previousGamepad = gamepad;


  if (gamepad & BUTTON_LEFT)
    {
      triangle.angle += -0.05f;
    }
  if (gamepad & BUTTON_RIGHT)
    {
      triangle.angle += 0.05f;
    }
  if (gamepad & BUTTON_UP)
    {
      triangle.pos.x += cosf(triangle.angle) * 0.5f;
      triangle.pos.y += sinf(triangle.angle) * 0.5f;
    }
  if (gamepad & BUTTON_DOWN)
    {
      triangle.pos.x += cosf(triangle.angle) * -0.5f;
      triangle.pos.y += sinf(triangle.angle) * -0.5f;
    }

  

  drawPolygon(triangle);

  drawPolygon(triangle2);

  /* tracef("collide: %s", overlapP(triangle2, triangle) ? "true" : "false"); */

  collide(&triangle, &triangle2);


  /* struct vec l1_start = {110, 120}; */
  /* struct vec l1_end = {130, 140}; */
  /* struct vec l2_start = {110, 130}; */
  /* struct vec l2_end = {110, 50}; */

  /* line(l1_start.x, l1_start.y, l1_end.x, l1_end.y); */
  /* line(l2_start.x, l2_start.y, l2_end.x, l2_end.y); */

  /* struct vec res = findIntersect(l1_start, l1_end, l2_start, l2_end); */

  /* tracef("res: %f %f", res.x, res.y); */
}
