#include "wasm4.h"
#include "cgsprites.h"
#include "types.h"

uint8_t openingState = 0; // TODO put back to 0

uint8_t roadPosition = 10;

struct vec treeMapOne[22] = {
    { .x = 7, .y = 8},
    { .x = 28, .y = 1},
    { .x = 24, .y = 16},
    { .x = 66, .y = -4},
    { .x = 13, .y = 37},
    { .x = 31, .y = 33},
    { .x = 48, .y = 39},
    { .x = 49, .y = 11},
    { .x = 67, .y = 22},
    { .x = 65, .y = 42},
    { .x = 82, .y = 42},
    { .x = 92, .y = 27},
    { .x = 94, .y = 7},
    { .x = 109, .y = 1},
    { .x = 111, .y = 26},
    { .x = 121, .y = 45},
    { .x = 137, .y = 23},
    { .x = 125, .y = 10},
    { .x = 154, .y = 25},
    { .x = 149, .y = 4},
    { .x = 146, .y = 46},
    { .x = 160, .y = 39}
    
};

struct  vec treeMapTwo[22] = 
{
    { .x = 167, .y = 3},
    { .x = 167, .y = 19},
    { .x = 176, .y = 41},
    { .x = 192, .y = 26},
    { .x = 208, .y = 42},
    { .x = 207, .y = 22},
    { .x = 187, .y = 12},
    { .x = 202, .y = 4},
    { .x = 218, .y = 3},
    { .x = 227, .y = 24},
    { .x = 241, .y = 20},
    { .x = 234, .y = 46},
    { .x = 247, .y = 41},
    { .x = 246, .y = 6},
    { .x = 257, .y = 28},
    { .x = 269, .y = 34},
    { .x = 268, .y = 1},
    { .x = 275, .y = 14},
    { .x = 306, .y = 7},
    { .x = 294, .y = 22},
    { .x = 281, .y = 42},
    { .x = 303, .y = 42}
};

uint8_t treeState = 0;
uint16_t treePosition = 0;

uint8_t carState = 0;
uint8_t carFrames = 0;

uint8_t debrisPosition = 0;

uint8_t flameFrames = 0;
uint8_t flameState = 0;

uint8_t textState = 0;

uint8_t play_opening(uint8_t pressedThisFrame) {
    switch (openingState)
    {
        case 0:
            *DRAW_COLORS = 0x4320;
            blit(title, 8, 20, 148, 79, BLIT_2BPP);
            *DRAW_COLORS = 0x2;
            text("X to continue", 28, 130);
            text("Z to skip cutscene", 8, 138);
            if(pressedThisFrame & BUTTON_1)
                openingState = 1;
            if(pressedThisFrame & BUTTON_2)
                return 1;
            break;
        case 1:
            *DRAW_COLORS = 0x4320;
            for (uint8_t i = 0; i < 13; i++)
                blit(road, (15 * i) - roadPosition, 60, 24, 22, BLIT_2BPP);
            if (roadPosition == 24)
                roadPosition = 10;
            else
                roadPosition++;
            for (uint8_t i = 0; i < 22; i++) {
                blit(tree, treeMapOne[i].x - treePosition + (treeState == 1 ? 320 : 0), treeMapOne[i].y, 12, 11, BLIT_2BPP);
                blit(tree, treeMapOne[i].x - treePosition + (treeState == 1 ? 320 : 0), treeMapOne[i].y + 90, 12, 11, BLIT_2BPP);
            }
            for (uint8_t i = 0; i < 22; i++) {
                blit(tree, treeMapTwo[i].x - treePosition, treeMapTwo[i].y, 12, 11, BLIT_2BPP);
                blit(tree, treeMapTwo[i].x - treePosition, treeMapTwo[i].y + 90, 12, 11, BLIT_2BPP);
            }

            if(treePosition > 160)
                treeState = 1;
            else 
                treeState = 0;

            if (treePosition == 320)
                treePosition = 0;
            else
                treePosition++;

            blit(truck, 10 , 63 - (carState == 1 ? 1 : 0), 28, 17, BLIT_2BPP | BLIT_FLIP_X);
            if (carFrames == 10) {
                carState = carState == 1 ? 0 : 1;
                carFrames = 0;
            } else
                carFrames++;
            if (debrisPosition != 0 || (debrisPosition == 0 && pressedThisFrame & BUTTON_1)) 
                debrisPosition++;
            else if (pressedThisFrame & BUTTON_2)
                return 1;
            blit(debris, 180 - debrisPosition, 72, 16, 7, BLIT_2BPP);
            if (debrisPosition == 142)
                openingState = 2;
            break;
            case 2:
                *DRAW_COLORS = 0x4320;
                for (uint8_t i = 0; i < 13; i++)
                    blit(road, (15 * i) - roadPosition, 60, 24, 22, BLIT_2BPP);
                for (uint8_t i = 0; i < 22; i++) {
                    blit(tree, treeMapOne[i].x - treePosition + (treeState == 1 ? 320 : 0), treeMapOne[i].y, 12, 11, BLIT_2BPP);
                    blit(tree, treeMapOne[i].x - treePosition + (treeState == 1 ? 320 : 0), treeMapOne[i].y + 90, 12, 11, BLIT_2BPP);
                } 
                for (uint8_t i = 0; i < 22; i++) {
                    blit(tree, treeMapTwo[i].x - treePosition, treeMapTwo[i].y, 12, 11, BLIT_2BPP);
                    blit(tree, treeMapTwo[i].x - treePosition, treeMapTwo[i].y + 90, 12, 11, BLIT_2BPP);
                }

                blit(truck, 10 , 63 - (carState == 1 ? 1 : 0), 28, 17, BLIT_2BPP | BLIT_FLIP_X | BLIT_FLIP_Y);

                blit(flameState == 0 ? flameA : flameState == 1 ? flameB : flameC, 20, 49, 12, 17, BLIT_2BPP);

                if (flameFrames == 10) {
                    flameState = flameState == 0 ? 1 : flameState == 1 ? 2 : 0;
                    flameFrames = 0;
                } else
                    flameFrames++;

                blit(debris, 38, 72, 16, 7, BLIT_2BPP);
                
                *DRAW_COLORS = 0x2;
                switch (textState)
                {
                case 0: text("Oh no!", 8, 150);
                    break;
                case 1: text("Gifts are all over!", 8, 150);
                    break;
                case 2: text("Christmas is ruined!", 2, 150);
                    break;
                case 3: text("Wait! Is that-", 8, 150);
                    break;
                default: openingState = 3;
                    break;
                }
                if(pressedThisFrame & BUTTON_1)
                    textState++;
                if(pressedThisFrame & BUTTON_2)
                    return 1;
                break;
                case 3:
                    *DRAW_COLORS = 0x4320;
                    blit(bike, 54, 45, 52, 32, BLIT_2BPP);
                    *DRAW_COLORS = 0x2;
                    text("You found a bike!", 15, 100);
                    if(pressedThisFrame & BUTTON_1 || pressedThisFrame & BUTTON_2)
                        return 1;
                    break;

    }
    return 0;
}
