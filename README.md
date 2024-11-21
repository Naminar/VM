# VM

### How to test
```bash
mkdir build && cd build
cmake -GNinja ..
ninja fibonacci_cycle && ./tests/fibonacci_cycle
ninja fibonacci_call && ./tests/fibonacci_call
```