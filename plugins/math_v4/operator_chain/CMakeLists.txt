# ABR v0.4-greenbuild Plugin: Operator Chain
cmake_minimum_required(VERSION 3.16)

project(abr_plugin_operator_chain)

add_library(abr_plugin_operator_chain SHARED
    operator_chain.c
)

target_include_directories(abr_plugin_operator_chain PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(abr_plugin_operator_chain PRIVATE abr_core abr_synth)

