
set(GEN_DIR ${CMAKE_BINARY_DIR}/generated)
make_directory(${GEN_DIR})

set(GENERATED_INC
    ${CMAKE_BINARY_DIR}/generated/init_func_vec.inc
    ${CMAKE_BINARY_DIR}/generated/isa_decl.inc
    ${CMAKE_BINARY_DIR}/generated/isa_impl.inc
)

add_custom_command(
    OUTPUT ${GENERATED_INC}
    COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/isa_cpp_generator.py ${CMAKE_CURRENT_SOURCE_DIR} ${GEN_DIR}
    COMMENT "Generating isa ..."
    DEPENDS json/isa.json isa_cpp_generator.py
)

# add_custom_target(gen_isa
#     COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/isa_cpp_generator.py ${CMAKE_CURRENT_SOURCE_DIR} ${GEN_DIR}
#     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#     SOURCES isa_cpp_generator.py
# )

add_custom_target(gen_isa ALL DEPENDS ${GENERATED_INC})
