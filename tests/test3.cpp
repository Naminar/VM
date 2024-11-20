#include "interpretator.h"

int main() {
    Interpretator interpretator;

    uint8_t *start_bytecode = reinterpret_cast<uint8_t *>(calloc(1000, 1));
    interpretator.SetPtr(start_bytecode, 1000, start_bytecode);
    std::vector<uint64_t> v;
    interpretator.create_call(0, 0, v);
    interpretator.create_exit(0);

    uint64_t func_id = interpretator.CreateFunction("main", 0 /* n_args */);
    Frame* start_frame = new Frame(3);
    interpretator._frames.push(start_frame);
    interpretator._current_frame = start_frame;

    Function *function = interpretator.GetFuncById(func_id);
    function->_bytecode = (uint8_t *) calloc(10000, 1);
    function->_bytecode_len = 10000;

    interpretator.SetPtr(function->_bytecode, function->_bytecode_len, function->_bytecode);
    interpretator.create_lmov(1, 1);
    interpretator.create_ladd(1, 1, 1);
    interpretator.create_ladd(1, 1, 1);
    interpretator.create_ladd(1, 1, 1);
    interpretator.create_ladd(1, 1, 2);
    interpretator.create_ldiv(1, 1, 1);
    interpretator.create_ldiv(1, 1, 1);
    interpretator.create_exit(0);

    std::cout << "------------------------" << std::endl;
    interpretator.SetPtr(function->_bytecode, function->_bytecode_len, function->_bytecode);
    interpretator.Dump();
    std::cout << "------------------------" << std::endl;
    interpretator.SetPtr(start_bytecode, 1000, start_bytecode);
    interpretator.Dump();
    std::cout << "------------------------" << std::endl;

    interpretator.SetPtr(start_bytecode, 1000, start_bytecode);
    interpretator.Run(true);
}