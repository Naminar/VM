#include "interpretator.h"
#include "isa.h"


int64_t Interpretator::Run() {
    if (_current_frame->_ptr == nullptr) {
        throw std::runtime_error("Can't Run bytecode, _ptr = nullptr.");
    }

    _current_frame->Run(this);
    return _return_code;
}


void Interpretator::Dump() {
    if (_current_frame->_ptr == nullptr) {
        throw std::runtime_error("Can't Dump bytecode, _ptr = nullptr.");
    }

    _current_frame->Dump(this);
}


int64_t Interpretator::CreateFunction(const std::string &name, int64_t n_args, int64_t n_regs) {
    _functions.push_back(new Function(name, n_args, n_regs));
    return _functions.size() - 1;
}
