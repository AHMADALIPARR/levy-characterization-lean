(* SPDX-License-Identifier: AGPL-3.0-only *)

(* Bray-Ali reduced model in the Wolfram Language.
   STATUS: UNTESTED. No Wolfram kernel was available when this was written.
   The Python module (brayali.py) is the tested reference; compare its numbers to this.
   Note: D and E are protected symbols in Mathematica, so the code uses del, uu, en.
   Run from the brayali/ folder:  wolframscript -file brayali.wl                      *)

(* ---------- Layer 1: reduced 3x3 problem and exact secular equation ---------- *)
h3[tt_, uu_, del_] := {{-del/2, 0, -Sqrt[2] tt}, {0, del/2, -Sqrt[2] tt}, {-Sqrt[2] tt, -Sqrt[2] tt, uu}};

(* (en - uu)(en^2 - del^2/4) - 4 tt^2 en == 0 *)
sec[en_, tt_, uu_, del_] := (en - uu) (en^2 - del^2/4) - 4 tt^2 en;

groundEnergy[tt_?NumericQ, uu_?NumericQ, del_?NumericQ] :=
  Min[en /. NSolve[sec[en, tt, uu, del] == 0, en, Reals]];

epsExact[tt_?NumericQ, uu_?NumericQ, del_?NumericQ] :=
  With[{e0 = groundEnergy[tt, uu, del]}, (e0 + del/2)/(e0 - del/2)];

(* exact p_rare from the ground eigenvector of the 3x3 matrix (bare basis) *)
pRareExact[tt_?NumericQ, uu_?NumericQ, del_?NumericQ] :=
  With[{v = Normalize[Last[Eigenvectors[N[h3[tt, uu, del]]]]]}, v[[2]]^2];

kappaPaper[tt_, uu_, del_] := 2 tt^2/(uu del);
kappaOnshell[tt_, uu_, del_] := 2 tt^2/((uu + del/2) del);

(* symbolic perturbative expansion of the ground energy: en = -del/2 + a1 tt^2 + a2 tt^4 *)
ansatz = -del/2 + a1 tt^2 + a2 tt^4;
coeffs = CoefficientList[Normal[Series[sec[ansatz, tt, uu, del], {tt, 0, 6}]], tt];
enSol = First @ Solve[{coeffs[[3]] == 0, coeffs[[5]] == 0}, {a1, a2}];
Print["a1 (expect -2/(uu + del/2)) = ", Simplify[a1 /. enSol]];
Print["a2 = ", Simplify[a2 /. enSol]];

With[{uu0 = 870., del0 = 470., h = 4.135667696},
  Module[{tt0 = 0.48 h},
    Print["t = ", tt0, " meV"];
    Print["p_rare exact = ", pRareExact[tt0, uu0, del0]];
    Print["(2t^2/(U del))^2 (paper) = ", kappaPaper[tt0, uu0, del0]^2];
    Print["ratio exact/paper = ", pRareExact[tt0, uu0, del0]/kappaPaper[tt0, uu0, del0]^2];
    Print["eps exact vs on-shell: ", epsExact[tt0, uu0, del0], " vs ", kappaOnshell[tt0, uu0, del0]]]];

(* ---------- Levy diagnostics on records written by export_csv.py ---------- *)
meta = Import["out/meta.csv"][[1]];
tEnd = meta[[1]]; dt = meta[[2]];
z[x_, mu_: 0] := (Mean[x] - mu)/(StandardDeviation[x]/Sqrt[Length[x]]);

levyReport[tag_String] := Module[{dW, L, W, QV, S, Wpre, S2},
  dW = Import["out/" <> tag <> "_dW.csv", "CSV"];
  L = Import["out/" <> tag <> "_L.csv", "CSV"];
  W = Total /@ dW;                    (* W_T per path *)
  QV = Total[dW^2, {2}];              (* realized quadratic variation *)
  S = Total[L dW, {2}];               (* int <Z>_filter dW   : drift detector *)
  Wpre = (Accumulate /@ dW) - dW;     (* left-endpoint W *)
  S2 = Total[Wpre dW, {2}];           (* int W dW            : W^2 - t martingale *)
  <|"tag" -> tag, "paths" -> Length[dW],
    "QV" -> Mean[QV], "T" -> tEnd,
    "z[E W_T = 0]" -> z[W], "z[E W_T^2 = T]" -> z[W^2, tEnd],
    "z[E int L dW = 0]" -> z[S], "z[E int W dW = 0]" -> z[S2],
    "kurtosis" -> Kurtosis[Flatten[dW]]|>];

Print[levyReport["good"]];
Print[levyReport["bad"]];

(* ---------- Brownian reference process, for the structural statement ----------
   WienerProcess[] has independent Gaussian increments, Variance[W_t] = t; Levy says
   these (continuity, martingale, <W>_t = t) characterize it.                        *)
Print["Var[WienerProcess at t] = ", Variance[WienerProcess[][t]] // Simplify];
