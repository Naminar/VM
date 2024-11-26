#include "interpretator.h"
#include "isa.h"

int64_t Interpretator::Run() {
    if (_current_frame->_ptr == nullptr) {
        throw std::runtime_error("Can't Run bytecode, _ptr = nullptr.");
    }

    ISA::dispatch_do[*_current_frame->_ptr](this, _current_frame->_ptr);

    return _return_code;
}

void Interpretator::Dump() {
    if (_current_frame->_ptr == nullptr) {
        throw std::runtime_error("Can't Dump bytecode, _ptr = nullptr.");
    }

    ISA::dispatch_dump[*_current_frame->_ptr](this, _current_frame->_ptr, true);
}
