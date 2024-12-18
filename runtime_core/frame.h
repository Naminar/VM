#pragma once
#include "function.h"
#include "isa.h"
#include <iostream>
#include <stack>

class IntrThread;

class Frame {
  public:
    Frame(const Function *func, int64_t *const regs) : _n_regs(func->_n_regs), _regs(regs) { SetPtr(func); }
    ~Frame() {}

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

    inline int64_t Run(IntrThread *i) {
        ISA::dispatch_do[*_ptr](i, _ptr);
        return _return_value;
    }

    inline void Dump(IntrThread *i) { ISA::dispatch_dump[*_ptr](i, _ptr, true); }

    int64_t *const _regs = nullptr; // owner
    const int64_t _n_regs = 0;
    int64_t *_bytecode = nullptr;
    int64_t *_ptr = nullptr;
    int64_t _bytecode_len = 0;
    int64_t _return_value = 0;
    Frame *previous_frame = nullptr;
};

template <uint64_t memorySize = 100'000> class FrameAllocator {
  private:
    char *_memory;
    char *_availablePtr;
    std::stack<char *> _framesStart;

  public:
    FrameAllocator() {
        _memory = new char[memorySize];
        if (_memory == nullptr) {
            throw std::runtime_error("Can't create allocator.");
        }
        _availablePtr = _memory;
    }

    Frame *allocate(Function *function) {
        // check availability to allocate
        if (_availablePtr + sizeof(Frame) + function->_n_args * sizeof(int64_t) > _memory + memorySize) {
            throw std::runtime_error("Impossible to allocate frame. Memory used(bytes): " +
                                     std::to_string(_availablePtr - _memory));
        }

        // save current pointer
        _framesStart.push(_availablePtr);

        // allocate regs
        int64_t *regs = new (_availablePtr) int64_t[function->_n_regs];
        _availablePtr += function->_n_regs * sizeof(int64_t);

        // creating frame header
        Frame *new_frame = new (_availablePtr) Frame(function, regs);
        _availablePtr += sizeof(Frame);

        return new_frame;
    }

    void deallocate() {
        _availablePtr = _framesStart.top();
        _framesStart.pop();
    }

    ~FrameAllocator() { delete[] _memory; }
};
