#include <cstdlib>
#include <sched.h>
#include <functional>
#include <unordered_map>

#define LINEDEFINE(LINE) __asm__ __volatile__ ( \
    "jmp L1_" LINE ";.align 4096;.rept " LINE ";nop;.endr; \
    L1_" LINE ":jmp L2_" LINE ";.rept 59;nop;.endr;L2_" LINE ":jmp L3_" LINE ";.rept 4027;nop;.endr; \
    L3_" LINE ":jmp L4_" LINE ";.rept 59;nop;.endr;L4_" LINE ":jmp L5_" LINE ";.rept 4027;nop;.endr; \
    L5_" LINE ":jmp L6_" LINE ";.rept 59;nop;.endr;L6_" LINE ":jmp L7_" LINE ";.rept 4027;nop;.endr; \
    L7_" LINE ":jmp L8_" LINE ";.rept 4091;nop;.endr; \
    L8_" LINE ":jmp L9_" LINE ";.rept 4091;nop;.endr; \
    L9_" LINE ":jmp L10_" LINE ";.rept 4091;nop;.endr; \
    L10_" LINE ":jmp L11_" LINE ";.rept 4091;nop;.endr; \
    L11_" LINE ":jmp L1_" LINE ";.rept 4091;nop;.endr;");

#define CASE(x, y) fun_map.insert({x, [](){LINEDEFINE(y)}});

int main(int argc, char** argv) {
    
    // Pins to the correct core
    unsigned int core = 4;
    unsigned int line = 42;
    if (argc >= 2) 
        line = atoi(argv[1]);
    if (argc >= 3) 
        core = atoi(argv[2]);
    cpu_set_t cpus;
    CPU_ZERO(&cpus);
    CPU_SET(core, &cpus);
    sched_setaffinity(0, sizeof(cpu_set_t), &cpus);

    std::unordered_map<unsigned int, std::function<void()>> fun_map;

        CASE(0,"4084")
        CASE(1,"52")
        CASE(2,"116")
        CASE(3,"180")
        CASE(4,"244")
        CASE(5,"308")
        CASE(6,"372")
        CASE(7,"436")
        CASE(8,"500")
        CASE(9,"564")
        CASE(10,"628")
        CASE(11,"692")
        CASE(12,"756")
        CASE(13,"820")
        CASE(14,"884")
        CASE(15,"948")
        CASE(16,"1012")
        CASE(17,"1076")
        CASE(18,"1140")
        CASE(19,"1204")
        CASE(20,"1268")
        CASE(21,"1332")
        CASE(22,"1396")
        CASE(23,"1460")
        CASE(24,"1524")
        CASE(25,"1588")
        CASE(26,"1652")
        CASE(27,"1716")
        CASE(28,"1780")
        CASE(29,"1844")
        CASE(30,"1908")
        CASE(31,"1972")
        CASE(32,"2036")
        CASE(33,"2100")
        CASE(34,"2164")
        CASE(35,"2228")
        CASE(36,"2292")
        CASE(37,"2356")
        CASE(38,"2420")
        CASE(39,"2484")
        CASE(40,"2548")
        CASE(41,"2612")
        CASE(42,"2676")
        CASE(43,"2740")
        CASE(44,"2804")
        CASE(45,"2868")
        CASE(46,"2932")
        CASE(47,"2996")
        CASE(48,"3060")
        CASE(49,"3124")
        CASE(50,"3188")
        CASE(51,"3252")
        CASE(52,"3316")
        CASE(53,"3380")
        CASE(54,"3444")
        CASE(55,"3508")
        CASE(56,"3572")
        CASE(57,"3636")
        CASE(58,"3700")
        CASE(59,"3764")
        CASE(60,"3828")
        CASE(61,"3892")
        CASE(62,"3956")
        CASE(63,"4020")
    
    if (fun_map.count(line) != 0) {
        fun_map.at(line)();
    } else {
        return -1;
    }
    return 0;
}
