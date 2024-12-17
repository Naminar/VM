#pragma once
#include "frame.h"
#include "isa.h"
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

class Function;

class Interpretator {
  public:
    FrameAllocator<1000000> frame_allocator;

    Interpretator(Function *start_func) {
        if (start_func->_n_args != 0) {
            throw std::runtime_error("Start func should be without arguments!");
        }
        _functions.push_back(start_func);
        // _current_frame = new Frame(start_func); // start frame
        _current_frame = frame_allocator.allocate(start_func);
    }

    ~Interpretator() {
        // delete _current_frame;
        // frame_allocator.deallocate();
    }

    int64_t Run() {
        _current_frame->Run(this);
        return _return_code;
    }

    void Dump() { _current_frame->Dump(this); }

    int64_t AppendFunction(Function *func) {
        _functions.push_back(func);
        return _functions.size() - 1;
    }

    inline void CallFuncById(int64_t func_id) {
        if (func_id < 0 || func_id > _functions.size()) {
            throw std::runtime_error("Out of range in _functions.");
        }

        Function *function = _functions[func_id];
        // Frame *new_frame = new Frame(function);
        Frame *new_frame = frame_allocator.allocate(function);
        memcpy(new_frame->_regs, _current_frame->_regs, function->_n_args * sizeof(_current_frame->_regs[0]));
        new_frame->previous_frame = _current_frame;
        _current_frame = new_frame;

        _current_frame->Run(this);

        _current_frame = new_frame->previous_frame;
        _current_frame->_return_value = new_frame->_return_value;
        std::cout << std::hex << "Returned to frame 0x" << _current_frame << std::endl;
        // delete new_frame;
        frame_allocator.deallocate();
    }

    Frame *_current_frame;
    std::vector<Function *> _functions;
    int64_t _return_code = 0; // from whole program
};
