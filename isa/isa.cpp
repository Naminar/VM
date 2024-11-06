
    void do_nop() {
        
    }

    void do_lmov() {
        GetReg() = GetLong();
    }

    void do_ladd() {
        GetReg() = GetReg() + GetReg();
    }

    void do_lsub() {
        GetReg() = GetReg() - GetReg();
    }

    void do_lmul() {
        GetReg() = GetReg() * GetReg();
    }

    void do_ldiv() {
        GetReg() = GetReg() / GetReg();
    }

    void do_lrem() {
        GetReg() = GetReg() % GetReg();
    }

    void do_br_licmpeq() {
        if (GetReg() == GetReg()) { GetIP() += GetLong(); }
    }

    void do_br_licmpne() {
        if (GetReg() != GetReg()) { GetIP() += GetLong(); }
    }

    void do_br_licmplt() {
        if (GetReg() < GetReg()) { GetIP() += GetLong(); }
    }

    void do_br_licmpge() {
        if (GetReg() >= GetReg()) { GetIP() += GetLong(); }
    }

    void do_br_licmpgt() {
        if (GetReg() > GetReg()) { GetIP() += GetLong(); }
    }

    void do_br_licmple() {
        if (GetReg() <= GetReg()) { GetIP() += GetLong(); }
    }

    void do_br() {
        GetIP() += GetLong();
    }

    void do_lreturn() {
        GetRetVal() = GetLong();
    }
