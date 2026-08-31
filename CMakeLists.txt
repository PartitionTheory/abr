cmake_minimum_required(VERSION 3.16)
project(abr C)

set(CMAKE_C_STANDARD 17)

add_subdirectory(core)
add_subdirectory(vm)
add_subdirectory(interface)
add_subdirectory(operators)
add_subdirectory(stream)
add_subdirectory(plugins)
add_subdirectory(cli)
add_subdirectory(tests)

