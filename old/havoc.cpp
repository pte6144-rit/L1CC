#include <cstdlib>
#include <sched.h>

int main(int argc, char** argv) {
    unsigned int core = 0;
    if (argc >= 2) {
        core = atoi(argv[1]);
    }
    cpu_set_t cpus;
    CPU_ZERO(&cpus);
    CPU_SET(core, &cpus);
    sched_setaffinity(0, sizeof(cpu_set_t), &cpus);
	__asm__ __volatile__ (
//        "jmp init;"
//        ".align 4096;"
//        ".rept 2000;"
//        "nop;"
//        ".endr;"
//        "init:"
        "movl $1, %edx;"
		"outer:"
		"movl $0xffffffff, %ecx;"
		"inner:"
		"jmp line1;"
		
		".align 4096;"
		".rept 1936;"
		"nop;"
		".endr;"

		"line1:"
		"sub $1, %ecx;"
		"jne line2;"
		"sub $1, %edx;"
		"jne outer;"
		"jmp end;"

		".align 4096;"
		".rept 1936;"
		"nop;"
		".endr;"

		"line2:"
		"jmp line3;"
		
		".align 4096;"
		".rept 1936;"
		"nop;"
		".endr;"

		"line3:"
		"jmp line4;"

		".align 4096;"
		".rept 1936;"
		"nop;"
		".endr;"

		"line4:"
		"jmp line5;"

		".align 4096;"
		".rept 1936;"
		"nop;"
		".endr;"

		"line5:"
		"jmp line6;"

		".align 4096;"
		".rept 1936;"
		"nop;"
		".endr;"

		"line6:"
		"jmp line7;"

		".align 4096;"
		".rept 1936;"
		"nop;"
		".endr;"

		"line7:"
		"jmp line8;"

		".align 4096;"
		".rept 1936;"
		"nop;"
		".endr;"

		"line8:"
		"jmp inner;"

		"end:"
	);
}



