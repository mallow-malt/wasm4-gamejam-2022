#include "wasm4.h"

uint8_t Block[] = { 0x66,0x66,0x66,0x66,0x99,0x99,0x99,0x99,0x64,0x00,0x00,0x16,0x91,0x00,0x00,0x49,0x60,0x40,0x01,0x06,0x90,0x10,0x04,0x09,0x60,0x04,0x10,0x06,0x90,0x01,0x40,0x09,0x60,0x01,0x40,0x06,0x90,0x04,0x10,0x09,0x60,0x10,0x04,0x06,0x90,0x40,0x01,0x09,0x61,0x00,0x00,0x46,0x94,0x00,0x00,0x19,0x66,0x66,0x66,0x66,0x99,0x99,0x99,0x99 };

uint8_t Gift[] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x20,0x00,0x00,0x08,0x88,0x00,0x00,0x02,0xa0,0x00,0x00,0x3d,0x7c,0x00,0x00,0x3d,0x7c,0x00,0x00,0x29,0x68,0x00,0x00,0x29,0x68,0x00,0x00,0x3d,0x7c,0x00,0x00,0x3d,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };

uint8_t HorizontalJumpBlock[] = { 0x6a,0xaa,0xaa,0xa6,0x9a,0xaa,0xaa,0xa9,0x60,0x00,0x00,0x06,0x90,0x03,0xc0,0x09,0x60,0x00,0xf0,0x06,0x90,0x00,0x3c,0x09,0x60,0x00,0x0f,0x06,0x93,0xff,0xff,0xc9,0x63,0xff,0xff,0xc6,0x90,0x00,0x0f,0x09,0x60,0x00,0x3c,0x06,0x90,0x00,0xf0,0x09,0x60,0x03,0xc0,0x06,0x90,0x00,0x00,0x09,0x66,0x66,0x66,0x66,0x99,0x99,0x99,0x99 };

uint8_t Mailbox[] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0xfc,0x00,0x00,0x0e,0xac,0x00,0x00,0xff,0xfc,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x40,0x00 };

uint8_t PlayerFlatA[] = { 0x00,0x0f,0x00,0x00,0x00,0x30,0xc0,0x00,0x00,0x30,0xc0,0x00,0x00,0x0f,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x0f,0xfc,0x00,0x00,0x0c,0x0f,0x00,0x00,0x0c,0x05,0x40,0x00,0x0f,0x01,0x00,0x00,0x07,0x45,0x00,0x00,0x01,0xd4,0x00,0x05,0x41,0xd5,0x40,0x14,0x55,0xd4,0x50,0x11,0x13,0x11,0x10,0x14,0x5c,0x14,0x50,0x05,0x40,0x05,0x40 };

uint8_t PlayerFlatB[] = { 0x00,0x0f,0x00,0x00,0x00,0x30,0xc0,0x00,0x00,0x30,0xc0,0x00,0x00,0x0f,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x0f,0xfc,0x00,0x00,0x0c,0x0f,0x00,0x00,0x0c,0x05,0x40,0x00,0x0f,0x01,0x00,0x00,0x07,0x45,0x00,0x00,0x01,0xd4,0x00,0x05,0x41,0xd5,0x40,0x11,0x15,0xd1,0x10,0x15,0x53,0x15,0x50,0x11,0x1c,0x11,0x10,0x05,0x40,0x05,0x40 };

uint8_t PlayerTiltA[] = { 0x00,0x00,0x00,0x00,0x3c,0x00,0x00,0x00,0xc3,0x00,0x00,0x00,0xc3,0x0c,0xd0,0x00,0x3c,0x33,0x40,0x00,0x03,0xc1,0x10,0x00,0x00,0xc0,0x11,0x50,0x00,0x3f,0x15,0x14,0x00,0x11,0xd4,0x44,0x00,0x00,0x75,0x14,0x00,0x00,0x71,0x50,0x00,0x05,0x40,0x00,0x00,0x14,0x50,0x00,0x00,0x11,0x10,0x00,0x00,0x14,0x50,0x00,0x00,0x05,0x40,0x00 };

uint8_t PlayerTiltB[] = { 0x00,0x00,0x00,0x00,0x3c,0x00,0x00,0x00,0xc3,0x00,0x00,0x00,0xc3,0x0c,0xd0,0x00,0x3c,0x33,0x40,0x00,0x03,0xc1,0x10,0x00,0x00,0xc0,0x11,0x50,0x00,0x3f,0x14,0x44,0x00,0x11,0xd5,0x54,0x00,0x00,0x74,0x44,0x00,0x00,0x71,0x50,0x00,0x05,0x40,0x00,0x00,0x11,0x10,0x00,0x00,0x15,0x50,0x00,0x00,0x11,0x10,0x00,0x00,0x05,0x40,0x00 };

uint8_t VerticalJumpBlock[] = { 0x6a,0xaa,0xaa,0xa6,0x9a,0xaa,0xaa,0xa9,0x60,0x00,0x00,0x06,0x90,0x03,0xc0,0x09,0x60,0x0f,0xf0,0x06,0x90,0x3f,0xfc,0x09,0x60,0xf3,0xcf,0x06,0x93,0xc3,0xc3,0xc9,0x63,0x03,0xc0,0xc6,0x90,0x03,0xc0,0x09,0x60,0x03,0xc0,0x06,0x90,0x03,0xc0,0x09,0x60,0x03,0xc0,0x06,0x90,0x00,0x00,0x09,0x66,0x66,0x66,0x66,0x99,0x99,0x99,0x99 };

