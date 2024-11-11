#include <cstring>
#include "isa.h"

uint64_t REG_FILE[128];
uint64_t IP = 0;
uint64_t RET_VAL = 0;




nop::nop(void *ptr) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));
    memcpy(bytecode, ptr, bytecode_len);
    Decode();
}

nop::nop() {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));

    

    Dump(bytecode);
}

uint8_t nop::Decode() {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(bytecode);
    _ptr++;

    

    return bytecode_len;
}


void nop::Run() const {
    
}

uint8_t nop::Dump(void *ptr) const {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);

    

    return bytecode_len;
}




lmov::lmov(void *ptr) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));
    memcpy(bytecode, ptr, bytecode_len);
    Decode();
}

lmov::lmov(LongType arg0, RegType arg1) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));

     _arg0 = arg0;
     _arg1 = arg1;
    

    Dump(bytecode);
}

uint8_t lmov::Decode() {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(bytecode);
    _ptr++;

     _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
     _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    return bytecode_len;
}


void lmov::Run() const {
    REG_FILE[_arg1] = _arg0;
}

uint8_t lmov::Dump(void *ptr) const {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);

    *reinterpret_cast<LongType *>(_ptr) = _arg0;
    _ptr += 8;
    *reinterpret_cast<RegType *>(_ptr) = _arg1;
    _ptr += 1;
    

    return bytecode_len;
}




ladd::ladd(void *ptr) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));
    memcpy(bytecode, ptr, bytecode_len);
    Decode();
}

ladd::ladd(RegType arg0, RegType arg1, RegType arg2) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));

     _arg0 = arg0;
     _arg1 = arg1;
     _arg2 = arg2;
    

    Dump(bytecode);
}

uint8_t ladd::Decode() {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(bytecode);
    _ptr++;

     _arg0 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    return bytecode_len;
}


void ladd::Run() const {
    REG_FILE[_arg2] = REG_FILE[_arg0] + REG_FILE[_arg1];
}

uint8_t ladd::Dump(void *ptr) const {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);

    *reinterpret_cast<RegType *>(_ptr) = _arg0;
    _ptr += 1;
    *reinterpret_cast<RegType *>(_ptr) = _arg1;
    _ptr += 1;
    *reinterpret_cast<RegType *>(_ptr) = _arg2;
    _ptr += 1;
    

    return bytecode_len;
}




lsub::lsub(void *ptr) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));
    memcpy(bytecode, ptr, bytecode_len);
    Decode();
}

lsub::lsub(RegType arg0, RegType arg1, RegType arg2) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));

     _arg0 = arg0;
     _arg1 = arg1;
     _arg2 = arg2;
    

    Dump(bytecode);
}

uint8_t lsub::Decode() {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(bytecode);
    _ptr++;

     _arg0 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    return bytecode_len;
}


void lsub::Run() const {
    REG_FILE[_arg2] = REG_FILE[_arg0] - REG_FILE[_arg1];
}

uint8_t lsub::Dump(void *ptr) const {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);

    *reinterpret_cast<RegType *>(_ptr) = _arg0;
    _ptr += 1;
    *reinterpret_cast<RegType *>(_ptr) = _arg1;
    _ptr += 1;
    *reinterpret_cast<RegType *>(_ptr) = _arg2;
    _ptr += 1;
    

    return bytecode_len;
}




lmul::lmul(void *ptr) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));
    memcpy(bytecode, ptr, bytecode_len);
    Decode();
}

lmul::lmul(RegType arg0, RegType arg1, RegType arg2) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));

     _arg0 = arg0;
     _arg1 = arg1;
     _arg2 = arg2;
    

    Dump(bytecode);
}

uint8_t lmul::Decode() {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(bytecode);
    _ptr++;

     _arg0 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    return bytecode_len;
}


void lmul::Run() const {
    REG_FILE[_arg2] = REG_FILE[_arg0] * REG_FILE[_arg1];
}

uint8_t lmul::Dump(void *ptr) const {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);

    *reinterpret_cast<RegType *>(_ptr) = _arg0;
    _ptr += 1;
    *reinterpret_cast<RegType *>(_ptr) = _arg1;
    _ptr += 1;
    *reinterpret_cast<RegType *>(_ptr) = _arg2;
    _ptr += 1;
    

    return bytecode_len;
}




ldiv::ldiv(void *ptr) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));
    memcpy(bytecode, ptr, bytecode_len);
    Decode();
}

ldiv::ldiv(RegType arg0, RegType arg1, RegType arg2) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));

     _arg0 = arg0;
     _arg1 = arg1;
     _arg2 = arg2;
    

    Dump(bytecode);
}

