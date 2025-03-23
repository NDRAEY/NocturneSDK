#include <mouse.h>
#include <syscall.h>

void mouse_get(uint32_t* out_x, uint32_t* out_y, uint32_t* flags) {
    _syscall(MOUSE_SYSCALL, (size_t)out_x, (size_t)out_y, (size_t)flags);
}