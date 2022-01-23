#include "wasm4.h"

uint8_t bike[] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0xff,0x00,0x03,0xff,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xc0,0x00,0x00,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xaa,0xaa,0xaa,0xaa,0xa8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x88,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x80,0x00,0x00,0x02,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x80,0x00,0x00,0x08,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x80,0x00,0x00,0x20,0x02,0x00,0x00,0x00,0x00,0x01,0x55,0x00,0x20,0x80,0x00,0x00,0x80,0x02,0x55,0x00,0x00,0x00,0x14,0x10,0x50,0x80,0x20,0x00,0x02,0x00,0x16,0x10,0x50,0x00,0x01,0x40,0x10,0x06,0x00,0x20,0x00,0x28,0x01,0x40,0x90,0x05,0x00,0x05,0x00,0x10,0x09,0x40,0x20,0x00,0x80,0x05,0x00,0x90,0x01,0x40,0x04,0x40,0x10,0x24,0x40,0x20,0x02,0x00,0x04,0x40,0x90,0x04,0x40,0x10,0x10,0x10,0x90,0x10,0x20,0x08,0x00,0x10,0x10,0x90,0x10,0x10,0x10,0x04,0x10,0x80,0x10,0x20,0x20,0x00,0x10,0x04,0x90,0x40,0x10,0x40,0x01,0x12,0x00,0x04,0x08,0x80,0x00,0x40,0x01,0x21,0x00,0x04,0x40,0x00,0x58,0x00,0x04,0x0a,0x00,0x00,0x40,0x00,0x64,0x00,0x04,0x55,0x55,0x6a,0xaa,0xaa,0xa8,0x00,0x00,0x55,0x55,0x65,0x55,0x54,0x40,0x00,0x54,0x00,0x04,0x00,0x00,0x00,0x40,0x00,0x54,0x00,0x04,0x40,0x01,0x11,0x00,0x04,0x00,0x00,0x00,0x40,0x01,0x11,0x00,0x04,0x10,0x04,0x10,0x40,0x10,0x00,0x00,0x00,0x10,0x04,0x10,0x40,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x00,0x10,0x10,0x10,0x10,0x10,0x04,0x40,0x10,0x04,0x40,0x00,0x00,0x00,0x04,0x40,0x10,0x04,0x40,0x05,0x00,0x10,0x01,0x40,0x00,0x00,0x00,0x05,0x00,0x10,0x01,0x40,0x01,0x40,0x10,0x05,0x00,0x00,0x00,0x00,0x01,0x40,0x10,0x05,0x00,0x00,0x14,0x10,0x50,0x00,0x00,0x00,0x00,0x00,0x14,0x10,0x50,0x00,0x00,0x01,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x00,0x00 };

uint8_t debris[] = { 0x00,0x02,0x00,0x00,0x00,0x8a,0x80,0x00,0x02,0xa9,0x80,0x00,0x2a,0x5a,0xaa,0x00,0x25,0xa9,0xa6,0x80,0x99,0x99,0x99,0x80,0xaa,0xaa,0xaa,0x80 };

uint8_t flameA[] = { 0x00,0x80,0x00,0x00,0x80,0x00,0x00,0xa0,0x00,0x0c,0xa8,0x3f,0x0c,0xaa,0xff,0x3e,0xab,0xff,0x3f,0xab,0xfc,0x3f,0xab,0xfc,0xff,0xef,0xfc,0x5e,0xbf,0x5f,0x56,0xbd,0x54,0x5a,0xbd,0x55,0x5a,0xa5,0x54,0x56,0xa9,0x54,0x55,0xa9,0x50,0x15,0xaa,0x50,0x06,0xa9,0x50 };

uint8_t flameB[] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x04,0x05,0x00,0x01,0x05,0x40,0x21,0x75,0x40,0x25,0x5d,0x60,0x29,0x5d,0x60,0xaa,0x7f,0x68,0xaa,0xbf,0x68,0x2b,0xff,0xa8,0x0b,0xfe,0xa8,0x3f,0xfa,0xa0,0x3f,0xfa,0xa0,0x0f,0xfa,0xa0 };

uint8_t flameC[] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x28,0x00,0x20,0x28,0x00,0x20,0xaa,0x30,0xa8,0xaa,0xb0,0xa8,0xaa,0xb2,0xa8,0x29,0xfa,0xb8,0x25,0xfa,0xbc,0x05,0xfa,0xbc,0x15,0x7e,0xbc,0x15,0x5a,0xfc,0x15,0x5f,0xfc,0x15,0x5f,0xfc,0x05,0x7f,0xfc,0x01,0xff,0xf0,0x00,0xff,0xc0 };

