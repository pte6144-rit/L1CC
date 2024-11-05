#include <cstdlib>
#include <iostream>
#include <sched.h>

int main(int argc, char** argv) {
    unsigned int core = 4;
    if (argc >= 2)
        core = atoi(argv[1]);
    cpu_set_t cpus;
    CPU_ZERO(&cpus);
    CPU_SET(core, &cpus);
    sched_setaffinity(0, sizeof(cpu_set_t), &cpus);
    unsigned int value[16*64*12];
    unsigned int line = 0;
    std::cout << value << std::endl;
    while (true) {
        value[line] = value[line] * value[(line + 16*64)%(16*64)] + value[(line + 32*64)%(16*64)];
        line = (line + 16*64) % (16*64);
    }
    return 0;
}
