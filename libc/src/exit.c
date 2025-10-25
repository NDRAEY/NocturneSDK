#include "syscall.h"
#include "exit.h"

__attribute__((noreturn)) void exit(int status) {
	_syscall1(
            EXIT_SYSCALL,
            status
            );

	while(1)
		;
}
