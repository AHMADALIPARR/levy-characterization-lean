# Lévy Characterization & Quantum Filtering Innovation (Lean 4)

Pure Lean 4 formalization (zero external dependencies, no Mathlib) of:

- Lévy's characterization of Brownian motion
- Quantum filtering innovation theorem
- Related counterexamples separating quadratic variation from the martingale property

Also includes a sketch of the rare-state amplitude identities for the reduced 3-level Bray-Ali model.

## Files

- `BrayAli.lean` — rare-state amplitude sketch (two open sorries)
- `scripts/levy_diagnostics.R` — R diagnostics for innovation records (QV, martingale tests, kurtosis, KS)
- Full pure-Lean `LevyModel.lean` (ScalarModel / StochasticModel, Itô cancellation, conditional characteristic function, innovation theorem) is extracted from the source paste; indentation was flattened. See commit history or request a cleaned version.

## Status

Source material noted that some parts were written without a Lean toolchain available. Verify with `lean` before relying on the proofs.

## License

AGPLv3 — see [LICENSE](LICENSE).
