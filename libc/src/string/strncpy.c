#include <stddef.h>
char *strncpy(char *dest, const char *src, size_t n) {
    for (size_t i = 0; i < n && src[i]; i++) {
        dest[i] = src[i];
    }

    return dest;
}