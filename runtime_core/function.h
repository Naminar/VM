#pragma once
#include <string>
#include <cstdint>

class Function {
  public:
    // TODO: Calloc -> new
    Function(const std::string &name, int64_t n_args, int64_t n_regs, int64_t bytecode_len):
        _name(name),
        _n_args(n_args),
        _n_regs(n_regs),
        _bytecode_len(bytecode_len),
        _bytecode(reinterpret_cast<int64_t *>(calloc(bytecode_len, 1))) {}

    ~Function() {
        delete _bytecode;
    }

    // TODO: dump bytecode
    void Dump() {
        std::cout << "------------------------" << std::endl;
        std::cout << "Function dump:" << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << "Name: " << _name << std::endl;
        std::cout << "Number of arguments: " << _n_args << std::endl;
        std::cout << "Number of registers: " << _n_regs << std::endl;
        // std::cout << "Bytecode: " << std::endl;
    }

    int64_t *const _bytecode = nullptr;   // owner
    const int64_t _bytecode_len = 0;
    const std::string _name = "";
    const int64_t _n_args = 0;
    const int64_t _n_regs = 0;
};