uint8_t ldiv::Decode() {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(bytecode);
    _ptr++;

     _arg0 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    return bytecode_len;
}


void ldiv::Run() const {
    REG_FILE[_arg2] = REG_FILE[_arg0] / REG_FILE[_arg1];
}

uint8_t ldiv::Dump(void *ptr) const {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);

    *reinterpret_cast<RegType *>(_ptr) = _arg0;
    _ptr += 1;
    *reinterpret_cast<RegType *>(_ptr) = _arg1;
    _ptr += 1;
    *reinterpret_cast<RegType *>(_ptr) = _arg2;
    _ptr += 1;
    

    return bytecode_len;
}




lrem::lrem(void *ptr) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));
    memcpy(bytecode, ptr, bytecode_len);
    Decode();
}

lrem::lrem(RegType arg0, RegType arg1, RegType arg2) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));

     _arg0 = arg0;
     _arg1 = arg1;
     _arg2 = arg2;
    

    Dump(bytecode);
}

uint8_t lrem::Decode() {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(bytecode);
    _ptr++;

     _arg0 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    return bytecode_len;
}


void lrem::Run() const {
    REG_FILE[_arg2] = REG_FILE[_arg0] % REG_FILE[_arg1];
}

uint8_t lrem::Dump(void *ptr) const {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);

    *reinterpret_cast<RegType *>(_ptr) = _arg0;
    _ptr += 1;
    *reinterpret_cast<RegType *>(_ptr) = _arg1;
    _ptr += 1;
    *reinterpret_cast<RegType *>(_ptr) = _arg2;
    _ptr += 1;
    

    return bytecode_len;
}




br_licmpeq::br_licmpeq(void *ptr) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));
    memcpy(bytecode, ptr, bytecode_len);
    Decode();
}

br_licmpeq::br_licmpeq(LongType arg0, RegType arg1, RegType arg2) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));

     _arg0 = arg0;
     _arg1 = arg1;
     _arg2 = arg2;
    

    Dump(bytecode);
}

uint8_t br_licmpeq::Decode() {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(bytecode);
    _ptr++;

     _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
     _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    return bytecode_len;
}


void br_licmpeq::Run() const {
    if (REG_FILE[_arg1] == REG_FILE[_arg2]) { IP += _arg0; }
}

uint8_t br_licmpeq::Dump(void *ptr) const {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);

    *reinterpret_cast<LongType *>(_ptr) = _arg0;
    _ptr += 8;
    *reinterpret_cast<RegType *>(_ptr) = _arg1;
    _ptr += 1;
    *reinterpret_cast<RegType *>(_ptr) = _arg2;
    _ptr += 1;
    

    return bytecode_len;
}




br_licmpne::br_licmpne(void *ptr) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));
    memcpy(bytecode, ptr, bytecode_len);
    Decode();
}

br_licmpne::br_licmpne(LongType arg0, RegType arg1, RegType arg2) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));

     _arg0 = arg0;
     _arg1 = arg1;
     _arg2 = arg2;
    

    Dump(bytecode);
}

uint8_t br_licmpne::Decode() {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(bytecode);
    _ptr++;

     _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
     _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    return bytecode_len;
}


void br_licmpne::Run() const {
    if (REG_FILE[_arg1] != REG_FILE[_arg2]) { IP += _arg0; }
}

uint8_t br_licmpne::Dump(void *ptr) const {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);

    *reinterpret_cast<LongType *>(_ptr) = _arg0;
    _ptr += 8;
    *reinterpret_cast<RegType *>(_ptr) = _arg1;
    _ptr += 1;
    *reinterpret_cast<RegType *>(_ptr) = _arg2;
    _ptr += 1;
    

    return bytecode_len;
}




br_licmplt::br_licmplt(void *ptr) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));
    memcpy(bytecode, ptr, bytecode_len);
    Decode();
}

br_licmplt::br_licmplt(LongType arg0, RegType arg1, RegType arg2) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));

     _arg0 = arg0;
     _arg1 = arg1;
     _arg2 = arg2;
    

    Dump(bytecode);
}

uint8_t br_licmplt::Decode() {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(bytecode);
    _ptr++;

     _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
     _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    return bytecode_len;
}


void br_licmplt::Run() const {
    if (REG_FILE[_arg1] < REG_FILE[_arg2]) { IP += _arg0; }
}

uint8_t br_licmplt::Dump(void *ptr) const {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);

    *reinterpret_cast<LongType *>(_ptr) = _arg0;
    _ptr += 8;
    *reinterpret_cast<RegType *>(_ptr) = _arg1;
    _ptr += 1;
    *reinterpret_cast<RegType *>(_ptr) = _arg2;
    _ptr += 1;
    

    return bytecode_len;
}




