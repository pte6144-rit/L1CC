#include <fstream>
#include <iostream>
#include <thread>
#include <sched.h>
#include <chrono>

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

int main(int argc, char** argv) {
    unsigned int scans = 100;
    if (argc >= 2) {
        scans = atoi(argv[1]);
    }
    cpu_set_t cpus;
    CPU_ZERO(&cpus);
    CPU_SET(0, &cpus);
    sched_setaffinity(0, sizeof(cpu_set_t), &cpus);
    CPU_ZERO(&cpus);
    CPU_SET(1, &cpus);
    unsigned int counter_val = 0;
    unsigned int* counter = &counter_val;
    std::thread worker([counter](){timer(counter);});
    pthread_setaffinity_np(worker.native_handle(), sizeof(cpu_set_t), &cpus);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    unsigned int* store_arr = (unsigned int*)malloc(4 * (scans * 64));
    void* scan_arr = malloc(64 * 64 * 2);
    while ((((unsigned long long)scan_arr) & 0xFFF) != 0) {
        scan_arr = (void*)(((unsigned char*)scan_arr) + 4);
    }
    //Register Usage
    //  eax: Iteration Counter
    //  ebx: Output array address (modifies during runtime)
    //  ecx: Counter address
    //  edx: Passthru register
    __asm__ (
        "begin:"
    
        "movq $64, %%r12;"
        "top_of_line:"
        
        "prefetchnta (%%rdx);"
        "addq $64, %%rdx;"
        "imulq $1, %%rcx;"
        "imull $1, %%edx;"
        "movl (%%rbx), %%edi;"
        "movl %%edi, (%%rax);"
        "addq $4, %%rax;"
        
        "subq $1, %%r12;"
        "jnz top_of_line;"
        "subq $4096, %%rdx;"
        
        "subl $1, %%ecx;"
        "jnz begin;"
        : : "a" ( store_arr ), "b" ( counter ), "c" ( scans ), "d" ( scan_arr )
    ); 
	std::ofstream stream("dat.txt", std::ios::binary);
	for (int i = 64; i < 64 * scans; i++) {
    	stream << store_arr[i] - store_arr[i-1] << " ";
	    if (i % 64 == 0)
            stream << std::endl;
	}
    return 0;
}
