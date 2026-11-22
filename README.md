# Lévy Characterization & Quantum Filtering Innovation (Lean 4)

Pure Lean 4 formalizations (zero external dependencies, no Mathlib):

- `LevyModel.lean` — Lévy's characterization and quantum filtering innovation theorem
- `BrayAliModel.lean` — Bray-Ali four-proton-state model, secular equation, amplitude bounds, pure dephasing Lindblad dynamics
- `RKernels.lean` — R-style diagnostic kernels that mirror `scripts/levy_diagnostics.R` (QV, z-scores, kurtosis, recursive matching)

Also:

- `BrayAli.lean` — earlier Mathlib sketch (two open sorries)
- `scripts/levy_diagnostics.R` — reference R diagnostics

The kernels in `RKernels.lean` implement the same statistics the R script computes so they can be matched recursively against R outputs on the same CSV records.

## License

AGPLv3 — see [LICENSE](LICENSE).
