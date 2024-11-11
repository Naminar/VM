#include <string>


class Interpretator {
  public:
    IP = 0;
    RET_VAL = 0;
    REG_FILE[128];

    void *bytecode = nullptr;

    void Run(void *ptr, uint64_t len) {
        bytecode = ptr;

        while (IP < bytecode + len) {
            
        }
    }
};