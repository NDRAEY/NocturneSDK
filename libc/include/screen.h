#pragma once

#include "stddef.h"
#include "stdint.h"
#include "syscall.h"

typedef enum {
    SCREEN_QUERY_WIDTH = 0,
    SCREEN_QUERY_HEIGHT = 1,
    SCREEN_QUERY_BITS_PER_PIXEL = 2,
} screen_query_t;

inline static size_t get_screen_parameters(size_t screen_id, size_t field_id, uint8_t* out, size_t len) {
    return _syscall4(
        GET_SCREEN_PARAMETERS_SYSCALL,
        screen_id,
        field_id,
        (size_t)out,
        len
    );
}

inline static size_t get_screen_width(size_t screen_id) {
    size_t out;

    get_screen_parameters(screen_id, SCREEN_QUERY_WIDTH, (uint8_t*)&out, sizeof(out));

    return out;
}

inline static size_t get_screen_height(size_t screen_id) {
    size_t out;

    get_screen_parameters(screen_id, SCREEN_QUERY_HEIGHT, (uint8_t*)&out, sizeof(out));

    return out;
}

inline static size_t get_screen_bpp(size_t screen_id) {
    size_t out;

    get_screen_parameters(screen_id, SCREEN_QUERY_BITS_PER_PIXEL, (uint8_t*)&out, sizeof(out));

    return out;
}

inline static size_t get_screen_memory_size(size_t screen_id) {
    return get_screen_width(screen_id) * get_screen_height(screen_id) * get_screen_bpp(screen_id);
}

inline static size_t copy_to_screen(uint32_t screen_id, uint8_t* buffer) {
    return _syscall2(
        COPY_TO_SCREEN_SYSCALL,
        screen_id,
        (size_t)buffer
    );
}

inline static size_t copy_from_screen(uint32_t screen_id, uint8_t* buffer) {
    return _syscall2(
        COPY_FROM_SCREEN_SYSCALL,
        screen_id,
        (size_t)buffer
    );
}