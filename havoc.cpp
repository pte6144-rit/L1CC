

int main() {
	__asm__ __volatile__ (
		"movl $1, %edx;"
		"outer:"
		"movl $0xffffffff, %ecx;"
		"inner:"
		"jmp line1;"
		
		".align 4096;"
		".rept 260;"
		"nop;"
		".endr;"

		"line1:"
		"sub $1, %ecx;"
		"jne line2;"
		"sub $1, %edx;"
		"jne outer;"
		"jmp end;"

		".align 4096;"
		".rept 260;"
		"nop;"
		".endr;"

		"line2:"
		"jmp line3;"
		
		".align 4096;"
		".rept 260;"
		"nop;"
		".endr;"

		"line3:"
		"jmp line4;"

		".align 4096;"
		".rept 260;"
		"nop;"
		".endr;"

		"line4:"
		"jmp line5;"

		".align 4096;"
		".rept 260;"
		"nop;"
		".endr;"

		"line5:"
		"jmp line6;"

		".align 4096;"
		".rept 260;"
		"nop;"
		".endr;"

		"line6:"
		"jmp line7;"

		".align 4096;"
		".rept 260;"
		"nop;"
		".endr;"

		"line7:"
		"jmp line8;"

		".align 4096;"
		".rept 260;"
		"nop;"
		".endr;"

		"line8:"
		"jmp inner;"

		"end:"
	);
}



