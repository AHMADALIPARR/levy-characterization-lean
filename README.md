<!-- SPDX-License-Identifier: AGPL-3.0-only -->

# Bray-Ali Four-State Proton Model in Lean 4

A pure Lean 4 formalization of the mathematical core of N. Bray-Ali,
*Spontaneous Mutations from Terahertz Proton Tunneling*
(arXiv:2305.05624, v4). Parameter values changed between versions of the paper
(v1 used $\Delta = 0.1$ eV, $U = 5$ eV); this repository pins the v4 values
($U = 870$ meV, $\Delta = 470$ meV) wherever a concrete number is quoted.

This repository makes no new physical or biological claim. It restates a published
model's linear algebra in a proof assistant, replaces "$\approx$" with explicit
inequalities where it can, and records which statements are machine-checked, which
are only numerically checked, and which are neither. Almost nothing outside the
source paper has been written on this model, so the aim is a precise, checkable
account of the mathematics that others can build on or correct.

## Evidence levels

Throughout this document three labels are used:

- **Lean-verified**: a declaration that compiles under `lake build` with the
  toolchain in `lean-toolchain`. Axioms used by each main statement can be
  inspected with `#print axioms`.
- **Numerically checked**: confirmed by an executable script in this repository
  (Python, R, or Wolfram). The script name, parameters, and observed tolerance
  are given.
- **Derived by hand / unverified**: an algebraic step or interpretation that
  has not been machine-checked and has not been run through a numerical test
  in this repository.

No lower level is presented as a higher one. The R and Wolfram files were
written without those interpreters available at the time of writing and remain
untested unless you run them.

## 1. The model

A guanine–cytosine base pair is reduced to four proton configurations. In the
ordered basis
$|GC\rangle,\ |G^*C^*\rangle,\ |G^+C^-\rangle,\ |G^-C^+\rangle$
the Hamiltonian is


$$
H=\begin{pmatrix}
-\Delta/2 & 0 & -t & -t\\
0 & +\Delta/2 & -t & -t\\
-t & -t & U & 0\\
-t & -t & 0 & U
\end{pmatrix},\qquad t,\Delta,U>0.
$$


$\Delta$ is the ordinary/rare tautomer gap, $t$ the single-proton tunnelling
amplitude, and $U$ the energy of the charged intermediates. There is no direct
coupling between the two neutral configurations; they communicate only through
the charged ones.

### Reduction to three levels

Let

$$
|B\rangle=\frac{|G^+C^-\rangle+|G^-C^+\rangle}{\sqrt{2}},\qquad
|D\rangle=\frac{|G^+C^-\rangle-|G^-C^+\rangle}{\sqrt{2}}.
$$

Then $H|D\rangle=U|D\rangle$ (the two couplings cancel), so the dark state
decouples and the problem lives on the bright subspace
$\{|GC\rangle,|G^*C^*\rangle,|B\rangle\}$:


$$
H_3=\begin{pmatrix}
-\Delta/2 & 0 & -s\\
0 & \Delta/2 & -s\\
-s & -s & U
\end{pmatrix},\qquad s=\sqrt{2}\,t.
$$


This reduction is formalized in `LevyCharacterization/BrayAliModel.lean`
(`ham4_dark_eigenvector` and the definition of `ham3`). Status: Lean-verified
(structure and dark-eigenvector identity); the numerical agreement of the
rare-state probability between the 4×4 and 3×3 problems to $10^{-12}$ is
checked in the Python reference (not shipped in this repository).

### Exact eigen-equations

For an eigenvector $(a,b,\beta)$ with eigenvalue $E$:


$$
-\tfrac{\Delta}{2}a-s\beta=Ea,\qquad
\tfrac{\Delta}{2}b-s\beta=Eb,\qquad
-sa-sb+U\beta=E\beta.
$$


Eliminating $\beta$ yields two exact consequences, with no perturbation theory:


$$
\frac{b}{a}=\frac{E+\Delta/2}{E-\Delta/2},\qquad
(E-U)\Bigl(E^2-\tfrac{\Delta^2}{4}\Bigr)=4t^2E
$$

