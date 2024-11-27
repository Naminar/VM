#include "builder.h"
#include "interpretator.h"

Function *CreateStartFunction() {
    Function *start_func = new Function("start_func", 0, 2, 1000);

    Builder builder;
    builder.SetPtr(start_func);
    // r0 = 10
    builder.create_lmov(10, 0);
    // call fibonacci(r0)
    builder.create_call(1);
    // r0 = _return_value
    builder.create_lmov_return(0);
    // exit(r0)
    builder.create_exit(0);

    return start_func;
}

Function *CreateFibonacciFunction() {
    Function *function = new Function("fibonacci", 1 /* n_args */, 6 /* n_regs */, 10000);

    Builder builder;
    builder.SetPtr(function);
    // r0 = n
    // r1 = 1
    builder.create_lmov(1, 1);
    // r2 = 2
    builder.create_lmov(2, 2);
    // if r0 > r2 jump over return
    builder.create_br_licmpgt(2, 0, 2);
    // return r1
    builder.create_lreturn(1);
    // r3 = r0 - r1
    builder.create_lsub(0, 1, 3);
    // r4 = r0 - r2
    builder.create_lsub(0, 2, 4);
    // r3 -> r0
    builder.create_rmov(3, 0);
    // call fibonacci(r0)
    builder.create_call(1);
    // return value -> r3
    builder.create_lmov_return(3);
    // r4 -> r0
    builder.create_rmov(4, 0);
    // call fibonacci(r0)
    builder.create_call(1);
    // return value -> r4
    builder.create_lmov_return(4);
    // r5 = r3 + r4
    builder.create_ladd(3, 4, 5);
    // return r5
    builder.create_lreturn(5);
    // exit(r1)
    builder.create_exit(1);

    return function;
}

int main() {
    Function *start_func = CreateStartFunction();
    Function *function = CreateFibonacciFunction();
    Interpretator interpretator(start_func);
    interpretator.AppendFunction(function);

    std::cout << "------------------------" << std::endl;
    std::cout << "Start function dump:" << std::endl;
    std::cout << "------------------------" << std::endl;
    interpretator._current_frame->SetPtr(start_func);
    interpretator.Dump();
    std::cout << "------------------------" << std::endl;
    std::cout << "Fibonacci function dump:" << std::endl;
    std::cout << "------------------------" << std::endl;
    interpretator._current_frame->SetPtr(function);
    interpretator.Dump();
    std::cout << "------------------------" << std::endl;
    std::cout << "Runtime trace dump:" << std::endl;
    std::cout << "------------------------" << std::endl;
    interpretator._current_frame->SetPtr(start_func);
    int64_t rc = interpretator.Run();
    std::cout << "------------------------" << std::endl;
    std::cout << "Result: " << rc << std::endl;
}