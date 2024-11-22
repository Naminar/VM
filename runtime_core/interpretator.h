#pragma once
#include <string>
#include <stack>
#include <vector>
#include <iostream>
#include <functional>
#include <cstdint>

class Frame {
  public:
    Frame(const int64_t n_regs):  _n_regs(n_regs) {
        _regs.resize(n_regs);
    }

    void DumpRegs();

    std::vector<int64_t> _regs;
    int64_t _n_regs;
    int64_t *_bytecode = nullptr;
    int64_t _bytecode_len = 0;
    int64_t *_ptr = nullptr;
    int64_t _return_value = 0; // from Call
};


class Function {
  public:
    Function(const std::string &name, int64_t n_args): _name(name), _n_args(n_args), _n_regs(200) {} // need to fix _n_regs

    std::string _name = "";
    int64_t _n_args = 0;
    int64_t _n_regs = 0;
    int64_t *_bytecode = nullptr;
    int64_t _bytecode_len = 0;
};


class Interpretator {
  public:

    Interpretator();
    int64_t Run(bool verbose = false);
    void Dump();

    std::stack<Frame *> _frames;
    Frame *_current_frame;
    std::vector<Function *> _functions;
    int64_t *_bytecode = nullptr;
    int64_t _bytecode_len = 0;
    int64_t *_ptr = nullptr;
    int64_t _return_value = 0; // from Call
    int64_t _return_code = 0;  // from whole program

    int64_t CreateFunction(const std::string &name, int64_t n_args) {
        _functions.push_back(new Function(name, n_args));
        return _functions.size() - 1;
    }

    inline void CreateNewFrame(int64_t func_id, std::vector<int64_t> &arg_regs) {
        _current_frame->_ptr = _ptr;

        Function *function = GetFuncById(func_id);
        Frame* new_frame = new Frame(function->_n_regs);

        if (function->_n_args != arg_regs.size()) {
            throw std::runtime_error("ERROR! Bad call: worng n_regs.");
        }

        for (int64_t i = 0; i < function->_n_args; ++i) {
            new_frame->_regs[i] = GetRegRef(arg_regs[i]);
        }

        _current_frame = new_frame;
        _frames.push(new_frame);
        _ptr = function->_bytecode;
    }

    inline void ReturnPreviousFrame() {
        delete _current_frame;
        _frames.pop();
        _current_frame = _frames.top();
        _ptr = _current_frame->_ptr;
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

    void SavePtrBeforeCall() {
        Frame *frame = _frames.top();
        frame->_ptr = _ptr;
    }

    int64_t &GetRegRef(const int64_t n);
    std::vector<std::function<void()>> DoInstr;
    std::vector<std::function<void()>> DumpInstr;

    #include "isa_decl.inc"
};