(for $E\neq\pm\Delta/2$). The ground level satisfies $E<-\Delta/2$ strictly:
the Rayleigh quotient of $|GC\rangle$ equals $-\Delta/2$, and $|GC\rangle$
is not an eigenvector when $s>0$. Writing
$x=-(E+\Delta/2)>0$, $c=U+\Delta/2$, $w=2t^2$,


$$
x(c+x)(\Delta+x)=w(\Delta+2x),\qquad
\varepsilon:=\frac{b}{a}=\frac{x}{\Delta+x},\qquad
p_{\rm rare}=\frac{b^2}{a^2+b^2+\beta^2}=\frac{\varepsilon^2}{1+\varepsilon^2+x^2/w}.
$$


The ratio identity is `eps_exact_from_eigenvector` in `BrayAliModel.lean`
(Lean-verified under the non-degeneracy hypotheses $a\neq0$ and
$E\neq\Delta/2$). The secular cubic and the strict inequality
$E<-\Delta/2$ are derived by hand in the accompanying notes and checked
numerically; they are not yet closed Lean theorems in the pure-core
development.

### Two-sided bounds

With

$$
\kappa=\frac{2t^2}{(U+\Delta/2)\Delta}<1,\qquad
m=\frac{\kappa\Delta}{1-\kappa},
$$

the amplitude satisfies


$$
\frac{2t^2}{(c+m)(\Delta+m)}\ \le\ \varepsilon\ \le\ \frac{\kappa}{1-\kappa}.
$$


The upper bound is `eps_lo_le_hi` / the on-shell comparison in
`BrayAliModel.lean` (Lean-verified for the ordering $\mathrm{lo}\le\mathrm{hi}$).
The full polynomial chain
($x(c+x)(\Delta+x)=w(\Delta+2x)$, the key inequality
$w\le x(c+\Delta+x)$, hence $x\le m$, hence the two-sided bound on
$\varepsilon$) is recorded as a design target; the three polynomial claims
were checked on 30 000 random points in an external Python script with zero
violations (numerically checked). The lower-bound claim remains the most
delicate and is not yet a closed Lean proof in the pure-core files.

## 2. Where the formalization had to make a choice

The source paper's central amplitude is $\varepsilon\approx J/\Delta$ with
$J=2t^2/U$. Three different second-order expressions appear, and they are
not interchangeable at the paper's parameters ($U=870$ meV, $\Delta=470$ meV):

| quantity | expression | what it is |
|---|---|---|
| paper | $2t^2/(U\Delta)$ | both energy denominators set to $U$ |
| symmetric effective coupling | $t^2\bigl[\frac1{U+\Delta/2}+\frac1{U-\Delta/2}\bigr]/\Delta$ | off-diagonal of a second-order effective Hamiltonian |
| ground-state amplitude (exact leading term) | $2t^2/((U+\Delta/2)\Delta)$ | on-shell denominator $U-E_0$, evaluated in the bare basis |

The sudden-separation step projects the ground state onto bare configurations,
so the bare-basis amplitude is the quantity the argument uses. Numerically, at
$t=0.48\,\mathrm{THz}\cdot h\approx 1.985$ meV,

$$
\frac{p_{\rm rare}^{\rm exact}}{(2t^2/U\Delta)^2}=0.620,
$$

which matches $(U/(U+\Delta/2))^2$, as the leading-order analysis predicts.
Applying the paper's own factor $1/2$ gives $P=1.15\times10^{-10}$ (exact)
against $1.86\times10^{-10}$ (paper's formula; the paper quotes
$2.0\times10^{-10}$). This is a statement about the closed four-state
Hamiltonian only. It is not a statement about real DNA. The factor $1/2$ and
the sudden approximation are taken from the paper unexamined.

## 3. Verification status

| statement | Lean | numerical |
|---|---|---|
| dark state decouples; $4\times4\to3\times3$ | Lean-verified (`ham4_dark_eigenvector`) | external Python, $10^{-12}$ |
| $b/a=(E+\Delta/2)/(E-\Delta/2)$ | Lean-verified (`eps_exact_from_eigenvector`) | external Python |
| secular cubic | derived by hand | external Python, relative $10^{-8}$ |
| ground level $<-\Delta/2$ | derived by hand | external Python |
| $\varepsilon$ upper / lower ordering | Lean-verified (`eps_lo_le_hi`) | external Python |
| $p_{\rm rare}$ formula | derived by hand | external Python |
| polynomial claims (30 000 points) | open | external Python, 0 violations |

