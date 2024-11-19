
#include <string>
#include <stack>
#include <vector>
#include <iostream>
#include <functional>
#include <cstdint>


class Frame {
  public:
    Frame(const uint64_t n_regs):  _n_regs(n_regs) {
        _regs.resize(n_regs);
    }

    void DumpRegs();

    std::vector<int64_t> _regs;
    uint64_t _n_regs;
    uint8_t *_bytecode = nullptr;
    uint64_t _bytecode_len = 0;
    uint8_t *_ptr = nullptr;
    int64_t _return_value = 0; // from Call
};


class Function {
  public:
    Function(const std::string &name, uint64_t n_args): _name(name), _n_args(n_args) {}

    std::string _name = "";
    uint64_t _n_args = 0;
    uint8_t *_bytecode = nullptr;
    uint64_t _bytecode_len = 0;
};


typedef uint8_t (DoFuncPtrType)(uint8_t*);
// typedef uint8_t (*DoFuncPtrType)(uint8_t*);
typedef uint8_t (DumpFuncPtrType)(uint8_t*);


class Interpretator {
  public:

    Interpretator();
    uint64_t Run(bool verbose = false);
    void Dump();

    std::stack<Frame *> _frames;
    Frame *current_frame;
    std::vector<Function *> _functions;
    uint8_t *_bytecode = nullptr;
    uint64_t _bytecode_len = 0;
    uint8_t *_ptr = nullptr;
    int64_t _return_value = 0; // from Call
    int64_t _return_code = 0;  // from whole program

    uint64_t CreateFunction(const std::string &name, uint64_t n_args) {
        _functions.push_back(new Function(name, n_args));
        return _functions.size() - 1;
    }

    Function *GetFuncById(uint64_t id) {
        if (id < 0 || id > _functions.size()) {
            throw std::runtime_error("Out of range in _functions.");
        }
        return _functions[id];
    }

    void SetPtr(uint8_t *bytecode, uint64_t bytecode_len, uint8_t *position) {
        _bytecode = bytecode;
        _bytecode_len = bytecode_len;
        _ptr = position;
    }

    void SavePtrBeforeCall() {
        Frame *frame = _frames.top();
        frame->_ptr = _ptr;
    }

    int64_t &GetRegRef(const uint64_t n);
    std::vector<std::function<uint8_t(uint8_t*)>> DoInstr;
    std::vector<std::function<uint8_t(uint8_t*)>> DumpInstr;

    #include "isa_decl.inc"
};
