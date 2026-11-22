;; SPDX-License-Identifier: AGPL-3.0-only
;; ACL2 port of ParrMath GF(2^8) multiply and AES S-Box.
;; Mirrors the 8-round shift-and-XOR loop with reduction by #x11B.
;; Verifies field properties via centaur/gl bit-blasting.

(in-package "ACL2")

(include-book "std/util/define" :dir :system)
(include-book "centaur/gl/gl" :dir :system)
;; (include-book "kestrel/crypto/aes/aes-spec" :dir :system)

;; --------------------------------------------------------------------------
;; 1. Exact mirror of ParrMath`GFMultiply
;; --------------------------------------------------------------------------
(define gf-xtime ((x (unsigned-byte-p 8 x)))
  :returns (res (unsigned-byte-p 8 res)
                :hints (("Goal" :in-theory (enable unsigned-byte-p))))
  (b* ((x (mbe :logic (loghead 8 x) :exec x))
       (shifted (ash x 1)))
    (if (not (eql (logand shifted 256) 0))
        (logxor shifted #x11B)
      shifted)))

(define gf-mul-loop ((x   (unsigned-byte-p 8 x))
                     (y   (unsigned-byte-p 8 y))
                     (acc (unsigned-byte-p 8 acc))
                     (i   natp))
  :returns (res (unsigned-byte-p 8 res))
  :measure (nfix i)
  (b* ((x   (mbe :logic (loghead 8 x) :exec x))
       (y   (mbe :logic (loghead 8 y) :exec y))
       (acc (mbe :logic (loghead 8 acc) :exec acc)))
    (if (zp i)
        (logand acc 255)
      (b* ((acc1 (if (oddp y) (logxor acc x) acc))
           (y1   (ash y -1))
           (x1   (gf-xtime x)))
        (gf-mul-loop x1 y1 acc1 (1- i))))))

(define gf-mul ((a (unsigned-byte-p 8 a))
                (b (unsigned-byte-p 8 b)))
  :returns (res (unsigned-byte-p 8 res))
  (gf-mul-loop a b 0 8))

;; --------------------------------------------------------------------------
;; 2. Field Inversion (a^254 in GF(2^8)) & AES S-Box
;; --------------------------------------------------------------------------
(define gf-sq ((a (unsigned-byte-p 8 a)))
  :returns (res (unsigned-byte-p 8 res))
  (gf-mul a a))

(define gf-inv ((a (unsigned-byte-p 8 a)))
  :returns (res (unsigned-byte-p 8 res))
  ;; a^254 = a^2 * a^4 * a^8 * a^16 * a^32 * a^64 * a^128 (0 |-> 0)
  (b* ((a2   (gf-sq a))
       (a4   (gf-sq a2))
       (a8   (gf-sq a4))
       (a16  (gf-sq a8))
       (a32  (gf-sq a16))
       (a64  (gf-sq a32))
       (a128 (gf-sq a64)))
    (gf-mul a2
      (gf-mul a4
        (gf-mul a8
          (gf-mul a16
            (gf-mul a32
              (gf-mul a64 a128))))))))

(define rotl8 ((x (unsigned-byte-p 8 x)) (k (integer-range-p 0 8 k)))
  :returns (res (unsigned-byte-p 8 res))
  (b* ((x (mbe :logic (loghead 8 x) :exec x)))
    (logand (logior (ash x k) (ash x (- k 8))) 255)))

(define aes-affine ((x (unsigned-byte-p 8 x)))
  :returns (res (unsigned-byte-p 8 res))
  (logxor x
    (logxor (rotl8 x 1)
      (logxor (rotl8 x 2)
        (logxor (rotl8 x 3)
          (logxor (rotl8 x 4) #x63))))))

(define aes-sbox ((a (unsigned-byte-p 8 a)))
  :returns (res (unsigned-byte-p 8 res))
  (aes-affine (gf-inv a)))

;; --------------------------------------------------------------------------
;; 3. Bit-blasted field & S-box proofs via GL
;; --------------------------------------------------------------------------
(gl::def-gl-thm gf-mul-commutative
  :hyp (and (unsigned-byte-p 8 a) (unsigned-byte-p 8 b))
  :concl (equal (gf-mul a b) (gf-mul b a))
  :g-bindings (gl::auto-bindings (:nat a 8) (:nat b 8)))

(gl::def-gl-thm gf-mul-associative
  :hyp (and (unsigned-byte-p 8 a) (unsigned-byte-p 8 b) (unsigned-byte-p 8 c))
  :concl (equal (gf-mul (gf-mul a b) c) (gf-mul a (gf-mul b c)))
  :g-bindings (gl::auto-bindings (:nat a 8) (:nat b 8) (:nat c 8)))

(gl::def-gl-thm gf-inv-correct
  :hyp (and (unsigned-byte-p 8 a) (not (equal a 0)))
  :concl (equal (gf-mul a (gf-inv a)) 1)
  :g-bindings (gl::auto-bindings (:nat a 8)))

(gl::def-gl-thm aes-sbox-injective
  :hyp (and (unsigned-byte-p 8 a) (unsigned-byte-p 8 b)
            (equal (aes-sbox a) (aes-sbox b)))
  :concl (equal a b)
  :g-bindings (gl::auto-bindings (:nat a 8) (:nat b 8)))
