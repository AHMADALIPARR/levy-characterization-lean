(* SPDX-License-Identifier: AGPL-3.0-only *)

BeginPackage["ParrMath`"];

GFMultiply::usage =
  "GFMultiply[a,b] multiplies elements in AES GF(2^8).";

VerifyPolynomial::usage =
  "VerifyPolynomial[expr,vars] checks a polynomial identity.";

Begin["`Private`"];

GFMultiply[a_Integer, b_Integer] /;
    0 <= a <= 255 && 0 <= b <= 255 :=
 Module[{x = a, y = b, result = 0, i},
  Do[
   If[OddQ[y], result = BitXor[result, x]];
   y = BitShiftRight[y, 1];
   x = BitShiftLeft[x, 1];
   If[BitAnd[x, 256] != 0,
    x = BitXor[x, 16^^11B]
   ];
   ,
   {i, 8}
  ];
  BitAnd[result, 255]
 ];

VerifyPolynomial[expr_, vars_List] :=
  TrueQ[
   Resolve[
    ForAll[vars, expr],
    Reals
   ]
  ];

End[];
EndPackage[];
