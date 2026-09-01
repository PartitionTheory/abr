# ABR v0.4-greenbuild Plugin: Density / Index
cmake_minimum_required(VERSION 3.16)

project(abr_plugin_density_index)

add_library(abr_plugin_density_index SHARED
    density_index.c
)

target_include_directories(abr_plugin_density_index PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(abr_plugin_density_index PRIVATE abr_core abr_synth)

