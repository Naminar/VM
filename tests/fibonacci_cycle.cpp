#include "builder.h"
#include "interpretator.h"

Function *CreateStartFunction() {
    Function *start_func = new Function("start_func", 0, 6, 1000);

    Builder builder;
    builder.SetPtr(start_func);
    // r0 = 1
    builder.create_lmov(1, 0);
    // r1 = 1
    builder.create_lmov(1, 1);
    // counter = 0
    builder.create_lmov(0, 3);
    // max_counter = 10 - 3 (10 fibonacci element equals to cycle 7 times)
    builder.create_lmov(7, 4);
    // r5 (constant) = 1
    builder.create_lmov(1, 5);
    // r2 = r0 + r1
    builder.create_ladd(0, 1, 2);
    // r0 = r1
    builder.create_rmov(1, 0);
    // r1 = r2
    builder.create_rmov(2, 1);
    // r3 (counter) += r5 (constant) + r3 (counter)
    builder.create_ladd(5, 3, 3);
    // continue if counter < maxcounter
    builder.create_br_licmple(-18, 3, 4);
    // exit(r2)
    builder.create_exit(2);

    return start_func;
}

int main() {
    Interpretator interpretator;
    Function *start_func = CreateStartFunction();
    IntrThread *thread = interpretator.CreateThread(start_func);
    std::cout << "------------------------" << std::endl;
    std::cout << "Bytecode dump:" << std::endl;
    std::cout << "------------------------" << std::endl;
    thread->Dump();
    std::cout << "------------------------" << std::endl;
    std::cout << "Runtime trace:" << std::endl;
    std::cout << "------------------------" << std::endl;
    int64_t rc = interpretator.StartThread();
    std::cout << "------------------------" << std::endl;
    std::cout << "Result: " << rc << std::endl;
    std::cout << "Total instructions: " << ISA::done_instructions << std::endl;
}