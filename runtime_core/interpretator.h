#pragma once
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <iostream>
#include <functional>
#include <cstdint>
#include "defines.h"

class Frame {
  public:
    Frame(const int64_t n_regs):  _n_regs(n_regs), _regs(new int64_t[n_regs]) {}
    ~Frame() {delete[] _regs;}

    void DumpRegs() const {
        std::cout << "Frame dump (" << _n_regs << "):\n";
        for (int64_t i = 0; i < _n_regs; ++i) {
            std::cout << "REG[" << i << "]: " << _regs[i] << std::endl;
        }
    }

    void SetPtr(int64_t *bytecode, int64_t bytecode_len, int64_t *ptr) {
        _bytecode = bytecode;
        _bytecode_len = bytecode_len;
        _ptr = ptr;
    }

    int64_t * const _regs = nullptr;   // owner
    const int64_t _n_regs = 0;
    int64_t *_bytecode = nullptr;
    int64_t _bytecode_len = 0;
    int64_t *_ptr = nullptr;
};


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


class Interpretator {
  public:

    Interpretator() {
        DoInstr.resize(OPCODE_EXIT + 1);
        DumpInstr.resize(OPCODE_EXIT + 1);

        for (auto &i : DoInstr) { i = 0; }
        for (auto &i : DumpInstr) { i = 0; }

        #include "init_func_vec.inc"
    }
    int64_t Run(bool verbose = false);
    void Dump();

    std::stack<Frame *> _frames;    // owner
    Frame *_current_frame;
    std::vector<Function *> _functions;
    int64_t *_bytecode = nullptr;
    int64_t _bytecode_len = 0;
    int64_t *_ptr = nullptr;
    int64_t _return_value = 0; // from Call
    int64_t _return_code = 0; // from whole program

    int64_t CreateFunction(const std::string &name, int64_t n_args, int64_t n_regs) {
        _functions.push_back(new Function(name, n_args, n_regs));
        return _functions.size() - 1;
    }

    inline void CreateFrame(int64_t func_id, int64_t n_args, const int64_t *args) {
        _current_frame->SetPtr(_bytecode, _bytecode_len, _ptr);

        Function *function = GetFuncById(func_id);
        Frame* new_frame = new Frame(function->_n_regs);

        if (function->_n_args != n_args) {
            throw std::runtime_error("ERROR! Bad call: worng n_regs.");
        }

        for (int i = 0; i < n_args; ++i) {
            new_frame->_regs[i] = GetRegRef(args[i]);
        } 

        _current_frame = new_frame;
        _frames.push(new_frame);
        SetPtr(function->_bytecode, function->_bytecode_len, function->_bytecode);
    }

    inline void ReturnPreviousFrame() {
        delete _current_frame;
        _frames.pop();
        _current_frame = _frames.top();
        SetPtr(_current_frame->_bytecode, _current_frame->_bytecode_len, _current_frame->_ptr);
    }

    Function *GetFuncById(int64_t id) {
        if (id < 0 || id > _functions.size()) {
            throw std::runtime_error("Out of range in _functions.");
        }
        return _functions[id];
    }

    void SetPtr(int64_t *bytecode, int64_t bytecode_len, int64_t *position) {
        _bytecode = bytecode;
        _bytecode_len = bytecode_len;
        _ptr = position;
    }


    inline int64_t &GetRegRef(const int64_t n) {
        if (_current_frame->_n_regs == 0 || n > _current_frame->_n_regs - 1) {
            throw std::runtime_error("Out of bounds in  frame registers.");
        }
        return _current_frame->_regs[n];
    }
    std::vector<std::function<void()>> DoInstr;
    std::vector<std::function<void()>> DumpInstr;

    #include "isa_decl.inc"
};
