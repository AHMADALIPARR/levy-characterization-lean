<!-- SPDX-License-Identifier: AGPL-3.0-only -->

# Lévy Characterization & Bray-Ali Model (Lean 4)

Pure Lean 4 formalizations (zero external dependencies).

## Structure

```
LevyCharacterization/
  BrayAliModel.lean   -- four-proton-state model, secular equation, amplitude bounds, dephasing/filtering
  LevyModel.lean      -- Lévy characterization interface and quantum filtering innovation
  RKernels.lean       -- R-style diagnostic kernels matching scripts/levy_diagnostics.R
scripts/
  levy_diagnostics.R  -- reference R diagnostics
docs/                 -- source notes
```

## Build

```bash
lake build LevyCharacterization.BrayAliModel
lake build LevyCharacterization.LevyModel
```

## License

AGPLv3 — see [LICENSE](LICENSE).
