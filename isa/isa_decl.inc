
    uint8_t do_nop(uint8_t *ptr);
    uint8_t dump_nop(uint8_t *ptr);
    uint8_t create_nop(uint8_t *ptr, uint64_t size);

    uint8_t do_lmov(uint8_t *ptr);
    uint8_t dump_lmov(uint8_t *ptr);
    uint8_t create_lmov(int64_t arg0, uint8_t arg1, uint8_t *ptr, uint64_t size);

    uint8_t do_ladd(uint8_t *ptr);
    uint8_t dump_ladd(uint8_t *ptr);
    uint8_t create_ladd(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_lsub(uint8_t *ptr);
    uint8_t dump_lsub(uint8_t *ptr);
    uint8_t create_lsub(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_lmul(uint8_t *ptr);
    uint8_t dump_lmul(uint8_t *ptr);
    uint8_t create_lmul(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_ldiv(uint8_t *ptr);
    uint8_t dump_ldiv(uint8_t *ptr);
    uint8_t create_ldiv(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_lrem(uint8_t *ptr);
    uint8_t dump_lrem(uint8_t *ptr);
    uint8_t create_lrem(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_br_licmpeq(uint8_t *ptr);
    uint8_t dump_br_licmpeq(uint8_t *ptr);
    uint8_t create_br_licmpeq(int64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_br_licmpne(uint8_t *ptr);
    uint8_t dump_br_licmpne(uint8_t *ptr);
    uint8_t create_br_licmpne(int64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_br_licmplt(uint8_t *ptr);
    uint8_t dump_br_licmplt(uint8_t *ptr);
    uint8_t create_br_licmplt(int64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_br_licmpge(uint8_t *ptr);
    uint8_t dump_br_licmpge(uint8_t *ptr);
    uint8_t create_br_licmpge(int64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_br_licmpgt(uint8_t *ptr);
    uint8_t dump_br_licmpgt(uint8_t *ptr);
    uint8_t create_br_licmpgt(int64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_br_licmple(uint8_t *ptr);
    uint8_t dump_br_licmple(uint8_t *ptr);
    uint8_t create_br_licmple(int64_t arg0, uint8_t arg1, uint8_t arg2, uint8_t *ptr, uint64_t size);

    uint8_t do_br(uint8_t *ptr);
    uint8_t dump_br(uint8_t *ptr);
    uint8_t create_br(int64_t arg0, uint8_t *ptr, uint64_t size);

    uint8_t do_lreturn(uint8_t *ptr);
    uint8_t dump_lreturn(uint8_t *ptr);
    uint8_t create_lreturn(int64_t arg0, uint8_t *ptr, uint64_t size);
