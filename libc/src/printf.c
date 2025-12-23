#include "stdint.h"
#include "stddef.h"
#include <stdarg.h>
#include "string.h"
#include "memory.h"
#include "tty.h"
#include "printf.h"
#include "sprintf.h"

/**
 * @brief Подфункция-обработчик для tty_printf
 *
 * @param format - строка форматов
 * @param args - аргументы
 */
static void __print(char character, void* arg) {
    (void)arg;

    _tty_write(&character, 1);
}

void printf(const char *text, ...) {
    va_list args;
    va_start(args, text);
   
    vfctprintf(__print, 0, text, args);
    
    va_end(args);
}
