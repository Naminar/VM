# cmake -GNinja ..
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(VM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(VM_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(ISA_ROOT_DIR "${VM_ROOT_DIR}/isa")
set(RUNTIME_CORE_ROOT_DIR "${VM_ROOT_DIR}/runtime_core")
set(TESTS_ROOT_DIR "${VM_ROOT_DIR}/tests")


add_subdirectory(${ISA_ROOT_DIR})
add_subdirectory(${RUNTIME_CORE_ROOT_DIR})


add_custom_target(clang-force-format
    COMMAND find "${ISA_ROOT_DIR}" "${RUNTIME_CORE_ROOT_DIR}" "${TESTS_ROOT_DIR}"
                -name "*.cpp" -exec clang-format -style='{ColumnLimit: 120}' -i {} +
)