CPPFLAGS= -m32 -fno-use-cxa-atexit -ffreestanding -msse2 -Iinclude -nostdlib -fno-builtin -fno-stack-protector -O0 -fno-exceptions -Wall -fno-pic -fno-pie -Wextra
CPP_COMPILE_FILES=$(shell find src/ -name '*.cpp')
OBJS=$(CPP_COMPILE_FILES:%.cpp=%.o)

OUT=libsayori_cpp.a

all: $(OUT)
	$(CXX) $(CPPFLAGS) maptest.cpp -c -o mt.o
	ld.lld -T../libc/link.ld mt.o $(OUT) ../libc/libsayori_c.a -o mt

clean:
	-rm $(OBJS)
	-rm $(OUT)

$(OBJS): %.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OUT): $(OBJS)
	$(AR) rs $(OUT) $(OBJS)

ext_compiler:
	@echo CPPFLAGS $(CPPFLAGS)
	@echo LIBCPP $(OUT)
