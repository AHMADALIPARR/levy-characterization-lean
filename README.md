# Lévy Characterization & Quantum Filtering Innovation (Lean 4)

Pure Lean 4 formalizations (zero external dependencies, no Mathlib) of:

- Lévy's characterization of Brownian motion and quantum filtering innovation theorem (`LevyModel.lean`)
- Bray-Ali four-proton-state model, exact secular equation, rare-state amplitude bounds, pure dephasing Lindblad dynamics, and filtering innovation (`BrayAliModel.lean`)

Also includes:

- `BrayAli.lean` — earlier Mathlib sketch of the rare-state amplitude (two open sorries)
- `scripts/levy_diagnostics.R` — R diagnostics for innovation records (QV, martingale tests, kurtosis, KS)

## Status

Source material noted that some parts were written without a Lean toolchain available. Verify with `lean` before relying on the proofs.

## License

AGPLv3 — see [LICENSE](LICENSE).
