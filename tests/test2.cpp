#include "interpretator.h"

int main() {
    Interpretator i;
    i._bytecode = reinterpret_cast<uint8_t *>(calloc(10000, 1));
    i._bytecode_len = 100;
    i._ptr = i._bytecode;
    Frame f(3);
    i._frames.push(f);
    uint8_t * ptr = i._bytecode;
    // std::cout << "ptr: " << reinterpret_cast<uint64_t>(ptr) << std::endl;
    // ptr_history.push_back(reinterpret_cast<uint64_t>(ptr));
    i.create_lmov(1, 1);
    i.create_ladd(1, 1, 1);
    i.create_ladd(1, 1, 1);
    i.create_ladd(1, 1, 1);
    i.create_ladd(1, 1, 2);
    i.create_ldiv(1, 1, 1);
    i.create_ldiv(1, 1, 1);
    i.create_exit(0);

    i._ptr = i._bytecode;
    i.Dump();
    i._ptr = i._bytecode;
    i.Run();
}