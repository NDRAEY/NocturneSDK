#include <stddef.h>
#include <stdint.h>

void* memset(void* ptr, char value, size_t num) {
    uint8_t* p = (uint8_t*)ptr;

    for (size_t i = 0; i < num; i++) {
        p[i] = value;
    }

    return ptr;
}