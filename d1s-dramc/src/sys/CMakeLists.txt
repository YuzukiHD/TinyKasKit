add_library(libsys
    sys-clock.c
    sys-dram.c 
    sys-uart.c
    libdram.c
)

target_link_libraries(libsys PRIVATE libstring)