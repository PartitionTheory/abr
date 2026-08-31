# ---------------------------------------------------------------------------
# ABR Test Suite
# Builds: abr_tests
# ---------------------------------------------------------------------------

add_executable(abr_tests)

target_include_directories(abr_tests
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../core
        ${CMAKE_CURRENT_SOURCE_DIR}/../vm
        ${CMAKE_CURRENT_SOURCE_DIR}/../interface
        ${CMAKE_CURRENT_SOURCE_DIR}/../operators
        ${CMAKE_CURRENT_SOURCE_DIR}/../stream
        ${CMAKE_CURRENT_SOURCE_DIR}/../plugins
)

# Test sources will be added later by CO.
# Example (future):
# target_sources(abr_tests PRIVATE test_main.c)

# Link against all ABR static libraries and plugin registry
target_link_libraries(abr_tests
    PRIVATE
        abr_core
        abr_vm
        abr_interface
        abr_operators
        abr_stream
        abr_plugins
        abr_plugin_registry
)

