# ABR v0.4-greenbuild Plugin: Graph Classifier
cmake_minimum_required(VERSION 3.16)

project(abr_plugin_graph_classifier)

add_library(abr_plugin_graph_classifier SHARED
    graph_classifier.c
)

target_include_directories(abr_plugin_graph_classifier PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(abr_plugin_graph_classifier PRIVATE abr_core abr_synth)

