#pragma once
#include "function.h"
#include "isa.h"
#include <iostream>
#include <stack>

class Interpretator;

class Frame {
  public:
    // Frame(const Function *func) : _n_regs(func->_n_regs) { SetPtr(func); }
    Frame(const Function *func, int64_t * const regs) : _n_regs(func->_n_regs), _regs(regs) { SetPtr(func); }
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

    inline int64_t Run(Interpretator *i) {
        ISA::dispatch_do[*_ptr](i, _ptr);
        return _return_value;
    }

    inline void Dump(Interpretator *i) { ISA::dispatch_dump[*_ptr](i, _ptr, true); }

    int64_t *const _regs = nullptr; // owner
    const int64_t _n_regs = 0;
    int64_t *_bytecode = nullptr;
    int64_t *_ptr = nullptr;
    int64_t _bytecode_len = 0;
    int64_t _return_value = 0;
    Frame *previous_frame = nullptr;
};

template <uint64_t memorySize> class FrameAllocator {
  private:
    char *_memory;
    char *_availablePtr;
    std::stack<char *> _framesStart;
    uint64_t _framesAllocated = 0;

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
            throw std::runtime_error(
                "Impossible to allocate frame. Total allocated: " + std::to_string(_framesAllocated) +
                ". Memory used(bytes): " + std::to_string(_availablePtr - _memory));
        }

        _framesAllocated++;
        // std::cout << "Frames allocated: " << _framesAllocated << std::endl;
        // save current pointer
        _framesStart.push(_availablePtr);

        // allocate and set regs
        int64_t *regs = new (_availablePtr) int64_t[function->_n_regs];
        _availablePtr += function->_n_regs * sizeof(int64_t);

        // creating frame header
        Frame *new_frame = new (_availablePtr) Frame(function, regs);
        _availablePtr += sizeof(Frame);

        std::cout << std::hex << "Allocated frame: regs address: 0x" << reinterpret_cast<int64_t *>(_framesStart.top()) << ", frame address: 0x"
            << new_frame << ", new available: 0x" << reinterpret_cast<int64_t *>(_availablePtr) << std::endl;


        return new_frame;
    }

    void deallocate() {
        _framesStart.pop();
        _availablePtr = _framesStart.top();
        std::cout << std::hex << "Dealoc. New available: 0x" << reinterpret_cast<int64_t *>(_availablePtr) << std::endl;
    }

    ~FrameAllocator() { delete[] _memory; }
};
