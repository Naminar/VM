

uint8_t Interpretator::do_nop(uint8_t *ptr) {
    ptr++;



    
    return 1;
}

uint8_t Interpretator::dump_nop(uint8_t *ptr) {
    std::cout << "nop";
    ptr++;



    std::cout << std::endl;
    return 1;
}

uint8_t Interpretator::create_nop(uint8_t *ptr, uint64_t size) {
    if (size < 1) {
        throw std::runtime_error("Out of range in create_nop");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 0;
    ptr++;


    return 1;
}



uint8_t Interpretator::do_lmov(uint8_t *ptr) {
    ptr++;



    const int64_t _arg0 = *reinterpret_cast<int64_t *>(ptr);
    ptr +=  8;

    int64_t &_arg1 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    _arg1 = _arg0;
    return 10;
}

uint8_t Interpretator::dump_lmov(uint8_t *ptr) {
    std::cout << "lmov";
    ptr++;



    std::cout << ", " << static_cast<int64_t>(*reinterpret_cast<int64_t *>(ptr));
    ptr +=  8;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << std::endl;
    return 10;
}

uint8_t Interpretator::create_lmov(int64_t arg0, uint8_t arg1, uint8_t *ptr, uint64_t size) {
    if (size < 10) {
        throw std::runtime_error("Out of range in create_lmov");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 2;
    ptr++;


    *reinterpret_cast<int64_t *>(ptr) = arg0;
    ptr +=  8;

    *reinterpret_cast<uint8_t *>(ptr) = arg1;
    ptr += 1;

    return 10;
}



uint8_t Interpretator::do_ladd(uint8_t *ptr) {
    ptr++;



    int64_t &_arg0 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    int64_t &_arg1 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    int64_t &_arg2 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    _arg2 = _arg0 + _arg1;
    return 4;
}

uint8_t Interpretator::dump_ladd(uint8_t *ptr) {
    std::cout << "ladd";
    ptr++;



    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << std::endl;
    return 4;
}

uint8_t Interpretator::create_ladd(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 4) {
        throw std::runtime_error("Out of range in create_ladd");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 97;
    ptr++;


    *reinterpret_cast<uint8_t *>(ptr) = arg0;
    ptr += 1;

    *reinterpret_cast<uint8_t *>(ptr) = arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t *>(ptr) = arg2;
    ptr += 1;

    return 4;
}



uint8_t Interpretator::do_lsub(uint8_t *ptr) {
    ptr++;



    int64_t &_arg0 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    int64_t &_arg1 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    int64_t &_arg2 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    _arg2 = _arg0 - _arg1;
    return 4;
}

uint8_t Interpretator::dump_lsub(uint8_t *ptr) {
    std::cout << "lsub";
    ptr++;



    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << std::endl;
    return 4;
}

uint8_t Interpretator::create_lsub(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 4) {
        throw std::runtime_error("Out of range in create_lsub");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 101;
    ptr++;


    *reinterpret_cast<uint8_t *>(ptr) = arg0;
    ptr += 1;

    *reinterpret_cast<uint8_t *>(ptr) = arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t *>(ptr) = arg2;
    ptr += 1;

    return 4;
}



uint8_t Interpretator::do_lmul(uint8_t *ptr) {
    ptr++;



    int64_t &_arg0 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    int64_t &_arg1 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    int64_t &_arg2 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    _arg2 = _arg0 * _arg1;
    return 4;
}

uint8_t Interpretator::dump_lmul(uint8_t *ptr) {
    std::cout << "lmul";
    ptr++;



    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << std::endl;
    return 4;
}

uint8_t Interpretator::create_lmul(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 4) {
        throw std::runtime_error("Out of range in create_lmul");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 105;
    ptr++;


    *reinterpret_cast<uint8_t *>(ptr) = arg0;
    ptr += 1;

    *reinterpret_cast<uint8_t *>(ptr) = arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t *>(ptr) = arg2;
    ptr += 1;

    return 4;
}



uint8_t Interpretator::do_ldiv(uint8_t *ptr) {
    ptr++;



    int64_t &_arg0 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    int64_t &_arg1 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    int64_t &_arg2 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    _arg2 = _arg0 / _arg1;
    return 4;
}

uint8_t Interpretator::dump_ldiv(uint8_t *ptr) {
    std::cout << "ldiv";
    ptr++;



    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << std::endl;
    return 4;
}

uint8_t Interpretator::create_ldiv(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 4) {
        throw std::runtime_error("Out of range in create_ldiv");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 109;
    ptr++;


    *reinterpret_cast<uint8_t *>(ptr) = arg0;
    ptr += 1;

    *reinterpret_cast<uint8_t *>(ptr) = arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t *>(ptr) = arg2;
    ptr += 1;

    return 4;
}



uint8_t Interpretator::do_lrem(uint8_t *ptr) {
    ptr++;



    int64_t &_arg0 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    int64_t &_arg1 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    int64_t &_arg2 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    _arg2 = _arg0 % _arg1;
    return 4;
}

uint8_t Interpretator::dump_lrem(uint8_t *ptr) {
    std::cout << "lrem";
    ptr++;



    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << std::endl;
    return 4;
}

uint8_t Interpretator::create_lrem(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 4) {
        throw std::runtime_error("Out of range in create_lrem");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 113;
    ptr++;


    *reinterpret_cast<uint8_t *>(ptr) = arg0;
    ptr += 1;

    *reinterpret_cast<uint8_t *>(ptr) = arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t *>(ptr) = arg2;
    ptr += 1;

    return 4;
}



uint8_t Interpretator::do_br_licmpeq(uint8_t *ptr) {
    ptr++;



    const int64_t _arg0 = *reinterpret_cast<int64_t *>(ptr);
    ptr +=  8;

    int64_t &_arg1 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    int64_t &_arg2 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    if (_arg1 == _arg2) { _ip += _arg0; }
    return 11;
}

uint8_t Interpretator::dump_br_licmpeq(uint8_t *ptr) {
    std::cout << "br_licmpeq";
    ptr++;



    std::cout << ", " << static_cast<int64_t>(*reinterpret_cast<int64_t *>(ptr));
    ptr +=  8;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << std::endl;
    return 11;
}

uint8_t Interpretator::create_br_licmpeq(int64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 11) {
        throw std::runtime_error("Out of range in create_br_licmpeq");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 153;
    ptr++;


    *reinterpret_cast<int64_t *>(ptr) = arg0;
    ptr +=  8;

    *reinterpret_cast<uint8_t *>(ptr) = arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t *>(ptr) = arg2;
    ptr += 1;

    return 11;
}



uint8_t Interpretator::do_br_licmpne(uint8_t *ptr) {
    ptr++;



    const int64_t _arg0 = *reinterpret_cast<int64_t *>(ptr);
    ptr +=  8;

    int64_t &_arg1 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    int64_t &_arg2 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    if (_arg1 != _arg2) { _ip += _arg0; }
    return 11;
}

uint8_t Interpretator::dump_br_licmpne(uint8_t *ptr) {
    std::cout << "br_licmpne";
    ptr++;



    std::cout << ", " << static_cast<int64_t>(*reinterpret_cast<int64_t *>(ptr));
    ptr +=  8;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << std::endl;
    return 11;
}

uint8_t Interpretator::create_br_licmpne(int64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 11) {
        throw std::runtime_error("Out of range in create_br_licmpne");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 154;
    ptr++;


    *reinterpret_cast<int64_t *>(ptr) = arg0;
    ptr +=  8;

    *reinterpret_cast<uint8_t *>(ptr) = arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t *>(ptr) = arg2;
    ptr += 1;

    return 11;
}



uint8_t Interpretator::do_br_licmplt(uint8_t *ptr) {
    ptr++;



    const int64_t _arg0 = *reinterpret_cast<int64_t *>(ptr);
    ptr +=  8;

    int64_t &_arg1 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    int64_t &_arg2 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    if (_arg1 < _arg2) { _ip += _arg0; }
    return 11;
}

uint8_t Interpretator::dump_br_licmplt(uint8_t *ptr) {
    std::cout << "br_licmplt";
    ptr++;



    std::cout << ", " << static_cast<int64_t>(*reinterpret_cast<int64_t *>(ptr));
    ptr +=  8;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << std::endl;
    return 11;
}

uint8_t Interpretator::create_br_licmplt(int64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 11) {
        throw std::runtime_error("Out of range in create_br_licmplt");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 155;
    ptr++;


    *reinterpret_cast<int64_t *>(ptr) = arg0;
    ptr +=  8;

    *reinterpret_cast<uint8_t *>(ptr) = arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t *>(ptr) = arg2;
    ptr += 1;

    return 11;
}



uint8_t Interpretator::do_br_licmpge(uint8_t *ptr) {
    ptr++;



    const int64_t _arg0 = *reinterpret_cast<int64_t *>(ptr);
    ptr +=  8;

    int64_t &_arg1 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    int64_t &_arg2 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    if (_arg1 >= _arg2) { _ip += _arg0; }
    return 11;
}

uint8_t Interpretator::dump_br_licmpge(uint8_t *ptr) {
    std::cout << "br_licmpge";
    ptr++;



    std::cout << ", " << static_cast<int64_t>(*reinterpret_cast<int64_t *>(ptr));
    ptr +=  8;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << std::endl;
    return 11;
}

uint8_t Interpretator::create_br_licmpge(int64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 11) {
        throw std::runtime_error("Out of range in create_br_licmpge");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 156;
    ptr++;


    *reinterpret_cast<int64_t *>(ptr) = arg0;
    ptr +=  8;

    *reinterpret_cast<uint8_t *>(ptr) = arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t *>(ptr) = arg2;
    ptr += 1;

    return 11;
}



uint8_t Interpretator::do_br_licmpgt(uint8_t *ptr) {
    ptr++;



    const int64_t _arg0 = *reinterpret_cast<int64_t *>(ptr);
    ptr +=  8;

    int64_t &_arg1 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    int64_t &_arg2 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    if (_arg1 > _arg2) { _ip += _arg0; }
    return 11;
}

uint8_t Interpretator::dump_br_licmpgt(uint8_t *ptr) {
    std::cout << "br_licmpgt";
    ptr++;



    std::cout << ", " << static_cast<int64_t>(*reinterpret_cast<int64_t *>(ptr));
    ptr +=  8;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << std::endl;
    return 11;
}

uint8_t Interpretator::create_br_licmpgt(int64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 11) {
        throw std::runtime_error("Out of range in create_br_licmpgt");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 157;
    ptr++;


    *reinterpret_cast<int64_t *>(ptr) = arg0;
    ptr +=  8;

    *reinterpret_cast<uint8_t *>(ptr) = arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t *>(ptr) = arg2;
    ptr += 1;

    return 11;
}



uint8_t Interpretator::do_br_licmple(uint8_t *ptr) {
    ptr++;



    const int64_t _arg0 = *reinterpret_cast<int64_t *>(ptr);
    ptr +=  8;

    int64_t &_arg1 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    int64_t &_arg2 = GetRegRef(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    if (_arg1 <= _arg2) { _ip += _arg0; }
    return 11;
}

uint8_t Interpretator::dump_br_licmple(uint8_t *ptr) {
    std::cout << "br_licmple";
    ptr++;



    std::cout << ", " << static_cast<int64_t>(*reinterpret_cast<int64_t *>(ptr));
    ptr +=  8;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << ", r" << static_cast<int64_t>(*reinterpret_cast<uint8_t *>(ptr));
    ptr += 1;

    std::cout << std::endl;
    return 11;
}

uint8_t Interpretator::create_br_licmple(int64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size) {
    if (size < 11) {
        throw std::runtime_error("Out of range in create_br_licmple");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 158;
    ptr++;


    *reinterpret_cast<int64_t *>(ptr) = arg0;
    ptr +=  8;

    *reinterpret_cast<uint8_t *>(ptr) = arg1;
    ptr += 1;

    *reinterpret_cast<uint8_t *>(ptr) = arg2;
    ptr += 1;

    return 11;
}



uint8_t Interpretator::do_br(uint8_t *ptr) {
    ptr++;



    const int64_t _arg0 = *reinterpret_cast<int64_t *>(ptr);
    ptr +=  8;

    _ip += _arg0;
    return 9;
}

uint8_t Interpretator::dump_br(uint8_t *ptr) {
    std::cout << "br";
    ptr++;



    std::cout << ", " << static_cast<int64_t>(*reinterpret_cast<int64_t *>(ptr));
    ptr +=  8;

    std::cout << std::endl;
    return 9;
}

uint8_t Interpretator::create_br(int64_t arg0, uint8_t *ptr, uint64_t size) {
    if (size < 9) {
        throw std::runtime_error("Out of range in create_br");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 167;
    ptr++;


    *reinterpret_cast<int64_t *>(ptr) = arg0;
    ptr +=  8;

    return 9;
}



uint8_t Interpretator::do_lreturn(uint8_t *ptr) {
    ptr++;



    const int64_t _arg0 = *reinterpret_cast<int64_t *>(ptr);
    ptr +=  8;

    _return_value = _arg0;
    return 9;
}

uint8_t Interpretator::dump_lreturn(uint8_t *ptr) {
    std::cout << "lreturn";
    ptr++;



    std::cout << ", " << static_cast<int64_t>(*reinterpret_cast<int64_t *>(ptr));
    ptr +=  8;

    std::cout << std::endl;
    return 9;
}

uint8_t Interpretator::create_lreturn(int64_t arg0, uint8_t *ptr, uint64_t size) {
    if (size < 9) {
        throw std::runtime_error("Out of range in create_lreturn");
    }

    *reinterpret_cast<uint8_t*>(ptr) = 173;
    ptr++;


    *reinterpret_cast<int64_t *>(ptr) = arg0;
    ptr +=  8;

    return 9;
}


