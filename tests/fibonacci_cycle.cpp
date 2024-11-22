#include "interpretator.h"

int main() {
    Interpretator interpretator;

    int64_t *start_bytecode = reinterpret_cast<int64_t *>(calloc(1000, 1));
    interpretator.SetPtr(start_bytecode, 1000, start_bytecode);
    std::vector<int64_t> v;
    v.push_back(0);
    v.push_back(1);

    // r0 = 1
    interpretator.create_lmov(1, 0);
    // r1 = 1
    interpretator.create_lmov(1, 1);
    // counter = 0
    interpretator.create_lmov(0, 3);
    // max_counter = 10 - 3 (10 элемент в цикле будет 7)
    interpretator.create_lmov(7, 4);
    // constant = 1
    interpretator.create_lmov(1, 5);
    // r3 = r0 + r1
    interpretator.create_ladd(0, 1, 2);
    // r0 = r1
    interpretator.create_rmov(1, 0);
    // r1 = r2
    interpretator.create_rmov(2, 1);
    // counter += constant + counter
    interpretator.create_ladd(5, 3, 3);
    // continue if counter < maxcounter
    interpretator.create_br_licmple(-18, 3, 4);
    // exit(0)
    interpretator.create_exit(0);


    Frame* start_frame = new Frame(6);
    interpretator._frames.push(start_frame);
    interpretator._current_frame = start_frame;


    std::cout << "------------------------" << std::endl;
    interpretator.SetPtr(start_bytecode, 1000, start_bytecode);
    interpretator.Dump();
    std::cout << "------------------------" << std::endl;

    interpretator.SetPtr(start_bytecode, 1000, start_bytecode);
    interpretator.Run(true);
}