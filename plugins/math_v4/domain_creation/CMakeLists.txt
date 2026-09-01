# ABR v0.4-greenbuild Plugin: Domain Creation
cmake_minimum_required(VERSION 3.16)

project(abr_plugin_domain_creation)

add_library(abr_plugin_domain_creation SHARED
    domain_creation.c
)

target_include_directories(abr_plugin_domain_creation PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(abr_plugin_domain_creation PRIVATE abr_core abr_synth)

