#include "env.h"
#include "syscall.h"

env_t getenv() {
    env_t env;

    _syscall1(ENV_GET_SYSCALL, (size_t) &env);

    return env;
}