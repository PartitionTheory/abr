# ABR v0.4-greenbuild Plugin: Manifold Dynamics
cmake_minimum_required(VERSION 3.16)

project(abr_plugin_manifold_dynamics)

add_library(abr_plugin_manifold_dynamics SHARED
    manifold_dynamics.c
)

target_include_directories(abr_plugin_manifold_dynamics PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(abr_plugin_manifold_dynamics PRIVATE abr_core abr_synth)

