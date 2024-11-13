
#include <string>
#include <stack>
#include <vector>
#include <iostream>
#include <functional>


class Frame {
  public:
    Frame(const uint64_t n_regs):  _n_regs(n_regs) {
        _regs.resize(n_regs);
    }

    std::vector<int64_t> _regs;
    uint64_t _n_regs;
};


typedef uint8_t (*DoFuncPtrType)(uint8_t*);
typedef uint8_t (*DumpFuncPtrType)(uint8_t*);


class Interpretator {
  public:

    Interpretator();

    std::stack<Frame> _frames;
    uint8_t *_bytecode = nullptr;
    uint8_t *_ip = nullptr;
    int64_t _return_value = 0;

    int64_t &GetRegRef(const uint64_t n);
    std::vector<std::function<uint8_t(uint8_t*)>> DoInstr;
    std::vector<std::function<uint8_t(uint8_t*)>> DumpInstr;
    // uint8_t DoInstr(uint8_t *ptr);
    // uint8_t DumpInstr(uint8_t *ptr);
    #include "isa_decl.inc"
};
