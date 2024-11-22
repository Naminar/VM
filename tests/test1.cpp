#include "interpretator.h"

int main() {
    Interpretator i;
    i._bytecode = reinterpret_cast<int64_t *>(calloc(10000, 1));
    Frame f(100);
    i._frames.push(f);
    std::vector<int64_t> ptr_history;
    int64_t * ptr = i._bytecode;
    // std::cout << "ptr: " << reinterpret_cast<int64_t>(ptr) << std::endl;
    // ptr_history.push_back(reinterpret_cast<int64_t>(ptr));
    ptr += i.create_ladd(1, 1, 1, ptr, 100);
    std::cout << "ptr: " << reinterpret_cast<int64_t>(ptr) << std::endl;
    ptr_history.push_back(reinterpret_cast<int64_t>(ptr));
    ptr += i.create_ladd(1, 1, 1, ptr, 100);
    std::cout << "ptr: " << reinterpret_cast<int64_t>(ptr) << std::endl;
    ptr_history.push_back(reinterpret_cast<int64_t>(ptr));
    ptr += i.create_ladd(1, 1, 1, ptr, 100);
    std::cout << "ptr: " << reinterpret_cast<int64_t>(ptr) << std::endl;
    ptr_history.push_back(reinterpret_cast<int64_t>(ptr));
    ptr += i.create_ladd(1, 1, 1, ptr, 100);
    std::cout << "ptr: " << reinterpret_cast<int64_t>(ptr) << std::endl;
    ptr_history.push_back(reinterpret_cast<int64_t>(ptr));
    ptr += i.create_ldiv(1, 1, 1, ptr, 100);
    std::cout << "ptr: " << reinterpret_cast<int64_t>(ptr) << std::endl;
    ptr_history.push_back(reinterpret_cast<int64_t>(ptr));
    ptr += i.create_ldiv(1, 5, 1, ptr, 100);
    std::cout << "ptr: " << reinterpret_cast<int64_t>(ptr) << std::endl;
    ptr_history.push_back(reinterpret_cast<int64_t>(ptr));

    ptr = i._bytecode;
    int ind = 0;
    while (*ptr != 0) {
        ptr += i.DumpInstr[*ptr](ptr);
        if (ptr_history[ind] != reinterpret_cast<int64_t>(ptr)) {
            std::cout << "Current ptr: " << reinterpret_cast<int64_t>(ptr) << ", history: " << ptr_history[ind] << std::endl;
            throw std::runtime_error("Bad ptr!");
        }
        ind++;
    }
}