add_subdirectory(sys)

add_executable(D1s-DRAM
    start.S
    main.c
    uart.c
)

set_target_properties(D1s-DRAM PROPERTIES LINK_DEPENDS "${LINK_SCRIPT}")
target_link_libraries(D1s-DRAM PRIVATE libdram libstring libsys)

add_custom_command(
    TARGET D1s-DRAM 
    POST_BUILD COMMAND ${CMAKE_OBJCOPY} -v -O binary D1s-DRAM D1s-DRAM.bin 
    COMMENT "Copy Binary"
)