br_licmpge::br_licmpge(void *ptr) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));
    memcpy(bytecode, ptr, bytecode_len);
    Decode();
}

br_licmpge::br_licmpge(LongType arg0, RegType arg1, RegType arg2) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));

     _arg0 = arg0;
     _arg1 = arg1;
     _arg2 = arg2;
    

    Dump(bytecode);
}

uint8_t br_licmpge::Decode() {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(bytecode);
    _ptr++;

     _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
     _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    return bytecode_len;
}


void br_licmpge::Run() const {
    if (REG_FILE[_arg1] >= REG_FILE[_arg2]) { IP += _arg0; }
}

uint8_t br_licmpge::Dump(void *ptr) const {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);

    *reinterpret_cast<LongType *>(_ptr) = _arg0;
    _ptr += 8;
    *reinterpret_cast<RegType *>(_ptr) = _arg1;
    _ptr += 1;
    *reinterpret_cast<RegType *>(_ptr) = _arg2;
    _ptr += 1;
    

    return bytecode_len;
}




br_licmpgt::br_licmpgt(void *ptr) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));
    memcpy(bytecode, ptr, bytecode_len);
    Decode();
}

br_licmpgt::br_licmpgt(LongType arg0, RegType arg1, RegType arg2) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));

     _arg0 = arg0;
     _arg1 = arg1;
     _arg2 = arg2;
    

    Dump(bytecode);
}

uint8_t br_licmpgt::Decode() {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(bytecode);
    _ptr++;

     _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
     _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    return bytecode_len;
}


void br_licmpgt::Run() const {
    if (REG_FILE[_arg1] > REG_FILE[_arg2]) { IP += _arg0; }
}

uint8_t br_licmpgt::Dump(void *ptr) const {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);

    *reinterpret_cast<LongType *>(_ptr) = _arg0;
    _ptr += 8;
    *reinterpret_cast<RegType *>(_ptr) = _arg1;
    _ptr += 1;
    *reinterpret_cast<RegType *>(_ptr) = _arg2;
    _ptr += 1;
    

    return bytecode_len;
}




br_licmple::br_licmple(void *ptr) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));
    memcpy(bytecode, ptr, bytecode_len);
    Decode();
}

br_licmple::br_licmple(LongType arg0, RegType arg1, RegType arg2) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));

     _arg0 = arg0;
     _arg1 = arg1;
     _arg2 = arg2;
    

    Dump(bytecode);
}

uint8_t br_licmple::Decode() {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(bytecode);
    _ptr++;

     _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
     _arg1 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
     _arg2 = *reinterpret_cast<RegType *>(_ptr);
    _ptr += 1;
    

    return bytecode_len;
}


void br_licmple::Run() const {
    if (REG_FILE[_arg1] <= REG_FILE[_arg2]) { IP += _arg0; }
}

uint8_t br_licmple::Dump(void *ptr) const {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);

    *reinterpret_cast<LongType *>(_ptr) = _arg0;
    _ptr += 8;
    *reinterpret_cast<RegType *>(_ptr) = _arg1;
    _ptr += 1;
    *reinterpret_cast<RegType *>(_ptr) = _arg2;
    _ptr += 1;
    

    return bytecode_len;
}




br::br(void *ptr) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));
    memcpy(bytecode, ptr, bytecode_len);
    Decode();
}

br::br(LongType arg0) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));

     _arg0 = arg0;
    

    Dump(bytecode);
}

uint8_t br::Decode() {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(bytecode);
    _ptr++;

     _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
    

    return bytecode_len;
}


void br::Run() const {
    IP += _arg0;
}

uint8_t br::Dump(void *ptr) const {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);

    *reinterpret_cast<LongType *>(_ptr) = _arg0;
    _ptr += 8;
    

    return bytecode_len;
}




lreturn::lreturn(void *ptr) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));
    memcpy(bytecode, ptr, bytecode_len);
    Decode();
}

lreturn::lreturn(LongType arg0) {
    bytecode = calloc(bytecode_len, sizeof(uint8_t));

     _arg0 = arg0;
    

    Dump(bytecode);
}

uint8_t lreturn::Decode() {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(bytecode);
    _ptr++;

     _arg0 = *reinterpret_cast<LongType *>(_ptr);
    _ptr += 8;
    

    return bytecode_len;
}


void lreturn::Run() const {
    RET_VAL = _arg0;
}

uint8_t lreturn::Dump(void *ptr) const {
    uint8_t *_ptr = reinterpret_cast<uint8_t *>(ptr);

    *reinterpret_cast<LongType *>(_ptr) = _arg0;
    _ptr += 8;
    

    return bytecode_len;
}



