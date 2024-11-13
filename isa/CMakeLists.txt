
set(GEN_DIR ${CMAKE_BINARY_DIR}/generated)
make_directory(${GEN_DIR})

add_custom_target(gen_isa
    COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/isa_cpp_generator.py ${CMAKE_CURRENT_SOURCE_DIR} ${GEN_DIR}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    SOURCES isa_cpp_generator.py
)
