extern "C" {
#include "../../libc/include/stdint.h"
#include "../../libc/include/memory.h"
}

#include "memory"

void* operator new(size_t size) {
    return malloc(size);
}

void* operator new[](size_t size) {
    return malloc(size);
}

void* operator new([[maybe_unused]] size_t size, void* obj) {
	return obj;
}

void operator delete(void* ptr) { free(ptr); }
void operator delete(void* ptr, [[maybe_unused]] size_t size) { free(ptr); }
void operator delete[](void* ptr) { free(ptr); }
void operator delete[](void* ptr, [[maybe_unused]] size_t size) { free(ptr); }
