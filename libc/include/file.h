#pragma once

#include "stdint.h"
#include "stddef.h"

#define SYSCALL_FILE_DESCR_OPEN 12
#define SYSCALL_FILE_DESCR_READ 13
#define SYSCALL_FILE_DESCR_WRITE 14
#define SYSCALL_FILE_DESCR_SEEK 15
#define SYSCALL_FILE_DESCR_TELL 16
#define SYSCALL_FILE_DESCR_CLOSE 17

#define O_READ 1
#define O_WRITE 2
#define O_CREATE 4
#define O_APPEND 8
#define O_TRUNC 16

int fd_open(const char* filename, size_t mode);
void fd_read(int fd, size_t size, size_t count, void* buffer);
void fd_write(int fd, size_t size, size_t count, const void* buffer);
void fd_seek(int fd, size_t off, size_t whence);
int fd_tell(int fd);
void fd_close(int fd);
