#include "interpretator.h"


void Frame::DumpRegs() {
    std::cout << "Frame dump:" << std::endl;
    for (uint8_t i = 0; i < _regs.size(); ++i) {
        std::cout << "REG[" << i << "]: " << _regs[i] << std::endl;
    }
}


int64_t &Interpretator::GetRegRef(const uint64_t n) {
    Frame &frame = _frames.top();
    if (n > frame._n_regs - 1) {
        throw std::runtime_error("Out of bounds in registers.");
    }
    return frame._regs[n];
}

#include "isa_impl.inc"


Interpretator::Interpretator() {
    DoInstr.resize(256);
    DumpInstr.resize(256);

    for (auto &i : DoInstr) { i = 0; }
    for (auto &i : DumpInstr) { i = 0; }

    #include "init_func_vec.inc"
}


uint64_t Interpretator::Run() {
    if (_ptr == nullptr) {
        throw std::runtime_error("Can't Run bytecode, _ptr = nullptr.");
    }

    _frames.top().DumpRegs();

    while (*_ptr != 255 /*exit opcode*/) {
        uint8_t opcode = *_ptr;
        if (opcode > 255 || DoInstr[opcode] == nullptr) {
            throw std::runtime_error("Invalid opcode: " + std::to_string(opcode));
        }

        // std::cout << "Running opcode: " << static_cast<uint32_t>(opcode) << std::endl;
        // _frames.top().DumpRegs();
        _ptr += DoInstr[*_ptr](_ptr);
    }

    _ptr += DoInstr[*_ptr](_ptr);

    return _return_code;
}


void Interpretator::Dump() {
    if (_ptr == nullptr) {
        throw std::runtime_error("Can't Dump bytecode, _ptr = nullptr.");
    }

    while (*_ptr != 255 /*exit opcode*/) {
        uint8_t opcode = *_ptr;
        if (opcode > 255 || DumpInstr[opcode] == nullptr) {
            throw std::runtime_error("Invalid opcode: " + std::to_string(opcode));
        }

        _ptr += DumpInstr[*_ptr](_ptr);
    }

    _ptr += DumpInstr[*_ptr](_ptr);
}
