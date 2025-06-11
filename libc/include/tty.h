#pragma once

#include "stdint.h"

#define TTY_WRITE_SYSCALL 3
#define TTY_WRITE_RAW_SYSCALL 29

void _tty_puts(const char* text);
void _tty_puts_raw(const char* text, uint32_t len);
