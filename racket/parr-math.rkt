#lang racket
;; SPDX-License-Identifier: AGPL-3.0-only
;; Racket port of ParrMath GF(2^8) multiply and AES S-Box.
;; Exact mirror of the 8-round shift-and-XOR loop with reduction by #x11B.

(provide gf-multiply
         gf-inv
         aes-affine
         aes-sbox
         verify-gf256-identity
         verify-polynomial-samples)

(define (byte? n)
  (and (exact-integer? n) (<= 0 n 255)))

;; Exact port of ParrMath`GFMultiply[a, b]
(define (gf-multiply a b)
  (unless (and (byte? a) (byte? b))
    (raise-argument-error 'gf-multiply "bytes in [0, 255]" (list a b)))
  (let-values ([( _x _y result)
                (for/fold ([x a] [y b] [result 0])
                          ([_i (in-range 8)])
                  (define res1 (if (odd? y) (bitwise-xor result x) result))
                  (define y1 (arithmetic-shift y -1))
                  (define x-shifted (arithmetic-shift x 1))
                  (define x1 (if (not (zero? (bitwise-and x-shifted 256)))
                                 (bitwise-xor x-shifted #x11B)
                                 x-shifted))
                  (values x1 y1 res1))])
    (bitwise-and result 255)))

;; Multiplicative inverse in GF(2^8) via a^254 (0 |-> 0)
(define (gf-sq a)
  (gf-multiply a a))

(define (gf-inv a)
  (unless (byte? a)
    (raise-argument-error 'gf-inv "byte in [0, 255]" a))
  (let* ([a2   (gf-sq a)]
         [a4   (gf-sq a2)]
         [a8   (gf-sq a4)]
         [a16  (gf-sq a8)]
         [a32  (gf-sq a16)]
         [a64  (gf-sq a32)]
         [a128 (gf-sq a64)])
    (gf-multiply a2
      (gf-multiply a4
        (gf-multiply a8
          (gf-multiply a16
            (gf-multiply a32
              (gf-multiply a64 a128))))))))

(define (rotl8 x k)
  (bitwise-and
   (bitwise-ior (arithmetic-shift x k)
                (arithmetic-shift x (- k 8)))
   255))

(define (aes-affine x)
  (bitwise-xor x
               (rotl8 x 1)
               (rotl8 x 2)
               (rotl8 x 3)
               (rotl8 x 4)
               #x63))

(define (aes-sbox a)
  (aes-affine (gf-inv a)))

;; Exhaustive arity-1 / arity-2 identity checker over GF(2^8)
(define (verify-gf256-identity pred #:arity [arity 1])
  (case arity
    [(1) (for/and ([a (in-range 256)]) (pred a))]
    [(2) (for*/and ([a (in-range 256)] [b (in-range 256)]) (pred a b))]
    [else (raise-argument-error 'verify-gf256-identity "1 or 2" arity)]))

;; Racket counterpart to VerifyPolynomial[expr, vars] over exact rationals:
;; checks a multivariate polynomial predicate on a Cartesian grid of exact points.
(define (verify-polynomial-samples pred arity
                                   [grid '(-2 -1 -1/2 0 1/2 1 2)])
  (define (loop k args)
    (if (= k 0)
        (apply pred (reverse args))
        (for/and ([v (in-list grid)])
          (loop (sub1 k) (cons v args)))))
  (loop arity '()))

;; --------------------------------------------------------------------------
;; Tests (run with: raco test parr-math.rkt)
;; --------------------------------------------------------------------------
(module+ test
  (require rackunit)

  (check-equal? (gf-multiply #x57 #x83) #xC1)
  (check-equal? (aes-sbox #x00) #x63)
  (check-equal? (aes-sbox #x53) #xED)
  (check-equal? (aes-sbox #xFF) #x16)

  (check-true (verify-gf256-identity (lambda (a b) (= (gf-multiply a b) (gf-multiply b a))) #:arity 2))
  (check-true (verify-gf256-identity (lambda (a) (or (= a 0) (= (gf-multiply a (gf-inv a)) 1))) #:arity 1))
  (check-equal? (length (remove-duplicates (for/list ([a (in-range 256)]) (aes-sbox a)))) 256)

  (check-true (verify-polynomial-samples
               (lambda (x y) (= (* (+ x y) (- x y)) (- (* x x) (* y y))))
               2)))
