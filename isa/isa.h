#include <cstdint>
#include <cstring>
#include <iostream>

typedef uint8_t RegType;
typedef uint64_t LongType;




class nop {
  public:
    nop(void *ptr);
    nop();
    uint8_t Decode();
    void Run() const;
    uint8_t Dump(void *ptr) const;

  private:
    
    uint8_t opcode = 0;
    void *bytecode = nullptr;
    uint8_t bytecode_len = 1;
};



class lmov {
  public:
    lmov(void *ptr);
    lmov(LongType arg0, RegType arg1);
    uint8_t Decode();
    void Run() const;
    uint8_t Dump(void *ptr) const;

  private:
    LongType _arg0 = 0;
    RegType _arg1 = 0;
    
    uint8_t opcode = 2;
    void *bytecode = nullptr;
    uint8_t bytecode_len = 10;
};



class ladd {
  public:
    ladd(void *ptr);
    ladd(RegType arg0, RegType arg1, RegType arg2);
    uint8_t Decode();
    void Run() const;
    uint8_t Dump(void *ptr) const;

  private:
    RegType _arg0 = 0;
    RegType _arg1 = 0;
    RegType _arg2 = 0;
    
    uint8_t opcode = 97;
    void *bytecode = nullptr;
    uint8_t bytecode_len = 4;
};



class lsub {
  public:
    lsub(void *ptr);
    lsub(RegType arg0, RegType arg1, RegType arg2);
    uint8_t Decode();
    void Run() const;
    uint8_t Dump(void *ptr) const;

  private:
    RegType _arg0 = 0;
    RegType _arg1 = 0;
    RegType _arg2 = 0;
    
    uint8_t opcode = 101;
    void *bytecode = nullptr;
    uint8_t bytecode_len = 4;
};



class lmul {
  public:
    lmul(void *ptr);
    lmul(RegType arg0, RegType arg1, RegType arg2);
    uint8_t Decode();
    void Run() const;
    uint8_t Dump(void *ptr) const;

  private:
    RegType _arg0 = 0;
    RegType _arg1 = 0;
    RegType _arg2 = 0;
    
    uint8_t opcode = 105;
    void *bytecode = nullptr;
    uint8_t bytecode_len = 4;
};



class ldiv {
  public:
    ldiv(void *ptr);
    ldiv(RegType arg0, RegType arg1, RegType arg2);
    uint8_t Decode();
    void Run() const;
    uint8_t Dump(void *ptr) const;

  private:
    RegType _arg0 = 0;
    RegType _arg1 = 0;
    RegType _arg2 = 0;
    
    uint8_t opcode = 109;
    void *bytecode = nullptr;
    uint8_t bytecode_len = 4;
};



class lrem {
  public:
    lrem(void *ptr);
    lrem(RegType arg0, RegType arg1, RegType arg2);
    uint8_t Decode();
    void Run() const;
    uint8_t Dump(void *ptr) const;

  private:
    RegType _arg0 = 0;
    RegType _arg1 = 0;
    RegType _arg2 = 0;
    
    uint8_t opcode = 113;
    void *bytecode = nullptr;
    uint8_t bytecode_len = 4;
};



class br_licmpeq {
  public:
    br_licmpeq(void *ptr);
    br_licmpeq(LongType arg0, RegType arg1, RegType arg2);
    uint8_t Decode();
    void Run() const;
    uint8_t Dump(void *ptr) const;

  private:
    LongType _arg0 = 0;
    RegType _arg1 = 0;
    RegType _arg2 = 0;
    
    uint8_t opcode = 153;
    void *bytecode = nullptr;
    uint8_t bytecode_len = 11;
};



class br_licmpne {
  public:
    br_licmpne(void *ptr);
    br_licmpne(LongType arg0, RegType arg1, RegType arg2);
    uint8_t Decode();
    void Run() const;
    uint8_t Dump(void *ptr) const;

  private:
    LongType _arg0 = 0;
    RegType _arg1 = 0;
    RegType _arg2 = 0;
    
    uint8_t opcode = 154;
    void *bytecode = nullptr;
    uint8_t bytecode_len = 11;
};



class br_licmplt {
  public:
    br_licmplt(void *ptr);
    br_licmplt(LongType arg0, RegType arg1, RegType arg2);
    uint8_t Decode();
    void Run() const;
    uint8_t Dump(void *ptr) const;

  private:
    LongType _arg0 = 0;
    RegType _arg1 = 0;
    RegType _arg2 = 0;
    
    uint8_t opcode = 155;
    void *bytecode = nullptr;
    uint8_t bytecode_len = 11;
};



class br_licmpge {
  public:
    br_licmpge(void *ptr);
    br_licmpge(LongType arg0, RegType arg1, RegType arg2);
    uint8_t Decode();
    void Run() const;
    uint8_t Dump(void *ptr) const;

  private:
    LongType _arg0 = 0;
    RegType _arg1 = 0;
    RegType _arg2 = 0;
    
    uint8_t opcode = 156;
    void *bytecode = nullptr;
    uint8_t bytecode_len = 11;
};



class br_licmpgt {
  public:
    br_licmpgt(void *ptr);
    br_licmpgt(LongType arg0, RegType arg1, RegType arg2);
    uint8_t Decode();
    void Run() const;
    uint8_t Dump(void *ptr) const;

  private:
    LongType _arg0 = 0;
    RegType _arg1 = 0;
    RegType _arg2 = 0;
    
    uint8_t opcode = 157;
    void *bytecode = nullptr;
    uint8_t bytecode_len = 11;
};



class br_licmple {
  public:
    br_licmple(void *ptr);
    br_licmple(LongType arg0, RegType arg1, RegType arg2);
    uint8_t Decode();
    void Run() const;
    uint8_t Dump(void *ptr) const;

  private:
    LongType _arg0 = 0;
    RegType _arg1 = 0;
    RegType _arg2 = 0;
    
    uint8_t opcode = 158;
    void *bytecode = nullptr;
    uint8_t bytecode_len = 11;
};



class br {
  public:
    br(void *ptr);
    br(LongType arg0);
    uint8_t Decode();
    void Run() const;
    uint8_t Dump(void *ptr) const;

  private:
    LongType _arg0 = 0;
    
    uint8_t opcode = 167;
    void *bytecode = nullptr;
    uint8_t bytecode_len = 9;
};



class lreturn {
  public:
    lreturn(void *ptr);
    lreturn(LongType arg0);
    uint8_t Decode();
    void Run() const;
    uint8_t Dump(void *ptr) const;

  private:
    LongType _arg0 = 0;
    
    uint8_t opcode = 173;
    void *bytecode = nullptr;
    uint8_t bytecode_len = 9;
};


