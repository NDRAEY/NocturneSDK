#include "tty.h"
#include "syscall.h"
#include "string.h"
#include "stddef.h"

void _tty_write(const char* text, uint32_t len) {
    _syscall2(TTY_WRITE_SYSCALL, (size_t) text, len);
}

void _tty_write_nulterminated(const char* text) {
    size_t len = strlen(text);

    _tty_write(text, len);
}
