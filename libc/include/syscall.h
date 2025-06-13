#pragma once

#include "stdint.h"

#define ENV_GET_SYSCALL 0
#define MEMORY_ALLOC_SYSCALL 3
#define MEMORY_REALLOC_SYSCALL 4
#define MEMORY_FREE_SYSCALL 5
#define TTY_WRITE_SYSCALL 6
#define TTY_WRITE_RAW_SYSCALL 7
#define KEYBOARD_GETKEY_SYSCALL 9
#define GETCH_SYSCALL 10
#define MOUSE_GET_SYSCALL 11
#define TIMER_GET_TICKS_SYSCALL 14
#define DATETIME_SYSCALL 18
#define EXIT_SYSCALL 20
#define TIMER_SLEEP_SYSCALL 24


int _syscall(size_t num, size_t p1, size_t p2, size_t p3);
