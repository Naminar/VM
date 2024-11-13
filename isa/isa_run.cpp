#include <cstring>
#include "isa.h"

uint64_t REG_FILE[128];
uint64_t IP = 0;
uint64_t RET_VAL = 0;




uint8_t do_nop(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;



    
    return 1;
}




uint8_t do_lmov(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;


    const uint64_t _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr +=  8;


    uint64_t &_arg1 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;


    _arg1 = _arg0;
    return 10;
}




uint8_t do_ladd(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;


    uint64_t &_arg0 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;

    uint64_t &_arg1 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;

    uint64_t &_arg2 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;


    _arg2 = _arg0 + _arg1;
    return 4;
}




uint8_t do_lsub(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;


    uint64_t &_arg0 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;

    uint64_t &_arg1 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;

    uint64_t &_arg2 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;


    _arg2 = _arg0 - _arg1;
    return 4;
}




uint8_t do_lmul(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;


    uint64_t &_arg0 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;

    uint64_t &_arg1 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;

    uint64_t &_arg2 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;


    _arg2 = _arg0 * _arg1;
    return 4;
}




uint8_t do_ldiv(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;


    uint64_t &_arg0 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;

    uint64_t &_arg1 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;

    uint64_t &_arg2 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;


    _arg2 = _arg0 / _arg1;
    return 4;
}




uint8_t do_lrem(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;


    uint64_t &_arg0 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;

    uint64_t &_arg1 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;

    uint64_t &_arg2 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;


    _arg2 = _arg0 % _arg1;
    return 4;
}




uint8_t do_br_licmpeq(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;


    const uint64_t _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr +=  8;


    uint64_t &_arg1 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;

    uint64_t &_arg2 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;


    if (_arg1 == _arg2) { _ip += _arg0; }
    return 11;
}




uint8_t do_br_licmpne(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;


    const uint64_t _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr +=  8;


    uint64_t &_arg1 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;

    uint64_t &_arg2 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;


    if (_arg1 != _arg2) { _ip += _arg0; }
    return 11;
}




uint8_t do_br_licmplt(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;


    const uint64_t _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr +=  8;


    uint64_t &_arg1 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;

    uint64_t &_arg2 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;


    if (_arg1 < _arg2) { _ip += _arg0; }
    return 11;
}




uint8_t do_br_licmpge(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;


    const uint64_t _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr +=  8;


    uint64_t &_arg1 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;

    uint64_t &_arg2 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;


    if (_arg1 >= _arg2) { _ip += _arg0; }
    return 11;
}




uint8_t do_br_licmpgt(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;


    const uint64_t _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr +=  8;


    uint64_t &_arg1 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;

    uint64_t &_arg2 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;


    if (_arg1 > _arg2) { _ip += _arg0; }
    return 11;
}




uint8_t do_br_licmple(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;


    const uint64_t _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr +=  8;


    uint64_t &_arg1 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;

    uint64_t &_arg2 = GetReg(*reinterpret_cast<RegType *>(_ptr));
    _ptr += 1;


    if (_arg1 <= _arg2) { _ip += _arg0; }
    return 11;
}




uint8_t do_br(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;


    const uint64_t _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr +=  8;



    _ip += _arg0;
    return 9;
}




uint8_t do_lreturn(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;


    const uint64_t _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr +=  8;



    return_value = _arg0;
    return 9;
}



