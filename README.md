# Lévy Characterization & Quantum Filtering Innovation (Lean 4)

Pure Lean 4 formalization (zero external dependencies, no Mathlib) of:

- Lévy's characterization of Brownian motion
- Quantum filtering innovation theorem
- Related counterexamples separating quadratic variation from the martingale property

Also includes a sketch of the rare-state amplitude identities for the reduced 3-level Bray-Ali model.

## Status

The formalization packages real/complex exponential algebra and a stochastic calculus interface as explicit structures, then proves the Itô drift cancellation, conditional characteristic function identity, and Lévy's characterization from those interfaces.

**Note:** The source material indicated that some parts were written without a Lean toolchain available. Verify with `lean` before relying on the proofs.

## License

AGPLv3 — see [LICENSE](LICENSE).

## Related

Mathematical background on bare-state amplitudes, nonequilibrium free energy, continuous measurement, and innovation processes is discussed in the accompanying notes.
