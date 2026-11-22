-- SPDX-License-Identifier: AGPL-3.0-only
-- Pure Lean 4 (Init only) cross-check of ParrMath GF(2^8) multiply and AES S-Box.
-- Compatible with the lean-toolchain of this repository.

set_option maxRecDepth 2048

namespace AesGF256

def gfXtime (x : BitVec 8) : BitVec 8 :=
  let s := x <<< 1
  if x.getMsbD 0 then s ^^^ 0x1B#8 else s

def gfMulLoop (x y acc : BitVec 8) : Nat → BitVec 8
  | 0 => acc
  | n + 1 =>
    let acc1 := if y &&& 1#8 == 1#8 then acc ^^^ x else acc
    gfMulLoop (gfXtime x) (y >>> 1) acc1 n

def gfMul (a b : BitVec 8) : BitVec 8 :=
  gfMulLoop a b 0#8 8

def gfInv (a : BitVec 8) : BitVec 8 :=
  let a2 := gfMul a a
  let a4 := gfMul a2 a2
  let a8 := gfMul a4 a4
  let a16 := gfMul a8 a8
  let a32 := gfMul a16 a16
  let a64 := gfMul a32 a32
  let a128 := gfMul a64 a64
  gfMul a2 (gfMul a4 (gfMul a8 (gfMul a16 (gfMul a32 (gfMul a64 a128)))))

def aesAffine (x : BitVec 8) : BitVec 8 :=
  x ^^^ x.rotateLeft 1 ^^^ x.rotateLeft 2 ^^^ x.rotateLeft 3 ^^^ x.rotateLeft 4 ^^^ 0x63#8

def aesSbox (a : BitVec 8) : BitVec 8 :=
  aesAffine (gfInv a)

-- Instant kernel checks
example : gfMul 0x57#8 0x83#8 = 0xC1#8 := by native_decide
example : aesSbox 0x00#8 = 0x63#8 := by native_decide
example : aesSbox 0x53#8 = 0xED#8 := by native_decide
theorem gfInv_0 : gfInv 0#8 = 0#8 := by native_decide

end AesGF256
