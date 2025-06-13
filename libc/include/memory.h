#pragma once

#include "stdint.h"

void* realloc(void* memory, size_t size);
void* calloc(size_t size, size_t count);
void* malloc_align(size_t size, size_t align);
void* malloc(size_t size);
void free(void* ptr);
