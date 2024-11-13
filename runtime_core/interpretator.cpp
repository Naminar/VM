#include "interpretator.h"

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
