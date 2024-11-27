add_executable(fibonacci_cycle fibonacci_cycle.cpp)
target_link_libraries(fibonacci_cycle PRIVATE isa)
target_include_directories(fibonacci_cycle PRIVATE ${RUNTIME_CORE_ROOT_DIR})


add_executable(fibonacci_call fibonacci_call.cpp)
target_link_libraries(fibonacci_call PRIVATE isa)
target_include_directories(fibonacci_call PRIVATE ${RUNTIME_CORE_ROOT_DIR})
