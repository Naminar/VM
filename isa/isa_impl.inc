

uint8_t Interpretator::do_nop(uint8_t *ptr) {
    ptr++;



    
    return 1;
}

uint8_t Interpretator::create_nop(, uint8_t *ptr, uint64_t size) {
    if (size < 1) {
        throw std::runtime_error("Out of range in create_nop");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 0;
    ptr++;


    return 1;
}



uint8_t Interpretator::do_lmov(uint8_t *ptr) {
    ptr++;



    const uint64_t _arg0 = *reinterpret_cast<LongType *>(ptr);
    ptr +=  8;

    uint64_t &_arg1 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    _arg1 = _arg0;
    return 10;
}

uint8_t Interpretator::create_lmov(uint64_t arg0, uint8_t arg1, uint8_t *ptr, uint64_t size) {
    if (size < 10) {
        throw std::runtime_error("Out of range in create_lmov");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 2;
    ptr++;


    *reinterpret_cast<uint64_t*>(ptr) = _arg0;
    ptr +=  8;

    *reinterpret_cast<uint8_t*>(ptr) = _arg1;
    ptr += 1;

    return 10;
}



uint8_t Interpretator::do_ladd(uint8_t *ptr) {
    ptr++;



    uint64_t &_arg0 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    uint64_t &_arg1 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    uint64_t &_arg2 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    _arg2 = _arg0 + _arg1;
    return 4;
}

uint8_t Interpretator::create_ladd(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 4) {
        throw std::runtime_error("Out of range in create_ladd");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 97;
    ptr++;


    *reinterpret_cast<uint8_t*>(ptr) = _arg0;
    ptr += 1;

    *reinterpret_cast<uint8_t*>(ptr) = _arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t*>(ptr) = _arg2;
    ptr += 1;

    return 4;
}



uint8_t Interpretator::do_lsub(uint8_t *ptr) {
    ptr++;



    uint64_t &_arg0 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    uint64_t &_arg1 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    uint64_t &_arg2 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    _arg2 = _arg0 - _arg1;
    return 4;
}

uint8_t Interpretator::create_lsub(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 4) {
        throw std::runtime_error("Out of range in create_lsub");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 101;
    ptr++;


    *reinterpret_cast<uint8_t*>(ptr) = _arg0;
    ptr += 1;

    *reinterpret_cast<uint8_t*>(ptr) = _arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t*>(ptr) = _arg2;
    ptr += 1;

    return 4;
}



uint8_t Interpretator::do_lmul(uint8_t *ptr) {
    ptr++;



    uint64_t &_arg0 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    uint64_t &_arg1 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    uint64_t &_arg2 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    _arg2 = _arg0 * _arg1;
    return 4;
}

uint8_t Interpretator::create_lmul(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 4) {
        throw std::runtime_error("Out of range in create_lmul");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 105;
    ptr++;


    *reinterpret_cast<uint8_t*>(ptr) = _arg0;
    ptr += 1;

    *reinterpret_cast<uint8_t*>(ptr) = _arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t*>(ptr) = _arg2;
    ptr += 1;

    return 4;
}



uint8_t Interpretator::do_ldiv(uint8_t *ptr) {
    ptr++;



    uint64_t &_arg0 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    uint64_t &_arg1 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    uint64_t &_arg2 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    _arg2 = _arg0 / _arg1;
    return 4;
}

uint8_t Interpretator::create_ldiv(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 4) {
        throw std::runtime_error("Out of range in create_ldiv");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 109;
    ptr++;


    *reinterpret_cast<uint8_t*>(ptr) = _arg0;
    ptr += 1;

    *reinterpret_cast<uint8_t*>(ptr) = _arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t*>(ptr) = _arg2;
    ptr += 1;

    return 4;
}



uint8_t Interpretator::do_lrem(uint8_t *ptr) {
    ptr++;



    uint64_t &_arg0 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    uint64_t &_arg1 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    uint64_t &_arg2 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    _arg2 = _arg0 % _arg1;
    return 4;
}

uint8_t Interpretator::create_lrem(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 4) {
        throw std::runtime_error("Out of range in create_lrem");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 113;
    ptr++;


    *reinterpret_cast<uint8_t*>(ptr) = _arg0;
    ptr += 1;

    *reinterpret_cast<uint8_t*>(ptr) = _arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t*>(ptr) = _arg2;
    ptr += 1;

    return 4;
}



uint8_t Interpretator::do_br_licmpeq(uint8_t *ptr) {
    ptr++;



    const uint64_t _arg0 = *reinterpret_cast<LongType *>(ptr);
    ptr +=  8;

    uint64_t &_arg1 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    uint64_t &_arg2 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    if (_arg1 == _arg2) { _ip += _arg0; }
    return 11;
}

uint8_t Interpretator::create_br_licmpeq(uint64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 11) {
        throw std::runtime_error("Out of range in create_br_licmpeq");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 153;
    ptr++;


    *reinterpret_cast<uint64_t*>(ptr) = _arg0;
    ptr +=  8;

    *reinterpret_cast<uint8_t*>(ptr) = _arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t*>(ptr) = _arg2;
    ptr += 1;

    return 11;
}



uint8_t Interpretator::do_br_licmpne(uint8_t *ptr) {
    ptr++;



    const uint64_t _arg0 = *reinterpret_cast<LongType *>(ptr);
    ptr +=  8;

    uint64_t &_arg1 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    uint64_t &_arg2 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    if (_arg1 != _arg2) { _ip += _arg0; }
    return 11;
}

uint8_t Interpretator::create_br_licmpne(uint64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 11) {
        throw std::runtime_error("Out of range in create_br_licmpne");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 154;
    ptr++;


    *reinterpret_cast<uint64_t*>(ptr) = _arg0;
    ptr +=  8;

    *reinterpret_cast<uint8_t*>(ptr) = _arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t*>(ptr) = _arg2;
    ptr += 1;

    return 11;
}



uint8_t Interpretator::do_br_licmplt(uint8_t *ptr) {
    ptr++;



    const uint64_t _arg0 = *reinterpret_cast<LongType *>(ptr);
    ptr +=  8;

    uint64_t &_arg1 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    uint64_t &_arg2 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    if (_arg1 < _arg2) { _ip += _arg0; }
    return 11;
}

uint8_t Interpretator::create_br_licmplt(uint64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 11) {
        throw std::runtime_error("Out of range in create_br_licmplt");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 155;
    ptr++;


    *reinterpret_cast<uint64_t*>(ptr) = _arg0;
    ptr +=  8;

    *reinterpret_cast<uint8_t*>(ptr) = _arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t*>(ptr) = _arg2;
    ptr += 1;

    return 11;
}



uint8_t Interpretator::do_br_licmpge(uint8_t *ptr) {
    ptr++;



    const uint64_t _arg0 = *reinterpret_cast<LongType *>(ptr);
    ptr +=  8;

    uint64_t &_arg1 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    uint64_t &_arg2 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    if (_arg1 >= _arg2) { _ip += _arg0; }
    return 11;
}

uint8_t Interpretator::create_br_licmpge(uint64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 11) {
        throw std::runtime_error("Out of range in create_br_licmpge");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 156;
    ptr++;


    *reinterpret_cast<uint64_t*>(ptr) = _arg0;
    ptr +=  8;

    *reinterpret_cast<uint8_t*>(ptr) = _arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t*>(ptr) = _arg2;
    ptr += 1;

    return 11;
}



uint8_t Interpretator::do_br_licmpgt(uint8_t *ptr) {
    ptr++;



    const uint64_t _arg0 = *reinterpret_cast<LongType *>(ptr);
    ptr +=  8;

    uint64_t &_arg1 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    uint64_t &_arg2 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    if (_arg1 > _arg2) { _ip += _arg0; }
    return 11;
}

uint8_t Interpretator::create_br_licmpgt(uint64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 11) {
        throw std::runtime_error("Out of range in create_br_licmpgt");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 157;
    ptr++;


    *reinterpret_cast<uint64_t*>(ptr) = _arg0;
    ptr +=  8;

    *reinterpret_cast<uint8_t*>(ptr) = _arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t*>(ptr) = _arg2;
    ptr += 1;

    return 11;
}



uint8_t Interpretator::do_br_licmple(uint8_t *ptr) {
    ptr++;



    const uint64_t _arg0 = *reinterpret_cast<LongType *>(ptr);
    ptr +=  8;

    uint64_t &_arg1 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    uint64_t &_arg2 = GetRegRef(*reinterpret_cast<RegType *>(ptr));
    ptr += 1;

    if (_arg1 <= _arg2) { _ip += _arg0; }
    return 11;
}

uint8_t Interpretator::create_br_licmple(uint64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 11) {
        throw std::runtime_error("Out of range in create_br_licmple");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 158;
    ptr++;


    *reinterpret_cast<uint64_t*>(ptr) = _arg0;
    ptr +=  8;

    *reinterpret_cast<uint8_t*>(ptr) = _arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t*>(ptr) = _arg2;
    ptr += 1;

    return 11;
}



uint8_t Interpretator::do_br(uint8_t *ptr) {
    ptr++;



    const uint64_t _arg0 = *reinterpret_cast<LongType *>(ptr);
    ptr +=  8;

    _ip += _arg0;
    return 9;
}

uint8_t Interpretator::create_br(uint64_t arg0, uint8_t *ptr, uint64_t size) {
    if (size < 9) {
        throw std::runtime_error("Out of range in create_br");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 167;
    ptr++;


    *reinterpret_cast<uint64_t*>(ptr) = _arg0;
    ptr +=  8;

    return 9;
}



uint8_t Interpretator::do_lreturn(uint8_t *ptr) {
    ptr++;



    const uint64_t _arg0 = *reinterpret_cast<LongType *>(ptr);
    ptr +=  8;

    return_value = _arg0;
    return 9;
}

uint8_t Interpretator::create_lreturn(uint64_t arg0, uint8_t *ptr, uint64_t size) {
    if (size < 9) {
        throw std::runtime_error("Out of range in create_lreturn");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 173;
    ptr++;


    *reinterpret_cast<uint64_t*>(ptr) = _arg0;
    ptr +=  8;

    return 9;
}


