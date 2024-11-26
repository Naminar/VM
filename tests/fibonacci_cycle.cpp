#include "interpretator.h"
#include "builder.h"

int main() {
    Interpretator interpretator;
    Builder builder;

    int64_t *start_bytecode = reinterpret_cast<int64_t *>(calloc(1000, 1));
    interpretator._current_frame->SetPtr(start_bytecode, 1000, start_bytecode);
    builder.SetPtr(start_bytecode, 1000, start_bytecode);

    // r0 = 1
    builder.create_lmov(1, 0);
    // r1 = 1
    builder.create_lmov(1, 1);
    // counter = 0
    builder.create_lmov(0, 3);
    // max_counter = 10 - 3 (10 fibonacci element equals to cycle 7 times)
    builder.create_lmov(7, 4);
    // constant = 1
    builder.create_lmov(1, 5);
    // r2 = r0 + r1
    builder.create_ladd(0, 1, 2);
    // r0 = r1
    builder.create_rmov(1, 0);
    // r1 = r2
    builder.create_rmov(2, 1);
    // counter += constant + counter
    builder.create_ladd(5, 3, 3);
    // continue if counter < maxcounter
    builder.create_br_licmple(-18, 3, 4);
    // exit(r2)
    builder.create_exit(2);

    Frame *start_frame = new Frame(6);
    interpretator._frames.push(start_frame);
    interpretator._current_frame = start_frame;

    std::cout << "------------------------" << std::endl;
    interpretator._current_frame->SetPtr(start_bytecode, 1000, start_bytecode);
    interpretator.Dump();
    std::cout << "------------------------" << std::endl;

    interpretator._current_frame->SetPtr(start_bytecode, 1000, start_bytecode);
      int64_t rc = interpretator.Run();
      std::cout << "---\nResult: " << rc << std::endl;
}