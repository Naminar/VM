
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

    void DumpRegs();

    std::vector<int64_t> _regs;
    uint64_t _n_regs;
};


typedef uint8_t (*DoFuncPtrType)(uint8_t*);
typedef uint8_t (*DumpFuncPtrType)(uint8_t*);


class Interpretator {
  public:

    Interpretator();
    uint64_t Run();
    void Dump();

    std::stack<Frame> _frames;
    uint8_t *_bytecode = nullptr;
    uint64_t _bytecode_len = 0;
    uint8_t *_ptr = nullptr;
    uint8_t *_ip = nullptr;
    int64_t _return_value = 0; // from Call
    int64_t _return_code = 0;  // from whole program

    int64_t &GetRegRef(const uint64_t n);
    std::vector<std::function<uint8_t(uint8_t*)>> DoInstr;
    std::vector<std::function<uint8_t(uint8_t*)>> DumpInstr;

    #include "isa_decl.inc"
};
