#include <stddef.h>
void* memmove(void *dest, void *src, size_t count) {
    void * ret = dest;
    if (dest <= src || (char*)dest >= ((char*)src + count))
    {
        while (count--)
        {
            *(char*)dest = *(char*)src;
            dest = (char*)dest + 1;
            src = (char*)src + 1;
        }
    }
    else
    {
        dest = (char*)dest + count - 1;
        src = (char*)src + count - 1;
        while (count--)
        {
            *(char*)dest = *(char*)src;
            dest = (char*)dest - 1;
            src = (char*)src - 1;
        }
    }
    return ret;
}