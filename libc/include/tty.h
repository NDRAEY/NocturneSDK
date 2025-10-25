#pragma once

#include "stdint.h"

void _tty_write(const char* text, uint32_t len);
void _tty_write_nulterminated(const char* text);