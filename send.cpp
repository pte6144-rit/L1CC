#include <cstdlib>
#include <sched.h>

#define LINES64M12 "1908" //I have no fucking clue why subtracting 12 fixes it, but it works now

int main(int argc, char** argv) {
    
    // Pins to the correct core
    unsigned int core = 4;
    if (argc >= 2) {
        core = atoi(argv[1]);
    }
    cpu_set_t cpus;
    CPU_ZERO(&cpus);
    CPU_SET(core, &cpus);
    sched_setaffinity(0, sizeof(cpu_set_t), &cpus);

    __asm__ __volatile__ (
        "start:"
        "jmp L20;"
        ".align 4096;"

        ".rept " LINES64M12 ";"
        "nop;"
        ".endr;"
        
        "L20:"
        "jmp L21;"
        ".rept 59;"
        "nop;"
        ".endr;"
        "L21:"
        "jmp L84;"
        ".rept 4027;"
        "nop;"
        ".endr;"

        "L84:"
        "jmp L85;"
        ".rept 59;"
        "nop;"
        ".endr;"
        "L85:"
        "jmp L148;"
        ".rept 4027;"
        "nop;"
        ".endr;"

        "L148:"
        "jmp L149;"
        ".rept 59;"
        "nop;"
        ".endr;"
        "L149:"
        "jmp L212;"
        ".rept 4027;"
        "nop;"
        ".endr;"

        "L212:"
        "jmp L276;"
        ".rept 59;"
        "nop;"
        ".endr;"
        "L213:"
        "jmp L276;"
        ".rept 4091;"
        "nop;"
        ".endr;"

        "L276:"
        "jmp L340;"
        ".rept 59;"
        "nop;"
        ".endr;"
        "L277:"
        "jmp L340;"
        ".rept 4091;"
        "nop;"
        ".endr;"

        "L340:"
        "jmp L404;"
        ".rept 59;"
        "nop;"
        ".endr;"
        "L341:"
        "jmp L404;"
        ".rept 4091;"
        "nop;"
        ".endr;"

        "L404:"
        "jmp L468;"
        ".rept 59;"
        "nop;"
        ".endr;"
        "L405:"
        "jmp L468;"
        ".rept 4091;"
        "nop;"
        ".endr;"

        "L468:"
        "jmp L20;"
        ".rept 59;"
        "nop;"
        ".endr;"
        "L469:"
        "jmp L20;"
    );
}
