/**
 * @file syscall.c
 * @author NDRAEY >_ (piakchu.andrey@vk.com)
 * @brief Syscall management
 * @version 0.3.4
 * @date 2023-12-10
 * @copyright Copyright SayoriOS Team (c) 2023
 */

#include "syscall.h"
#include "stddef.h"

size_t _syscall1(size_t num, size_t p1) {
  size_t result = 0;
  __asm__ volatile("int $0x80"
               : "=a"(result)
               : "a"(num),
                 "b"(p1));
  return result;
}

size_t _syscall2(size_t num, size_t p1, size_t p2) {
  size_t result = 0;
  __asm__ volatile("int $0x80"
               : "=a"(result)
               : "a"(num),
                 "b"(p1),
                 "c"(p2));
  return result;
}

size_t _syscall3(size_t num, size_t p1, size_t p2, size_t p3) {
  size_t result = 0;
  __asm__ volatile("int $0x80"
               : "=a"(result)
               : "a"(num),
                 "b"(p1),
                 "c"(p2),
                 "d"(p3));
  return result;
}

size_t _syscall4(size_t num, size_t p1, size_t p2, size_t p3, size_t p4) {
  size_t result = 0;
  __asm__ volatile("int $0x80"
               : "=a"(result)
               : "a"(num),
                 "b"(p1),
                 "c"(p2),
                 "d"(p3),
                 "S"(p4));
  return result;
}

size_t _syscall5(size_t num, size_t p1, size_t p2, size_t p3, size_t p4, size_t p5) {
  size_t result = 0;
  __asm__ volatile("int $0x80"
               : "=a"(result)
               : "a"(num),
                 "b"(p1),
                 "c"(p2),
                 "d"(p3),
                 "S"(p4),
                 "D"(p5));
  return result;
}