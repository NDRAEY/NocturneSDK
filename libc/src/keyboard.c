//
// Created by ndraey on 22.01.24.
//

#include "keyboard.h"
#include "syscall.h"

size_t getkey() {
    return _syscall1(
            KEYBOARD_GETKEY_SYSCALL,
            0
            );
}
