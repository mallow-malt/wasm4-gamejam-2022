#include "collider.h"
#include "colliderdemo.h"
#include "wasm4.h"

struct polygon poly1;
struct polygon poly2;

void colliderdemo_start()
{
  poly1 = makeTriangle();
  poly1.scale = 20;
  poly1.pos.x = 80;
  poly1.pos.y = 80;

  poly2 = makeTriangle();
  poly2.scale = 2;
  poly2.pos.x = 30;
  poly2.pos.y = 30;
  /* poly2.angle = 2; */
}


void colliderdemo_update()
{
  uint8_t gamepad = *GAMEPAD1;
  
  if (gamepad & BUTTON_LEFT)
    {
      poly2.pos.x -= 0.5f;
    }
  if (gamepad & BUTTON_RIGHT)
    {
      poly2.pos.x += 0.5f;
    }
  if (gamepad & BUTTON_UP)
    {
      poly2.pos.y -= 0.5f;
    }
  if (gamepad & BUTTON_DOWN)
    {
      poly2.pos.y += 0.5f;
    }

  if (overlapP(poly1, poly2))
    {
      *DRAW_COLORS = 0x42; 
    }
  else
    {
      *DRAW_COLORS = 0x43;
    }

  drawPolygon(poly1);
  drawPolygon(poly2);
}

