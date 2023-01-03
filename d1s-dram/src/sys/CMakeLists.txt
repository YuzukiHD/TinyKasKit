add_library(libsys
    sys-clock.c
    sys-dram.c 
    sys-uart.c
)

target_link_libraries(libsys PRIVATE libdram libstring)