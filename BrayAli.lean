import Mathlib

/-!
# Rare-state amplitude of the reduced (3-level) Bray-Ali model

STATUS: NOT COMPILED. No Lean toolchain was available when this was written, so every
proof below is unchecked, and the two `sorry`s are genuine open obligations.
The numerical counterparts (and the bounds' derivation) are in `../../brayali.py`.

Reduction: the dark charged combination decouples, leaving the bare basis
`|GC>, |G*C*>, |B>` with `|B> = (|G+C-> + |G-C+>)/sqrt 2`, bright coupling `s = sqrt 2 * t`.
Eigen-equations for an eigenvector `(a, b, β)` with eigenvalue `E`:
  row a:  -(D/2) a - s β = E a
  row b:   (D/2) b - s β = E b
  row B:   -s a - s b + U β = E β
-/

namespace BrayAli

variable {D s U E a b β : ℝ}

/-- Eliminating `β` from rows a and b gives the exact bare-basis ratio. -/
theorem ratio_identity
    (ha : -(D / 2) * a - s * β = E * a)
    (hb : (D / 2) * b - s * β = E * b) :
    b * (E - D / 2) = a * (E + D / 2) := by
  linarith

/-- Secular equation `(E - U)(E² - D²/4) = 2 s² E`  (here `2 s² = 4 t²`),
valid whenever `a ≠ 0` and `E ± D/2 ≠ 0`. -/
theorem secular
    (ha : -(D / 2) * a - s * β = E * a)
    (hb : (D / 2) * b - s * β = E * b)
    (hB : -s * a - s * b + U * β = E * β)
    (hE1 : E + D / 2 ≠ 0) (hE2 : E - D / 2 ≠ 0) :
    (E - U) * (E ^ 2 - D ^ 2 / 4) = 2 * s ^ 2 * E := by
  -- a = -s β / (E + D/2),  b = s β / (D/2 - E); substitute into hB and clear denominators.
  have hα : a * (E + D / 2) = -s * β := by linarith
  have hγ : b * (E - D / 2) = -s * β := by linarith
  sorry -- TODO: multiply hB by (E + D/2)(E - D/2), use hα, hγ; needs β ≠ 0 or a separate case.

/-- Two-sided bound on `ε = b / a` in terms of the on-shell amplitude
`κ = 2 t² / ((U + D/2) D)` (with `s² = 2 t²`, so `κ = s² / ((U + D/2) D)`).
Hypotheses encode: ground state below the neutral doublet, weak coupling `κ < 1`. -/
theorem eps_bounds
    (hD : 0 < D) (hU : D / 2 < U) (hs : 0 < s)
    (hκ : s ^ 2 / ((U + D / 2) * D) < 1)
    (hE : E < -D / 2)                       -- ground level pushed down by level repulsion
    (ha0 : a ≠ 0)
    (ha : -(D / 2) * a - s * β = E * a)
    (hb : (D / 2) * b - s * β = E * b)
    (hB : -s * a - s * b + U * β = E * β) :
    let κ := s ^ 2 / ((U + D / 2) * D)
    let m := κ * D / (1 - κ)
    s ^ 2 / ((U + D / 2 + m) * (D + m)) ≤ b / a ∧ b / a ≤ κ / (1 - κ) := by
  -- Sketch (matches brayali.eps_bounds, checked numerically):
  --   δ := -(E + D/2) > 0;  ε = δ / (D + δ) ≤ δ / D;  δ (U + D/2 + δ) = s² (1 + ε).
  --   Upper: δ ≤ s²(1+ε)/(U + D/2)  ⇒  ε ≤ κ(1+ε)  ⇒  ε ≤ κ/(1-κ).
  --   Then δ ≤ m := κD/(1-κ); lower: δ ≥ s²/(U + D/2 + m), ε ≥ δ/(D + m).
  sorry

end BrayAli
