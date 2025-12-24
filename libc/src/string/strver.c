#include <stdint.h>
#include <string.h>

void strver(char *str) {
    int32_t j = strlen(str) - 1;

    for (int32_t i = 0; i < j; i++) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
        j--;
    }
}