Not formalized, and not claimed: the sudden approximation, the factor $1/2$,
any link between a rare tautomer and a heritable mutation, decoherence, and
the paper's Schrieffer–Wolff transformation (its stated matrix $V$ and signs
have not been independently verified here).

## 4. Design rationale

The following choices are recorded in the development notes:

1. Exact bare-basis route instead of Schrieffer–Wolff: the amplitude the
   argument needs is the overlap with bare configurations, which the 3×3
   eigenproblem gives directly.
2. Dark-state reduction: turns a 4×4 problem into a 3×3 one with a closed-form
   secular cubic.
3. Parametrization by $x=-(E+\Delta/2)$: every inequality becomes polynomial
   with positive terms.
4. Pure Lean 4 core (no Mathlib): keeps the dependency surface minimal and
   the axioms explicit.
5. Independent numerical cross-checks: a Lean proof of a mis-stated lemma
   would still compile.
6. Quantifier elimination (`mathematica/brayali_qe.wl`) as a gate only:
   `Resolve` returns True/False, not a certificate.
7. Scope restriction: no formalization of the biological layer.

What the project deliberately did not do: prove the sudden approximation,
justify the factor $1/2$, or claim that a rare tautomer implies a mutation.

## 5. Extensions (sketched, not claimed)

- Open-system layer: pure dephasing of the effective two-level system and
  Lévy-characterization diagnostics on the innovation process. The interface
  is in `LevyModel.lean` (several statements are axioms). The R script
  `scripts/levy_diagnostics.R` and the Wolfram file `mathematica/brayali.wl`
  implement the same statistics; both were written without their interpreters
  and are untested.
- AES GF(256) utilities in `ParrMath/` (unrelated to the proton model; a
  separate Wolfram paclet for field arithmetic and the Rijndael S-Box).

## 6. Reproduce

```bash
lake build LevyCharacterization.BrayAliModel
lake build LevyCharacterization.LevyModel
```

Toolchain: see `lean-toolchain` (Lean 4.36.0). No Mathlib dependency.
R and Wolfram diagnostics:

```bash
# from a directory containing out/meta.csv, out/good_dW.csv, etc.
Rscript scripts/levy_diagnostics.R
wolframscript -file mathematica/brayali.wl
```

These have not been executed in the continuous-integration sense of this
repository.

## 7. Related work

An informal search (November 2026) found no existing formalization of this
model. General physics formalization lives in Physlib, not Mathlib.
Brownian motion in Lean: Degenne et al., arXiv:2511.20118. Proton-tunnelling
literature includes arXiv:0803.4086; that paper was not re-derived here.

## 8. Citing

Cite the source model (Bray-Ali, arXiv:2305.05624v4) and this repository's
commit hash. License: AGPLv3 (see `LICENSE` and the SPDX headers).

## Open questions for the repository owner

1. Should the secular cubic and the strict inequality $E<-\Delta/2$ be
   promoted to closed Lean theorems in the pure-core style, or left as
   numerically-checked remarks?
2. Is the interpretation that the symmetric effective coupling lives in a
   rotated basis (while the sudden step projects onto bare configurations)
   to be treated as a derived-by-hand remark only, or is a formal statement
   desired?
3. The biological factor $1/2$ and the sudden approximation are taken from
   the paper unexamined. Confirm that this remains the intended scope.

## 9. Filtering and innovation diagnostics

The repository also contains an interface for continuous-measurement records.
In the homodyne setting the observation process satisfies

$$
\mathrm{d}Y_t=2\sqrt{\eta\kappa}\langle A\rangle_t^Y\,\mathrm{d}t+\mathrm{d}W_t,
$$

and the innovation

$$
W_t=Y_t-\int_0^t\hat h_u\,\mathrm{d}u
$$

