
    uint8_t do_nop(uint8_t *ptr);
    uint8_t create_nop(, uint8_t *ptr, uint64_t size);

    uint8_t do_lmov(uint8_t *ptr);
    uint8_t create_lmov(uint64_t arg0, uint8_t arg1, uint8_t *ptr, uint64_t size);

    uint8_t do_ladd(uint8_t *ptr);
    uint8_t create_ladd(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_lsub(uint8_t *ptr);
    uint8_t create_lsub(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_lmul(uint8_t *ptr);
    uint8_t create_lmul(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_ldiv(uint8_t *ptr);
    uint8_t create_ldiv(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_lrem(uint8_t *ptr);
    uint8_t create_lrem(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_br_licmpeq(uint8_t *ptr);
    uint8_t create_br_licmpeq(uint64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_br_licmpne(uint8_t *ptr);
    uint8_t create_br_licmpne(uint64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_br_licmplt(uint8_t *ptr);
    uint8_t create_br_licmplt(uint64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_br_licmpge(uint8_t *ptr);
    uint8_t create_br_licmpge(uint64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_br_licmpgt(uint8_t *ptr);
    uint8_t create_br_licmpgt(uint64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_br_licmple(uint8_t *ptr);
    uint8_t create_br_licmple(uint64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_br(uint8_t *ptr);
    uint8_t create_br(uint64_t arg0, uint8_t *ptr, uint64_t size);

    uint8_t do_lreturn(uint8_t *ptr);
    uint8_t create_lreturn(uint64_t arg0, uint8_t *ptr, uint64_t size);
