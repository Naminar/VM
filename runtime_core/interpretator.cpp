#include "interpretator.h"
#include "isa_opcode_defines.h"

void Frame::DumpRegs() {
    std::cout << "Frame dump (" << _regs.size() << "):\n";
    for (uint8_t i = 0; i < _regs.size(); ++i) {
        std::cout << "REG[" << static_cast<int64_t>(i) << "]: " << _regs[i] << std::endl;
    }
}


int64_t &Interpretator::GetRegRef(const uint64_t n) {
    if (_current_frame->_n_regs == 0 || n > _current_frame->_n_regs - 1) {
        throw std::runtime_error("Out of bounds in registers.");
    }
    return _current_frame->_regs[n];
}

#include "isa_impl.inc"


Interpretator::Interpretator() {
    DoInstr.resize(OPCODE_EXIT + 1);
    DumpInstr.resize(OPCODE_EXIT + 1);

    for (auto &i : DoInstr) { i = 0; }
    for (auto &i : DumpInstr) { i = 0; }

    #include "init_func_vec.inc"
}


uint64_t Interpretator::Run(bool verbose) {
    if (_ptr == nullptr) {
        throw std::runtime_error("Can't Run bytecode, _ptr = nullptr.");
    }

    if (verbose) {
        _current_frame->DumpRegs();
    }

    try {
        while (*_ptr != OPCODE_EXIT) {
            uint8_t opcode = *_ptr;
            if (opcode > OPCODE_EXIT || DoInstr[opcode] == nullptr) {
                throw std::runtime_error("Invalid opcode: " + std::to_string(opcode));
            }

            if (verbose) {
                uint8_t *old_ptr = _ptr;
                DumpInstr[*_ptr]();
                _ptr = old_ptr;
            }

            DoInstr[*_ptr]();

            if (verbose) {
                _current_frame->DumpRegs();
            }
        }
    }
    catch (std::runtime_error &e) {
        std::cout << *_ptr <<e.what() << std::endl;
        return 0;
    }

    if (verbose) {
        uint8_t *old_ptr = _ptr;
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
        uint8_t opcode = *_ptr;
        if (opcode > OPCODE_EXIT || DumpInstr[opcode] == nullptr) {
            throw std::runtime_error("Invalid opcode: " + std::to_string(opcode));
        }

        DumpInstr[*_ptr]();
    }

    DumpInstr[*_ptr]();
}
