(* SPDX-License-Identifier: AGPL-3.0-only *)

Needs["CCompilerDriver`"];

lib = CreateLibrary[
  {"Native/gf256.c"},
  "ParrGF256"
];

nativeMultiply = LibraryFunctionLoad[
  lib,
  "gf256mul",
  {Integer, Integer},
  Integer
];

VerificationTest[
  nativeMultiply[16^^57, 16^^83],
  193,
  TestID -> "GF256-AES-mul"
]
