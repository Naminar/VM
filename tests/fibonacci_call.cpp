#include "interpretator.h"

int main() {
  Interpretator interpretator;

  Frame *start_frame = new Frame(2);
  interpretator._frames.push(start_frame);
  interpretator._current_frame = start_frame;

  int64_t *start_bytecode = reinterpret_cast<int64_t *>(calloc(1000, 1));
  interpretator.SetPtr(start_bytecode, 1000, start_bytecode);
  // r0 = 10
  interpretator.create_lmov(10, 0);
  // call fibonacci(r0)
  int64_t v[] = {0};
  interpretator.create_call(0, 1, v);
  // r0 = _return_value
  interpretator.create_lmov_return(0);
  // exit(r0)
  interpretator.create_exit(0);

  int64_t func_id = interpretator.CreateFunction("fibonacci", 1 /* n_args */, 6 /* n_regs */);
  Function *function = interpretator.GetFuncById(func_id);
  function->_bytecode = (int64_t *)calloc(10000, 1);
  function->_bytecode_len = 10000;
  interpretator.SetPtr(function->_bytecode, function->_bytecode_len, function->_bytecode);

  // r0 = n
  // r1 = 1
  interpretator.create_lmov(1, 1);
  // r2 = 2
  interpretator.create_lmov(2, 2);
  // if r0 > r2 jump over return
  interpretator.create_br_licmpgt(2, 0, 2);
  // return r1
  interpretator.create_lreturn(1);
  // r3 = r0 - r1
  interpretator.create_lsub(0, 1, 3);
  // call fibonacci(r3)
  int64_t v1[] = {3};
  interpretator.create_call(0, 1, v1);
  // r3 = return value
  interpretator.create_lmov_return(3);
  // r4 = r0 - r2
  interpretator.create_lsub(0, 2, 4);
  // call fibonacci(r3)
  int64_t v2[] = {4};
  interpretator.create_call(0, 1, v2);
  // r4 = return value
  interpretator.create_lmov_return(4);
  // r5 = r3 + r4
  interpretator.create_ladd(3, 4, 5);
  interpretator.create_lreturn(5);

  std::cout << "------------------------" << std::endl;
  interpretator.SetPtr(function->_bytecode, function->_bytecode_len, function->_bytecode);
  interpretator.Dump();
  std::cout << "------------------------" << std::endl;
  interpretator.SetPtr(start_bytecode, 1000, start_bytecode);
  interpretator.Dump();
  std::cout << "------------------------" << std::endl;

  interpretator.SetPtr(start_bytecode, 1000, start_bytecode);
  int64_t rc = interpretator.Run(false);
  std::cout << "---\nResult: " << rc << std::endl;
}