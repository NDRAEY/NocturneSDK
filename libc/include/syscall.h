#pragma once

#include "stdint.h"

#define ENV_GET_SYSCALL 0
#define MEMORY_ALLOC_SYSCALL 1
#define MEMORY_FREE_SYSCALL 2
#define TTY_WRITE_SYSCALL 3
#define KEYBOARD_GETKEY_SYSCALL 13
#define TIMER_GET_TICKS_SYSCALL 14
#define TIMER_SLEEP_SYSCALL 15
#define DATETIME_SYSCALL 16
#define EXIT_SYSCALL 17
#define MEMORY_REALLOC_SYSCALL 18
#define MOUSE_GET_SYSCALL 25
#define TTY_WRITE_RAW_SYSCALL 29


int _syscall(size_t num, size_t p1, size_t p2, size_t p3);
