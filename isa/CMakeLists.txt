
set(ISA_TEMPLATES
    ${CMAKE_CURRENT_SOURCE_DIR}/isa.h.j2
    ${CMAKE_CURRENT_SOURCE_DIR}/builder.h.j2
    ${CMAKE_CURRENT_SOURCE_DIR}/isa.cpp.j2
    )

    set(GENERATED_INC
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

add_custom_target(gen_isa ALL DEPENDS ${GENERATED_INC})

add_library(isa ${GEN_DIR}/isa.cpp)
target_include_directories(isa PUBLIC ${GEN_DIR} ${RUNTIME_CORE_ROOT_DIR})
