cmake_minimum_required(VERSION 3.27)
project(NocturneLibM VERSION 0.1.0 LANGUAGES C)

set(FILES
    src/acos.c
    src/asin.c
    src/atan.c
    src/cbrt.c
    src/cos.c
    src/exp.c
    src/log.c
    src/math.c
    src/modf.c
    src/pow.c
    src/sin.c
    src/sqrt.c
    src/tan.c
)

set(CMAKE_ASM_FLAGS "-m32 -g")
set(CMAKE_C_FLAGS "-nostdlib -nostdinc -Wall -Wextra -fno-pic -ggdb3 -O0 -m32 -march=i386 -ffreestanding -static -fno-stack-protector -I${CMAKE_SOURCE_DIR}/libm/include -I${CMAKE_SOURCE_DIR}/libc/include")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-static")

add_library(NocturneM STATIC ${FILES})

install(FILES ${CMAKE_BINARY_DIR}/libm/libNocturneM.a DESTINATION nocturneos/lib/)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/libm/include/ DESTINATION nocturneos/include)
