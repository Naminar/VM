
add_custom_target(gen_isa_bin
    COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/dec_to_bin.py
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    SOURCES dec_to_bin.py
)