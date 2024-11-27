#pragma once
#include <iostream>
#include "function.h"
#include "isa.h"

class Interpretator;

class Frame {
  public:
    Frame(const Function *func):  _n_regs(func->_n_regs), _regs(new int64_t[func->_n_regs]) {
        SetPtr(func);
    }
    ~Frame() {delete[] _regs;}

    void DumpRegs() const {
        std::cout << "Frame dump (" << _n_regs << "):\n";
        for (int64_t i = 0; i < _n_regs; ++i) {
            std::cout << "REG[" << i << "]: " << _regs[i] << std::endl;
        }
    }

    inline void SetPtr(int64_t *bytecode, int64_t bytecode_len, int64_t *ptr) {
        _bytecode = bytecode;
        _bytecode_len = bytecode_len;
        _ptr = ptr;
    }

    inline void SetPtr(const Function *func) {
        _bytecode = func->_bytecode;
        _bytecode_len = func->_bytecode_len;
        _ptr = func->_bytecode;
    }

    inline int64_t Run(Interpretator *i) {
        ISA::dispatch_do[*_ptr](i, _ptr);
        return _return_value;
    }

    inline void Dump(Interpretator *i) {
        ISA::dispatch_dump[*_ptr](i, _ptr, true);
    }

    int64_t *const _regs = nullptr;   // owner
    const int64_t _n_regs = 0;
    int64_t *_bytecode = nullptr;
    int64_t *_ptr = nullptr;
    int64_t _bytecode_len = 0;
    int64_t _return_value = 0;
    Frame *previous_frame = nullptr;
};