uint8_t road[] = { 0xff,0xff,0xff,0xfc,0x00,0x00,0xff,0xff,0xff,0xfc,0x00,0x00,0xff,0xff,0xff,0xfc,0x00,0x00,0x3f,0xff,0xff,0xff,0x00,0x00,0x3f,0xff,0xff,0xff,0x00,0x00,0x0f,0xff,0xff,0xff,0xc0,0x00,0x0f,0xff,0xff,0xff,0xc0,0x00,0x03,0xff,0xff,0xff,0xf0,0x00,0x03,0xff,0xff,0xff,0xf0,0x00,0x00,0xff,0xff,0xff,0xfc,0x00,0x00,0xff,0xd5,0x5f,0xfc,0x00,0x00,0x3f,0xf5,0x57,0xff,0x00,0x00,0x3f,0xff,0xff,0xff,0x00,0x00,0x0f,0xff,0xff,0xff,0xc0,0x00,0x0f,0xff,0xff,0xff,0xc0,0x00,0x03,0xff,0xff,0xff,0xf0,0x00,0x03,0xff,0xff,0xff,0xf0,0x00,0x00,0xff,0xff,0xff,0xfc,0x00,0x00,0xff,0xff,0xff,0xfc,0x00,0x00,0x3f,0xff,0xff,0xff,0x00,0x00,0x3f,0xff,0xff,0xff,0x00,0x00,0x3f,0xff,0xff,0xff };

