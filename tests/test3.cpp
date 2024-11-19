#include "interpretator.h"

int main() {
    Interpretator i;
    uint64_t func_id = i.CreateFunction("main", 0 /* n_args */);
    Frame* start_frame = new Frame(3);
    i._frames.push(start_frame);
    i.current_frame = start_frame;

    Function *f = i.GetFuncById(func_id);
    f->_bytecode = (uint8_t *) calloc(10000, 1);
    f->_bytecode_len = 10000;

    i.SetPtr(f->_bytecode, f->_bytecode_len, f->_bytecode);
    i.create_lmov(1, 1);
    i.create_ladd(1, 1, 1);
    i.create_ladd(1, 1, 1);
    i.create_ladd(1, 1, 1);
    i.create_ladd(1, 1, 2);
    i.create_ldiv(1, 1, 1);
    i.create_ldiv(1, 1, 1);
    std::vector<uint64_t> v;
    i.create_call(0, 0, v);
    i.create_exit(0);

    i.SetPtr(f->_bytecode, f->_bytecode_len, f->_bytecode);
    std::cout << "------------------------" << std::endl;
    i.Dump();
    std::cout << "------------------------" << std::endl;
    i.SetPtr(f->_bytecode, f->_bytecode_len, f->_bytecode);
    i.Run(true);
}