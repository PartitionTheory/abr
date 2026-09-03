ABR v0.5 — Canonical Release Manifest
====================================

Version:        0.5
Codename:       Phoenix-Scflder
Release Date:   2026-09-08 YYYY-MM-DD
ABI Status:     Stable
Build System:   CMake 3.16+
Language:       C11

------------------------------------
Subsystem Overview
------------------------------------

include/        — canonical ABI headers
core/           — runtime, system, dispatch, stream, operators, loader, registry
plugins/        — builtin + math_v4 plugin families
cli/            — command-line interface
vm/             — virtual machine runtime
tests/          — runtime, plugin, pipeline, VM tests

------------------------------------
ABI Definition
------------------------------------

Defined in: include/abr.h

ABI includes:
  - abr_plugin
  - abr_plugin_result
  - abr_plugin_factory
  - abr_context
  - create/execute/destroy signatures

ABI is stable for:
  - builtin plugins
  - math_v4 plugins
  - future plugin families
  - CLI and VM execution
  - operator-chain subsystem
  - runtime pipeline subsystem

------------------------------------
Plugin Families
------------------------------------

Builtin Plugins:
  - identity
  - not

Math v4 Plugins:
  - manifold_dynamics
  - manifold_dynamics_extension
  - invariant_explorer
  - recursion_engine
  - density_index
  - phi_stability
  - domain_seed
  - operator_chain

------------------------------------
Runtime Subsystems
------------------------------------

Runtime Context:
  core/runtime/abr_runtime_context.c

Execution Engine:
  core/runtime/abr_runtime_execute.c

Pipeline Engine:
  core/runtime/abr_runtime_pipeline.c

System Layer:
  core/system/abr_system.c

Dispatch Layer:
  core/dispatch/abr_dispatch.c

Stream Subsystem:
  core/stream/abr_stream.c

Operator Subsystem:
  core/operators/abr_operators.c
  core/operators/abr_operator_chain.c

------------------------------------
Loader + Registry
------------------------------------

Unified Loader:
  core/loader/abr_plugin_loader.c

Builtin Loader:
  core/loader/abr_plugin_loader_builtin.c

Math v4 Loader:
  core/loader/abr_plugin_loader_math_v4.c

Registry:
  core/registry/abr_plugin_registry.c

------------------------------------
CLI + VM
------------------------------------

CLI:
  cli/abr_cli.c

VM:
  vm/abr_vm.c

------------------------------------
Build System
------------------------------------

Canonical CMakeLists.txt included at root.

Targets:
  - abr_core (static library)
  - abr_builtin_plugins (static library)
  - abr_math_v4_plugins (static library)
  - abr (CLI executable)
  - abr_vm (VM executable)

------------------------------------
Release Packaging
------------------------------------

abr-v0.5/
  include/
  src/
  plugins/
  cli/
  vm/
  tests/
  CMakeLists.txt
  LICENSE
  README.md
  examples/

------------------------------------
Version Tag
------------------------------------

Tag: v0.5
Commit: <to be assigned by EF>
Branch: main
Status: RELEASED

------------------------------------
Phoenix Annotation (scflder)
------------------------------------

f = front (release input)
s = second (release resolution)
l = last (release output)
d = degree domain (release width)
r = residue domain (release propagation)

------------------------------------
End of Manifest
------------------------------------