uint8_t title[] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0xa0,0x00,0x2a,0x80,0x00,0x02,0xa8,0x00,0x00,0xaa,0x00,0x28,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x02,0xa8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x08,0x28,0x00,0x80,0x20,0x00,0x28,0x00,0x00,0x02,0x00,0x80,0x28,0x00,0xa0,0x00,0x02,0x00,0x28,0x00,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x00,0x02,0x00,0x20,0x02,0x80,0x00,0x00,0x08,0x00,0x80,0x28,0x02,0x88,0x00,0x02,0x2a,0xa8,0x02,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x80,0x00,0x08,0x00,0x80,0x08,0x00,0x00,0x00,0x20,0x02,0x00,0x28,0x02,0x08,0x00,0xaa,0xa8,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x22,0x80,0x00,0x20,0x0a,0x00,0x08,0x00,0x00,0x00,0x80,0x28,0x00,0x28,0x08,0x08,0x2a,0xa2,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x22,0x00,0x00,0x22,0xa8,0x00,0x08,0x00,0x00,0x00,0x8a,0xa0,0x00,0x28,0x08,0x08,0x00,0x02,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2a,0x00,0x00,0x2a,0x00,0x00,0x0a,0xa0,0x00,0x00,0xa8,0x00,0x00,0x08,0x20,0x08,0x00,0x02,0x00,0x00,0x0a,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x28,0x00,0x00,0x80,0x00,0x00,0x02,0xaa,0xa0,0x02,0x00,0x00,0x00,0x08,0x20,0x08,0x00,0x02,0x00,0x00,0x02,0xaa,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x28,0x00,0x00,0x80,0x00,0x08,0x00,0x02,0xaa,0x02,0x00,0x00,0x20,0x08,0x20,0x08,0x00,0x02,0x00,0x00,0x00,0x02,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x80,0x00,0x08,0x00,0x00,0x0a,0x82,0x00,0x00,0x20,0x08,0x80,0x08,0x00,0x02,0x00,0x00,0x00,0x00,0x0a,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x80,0x00,0x20,0x00,0x00,0x00,0x82,0x00,0x00,0x80,0x08,0x80,0x08,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x80,0x00,0x20,0x00,0x00,0x00,0x82,0x00,0x00,0x80,0x08,0x80,0x08,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0xa0,0x00,0x80,0x00,0x00,0x02,0x02,0x80,0x02,0x00,0x0a,0x00,0x08,0x00,0x02,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xc0,0x00,0x00,0x00,0x20,0x00,0x00,0x20,0x02,0x00,0x00,0x00,0x02,0x00,0x80,0x08,0x00,0x0a,0x00,0x08,0x00,0x02,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xc0,0x00,0x00,0x00,0x28,0x00,0x00,0x0a,0xa8,0x03,0xc0,0x80,0x28,0x00,0x2a,0xa0,0x00,0x00,0x00,0x08,0x00,0x02,0x80,0x00,0x00,0x80,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xff,0xfc,0x00,0x00,0x28,0x00,0x00,0x00,0x00,0x03,0xc2,0xaa,0x80,0x00,0x00,0x0f,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x02,0xaa,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x20,0x0f,0xc0,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xfc,0x00,0x00,0x00,0x00,0x00,0x20,0x0f,0xc0,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x20,0x0f,0xc0,0x00,0x00,0x00,0x20,0x3f,0x0a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x3f,0xc0,0x00,0x00,0x00,0x00,0x08,0x0f,0x00,0x00,0x00,0x28,0x08,0x3f,0xa0,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x0f,0xc0,0xa0,0x00,0x00,0x00,0x08,0x3f,0x00,0x00,0x0a,0x80,0x02,0x2a,0xaa,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x00,0x00,0x0f,0xc0,0x0a,0xa0,0x00,0x00,0x08,0x3f,0x22,0x0a,0xa0,0x00,0x02,0xaa,0x00,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x00,0x00,0x3f,0xc0,0xaa,0x2a,0x80,0x00,0x08,0x3f,0x82,0xa0,0x00,0x00,0xaa,0xec,0x2a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x03,0xff,0x00,0x00,0xaa,0xaa,0x00,0x3e,0xfa,0xa8,0x80,0xff,0xea,0x80,0xfa,0xa2,0xaa,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xf0,0x00,0xff,0xfc,0x00,0x3f,0xea,0x0a,0xaa,0xbe,0xea,0x00,0x83,0xea,0xa8,0x2a,0xaa,0xa8,0x02,0xa8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xf0,0x3f,0xff,0xc0,0x03,0xbf,0xec,0xa0,0x2e,0xaa,0xa8,0x00,0x2a,0xaa,0xaa,0x8a,0xa0,0xaa,0xa8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0xff,0xfc,0x00,0x0f,0xeb,0xf8,0x0a,0xba,0xb2,0xaa,0xaa,0xaa,0xa8,0xfe,0xaa,0xaa,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xff,0xff,0x00,0x00,0x3f,0xc2,0xf8,0x2a,0xaa,0xaa,0xba,0x82,0xaa,0xaa,0xaa,0xa3,0xc0,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xfc,0x00,0x00,0x00,0x3f,0x2a,0xaa,0xab,0xfa,0xaa,0xa0,0xaa,0xaa,0x82,0xaa,0xab,0xc0,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x00,0x00,0x00,0x02,0xaa,0xbf,0xea,0x03,0xea,0xaa,0xaa,0xa2,0xaa,0xab,0xa0,0x0e,0xaa,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x00,0x00,0x00,0x03,0xff,0xea,0xaa,0x8a,0xaa,0xa2,0xa8,0x2b,0xca,0xaa,0xf0,0x0f,0xc0,0x2a,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x03,0xfa,0x82,0xaa,0xab,0xe0,0x0a,0xaa,0x8e,0xa2,0x2a,0xa0,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x03,0xaa,0xaa,0xaa,0x0a,0x82,0xaf,0xaa,0xab,0xc2,0xbf,0xca,0xaf,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3c,0x00,0x00,0x00,0xaa,0xf2,0xaa,0xb8,0x0b,0xa8,0xfa,0xe2,0x8f,0xeb,0xbf,0xc0,0x3a,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x00,0x00,0x00,0x02,0xaa,0xaf,0xf2,0xaa,0xab,0xaf,0xe0,0x0e,0xbf,0x8f,0xc0,0x3f,0x2a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x00,0x00,0x00,0x28,0xeb,0xff,0xc2,0xa3,0xfa,0xaa,0xaa,0xaa,0xbc,0x2f,0xc0,0x3f,0x00,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x00,0x00,0x0a,0xbf,0xfc,0x2a,0x00,0xac,0x03,0xc2,0x80,0x2a,0xaa,0xaa,0xa8,0x00,0x00,0xa8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0x00,0x02,0xaa,0x0a,0x00,0x00,0x28,0x00,0x2a,0xa8,0x00,0x02,0xaa,0xa0,0x02,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa8,0x82,0xa0,0x00,0x02,0x80,0x0a,0x80,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x02,0x0a,0x00,0x00,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0x00,0xa0,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x0c,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x0c,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xc0,0xf0,0x00,0x0f,0x0c,0x00,0x3c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x03,0x30,0x00,0x3c,0x0c,0xf0,0xcc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x0c,0x30,0x00,0x30,0x0f,0x33,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0xcc,0xc0,0x00,0x33,0x3c,0xc3,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xcf,0xc0,0x00,0x3f,0x30,0xc3,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x03,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xfc,0x00,0x0f,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xfc,0x00,0x3f,0xf0,0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x03,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x3c,0x00,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x03,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xf0,0x3c,0x03,0xf3,0xc0,0x00,0x00,0x00,0x00,0x00,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x0f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xc0,0x3c,0x0f,0xc3,0xc0,0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x3c,0x00,0x0f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xc0,0xfc,0x0f,0x03,0xc0,0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0xfc,0x3f,0x03,0xc0,0x00,0x00,0x00,0x00,0x03,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3c,0x00,0xf0,0xfc,0x0f,0xc0,0x00,0x00,0x00,0x00,0x03,0xf0,0x3f,0x00,0x00,0x3f,0xff,0x00,0xfc,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x00,0xf0,0xf0,0x0f,0xc0,0x00,0x0f,0xfc,0x00,0x03,0xff,0xff,0x00,0x00,0xff,0xff,0x00,0xf0,0x00,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xf0,0x03,0xf3,0xc0,0x0f,0x00,0x00,0xff,0xff,0x00,0xff,0xff,0xfc,0x00,0x03,0xff,0xff,0x03,0xf0,0x00,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xf0,0x03,0xff,0xc0,0x0f,0x00,0x03,0xff,0xff,0x00,0xff,0xff,0xc0,0x00,0x0f,0xf0,0x3f,0x03,0xf0,0x00,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xc0,0x03,0xff,0x00,0x0f,0x00,0x0f,0xf0,0x3f,0x00,0xff,0xc0,0x00,0x00,0x3f,0xc0,0x3c,0x03,0xc0,0x03,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xc0,0x03,0xff,0x00,0x3f,0x00,0x0f,0xc0,0xff,0x00,0x0f,0x00,0x00,0x00,0xff,0x00,0xfc,0x03,0xc0,0x03,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xc0,0x0f,0xfc,0x00,0x3f,0x00,0x3f,0xff,0xfc,0x00,0x3f,0x00,0x00,0x00,0xfc,0x00,0xfc,0x0f,0xc0,0x03,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x0f,0xf0,0x00,0x3f,0x00,0xff,0xff,0xc0,0x00,0x3f,0x00,0x0f,0x03,0xf0,0x03,0xfc,0x0f,0xc0,0x03,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x0f,0xf0,0x00,0x3c,0x00,0xff,0xf0,0x00,0x00,0x3f,0x00,0x3c,0x03,0xf0,0x0f,0xf0,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x00,0x0f,0xc0,0x00,0x3c,0x00,0xfc,0x00,0x0f,0x00,0x3f,0x00,0xfc,0x03,0xf0,0xff,0xf0,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x00,0x3f,0x00,0x00,0xfc,0x00,0xfc,0x00,0xff,0x00,0x3f,0x03,0xf0,0x03,0xff,0xff,0xf0,0x3f,0x00,0x0f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xfc,0x00,0x3f,0x00,0x00,0xfc,0x00,0xff,0xff,0xfc,0x00,0x3f,0xff,0xf0,0x03,0xff,0xc3,0xf0,0x3f,0x00,0x3f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xf0,0x00,0x3f,0x00,0x00,0xfc,0x00,0x3f,0xff,0xf0,0x00,0x0f,0xff,0xc0,0x00,0xff,0x03,0xf0,0x3f,0x00,0x3f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xf0,0x00,0x3c,0x00,0x00,0xf0,0x00,0x0f,0xff,0x00,0x00,0x03,0xfc,0x00,0x00,0x00,0x03,0xc0,0x3c,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };

