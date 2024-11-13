
#include <string>
#include <stack>
#include <vector>
#include <iostream>


class Frame {
  public:
    Frame(const uint64_t n_regs):  _n_regs(n_regs) {
        _regs.resize(n_regs);
    }

    std::vector<int64_t> _regs;
    uint64_t _n_regs;
};


class Interpretator {
  public:

    std::stack<Frame> frames;
    uint8_t *bytecode = nullptr;
    uint8_t *ip = nullptr;
    int64_t return_value = 0;

    int64_t &Reg(const uint64_t n) {
        Frame &frame = frames.top();
        if (n > frame._n_regs - 1) {
            throw std::runtime_error("Out of bounds in registers.");
        }
        return frames.top()._regs[n];
    }

    #include "isa_run.h"
};
