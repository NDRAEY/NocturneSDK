//#include "printf.h"

//extern int(*main)(int, char**);	
// Possible initializations here.
//void __init_everything(int argc, char** argv) {
//	printf("main() at: %x; argc = %d; argv = %x\n", main, argc, argv);
//	
//	for(int i = 0; i < argc; i++) {
//		printf("argv[%d] = %s\n", i, argv[i]);
//	}
//
//	main(argc, argv);
//}

.extern main

.globl _start
_start:
	jmp main
	leave
	ret