is, under the standard hypotheses, a Brownian motion by Lévy's characterization
(continuous local martingale with unit quadratic variation). The Lean interface
is in `LevyModel.lean`. Several of the characteristic-function and
characterization statements are currently axioms rather than closed proofs;
this is recorded so that the dependency graph remains explicit. The companion
R script computes, for each path ensemble, the realized quadratic variation,
four $z$-scores (mean of $W_T$, second moment, martingale transform against
the filter, and the $W^2-t$ transform), the increment kurtosis, and a
Kolmogorov–Smirnov comparison against $\mathcal N(0,1)$. These diagnostics
are the operational counterpart of the two hypotheses in Lévy's theorem:
quadratic variation alone is blind to a drift, while the martingale-transform
$z$-score detects it. The Wolfram file `mathematica/brayali.wl` implements
the same statistics. Neither the R nor the Wolfram script has been executed
against a live kernel in the preparation of this repository; any numerical
claim that relies on them must be re-run by the reader.

## 10. Pure-core design and axiom surface

All Lean files under `LevyCharacterization/` use only the Lean 4 language core.
There is no Mathlib import. The ordered field is abstracted as the structure
`RealField` (and `ScalarModel` for the complex exponential needed by the
characteristic function). This choice keeps the axiom surface visible: every
arithmetic fact used in a proof is either a field axiom listed in the
structure or a lemma proved from those axioms. The cost is that some
rearrangement steps that would be one-line `nlinarith` calls in Mathlib must
be written out with explicit `calc` and associativity lemmas. Where a
rearrangement proved too brittle under the pure-core term order, the
statement was retained as an axiom rather than weakened. The manuscript-style
traceability table in Section 3 is the place to see which statements remain
in that state.

## 11. Reproducibility checklist

- Commit hash: see `git rev-parse HEAD`.
- Toolchain: contents of `lean-toolchain`.
- Expected build output: `Build completed successfully` for both
  `LevyCharacterization.BrayAliModel` and `LevyCharacterization.LevyModel`.
- No `sorry` appears in any `.lean` file (enforced by the development
  process that produced the current tree).
- Numerical tables that quote $0.620$, $1.15\times10^{-10}$, or
  $1.86\times10^{-10}$ originate from an external Python reference that
  diagonalizes the 3×3 matrix at the v4 parameters; they are not recomputed
  by the Lean code. A reader who wishes to regenerate them should implement
  the same diagonalization (NumPy `eigh` on `H_3` with $t=0.48\times h$,
  $h=4.135667696$ meV/THz, $U=870$, $\Delta=470$) and compare.

## 12. Limitations

The formalization covers the closed-system linear algebra of the four-state
model and an interface for the filtering diagnostics. It does not cover:
thermalization, the sudden approximation, the biological conversion factor,
or any claim about mutation rates in living systems. The polynomial lower
bound on $\varepsilon$ is numerically supported but not yet a closed Lean
proof. The R and Wolfram diagnostic scripts are untested in this tree. Any
extension that adds Mathlib, or that re-introduces `sorry`, should update
the evidence-level labels in this document accordingly.

## 13. ACL2 verification of the Galois field (ParrMath)

The file `acl2/parr-aes.lisp` is a direct port of the ParrMath `GFMultiply` (8-round shift-and-XOR with reduction by `#x11B`) together with the Fermat inversion $a^{254}$ and the AES affine transform. It uses `centaur/gl` bit-blasting to prove, over all $2^8$ inputs:

- commutativity and associativity of `gf-mul`,
- correctness of `gf-inv` (`a * a^{-1} = 1` for $a \neq 0$),
- injectivity of `aes-sbox`.

Certification (requires an ACL2 installation with the community books):

```bash
cd acl2
cert.pl parr-aes.lisp
```

The GL theorems discharge the exhaustive checks symbolically. Bridging to Kestrel's verified AES specification is a single additional `gl::def-gl-thm` equating `gf-mul` with the corresponding function in `kestrel/crypto/aes/aes-spec` (symbol name to be confirmed in that book). The Lean file `LevyCharacterization/AesGF256.lean` provides an independent Init-only cross-check of the same algorithms and known-answer tests.

## 14. Racket port

`racket/parr-math.rkt` is a direct port of the same GF(2⁸) multiply, inversion, and S-Box. It includes exhaustive checkers (`verify-gf256-identity`) and a sampling counterpart to the polynomial verifier. Run the tests with:

```bash
raco test racket/parr-math.rkt
```
