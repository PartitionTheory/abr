# ABR v0.4-greenbuild Plugin: Phi Stability (Φₛ)
cmake_minimum_required(VERSION 3.16)

project(abr_plugin_phi_stability)

add_library(abr_plugin_phi_stability SHARED
    phi_stability.c
)

target_include_directories(abr_plugin_phi_stability PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(abr_plugin_phi_stability PRIVATE abr_core abr_synth)

