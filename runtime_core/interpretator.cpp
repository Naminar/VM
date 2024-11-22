#include "interpretator.h"
#include "isa_impl.inc"

int64_t Interpretator::Run(bool verbose) {
  if (_ptr == nullptr) {
    throw std::runtime_error("Can't Run bytecode, _ptr = nullptr.");
  }

  if (verbose) {
    _current_frame->DumpRegs();
  }

  try {
    while (*_ptr != OPCODE_EXIT) {
      int64_t opcode = *_ptr;
      if (opcode > OPCODE_EXIT || DoInstr[opcode] == nullptr) {
        throw std::runtime_error("Invalid opcode: " + std::to_string(opcode));
      }

      if (verbose) {
        int64_t *old_ptr = _ptr;
        DumpInstr[*_ptr]();
        _ptr = old_ptr;
      }

      DoInstr[*_ptr]();

      if (verbose) {
        _current_frame->DumpRegs();
      }
    }
  } catch (std::runtime_error &e) {
    std::cout << *_ptr << e.what() << std::endl;
    return 0;
  }

  if (verbose) {
    int64_t *old_ptr = _ptr;
    DumpInstr[*_ptr]();
    _ptr = old_ptr;
  }

  DoInstr[*_ptr]();

  return _return_code;
}

void Interpretator::Dump() {
  if (_ptr == nullptr) {
    throw std::runtime_error("Can't Dump bytecode, _ptr = nullptr.");
  }

  while (*_ptr != OPCODE_EXIT && *_ptr != OPCODE_NOP) {
    int64_t opcode = *_ptr;
    if (opcode > OPCODE_EXIT || DumpInstr[opcode] == nullptr) {
      throw std::runtime_error("Invalid opcode: " + std::to_string(opcode));
    }

    DumpInstr[*_ptr]();
  }

  DumpInstr[*_ptr]();
}
