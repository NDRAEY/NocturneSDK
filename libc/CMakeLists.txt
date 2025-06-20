cmake_minimum_required(VERSION 3.27)
project(NocturneLibC VERSION 0.1.0 LANGUAGES C ASM)

set(FILES 
        src/__init.S
        src/tty.c
        src/time.c
        src/syscall.c
        src/string.c
        src/timer.c
        src/env.c
        src/rand.c
        src/memory.c
        src/exit.c
        src/keyboard.c
        src/printf.c
        src/file.c
        src/syscall.c
        src/mouse.c
)

set(CMAKE_ASM_FLAGS "-m32 -g")
set(CMAKE_C_FLAGS "-Wall -Wextra -fno-pic -ggdb3 -O0 -m32 -march=i386 -ffreestanding -static -fno-stack-protector -I${CMAKE_SOURCE_DIR}/libc/include")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-static")

add_library(NocturneC STATIC ${FILES})

install(FILES ${CMAKE_BINARY_DIR}/libc/libNocturneC.a DESTINATION nocturneos/lib/)
install(FILES ${CMAKE_SOURCE_DIR}/common/link.ld DESTINATION nocturneos/share/)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/libc/include/ DESTINATION nocturneos/include)
