cmake_minimum_required(VERSION 3.16)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/wch_gcc.cmake)

project(wch_demo CXX C ASM)

ch32_fetch_cmsis(V0)

find_package(CMSIS COMPONENTS CH32V0 REQUIRED)

set(PROJECT_SOURCES
    src/main.c)

add_executable(wch_demo ${PROJECT_SOURCES})

target_link_libraries(wch_demo CMSIS::CH32::V003F4 CH32::Nano CH32::NoSys)

ch32_print_size_of_target(wch_demo)
ch32_generate_hex_file(wch_demo)