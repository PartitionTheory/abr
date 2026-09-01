#include "abr_synth_set.h"
#include "abr_synth_math_add_op.h"
#include "abr_synth_math_mul_op.h"
#include "abr_synth_math_pow_op.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Math Family #1 — Basic arithmetic operators.
 *
 * This family groups the foundational math operators:
 *   - add
 *   - mul
 *   - pow
 */

void abr_synth_math_basic_set_init(void)
{
    abr_synth_set_add("synth.math.basic", &synth_math_add_op);
    abr_synth_set_add("synth.math.basic", &synth_math_mul_op);
    abr_synth_set_add("synth.math.basic", &synth_math_pow_op);
}

