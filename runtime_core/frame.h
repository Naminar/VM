#pragma once
#include "function.h"
#include "isa.h"
#include <iostream>
#include <stack>
#include <iomanip>

class Interpretator;

using regs_t = int64_t;

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

    void DumpMySelf() {
        std::cout << "Frame dump:" << this << std::endl;
        std::cout << std::setw(15)<< "-regs "           << std::setw(20) << _regs << std::endl;
        std::cout << std::setw(15) << "_n_regs "        << std::setw(20) << _n_regs << std::endl;
        std::cout << std::setw(15) << "_bytecode "      << std::setw(20) << _bytecode << std::endl;
        std::cout << std::setw(15) << "_ptr "           << std::setw(20) << _ptr << std::endl;
        std::cout << std::setw(15) << "_bytecode_len "  << std::setw(20) << _bytecode_len << std::endl;
        std::cout << std::setw(15) << "_return_value "  << std::setw(20) << _return_value << std::endl;
        std::cout << std::setw(15) << "previous_frame " << std::setw(20) << previous_frame << std::endl;
        std::cout << std::setw(15) << "------------------------" << std::endl;
    }
    int64_t *_regs = nullptr; // owner
    int64_t _n_regs = 0;
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
    if (_memory == nullptr)
      throw std::runtime_error("Impossible to allocate memory for frames.");
    _availablePtr = _memory;
  }

  Frame *allocate(Interpretator *i, Frame *current_frame, Function *function) {
    // check availability to allocate
    if (_availablePtr + sizeof(Frame) +
            function->_n_args * sizeof(regs_t)>
        _memory + memorySize)
      throw std::runtime_error(
          "Impossible to allocate frame. Total allocated: " +
          std::to_string(_framesAllocated) +
          ". Memory used(bytes): " + std::to_string(_availablePtr - _memory));

    _framesAllocated++;
    // std::cout << "Frames allocated: " << _framesAllocated << std::endl;
    // save current pointer
    _framesStart.push(_availablePtr);

    // creating frame header
    Frame *new_frame = reinterpret_cast<Frame *>(_availablePtr);
    _availablePtr += sizeof(Frame);

    // allocate and set regs
    new_frame->_regs =
        reinterpret_cast<regs_t*>(_availablePtr);
    if (current_frame)
      _availablePtr += function->_n_args * sizeof(regs_t);
    else
      _availablePtr += function->_n_regs * sizeof(regs_t);
    
    new_frame->_n_regs = function->_n_regs;
    
    if (current_frame)
    memcpy(new_frame->_regs, current_frame->_regs,
           function->_n_args * sizeof(regs_t));

    // set bytecode
    new_frame->SetPtr(function);

    // save
    new_frame->previous_frame = current_frame;
    
    if (current_frame) current_frame->DumpMySelf();
    new_frame->DumpMySelf();

    return new_frame;
  }

  Frame *deallocate() {
    _availablePtr = _framesStart.top();
    _framesStart.pop();

    char *previous_frame = nullptr;
    if (!_framesStart.empty()) {
      previous_frame = _framesStart.top();
      reinterpret_cast<Frame *>(previous_frame)->_return_value =
          reinterpret_cast<Frame *>(_availablePtr)->_return_value;
    }
    return reinterpret_cast<Frame *>(previous_frame);
  }

  ~FrameAllocator() { delete[] _memory; }
};