(* SPDX-License-Identifier: AGPL-3.0-only *)

Needs["CCompilerDriver`"];
Needs["ParrMath`"];

lib = CreateLibrary[
  {"Native/gf256.c"},
  "ParrGF256"
];

nativeMultiply = LibraryFunctionLoad[lib, "gf256mul", {Integer, Integer}, Integer];
nativeSBox = LibraryFunctionLoad[lib, "aes_sbox", {Integer}, Integer];
nativeInvSBox = LibraryFunctionLoad[lib, "aes_inv_sbox", {Integer}, Integer];

VerificationTest[
  nativeMultiply[16^^57, 16^^83],
  193,
  TestID -> "GF256-AES-mul"
]

(* Standard AES S-Box values *)
VerificationTest[nativeSBox[0x00], 0x63, TestID -> "SBox-00"]
VerificationTest[nativeSBox[0x01], 0x7C, TestID -> "SBox-01"]
VerificationTest[nativeSBox[0x53], 0xED, TestID -> "SBox-53"]
VerificationTest[nativeSBox[0xFF], 0x16, TestID -> "SBox-FF"]

(* Inverse consistency *)
VerificationTest[nativeInvSBox[nativeSBox[0x53]], 0x53, TestID -> "InvSBox-roundtrip"]
VerificationTest[AES_SBox[0x53], 0xED, TestID -> "Wolfram-SBox-53"]
VerificationTest[AES_InvSBox[AES_SBox[0xAB]], 0xAB, TestID -> "Wolfram-InvSBox-roundtrip"]
