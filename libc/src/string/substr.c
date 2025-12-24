#include <string.h>

void substr(char* restrict dest, const char* restrict source, int from, int length){
    strncpy(dest, source + from, length);
    dest[length] = 0;
}