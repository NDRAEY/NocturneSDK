#pragma once

#include <common.h>
#include <stdint.h>

#define MOUSE_FLAG_BUTTON_LEFT      0x01
#define MOUSE_FLAG_BUTTON_RIGHT     0x02
#define MOUSE_FLAG_BUTTON_MIDDLE    0x04

void mouse_get(uint32_t* out_x, uint32_t* out_y, uint32_t* flags);