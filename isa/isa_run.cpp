#include <cstring>
#include "isa.h"

class Frame

uint64_t *REG_FILE;
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

     LongType _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
     RegType _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    REG_FILE[_arg1] = _arg0;
    return 10;
}




uint8_t do_ladd(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;

     RegType _arg0 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     RegType _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     RegType _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    REG_FILE[_arg2] = REG_FILE[_arg0] + REG_FILE[_arg1];
    return 4;
}




uint8_t do_lsub(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;

     RegType _arg0 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     RegType _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     RegType _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    REG_FILE[_arg2] = REG_FILE[_arg0] - REG_FILE[_arg1];
    return 4;
}




uint8_t do_lmul(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;

     RegType _arg0 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     RegType _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     RegType _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    REG_FILE[_arg2] = REG_FILE[_arg0] * REG_FILE[_arg1];
    return 4;
}




uint8_t do_ldiv(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;

     RegType _arg0 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     RegType _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     RegType _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    REG_FILE[_arg2] = REG_FILE[_arg0] / REG_FILE[_arg1];
    return 4;
}




uint8_t do_lrem(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;

     RegType _arg0 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     RegType _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     RegType _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    REG_FILE[_arg2] = REG_FILE[_arg0] % REG_FILE[_arg1];
    return 4;
}




uint8_t do_br_licmpeq(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;

     LongType _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
     RegType _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     RegType _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    if (REG_FILE[_arg1] == REG_FILE[_arg2]) { IP += _arg0; }
    return 11;
}




uint8_t do_br_licmpne(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;

     LongType _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
     RegType _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     RegType _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    if (REG_FILE[_arg1] != REG_FILE[_arg2]) { IP += _arg0; }
    return 11;
}




uint8_t do_br_licmplt(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;

     LongType _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
     RegType _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     RegType _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    if (REG_FILE[_arg1] < REG_FILE[_arg2]) { IP += _arg0; }
    return 11;
}




uint8_t do_br_licmpge(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;

     LongType _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
     RegType _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     RegType _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    if (REG_FILE[_arg1] >= REG_FILE[_arg2]) { IP += _arg0; }
    return 11;
}




uint8_t do_br_licmpgt(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;

     LongType _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
     RegType _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     RegType _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    if (REG_FILE[_arg1] > REG_FILE[_arg2]) { IP += _arg0; }
    return 11;
}




uint8_t do_br_licmple(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;

     LongType _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
     RegType _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     RegType _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    if (REG_FILE[_arg1] <= REG_FILE[_arg2]) { IP += _arg0; }
    return 11;
}




uint8_t do_br(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;

     LongType _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
    

    IP += _arg0;
    return 9;
}




uint8_t do_lreturn(void *ptr) {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);
    _ptr++;

     LongType _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
    

    RET_VAL = _arg0;
    return 9;
}



