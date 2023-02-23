add_subdirectory(sys)

add_executable(T113-DRAM
    start.S
    main.c
    uart.c
)

set_target_properties(T113-DRAM PROPERTIES LINK_DEPENDS "${LINK_SCRIPT}")
target_link_libraries(T113-DRAM PRIVATE libstring libsys)

add_custom_command(
    TARGET T113-DRAM 
    POST_BUILD COMMAND ${CMAKE_OBJCOPY} -v -O binary T113-DRAM T113-DRAM.bin 
    COMMENT "Copy Binary"
)