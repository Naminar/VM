#include "interpretator.h"
#include "builder.h"

int main() {
    Interpretator interpretator;
    Builder builder;

    Frame *start_frame = new Frame(2);
    interpretator._frames.push(start_frame);
    interpretator._current_frame = start_frame;

    int64_t *start_bytecode = reinterpret_cast<int64_t *>(calloc(1000, 1));
    interpretator._current_frame->SetPtr(start_bytecode, 1000, start_bytecode);
    builder.SetPtr(start_bytecode, 1000, start_bytecode);
    // r0 = 10
    builder.create_lmov(10, 0);
    // call fibonacci(r0)
    builder.create_call(0, 1);
    // r0 = _return_value
    builder.create_lmov_return(0);
    // exit(r0)
    builder.create_exit(0);

    int64_t func_id = interpretator.CreateFunction("fibonacci", 1 /* n_args */, 6 /* n_regs */);
    Function *function = interpretator.GetFuncById(func_id);
    function->_bytecode = (int64_t *)calloc(10000, 1);
    function->_bytecode_len = 10000;
    builder.SetPtr(function->_bytecode, function->_bytecode_len, function->_bytecode);

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
    builder.create_call(0, 1);
    // return value -> r3
    builder.create_lmov_return(3);
    // r4 -> r0
    builder.create_rmov(4, 0);
    // call fibonacci(r0)
    builder.create_call(0, 1);
    // return value -> r4
    builder.create_lmov_return(4);
    // r5 = r3 + r4
    builder.create_ladd(3, 4, 5);
    builder.create_lreturn(5);
    // exit(r1)
    builder.create_exit(1);

    std::cout << "------------------------" << std::endl;
    interpretator._current_frame->SetPtr(function->_bytecode, function->_bytecode_len, function->_bytecode);
    interpretator.Dump();
    std::cout << "------------------------" << std::endl;
    interpretator._current_frame->SetPtr(start_bytecode, 1000, start_bytecode);
    interpretator.Dump();
    std::cout << "------------------------" << std::endl;

    interpretator._current_frame->SetPtr(start_bytecode, 1000, start_bytecode);
    int64_t rc = interpretator.Run();
    std::cout << "---\nResult: " << rc << std::endl;
}