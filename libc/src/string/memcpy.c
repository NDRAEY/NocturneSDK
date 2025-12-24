#include <stddef.h>

void* memcpy(void *restrict destination, const void *restrict source, size_t n){
    size_t *tmp_dest = (size_t *)destination;
    size_t *tmp_src = (size_t *)source;
    size_t len = n / sizeof(size_t);
    size_t i = 0;
    size_t tail = n & (sizeof(size_t) - 1);

    for (; i < len; i++) {
        *tmp_dest++ = *tmp_src++;
    }

    if(tail) {
        char *dest = (char *)destination;
        const char *src = (const char *)source;

        for(i = n - tail; i < n; i++) {
            dest[i] = src[i];
        }
    }

    return destination;
}