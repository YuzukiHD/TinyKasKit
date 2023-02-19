cmake_minimum_required(VERSION 3.10)

set(TOOLCHAIN_ROOT_PATH "/home/yuzuki/sdk/gcc-arm-10.3-2021.07-x86_64-arm-none-linux-gnueabihf")

set(TOOLCHAIN_ROOT_PATH ${TOOLCHAIN_ROOT_PATH} CACHE STRING "root path to riscv toolchain")

set(CMAKE_C_COMPILER "${TOOLCHAIN_ROOT_PATH}/bin/arm-none-linux-gnueabihf-gcc")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_ROOT_PATH}/bin/arm-none-linux-gnueabihf-g++")

set(CMAKE_COMMON_FLAGS "-mcpu=cortex-a7 -mthumb-interwork -mthumb -mno-unaligned-access -mfpu=neon-vfpv4 -mfloat-abi=hard")
set(CMAKE_DISABLE_WARN_FLAGS "-Wno-int-to-pointer-cast -Wno-implicit-function-declaration")

set(CMAKE_C_FLAGS "${CMAKE_DISABLE_WARN_FLAGS} ${CMAKE_C_FLAGS} ${CMAKE_COMMON_FLAGS}" CACHE STRING "c flags")
set(CMAKE_CXX_FLAGS "${CMAKE_DISABLE_WARN_FLAGS} ${CMAKE_CXX_FLAGS} ${CMAKE_COMMON_FLAGS}" CACHE STRING "c++ flags")

# Set Version, Release need cmake
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)

# use git version as library version
find_package(Git QUIET)
if (Git_FOUND AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../.git")
    execute_process(
            COMMAND ${GIT_EXECUTABLE} rev-list --count HEAD
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            OUTPUT_VARIABLE _git_version
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    execute_process(
            COMMAND ${GIT_EXECUTABLE} log -1 --pretty=format:%h
            OUTPUT_VARIABLE PROJECT_GIT_HASH
            OUTPUT_STRIP_TRAILING_WHITESPACE
            ERROR_QUIET
            WORKING_DIRECTORY
            ${CMAKE_CURRENT_SOURCE_DIR}
    )
else ()
    set(_git_version 0)
    set(PROJECT_GIT_HASH "")
endif ()

project(T113-DRAM C CXX ASM)

configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)

set(CMAKE_AR "${TOOLCHAIN_ROOT_PATH}/bin/arm-none-linux-gnueabihf-ar")
set(CMAKE_OBJCOPY "${TOOLCHAIN_ROOT_PATH}/bin/arm-none-linux-gnueabihf-objcopy")

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/link.ld)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${LINKER_SCRIPT} -nostdlib")

include_directories(
    include
    include/sys
    ${PROJECT_BINARY_DIR}
)

add_subdirectory(lib)
add_subdirectory(src)