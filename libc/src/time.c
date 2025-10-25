#include "time.h"
#include "syscall.h"

sayori_time_t get_time() {
	sayori_time_t time;
	
    _syscall1(
            DATETIME_SYSCALL,
            (size_t)&time
            );

   	return time;
}
