#include "interpretator.h"

int main() {
    Interpretator i;
    i._bytecode = reinterpret_cast<uint8_t *>(calloc(10000, 1));
    Frame f(100);
    i._frames.push(f);
    std::vector<uint64_t> ptr_history;
    uint8_t * ptr = i._bytecode;
    // std::cout << "ptr: " << reinterpret_cast<uint64_t>(ptr) << std::endl;
    // ptr_history.push_back(reinterpret_cast<uint64_t>(ptr));
    ptr += i.create_ladd(1, 1, 1, ptr, 100);
    std::cout << "ptr: " << reinterpret_cast<uint64_t>(ptr) << std::endl;
    ptr_history.push_back(reinterpret_cast<uint64_t>(ptr));
    ptr += i.create_ladd(1, 1, 1, ptr, 100);
    std::cout << "ptr: " << reinterpret_cast<uint64_t>(ptr) << std::endl;
    ptr_history.push_back(reinterpret_cast<uint64_t>(ptr));
    ptr += i.create_ladd(1, 1, 1, ptr, 100);
    std::cout << "ptr: " << reinterpret_cast<uint64_t>(ptr) << std::endl;
    ptr_history.push_back(reinterpret_cast<uint64_t>(ptr));
    ptr += i.create_ladd(1, 1, 1, ptr, 100);
    std::cout << "ptr: " << reinterpret_cast<uint64_t>(ptr) << std::endl;
    ptr_history.push_back(reinterpret_cast<uint64_t>(ptr));
    ptr += i.create_ldiv(1, 1, 1, ptr, 100);
    std::cout << "ptr: " << reinterpret_cast<uint64_t>(ptr) << std::endl;
    ptr_history.push_back(reinterpret_cast<uint64_t>(ptr));
    ptr += i.create_ldiv(1, 5, 1, ptr, 100);
    std::cout << "ptr: " << reinterpret_cast<uint64_t>(ptr) << std::endl;
    ptr_history.push_back(reinterpret_cast<uint64_t>(ptr));

    ptr = i._bytecode;
    int ind = 0;
    while (*ptr != 0) {
        ptr += i.DumpInstr[*ptr](ptr);
        if (ptr_history[ind] != reinterpret_cast<uint64_t>(ptr)) {
            std::cout << "Current ptr: " << reinterpret_cast<uint64_t>(ptr) << ", history: " << ptr_history[ind] << std::endl;
            throw std::runtime_error("Bad ptr!");
        }
        ind++;
    }
}

int64_t &Interpretator::GetRegRef(const uint64_t n) {
    Frame &frame = _frames.top();
    if (n > frame._n_regs - 1) {
        throw std::runtime_error("Out of bounds in registers.");
    }
    return frame._regs[n];
}

#include "isa_impl.inc"


Interpretator::Interpretator() {
    DoInstr.resize(256);
    DumpInstr.resize(256);

    for (auto &i : DoInstr) { i = 0; }
    for (auto &i : DumpInstr) { i = 0; }

    #include "init_func_vec.inc"
}
