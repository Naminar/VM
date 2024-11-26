
set(ISA_TEMPLATES
    # ${CMAKE_CURRENT_SOURCE_DIR}/init_func_vec.inc.j2
    # ${CMAKE_CURRENT_SOURCE_DIR}/isa_decl.inc.j2
    # ${CMAKE_CURRENT_SOURCE_DIR}/isa_impl.inc.j2
    # ${CMAKE_CURRENT_SOURCE_DIR}/defines.h.j2
    # ${CMAKE_CURRENT_SOURCE_DIR}/isa_structs.inc.j2
    ${CMAKE_CURRENT_SOURCE_DIR}/isa.h.j2
    ${CMAKE_CURRENT_SOURCE_DIR}/builder.h.j2
    ${CMAKE_CURRENT_SOURCE_DIR}/isa.cpp.j2
    )

    set(GENERATED_INC
    # ${CMAKE_BINARY_DIR}/generated/init_func_vec.inc
    # ${CMAKE_BINARY_DIR}/generated/isa_decl.inc
    # ${CMAKE_BINARY_DIR}/generated/isa_impl.inc
    # ${CMAKE_BINARY_DIR}/generated/defines.h
    # ${CMAKE_BINARY_DIR}/generated/isa_structs.inc
    ${GEN_DIR}/isa.h
    ${GEN_DIR}/builder.h
    ${GEN_DIR}/isa.cpp
)

add_custom_command(
    OUTPUT ${GENERATED_INC}
    COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/isa_cpp_generator.py ${CMAKE_CURRENT_SOURCE_DIR} ${GEN_DIR} ${ISA_TEMPLATES}
    COMMENT "Generating isa ..."
    DEPENDS json/isa.json isa_cpp_generator.py ${ISA_TEMPLATES}
)

# add_custom_target(gen_isa
#     COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/isa_cpp_generator.py ${CMAKE_CURRENT_SOURCE_DIR} ${GEN_DIR}
#     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#     SOURCES isa_cpp_generator.py
# )

add_custom_target(gen_isa ALL DEPENDS ${GENERATED_INC})

add_library(isa ${GEN_DIR}/isa.cpp)
target_include_directories(isa PUBLIC ${GEN_DIR} ${RUNTIME_CORE_ROOT_DIR})

# add_library(isa_api ${GEN_DIR}/isa.cpp)
# target_include_directories(isa_api PUBLIC ${GEN_DIR} ${RUNTIME_CORE_ROOT_DIR})
