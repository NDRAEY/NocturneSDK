#pragma once

#include "stdint.h"

void _tty_puts(const char* text);
void _tty_puts_raw(const char* text, uint32_t len);
