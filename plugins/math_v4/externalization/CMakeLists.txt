# ABR v0.4-greenbuild Plugin: Externalization Vectors
cmake_minimum_required(VERSION 3.16)

project(abr_plugin_externalization)

add_library(abr_plugin_externalization SHARED
    externalization.c
)

target_include_directories(abr_plugin_externalization PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(abr_plugin_externalization PRIVATE abr_core abr_synth)

