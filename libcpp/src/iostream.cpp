#include "iostream"
#include "memory"

extern "C" {
	#include "../../libc/include/printf.h"
}

void __printf_cerr(const char* _s) {
	printf("cerr| %s", _s);
};

void __printf_cout(const char* _s) {
	printf("%s", _s);
};

extern "C" void __cpp_init() {
	new (&std::cerr) std::ostream(__printf_cerr);
	new (&std::cout) std::ostream(__printf_cout);
}

namespace std {
	ostream cerr(__printf_cerr);
	ostream cout(__printf_cout);

	ostream& endl(ostream& stream) {
		return stream << '\n';
	}

}
