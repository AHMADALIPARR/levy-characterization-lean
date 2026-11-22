(* SPDX-License-Identifier: AGPL-3.0-only *)

(* Quantifier elimination for the eps-bound lemmas, and Lean emitters.
   STATUS: UNTESTED in Wolfram (no kernel here). The claims themselves were sanity-checked in
   Python on 30,000 random parameter points with zero violations, and the DeltaBound claim
   has a hand proof (see lean/BrayAli/PolyClaims.lean).

   Substitution (all derived from the 3x3 eigen-equations, see Rare.lean):
     x = -(E + d/2) > 0      ground-level depression
     d = Delta,  c = U + d/2 (> d  because U > d/2),  w = s^2 = 2 t^2
     secular cubic in x:     x (c + x)(d + x) = w (d + 2 x)
     eps = x/(d + x),  kappa = w/(c d) < 1.

   IMPORTANT: Resolve returns True/False; Lean cannot consume that verdict. It is a gate
   (don't try to prove a false claim) and a guide for hints, not a proof certificate.      *)

cubic[x_, w_, c_, d_] := x (c + x) (d + x) - w (d + 2 x);

hyps[x_, w_, c_, d_] := d > 0 && c > d && w > 0 && c d > w && x > 0 && cubic[x, w, c, d] == 0;

(* the three polynomial claims (denominators cleared, all positive under hyps) *)
claimDelta[x_, w_, c_, d_] := x (c d - w) <= w d;                              (* x <= m *)
claimUpper[x_, w_, c_, d_] := x (c d - 2 w) <= w d;                            (* eps <= kappa/(1-kappa) *)
claimLower[x_, w_, c_, d_] :=
  x c d^2 (c^2 d - c w + w d) >= w (c d - w)^2 (d + x);                        (* eps >= 2t^2/((c+m)(d+m)) *)

claims = <|"Delta" -> claimDelta, "Upper" -> claimUpper, "Lower" -> claimLower|>;

(* Full 4-variable check *)
checkFull[name_String] :=
  Resolve[ForAll[{x, w, c, d}, Implies[hyps[x, w, c, d], claims[name][x, w, c, d]]], Reals];

(* The cubic is homogeneous (x, c, d of weight 1; w of weight 2), so d = 1 loses nothing as a
   QE check and cuts the problem to 3 variables, which CAD handles far more easily.
   Lean still needs the unnormalised statement; this is only the cheaper gate.            *)
checkNormalized[name_String] :=
  Resolve[ForAll[{x, w, c}, Implies[hyps[x, w, c, 1], claims[name][x, w, c, 1]]], Reals];

(* try the cheap one first, with a time limit, then the full one *)
Do[
  Print[name, "  d=1: ", TimeConstrained[checkNormalized[name], 300, "timeout"]],
  {name, Keys[claims]}];
Do[
  Print[name, "  full: ", TimeConstrained[checkFull[name], 600, "timeout"]],
  {name, Keys[claims]}];

(* If QE times out, falsify cheaply instead: search for a counterexample. *)
Do[
  Print[name, " counterexample search: ",
    TimeConstrained[
      FindInstance[hyps[x, w, c, d] && ! claims[name][x, w, c, d], {x, w, c, d}, Reals], 120, "timeout"]],
  {name, Keys[claims]}];

(* ---------- Lean 4 emitter ---------- *)
leanForm[e_] := StringReplace[ToString[e, InputForm],
  {"*" -> " * ", "^" -> " ^ ", "+" -> " + ", "-" -> " - ", "/" -> " / ", "<=" -> " ≤ ", ">=" -> " ≥ ",
   "==" -> " = ", "  " -> " "}];

leanClaim[name_String] := Module[{h, g},
  g = leanForm[claims[name][x, w, c, d]];
  "theorem claim_" <> name <> " {x w c d : ℝ}\n" <>
  "    (hd : 0 < d) (hcd : d < c) (hw : 0 < w) (hk : w < c * d) (hx : 0 < x)\n" <>
  "    (hcub : x * (c + x) * (d + x) = w * (d + 2 * x)) :\n    " <> g <> " := by\n  sorry"];

Print["\n---- Lean statements ----"];
Do[Print[leanClaim[name]], {name, Keys[claims]}];
