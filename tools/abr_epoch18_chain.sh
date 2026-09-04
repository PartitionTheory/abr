#!/usr/bin/env bash
#
# ABR Epoch 18 full chain runner
# Usage:
#   tools/abr_epoch18_chain.sh 11001010011100010111
#
# Runs the window through all Epoch 18 math stages:
# Domain Seed → Density Index → Phi Stability → Invariant Explorer
# → Recursion Engine → Operator Chain → Manifold Dynamics
#
# Echoes the in/out at each stage with simple math commentary.

set -euo pipefail

if [ $# -ne 1 ]; then
  echo "Usage: $0 <window>"
  exit 1
fi

WINDOW="$1"

echo "=== ABR Epoch 18 full chain run ==="
echo "Initial window (b₀): $WINDOW"
echo

# 1. Domain Seed
echo "[1] Domain Seed"
OUT=$(./abr --plugin domain_seed --window "$WINDOW")
echo "$OUT"
SEED_WINDOW=$(echo "$OUT" | awk '/window:/ {print $2}')
echo "  → 𝓜₀.window = b₀ + (b₀ & 0xFF) ≈ $SEED_WINDOW"
echo

# 2. Density Index
echo "[2] Density Index"
OUT=$(./abr --plugin density_index --window "$SEED_WINDOW")
echo "$OUT"
DENSITY_WINDOW=$(echo "$OUT" | awk '/window:/ {print $2}')
echo "  → 𝓜₁.window = 𝓜₀.window (structural pass-through in v0.5) = $DENSITY_WINDOW"
echo

# 3. Phi Stability
echo "[3] Phi Stability"
OUT=$(./abr --plugin phi_stability --window "$DENSITY_WINDOW")
echo "$OUT"
PHI_WINDOW=$(echo "$OUT" | awk '/window:/ {print $2}')
echo "  → 𝓜₂.window = 𝓜₁.window (stability confirmation) = $PHI_WINDOW"
echo

# 4. Invariant Explorer
echo "[4] Invariant Explorer"
OUT=$(./abr --plugin invariant_explorer --window "$PHI_WINDOW")
echo "$OUT"
INV_WINDOW=$(echo "$OUT" | awk '/window:/ {print $2}')
echo "  → 𝓜₃.window = 𝓜₂.window (invariant-preserving in v0.5) = $INV_WINDOW"
echo

# 5. Recursion Engine
echo "[5] Recursion Engine"
OUT=$(./abr --plugin recursion_engine --window "$INV_WINDOW")
echo "$OUT"
RECUR_WINDOW=$(echo "$OUT" | awk '/window:/ {print $2}')
echo "  → 𝓜₄.window = recursive operator-chain manifold = $RECUR_WINDOW"
echo

# 6. Operator Chain
echo "[6] Operator Chain"
OUT=$(./abr --plugin operator_chain --window "$PHI_WINDOW")
echo "$OUT"
OP_WINDOW=$(echo "$OUT" | awk '/window:/ {print $2}')
echo "  → 𝓜₅.window = pure operator-algebraic projection = $OP_WINDOW"
echo

# 7. Manifold Dynamics
echo "[7] Manifold Dynamics"
OUT=$(./abr --plugin manifold_dynamics --window "$RECUR_WINDOW")
echo "$OUT"
MANIFOLD_WINDOW=$(echo "$OUT" | awk '/window:/ {print $2}')
echo "  → 𝓜₆.window = dynamic return manifold (often 𝓜₀ + 1) = $MANIFOLD_WINDOW"
echo

echo "=== Chain complete ==="
echo "b₀           = $WINDOW"
echo "𝓜₀ (seed)   = $SEED_WINDOW"
echo "𝓜₁ (density)= $DENSITY_WINDOW"
echo "𝓜₂ (phi)    = $PHI_WINDOW"
echo "𝓜₃ (inv)    = $INV_WINDOW"
echo "𝓜₄ (recur)  = $RECUR_WINDOW"
echo "𝓜₅ (op)     = $OP_WINDOW"
echo "𝓜₆ (dyn)    = $MANIFOLD_WINDOW"

