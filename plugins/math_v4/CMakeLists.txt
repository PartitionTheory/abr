# ABR v0.4-greenbuild Pure-Math Plugin Suite
cmake_minimum_required(VERSION 3.16)

project(abr_math_v4_plugins)

# Build all v0.4 plugins into a single static library
add_library(abr_math_v4_plugins STATIC
    invariant_explorer/invariant_explorer.c
    manifold_dynamics/manifold_dynamics.c
    recursion_engine/recursion_engine.c
    domain_creation/domain_creation.c
    externalization/externalization.c
    phi_stability/phi_stability.c
    density_index/density_index.c
    operator_chain/operator_chain.c
    graph_classifier/graph_classifier.c
    domain_seed/domain_seed.c
)

target_include_directories(abr_math_v4_plugins PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../..    # for abr_plugin.h, abr_core.h, etc.
)

