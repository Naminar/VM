add_library(interpretator interpretator.cpp)
target_include_directories(interpretator PUBLIC ${CMAKE_BINARY_DIR}/generated)
add_dependencies(interpretator gen_isa)
