# ABR v0.4-greenbuild Plugin: Invariant Explorer
cmake_minimum_required(VERSION 3.16)

project(abr_plugin_invariant_explorer)

add_library(abr_plugin_invariant_explorer SHARED
    invariant_explorer.c
)

target_include_directories(abr_plugin_invariant_explorer PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(abr_plugin_invariant_explorer PRIVATE abr_core abr_synth)

