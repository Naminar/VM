#pragma once
#include <cstring>
#include <vector>
#include <iostream>
#include <cstdint>
#include "isa.h"
#include "frame.h"


class Function;

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


    int64_t Run() {
        _current_frame->Run(this);
        return _return_code;
    }


    void Dump() {
        _current_frame->Dump(this);
    }


    int64_t AppendFunction(Function *func) {
        _functions.push_back(func);
        return _functions.size() - 1;
    }


    inline void CallFuncById(int64_t func_id) {
        if (func_id < 0 || func_id > _functions.size()) {
            throw std::runtime_error("Out of range in _functions.");
        }
        // static uint64_t called = 0;
        // called++;
        // // std::cout << "Call function " << called << std::endl;
        // Function *function = _functions[func_id];
        // Frame *new_frame = new Frame(function);
        // _current_frame->DumpMySelf();
        // memcpy(new_frame->_regs, _current_frame->_regs, function->_n_args *
        // sizeof(_current_frame->_regs[0])); 
        // new_frame->previous_frame = _current_frame; 
        // new_frame->DumpMySelf();
        // _current_frame = new_frame;
        // _current_frame->Run(this);
        // _current_frame = new_frame->previous_frame;
        // _current_frame->_return_value = new_frame->_return_value;
        // delete new_frame;

        _current_frame =
            frame_allocator.allocate(this, _current_frame, _functions[func_id]);
        _current_frame->Run(this);
        _current_frame = frame_allocator.deallocate();
    }

    FrameAllocator<10000000> frame_allocator;
    Frame *_current_frame;
    std::vector<Function *> _functions;
    int64_t _return_code = 0; // from whole program
};
