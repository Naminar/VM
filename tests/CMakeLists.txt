add_executable(test1 test1.cpp)
target_link_libraries(test1 PRIVATE interpretator)
target_include_directories(test1 PRIVATE ${RUNTIME_CORE_ROOT_DIR})


add_executable(test2 test2.cpp)
target_link_libraries(test2 PRIVATE interpretator)
target_include_directories(test2 PRIVATE ${RUNTIME_CORE_ROOT_DIR})


add_executable(fibonacci_cycle fibonacci_cycle.cpp)
target_link_libraries(fibonacci_cycle PRIVATE interpretator)
target_include_directories(fibonacci_cycle PRIVATE ${RUNTIME_CORE_ROOT_DIR})


add_executable(fibonacci_call fibonacci_call.cpp)
target_link_libraries(fibonacci_call PRIVATE interpretator)
target_include_directories(fibonacci_call PRIVATE ${RUNTIME_CORE_ROOT_DIR})
