#pragma once
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <iostream>
#include <functional>
#include <cstdint>
#include "isa.h"


class Function {
  public:
    Function(const std::string &name, int64_t n_args, int64_t n_regs):
        _name(name), _n_args(n_args), _n_regs(n_regs) {}

    const std::string _name = "";
    const int64_t _n_args = 0;
    const int64_t _n_regs = 0;
    int64_t *_bytecode = nullptr;   // owner
    int64_t _bytecode_len = 0;
};


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

    int64_t Run(Interpretator *i) {
        ISA::dispatch_do[*_ptr](i, _ptr);
        return _return_value;
    }

    void Dump(Interpretator *i) {
        ISA::dispatch_dump[*_ptr](i, _ptr, true);
    }

    int64_t *const _regs = nullptr;   // owner
    const int64_t _n_regs = 0;
    int64_t *_bytecode = nullptr;
    int64_t _bytecode_len = 0;
    int64_t *_ptr = nullptr;
    int64_t _return_value = 0; // from Call
    Frame *previous_frame = nullptr;
};


class Interpretator {
  public:

    Interpretator(Function *start_func) {
        if (start_func->_n_args != 0) {
            throw std::runtime_error("Start func should be without arguments!");
        }
        _functions.push_back(start_func);
        _current_frame = new Frame(start_func); // start frame
    }

    ~Interpretator() {
        delete _current_frame;
    }

    int64_t Run();
    void Dump();

    Frame *_current_frame;
    std::vector<Function *> _functions;
    int64_t _return_code = 0; // from whole program

    int64_t CreateFunction(const std::string &name, int64_t n_args, int64_t n_regs);

    int64_t AppendFunction(Function *func) {
        _functions.push_back(func);
        return _functions.size() - 1;
    }

    inline void CreateFrame(int64_t func_id, int64_t n_args) {

        Function *function = GetFuncById(func_id);
        Frame* new_frame = new Frame(function);

        if (function->_n_args != n_args) {
            throw std::runtime_error("ERROR! Bad call: worng n_regs.");
        }

        memcpy(new_frame->_regs, _current_frame->_regs, n_args * sizeof(_current_frame->_regs[0]));

        new_frame->previous_frame = _current_frame;
        _current_frame = new_frame;
    }

    inline void ReturnPreviousFrame() {
        Frame *previous_frame = _current_frame->previous_frame;
        if (previous_frame == nullptr) {
            throw std::runtime_error("There is no previous frame");
        }

        previous_frame->_return_value = _current_frame->_return_value;
        delete _current_frame;
        _current_frame = previous_frame;
    }

    Function *GetFuncById(int64_t id) {
        if (id < 0 || id > _functions.size()) {
            throw std::runtime_error("Out of range in _functions.");
        }
        return _functions[id];
    }


    inline int64_t &GetRegRef(const int64_t n) {
        if (_current_frame->_n_regs == 0 || n > _current_frame->_n_regs - 1) {
            throw std::runtime_error("Out of bounds in  frame registers.");
        }
        return _current_frame->_regs[n];
    }
};
