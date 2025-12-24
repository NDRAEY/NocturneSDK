#include <stddef.h>
#include <string.h>

size_t itoa(int32_t n, char *buffer) {
    char const digits[10] __attribute__((nonstring)) = "0123456789";
    char* p = buffer;

    if (n < 0){
        *p++ = '-';
        n = -n;
    }

    int s = n;

    do {
        ++p;
        s = s / 10;
    } while(s);

    *p = '\0';

    do {
        *--p = digits[n % 10];
        n = n / 10;
    } while(n);

    return strlen(buffer);
}