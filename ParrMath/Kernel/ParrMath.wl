(* SPDX-License-Identifier: AGPL-3.0-only *)

BeginPackage["ParrMath`"];

GFMultiply::usage =
  "GFMultiply[a,b] multiplies elements in AES GF(2^8).";

VerifyPolynomial::usage =
  "VerifyPolynomial[expr,vars] checks a polynomial identity.";

AES_SBox::usage =
  "AES_SBox[a] returns the AES Rijndael S-Box value for byte a.";

AES_InvSBox::usage =
  "AES_InvSBox[a] returns the AES inverse S-Box value for byte a.";

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

(* Field inverse via Fermat: a^{-1} = a^{254} for a != 0 *)
gfInverse[0] := 0;
gfInverse[a_Integer] :=
 Module[{r = 1, b = a, e = 254},
  While[e > 0,
   If[OddQ[e], r = GFMultiply[r, b]];
   b = GFMultiply[b, b];
   e = BitShiftRight[e, 1]
  ];
  r
 ];

(* Affine transform: b' = A*b xor 0x63 *)
affine[b_Integer] :=
 Module[{r = 0, i},
  Do[
   r = BitOr[r,
     BitShiftLeft[
      BitAnd[
       BitXor[
        BitAnd[BitShiftRight[b, i], 1],
        BitAnd[BitShiftRight[b, Mod[i + 4, 8]], 1],
        BitAnd[BitShiftRight[b, Mod[i + 5, 8]], 1],
        BitAnd[BitShiftRight[b, Mod[i + 6, 8]], 1],
        BitAnd[BitShiftRight[b, Mod[i + 7, 8]], 1],
        BitAnd[BitShiftRight[16^^63, i], 1]
       ], 1
      ], i
     ]
    ],
   {i, 0, 7}
  ];
  r
 ];

AES_SBox[a_Integer] /; 0 <= a <= 255 := affine[gfInverse[a]];

(* Inverse affine then field inverse *)
invAffine[b_Integer] :=
 Module[{r = 0, i, c = 16^^05},
  Do[
   r = BitOr[r,
     BitShiftLeft[
      BitAnd[
       BitXor[
        BitAnd[BitShiftRight[b, Mod[i + 2, 8]], 1],
        BitAnd[BitShiftRight[b, Mod[i + 5, 8]], 1],
        BitAnd[BitShiftRight[b, Mod[i + 7, 8]], 1],
        BitAnd[BitShiftRight[c, i], 1]
       ], 1
      ], i
     ]
    ],
   {i, 0, 7}
  ];
  r
 ];

AES_InvSBox[a_Integer] /; 0 <= a <= 255 := gfInverse[invAffine[a]];

VerifyPolynomial[expr_, vars_List] :=
  TrueQ[
   Resolve[
    ForAll[vars, expr],
    Reals
   ]
  ];

End[];
EndPackage[];
