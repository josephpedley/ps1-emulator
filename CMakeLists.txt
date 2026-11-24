cmake_minimum_required(VERSION 3.16)
project(ps1 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(emu src/main.c src/cpu.c src/interconnect.c src/bios.c)

target_compile_options(emu PRIVATE -Wall -Wextra)


