#include <stdbool.h>

int atoi(const char* s){
    int i = 0, n = 0;
    bool minus = *s == '-';

    if(minus)
        i++;

    for (; s[i] >= '0' && s[i] <= '9'; ++i)
        n = (n * 10) + (s[i] - '0');

    n *= minus ? -1 : 1;

    return n;
}