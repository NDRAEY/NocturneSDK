#include "tty.h"
#include "syscall.h"

void _tty_puts(const char* text) {
    _syscall(TTY_WRITE_SYSCALL, (size_t) text, 0, 0);
}

void _tty_puts_raw(const char* text, uint32_t len) {
    _syscall(TTY_WRITE_SYSCALL, (size_t) text, len, 0);
}
