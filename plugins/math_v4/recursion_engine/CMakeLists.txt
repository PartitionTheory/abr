# ABR v0.4-greenbuild Plugin: Recursion Engine
cmake_minimum_required(VERSION 3.16)

project(abr_plugin_recursion_engine)

add_library(abr_plugin_recursion_engine SHARED
    recursion_engine.c
)

target_include_directories(abr_plugin_recursion_engine PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(abr_plugin_recursion_engine PRIVATE abr_core abr_synth)

