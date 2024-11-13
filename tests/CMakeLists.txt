add_subdirectory(fibonacci_cycle)
add_subdirectory(fibonacci_recursive)

add_executable(test1 test1.cpp)
target_link_libraries(test1 PRIVATE interpretator)
target_include_directories(test1 PRIVATE ${RUNTIME_CORE_ROOT_DIR})
