#include <fstream>
#include <iostream>
#include <thread>

void timer(unsigned int* counter) {
    __asm__ __volatile__ (
        "xor %%eax, %%eax;"
        "init:"
        "inc %%eax;"
        "movl %%eax, (%0);"
        "jmp init;"
        : : "b" ( counter )
    );
}

int main() {
    unsigned int counter_val = 0;
    unsigned int* counter = &counter_val;
    std::thread worker([counter](){timer(counter);});
    unsigned int arr[1];
    __asm__ (
        "movl $0xffffffff, %%eax;"
        "caller:"
        "sub $1, %%eax;"
        "jne caller;"
        "movl (%%ecx), %%edi;"
        "movl %%edi, (%%ebx);"
		: : "b" ( arr ), "c" ( counter )
    ); 
    std::cout << arr[0] << std::endl;
    return 0;
}