uint8_t tree[] = { 0x00,0x40,0x00,0x01,0x50,0x00,0x01,0x50,0x00,0x05,0x54,0x00,0x05,0x54,0x00,0x15,0x55,0x00,0x15,0x55,0x00,0x55,0x55,0x40,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00 };

uint8_t truck[] = { 0x00,0x00,0xaa,0xaa,0xaa,0xa8,0x00,0x00,0x00,0xbe,0x55,0x55,0x58,0x00,0x00,0x00,0xbe,0x55,0x55,0x58,0x00,0x00,0x02,0xfe,0x6a,0xaa,0x58,0x00,0x00,0x02,0xfe,0x6b,0xfa,0x58,0x00,0x02,0xaa,0xaa,0x6e,0xee,0x58,0x00,0x09,0x56,0x56,0x6f,0xbe,0x58,0x00,0x09,0x56,0x66,0x6a,0xaa,0x58,0x00,0x25,0x56,0x56,0x55,0x55,0x58,0x00,0x25,0x56,0x56,0x55,0x55,0x58,0x00,0x2a,0x96,0xaa,0x55,0x55,0xa8,0x00,0x25,0x65,0x55,0x55,0x56,0x56,0x00,0x9a,0x99,0x55,0x55,0x59,0xa9,0x80,0x99,0x9a,0xaa,0xaa,0xa9,0x99,0x80,0x9a,0x98,0x00,0x00,0x09,0xa9,0x80,0x25,0x60,0x00,0x00,0x02,0x56,0x00,0x0a,0x80,0x00,0x00,0x00,0xa8,0x00 };
