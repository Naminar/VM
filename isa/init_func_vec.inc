
    DoInstr[0] = [this](uint8_t* ptr) { return this->do_nop(ptr); };
    DumpInstr[0] = [this](uint8_t* ptr) { return this->dump_nop(ptr); };

    DoInstr[2] = [this](uint8_t* ptr) { return this->do_lmov(ptr); };
    DumpInstr[2] = [this](uint8_t* ptr) { return this->dump_lmov(ptr); };

    DoInstr[97] = [this](uint8_t* ptr) { return this->do_ladd(ptr); };
    DumpInstr[97] = [this](uint8_t* ptr) { return this->dump_ladd(ptr); };

    DoInstr[101] = [this](uint8_t* ptr) { return this->do_lsub(ptr); };
    DumpInstr[101] = [this](uint8_t* ptr) { return this->dump_lsub(ptr); };

    DoInstr[105] = [this](uint8_t* ptr) { return this->do_lmul(ptr); };
    DumpInstr[105] = [this](uint8_t* ptr) { return this->dump_lmul(ptr); };

    DoInstr[109] = [this](uint8_t* ptr) { return this->do_ldiv(ptr); };
    DumpInstr[109] = [this](uint8_t* ptr) { return this->dump_ldiv(ptr); };

    DoInstr[113] = [this](uint8_t* ptr) { return this->do_lrem(ptr); };
    DumpInstr[113] = [this](uint8_t* ptr) { return this->dump_lrem(ptr); };

    DoInstr[153] = [this](uint8_t* ptr) { return this->do_br_licmpeq(ptr); };
    DumpInstr[153] = [this](uint8_t* ptr) { return this->dump_br_licmpeq(ptr); };

    DoInstr[154] = [this](uint8_t* ptr) { return this->do_br_licmpne(ptr); };
    DumpInstr[154] = [this](uint8_t* ptr) { return this->dump_br_licmpne(ptr); };

    DoInstr[155] = [this](uint8_t* ptr) { return this->do_br_licmplt(ptr); };
    DumpInstr[155] = [this](uint8_t* ptr) { return this->dump_br_licmplt(ptr); };

    DoInstr[156] = [this](uint8_t* ptr) { return this->do_br_licmpge(ptr); };
    DumpInstr[156] = [this](uint8_t* ptr) { return this->dump_br_licmpge(ptr); };

    DoInstr[157] = [this](uint8_t* ptr) { return this->do_br_licmpgt(ptr); };
    DumpInstr[157] = [this](uint8_t* ptr) { return this->dump_br_licmpgt(ptr); };

    DoInstr[158] = [this](uint8_t* ptr) { return this->do_br_licmple(ptr); };
    DumpInstr[158] = [this](uint8_t* ptr) { return this->dump_br_licmple(ptr); };

    DoInstr[167] = [this](uint8_t* ptr) { return this->do_br(ptr); };
    DumpInstr[167] = [this](uint8_t* ptr) { return this->dump_br(ptr); };

    DoInstr[173] = [this](uint8_t* ptr) { return this->do_lreturn(ptr); };
    DumpInstr[173] = [this](uint8_t* ptr) { return this->dump_lreturn(ptr); };
