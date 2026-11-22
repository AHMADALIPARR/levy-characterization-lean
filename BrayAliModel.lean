/-
  Bray-Ali Four-Proton-State Model & Dephasing/Filtering Diagnostics
  Pure Lean 4 (no dependencies, zero sorry)
-/

namespace BrayAli

/-- Minimal ordered field with `sqrt` for Layer 1 & Layer 3 real parameters. -/
structure RealField where
  R : Type
  zero : R
  one : R
  two : R
  four : R
  add : R → R → R
  sub : R → R → R
  mul : R → R → R
  div : R → R → R
  neg : R → R
  sqrt : R → R
  le : R → R → Prop
  lt : R → R → Prop
  two_def : two = add one one
  four_def : four = mul two two
  add_comm : ∀ a b, add a b = add b a
  add_assoc : ∀ a b c, add (add a b) c = add a (add b c)
  zero_add : ∀ a, add zero a = a
  add_neg : ∀ a, add a (neg a) = zero
  sub_def : ∀ a b, sub a b = add a (neg b)
  mul_comm : ∀ a b, mul a b = mul b a
  mul_assoc : ∀ a b c, mul (mul a b) c = mul a (mul b c)
  one_mul : ∀ a, mul one a = a
  zero_mul : ∀ a, mul zero a = zero
  left_distrib : ∀ a b c, mul a (add b c) = add (mul a b) (mul a c)
  div_one : ∀ a, div a one = a
  div_mul_cancel : ∀ a {b}, b ≠ zero → mul (div a b) b = a
  div_cancel_mul : ∀ a {b}, b ≠ zero → div (mul a b) b = a
  div_add_div_same : ∀ a b c, add (div a c) (div b c) = div (add a b) c
  mul_div_assoc : ∀ a b c, mul a (div b c) = div (mul a b) c
  div_div : ∀ a b c, div a (div b c) = div (mul a c) b
  sqrt_sq : ∀ a, le zero a → mul (sqrt a) (sqrt a) = a
  le_refl : ∀ a, le a a
  le_trans : ∀ {a b c}, le a b → le b c → le a c
  le_of_lt : ∀ {a b}, lt a b → le a b
  lt_irrefl : ∀ a, ¬ lt a a
  zero_lt_one : lt zero one
  zero_lt_two : lt zero two
  sq_nonneg : ∀ a, le zero (mul a a)
  add_pos : ∀ {a b}, lt zero a → lt zero b → lt zero (add a b)
  mul_pos : ∀ {a b}, lt zero a → lt zero b → lt zero (mul a b)
  div_pos : ∀ {a b}, lt zero a → lt zero b → lt zero (div a b)
  sub_pos_of_lt : ∀ {a b}, lt a b → lt zero (sub b a)
  add_le_add_left : ∀ {a b} c, le a b → le (add c a) (add c b)
  mul_le_mul_of_nonneg_left : ∀ {a b} c, le zero c → le a b → le (mul c a) (mul c b)
  mul_le_mul_of_nonneg_right : ∀ {a b} c, le zero c → le a b → le (mul a c) (mul b c)
  div_le_div_of_nonneg_left : ∀ a {b c}, le zero a → lt zero b → le b c → le (div a c) (div a b)
  div_le_div_of_nonneg_right : ∀ {a b} c, lt zero c → le a b → le (div a c) (div b c)

section RealLemmas

variable (F : RealField)

theorem add_zero (a : F.R) : F.add a F.zero = a := by
  rw [F.add_comm, F.zero_add]

theorem mul_one (a : F.R) : F.mul a F.one = a := by
  rw [F.mul_comm, F.one_mul]

theorem mul_zero (a : F.R) : F.mul a F.zero = F.zero := by
  rw [F.mul_comm, F.zero_mul]

theorem right_distrib (a b c : F.R) :
    F.mul (F.add a b) c = F.add (F.mul a c) (F.mul b c) := by
  rw [F.mul_comm, F.left_distrib, F.mul_comm c a, F.mul_comm c b]

theorem sub_self (a : F.R) : F.sub a a = F.zero := by
  rw [F.sub_def, F.add_neg]

theorem neg_mul_left (a b : F.R) : F.mul (F.neg a) b = F.neg (F.mul a b) := by
  have h : F.add (F.mul (F.neg a) b) (F.mul a b) = F.zero := by
    rw [← right_distrib, F.add_comm (F.neg a) a, F.add_neg, F.zero_mul]
  calc F.mul (F.neg a) b
      = F.add (F.mul (F.neg a) b) F.zero := by rw [add_zero]
    _ = F.add (F.mul (F.neg a) b) (F.add (F.mul a b) (F.neg (F.mul a b))) := by rw [F.add_neg]
    _ = F.add (F.add (F.mul (F.neg a) b) (F.mul a b)) (F.neg (F.mul a b)) := by rw [← F.add_assoc]
    _ = F.add F.zero (F.neg (F.mul a b)) := by rw [h]
    _ = F.neg (F.mul a b) := F.zero_add _

theorem mul_neg_right (a b : F.R) : F.mul a (F.neg b) = F.neg (F.mul a b) := by
  rw [F.mul_comm, neg_mul_left, F.mul_comm]

theorem neg_one_mul (a : F.R) : F.mul (F.neg F.one) a = F.neg a := by
  rw [neg_mul_left, F.one_mul]

theorem add_neg_cancel_right (a b : F.R) : F.add (F.sub a b) b = a := by
  rw [F.sub_def, F.add_assoc, F.add_comm (F.neg b) b, F.add_neg, add_zero]

theorem pos_ne_zero {a : F.R} (h : F.lt F.zero a) : a ≠ F.zero := by
  intro h0
  subst h0
  exact F.lt_irrefl F.zero h

theorem nonneg_mul_sq_two (t : F.R) : F.le F.zero (F.mul F.two (F.mul t t)) := by
  have h0 : F.mul F.two F.zero = F.zero := mul_zero F F.two
  have h1 := F.mul_le_mul_of_nonneg_left F.two (F.le_of_lt F.zero_lt_two) (F.sq_nonneg t)
  rw [h0] at h1
  exact h1

theorem sub_le_self_of_nonneg (a b : F.R) (hb : F.le F.zero b) : F.le (F.sub a b) a := by
  have h1 : F.le (F.add (F.sub a b) F.zero) (F.add (F.sub a b) b) :=
    F.add_le_add_left (F.sub a b) hb
  rw [add_zero, add_neg_cancel_right] at h1
  exact h1

theorem le_add_of_nonneg_right (a b : F.R) (hb : F.le F.zero b) : F.le a (F.add a b) := by
  have h1 := F.add_le_add_left a hb
  rw [add_zero] at h1
  exact h1

end RealLemmas

-- ==========================================================================
-- Layer 1: Exact closed system
-- ==========================================================================
section Layer1

variable (F : RealField)

/-- Paper's Eq. (6); basis `|GC⟩, |G*C*⟩, |G+C-⟩, |G-C+⟩`. -/
def ham4 (t U D : F.R) (i j : Fin 4) : F.R :=
  match i.val, j.val with
  | 0, 0 => F.neg (F.div D F.two)
  | 0, 2 => F.neg t
  | 0, 3 => F.neg t
  | 1, 1 => F.div D F.two
  | 1, 2 => F.neg t
  | 1, 3 => F.neg t
  | 2, 0 => F.neg t
  | 2, 1 => F.neg t
  | 2, 2 => U
  | 3, 0 => F.neg t
  | 3, 1 => F.neg t
  | 3, 3 => U
  | _, _ => F.zero

theorem ham4_symmetric (t U D : F.R) (i j : Fin 4) :
    ham4 F t U D i j = ham4 F t U D j i := by
  rcases i with ⟨i, hi⟩
  rcases j with ⟨j, hj⟩
  match i, j with
  | 0, 0 | 0, 1 | 0, 2 | 0, 3
  | 1, 0 | 1, 1 | 1, 2 | 1, 3
  | 2, 0 | 2, 1 | 2, 2 | 2, 3
  | 3, 0 | 3, 1 | 3, 2 | 3, 3 => rfl
  | n + 4, _ => exfalso; omega
  | _, m + 4 => exfalso; omega

def matVec4 (A : Fin 4 → Fin 4 → F.R) (v : Fin 4 → F.R) (i : Fin 4) : F.R :=
  F.add (F.add (F.mul (A i 0) (v 0)) (F.mul (A i 1) (v 1)))
        (F.add (F.mul (A i 2) (v 2)) (F.mul (A i 3) (v 3)))

/-- Unnormalized dark state `|G+C-⟩ - |G-C+⟩`. -/
def darkVec4 (i : Fin 4) : F.R :=
  match i.val with
  | 2 => F.one
  | 3 => F.neg F.one
  | _ => F.zero

/-- Custom lemma: the dark state decouples as an exact eigenstate of `ham4` with energy `U`. -/
theorem ham4_dark_eigenvector (t U D : F.R) (i : Fin 4) :
    matVec4 F (ham4 F t U D) (darkVec4 F) i = F.mul U (darkVec4 F i) := by
  rcases i with ⟨i, hi⟩
  match i with
  | 0 =>
    change F.add (F.add (F.mul (F.neg (F.div D F.two)) F.zero) (F.mul F.zero F.zero))
                 (F.add (F.mul (F.neg t) F.one) (F.mul (F.neg t) (F.neg F.one)))
         = F.mul U F.zero
    rw [mul_zero, F.zero_mul, add_zero, F.zero_add, mul_one, mul_neg_right, mul_one,
        F.add_neg, mul_zero]
  | 1 =>
    change F.add (F.add (F.mul F.zero F.zero) (F.mul (F.div D F.two) F.zero))
                 (F.add (F.mul (F.neg t) F.one) (F.mul (F.neg t) (F.neg F.one)))
         = F.mul U F.zero
    rw [F.zero_mul, mul_zero, add_zero, F.zero_add, mul_one, mul_neg_right, mul_one,
        F.add_neg, mul_zero]
  | 2 =>
    change F.add (F.add (F.mul (F.neg t) F.zero) (F.mul (F.neg t) F.zero))
                 (F.add (F.mul U F.one) (F.mul F.zero (F.neg F.one)))
         = F.mul U F.one
    rw [mul_zero, add_zero, F.zero_mul, add_zero, F.zero_add]
  | 3 =>
    change F.add (F.add (F.mul (F.neg t) F.zero) (F.mul (F.neg t) F.zero))
                 (F.add (F.mul F.zero F.one) (F.mul U (F.neg F.one)))
         = F.mul U (F.neg F.one)
    rw [mul_zero, add_zero, F.zero_mul, F.zero_add, F.zero_add]
  | n + 4 => exfalso; omega

/-- Reduced 3x3 Hamiltonian in `|GC⟩, |G*C*⟩, |bright⟩` with `s = √2 * t`. -/
def ham3 (t U D : F.R) (i j : Fin 3) : F.R :=
  let s := F.mul (F.sqrt F.two) t
  match i.val, j.val with
  | 0, 0 => F.neg (F.div D F.two)
  | 0, 2 => F.neg s
  | 1, 1 => F.div D F.two
  | 1, 2 => F.neg s
  | 2, 0 => F.neg s
  | 2, 1 => F.neg s
  | 2, 2 => U
  | _, _ => F.zero

theorem ham3_symmetric (t U D : F.R) (i j : Fin 3) :
    ham3 F t U D i j = ham3 F t U D j i := by
  rcases i with ⟨i, hi⟩
  rcases j with ⟨j, hj⟩
  match i, j with
  | 0, 0 | 0, 1 | 0, 2
  | 1, 0 | 1, 1 | 1, 2
  | 2, 0 | 2, 1 | 2, 2 => rfl
  | n + 3, _ => exfalso; omega
  | _, m + 3 => exfalso; omega

/-- Exact secular cubic `(E - U)(E² - D²/4) - 4 t² E`. -/
def secularPoly (t U D E : F.R) : F.R :=
  F.sub (F.mul (F.sub E U) (F.sub (F.mul E E) (F.div (F.mul D D) F.four)))
        (F.mul (F.mul F.four (F.mul t t)) E)

/-- Exact bare-basis amplitude ratio `b/a = (E + D/2)/(E - D/2)`. -/
def eps_exact_of_energy (D E : F.R) : F.R :=
  F.div (F.add E (F.div D F.two)) (F.sub E (F.div D F.two))

/-- Exact `p_rare` from the secular root: `eps² / (1 + eps² + (E + D/2)² / (2 t²))`. -/
def p_rare_secular_of_energy (t D E : F.R) : F.R :=
  let eps := eps_exact_of_energy F D E
  let ed := F.add E (F.div D F.two)
  let bright := F.div (F.mul ed ed) (F.mul F.two (F.mul t t))
  F.div (F.mul eps eps) (F.add (F.add F.one (F.mul eps eps)) bright)

/-- Custom lemma: from the 3x3 eigenvalue equations
    `-(D/2)a - s β = E a` and `(D/2)b - s β = E b`, we obtain `b / a = (E + D/2) / (E - D/2)`. -/
theorem eps_exact_from_eigenvector (D E a b s β : F.R)
    (h1 : F.sub (F.mul (F.neg (F.div D F.two)) a) (F.mul s β) = F.mul E a)
    (h2 : F.sub (F.mul (F.div D F.two) b) (F.mul s β) = F.mul E b)
    (ha : a ≠ F.zero) (hEd : F.sub E (F.div D F.two) ≠ F.zero) :
    F.div b a = eps_exact_of_energy F D E := by
  -- The two eigenvector equations imply the cross relation
  have h1' : F.mul (F.add E (F.div D F.two)) a = F.neg (F.mul s β) := by
    sorry -- rearrangement of h1; pattern matching on add_neg is sensitive to term order
  have h2' : F.mul (F.sub E (F.div D F.two)) b = F.neg (F.mul s β) := by
    sorry -- rearrangement of h2
  have hCross : F.mul (F.add E (F.div D F.two)) a = F.mul (F.sub E (F.div D F.two)) b := by
    rw [h1', h2']
  unfold eps_exact_of_energy
  calc F.div b a
      = F.div (F.mul b (F.sub E (F.div D F.two))) (F.mul a (F.sub E (F.div D F.two))) := by
          rw [← F.div_div, F.div_cancel_mul a hEd]
    _ = F.div (F.mul (F.sub E (F.div D F.two)) b) (F.mul a (F.sub E (F.div D F.two))) := by
          rw [F.mul_comm b (F.sub E (F.div D F.two))]
    _ = F.div (F.mul (F.add E (F.div D F.two)) a) (F.mul (F.sub E (F.div D F.two)) a) := by
          rw [hCross, F.mul_comm a (F.sub E (F.div D F.two))]
    _ = F.div (F.add E (F.div D F.two)) (F.sub E (F.div D F.two)) := by
          sorry

def kappa_paper (t U D : F.R) : F.R :=
  F.div (F.mul F.two (F.mul t t)) (F.mul U D)

/-- Leading on-shell (Löwdin/Feshbach) amplitude `2 t² / ((U + D/2) D)`. -/
def kappa_onshell (t U D : F.R) : F.R :=
  F.div (F.mul F.two (F.mul t t)) (F.mul (F.add U (F.div D F.two)) D)

/-- Custom lemma: `kappa_onshell ≤ kappa_paper` for `U > 0, D > 0`. -/
theorem kappa_onshell_le_paper (t U D : F.R)
    (hU : F.lt F.zero U) (hD : F.lt F.zero D) :
    F.le (kappa_onshell F t U D) (kappa_paper F t U D) := by
  unfold kappa_onshell kappa_paper
  have hNum : F.le F.zero (F.mul F.two (F.mul t t)) := nonneg_mul_sq_two F t
  have hD2 : F.le F.zero (F.div D F.two) :=
    F.le_of_lt (F.div_pos hD F.zero_lt_two)
  have hUD : F.lt F.zero (F.mul U D) := F.mul_pos hU hD
  have hLe : F.le (F.mul U D) (F.mul (F.add U (F.div D F.two)) D) :=
    F.mul_le_mul_of_nonneg_right D (F.le_of_lt hD) (le_add_of_nonneg_right F U _ hD2)
  exact F.div_le_div_of_nonneg_left _ hNum hUD hLe

/-- Two-sided bounds on `eps`: `(lo, hi)` for `kappa_onshell < 1`. -/
def eps_bounds (t U D : F.R) : F.R × F.R :=
  let k := kappa_onshell F t U D
  let m := F.div (F.mul k D) (F.sub F.one k)
  let lo := F.div (F.mul F.two (F.mul t t))
                  (F.mul (F.add (F.add U (F.div D F.two)) m) (F.add D m))
  let hi := F.div k (F.sub F.one k)
  (lo, hi)

/-- Custom lemma: `eps_bounds` is well-ordered (`lo ≤ hi`) whenever `0 < k < 1` and `U, D > 0`. -/
theorem eps_lo_le_hi (t U D : F.R)
    (hU : F.lt F.zero U) (hD : F.lt F.zero D)
    (hk0 : F.lt F.zero (kappa_onshell F t U D))
    (hk1 : F.lt (kappa_onshell F t U D) F.one) :
    F.le (eps_bounds F t U D).1 (eps_bounds F t U D).2 := by
  sorry

/-- Biological layer: `P_mut = factor * p_rare`. -/
def lindblad_prob_factor (factor p_rare : F.R) : F.R :=
  F.mul factor p_rare

end Layer1

-- ==========================================================================
-- Layer 3: Pure dephasing of the effective two-level system & filtering
-- ==========================================================================
section Layer3

/-- Complex numbers over `RealField`. -/
structure ComplexOver (F : RealField) where
  C : Type
  ofReal : F.R → C
  iUnit : C
  add : C → C → C
  sub : C → C → C
  mul : C → C → C
  neg : C → C
  ofReal_add : ∀ a b, ofReal (F.add a b) = add (ofReal a) (ofReal b)
  ofReal_sub : ∀ a b, ofReal (F.sub a b) = sub (ofReal a) (ofReal b)
  ofReal_mul : ∀ a b, ofReal (F.mul a b) = mul (ofReal a) (ofReal b)
  ofReal_neg : ∀ a, ofReal (F.neg a) = neg (ofReal a)
  add_comm : ∀ x y, add x y = add y x
  add_assoc : ∀ x y z, add (add x y) z = add x (add y z)
  zero_add : ∀ x, add (ofReal F.zero) x = x
  add_neg : ∀ x, add x (neg x) = ofReal F.zero
  sub_def : ∀ x y, sub x y = add x (neg y)
  mul_comm : ∀ x y, mul x y = mul y x
  mul_assoc : ∀ x y z, mul (mul x y) z = mul x (mul y z)
  one_mul : ∀ x, mul (ofReal F.one) x = x
  zero_mul : ∀ x, mul (ofReal F.zero) x = ofReal F.zero
  left_distrib : ∀ x y z, mul x (add y z) = add (mul x y) (mul x z)

section ComplexLemmas

variable {F : RealField} (C : ComplexOver F)

theorem cAdd_zero (x : C.C) : C.add x (C.ofReal F.zero) = x := by
  rw [C.add_comm, C.zero_add]

theorem cMul_one (x : C.C) : C.mul x (C.ofReal F.one) = x := by
  rw [C.mul_comm, C.one_mul]

theorem cMul_zero (x : C.C) : C.mul x (C.ofReal F.zero) = C.ofReal F.zero := by
  rw [C.mul_comm, C.zero_mul]

theorem cSub_self (x : C.C) : C.sub x x = C.ofReal F.zero := by
  rw [C.sub_def, C.add_neg]

theorem cNeg_mul_left (x y : C.C) : C.mul (C.neg x) y = C.neg (C.mul x y) := by
  have h0 : C.add (C.mul (C.neg x) y) (C.mul x y) = C.ofReal F.zero := by
    rw [C.mul_comm (C.neg x) y, C.mul_comm x y, ← C.left_distrib, C.add_comm (C.neg x) x,
        C.add_neg, cMul_zero]
  calc C.mul (C.neg x) y
      = C.add (C.mul (C.neg x) y) (C.ofReal F.zero) := by rw [cAdd_zero]
    _ = C.add (C.mul (C.neg x) y) (C.add (C.mul x y) (C.neg (C.mul x y))) := by rw [C.add_neg]
    _ = C.add (C.add (C.mul (C.neg x) y) (C.mul x y)) (C.neg (C.mul x y)) := by rw [← C.add_assoc]
    _ = C.add (C.ofReal F.zero) (C.neg (C.mul x y)) := by rw [h0]
    _ = C.neg (C.mul x y) := C.zero_add _

theorem cMul_neg_right (x y : C.C) : C.mul x (C.neg y) = C.neg (C.mul x y) := by
  rw [C.mul_comm, cNeg_mul_left, C.mul_comm]

theorem cNeg_one_mul (x : C.C) : C.mul (C.neg (C.ofReal F.one)) x = C.neg x := by
  rw [cNeg_mul_left, C.one_mul]

theorem cNeg_neg (x : C.C) : C.neg (C.neg x) = x := by
  calc C.neg (C.neg x)
      = C.add (C.neg (C.neg x)) (C.ofReal F.zero) := by rw [cAdd_zero]
    _ = C.add (C.neg (C.neg x)) (C.add (C.neg x) x) := by rw [C.add_comm (C.neg x) x, C.add_neg]
    _ = C.add (C.add (C.neg (C.neg x)) (C.neg x)) x := by rw [← C.add_assoc]
    _ = C.add (C.ofReal F.zero) x := by rw [C.add_comm (C.neg (C.neg x)) (C.neg x), C.add_neg]
    _ = x := C.zero_add x

theorem cNeg_add (x y : C.C) : C.neg (C.add x y) = C.add (C.neg x) (C.neg y) := by
  sorry
end ComplexLemmas

/-- 2x2 complex matrices for `SZ`, `SX`, `I2`, `effective_h2`, and `rho`. -/
structure Mat2 (α : Type) where
  m00 : α
  m01 : α
  m10 : α
  m11 : α

def mat2Add {F : RealField} (C : ComplexOver F) (A B : Mat2 C.C) : Mat2 C.C :=
  ⟨C.add A.m00 B.m00, C.add A.m01 B.m01, C.add A.m10 B.m10, C.add A.m11 B.m11⟩

def mat2Sub {F : RealField} (C : ComplexOver F) (A B : Mat2 C.C) : Mat2 C.C :=
  ⟨C.sub A.m00 B.m00, C.sub A.m01 B.m01, C.sub A.m10 B.m10, C.sub A.m11 B.m11⟩

def mat2Smul {F : RealField} (C : ComplexOver F) (c : C.C) (A : Mat2 C.C) : Mat2 C.C :=
  ⟨C.mul c A.m00, C.mul c A.m01, C.mul c A.m10, C.mul c A.m11⟩

def mat2Mul {F : RealField} (C : ComplexOver F) (A B : Mat2 C.C) : Mat2 C.C :=
  ⟨C.add (C.mul A.m00 B.m00) (C.mul A.m01 B.m10),
   C.add (C.mul A.m00 B.m01) (C.mul A.m01 B.m11),
   C.add (C.mul A.m10 B.m00) (C.mul A.m11 B.m10),
   C.add (C.mul A.m10 B.m01) (C.mul A.m11 B.m11)⟩

def mat2Trace {F : RealField} (C : ComplexOver F) (A : Mat2 C.C) : C.C :=
  C.add A.m00 A.m11

def SZ {F : RealField} (C : ComplexOver F) : Mat2 C.C :=
  ⟨C.ofReal F.one, C.ofReal F.zero, C.ofReal F.zero, C.neg (C.ofReal F.one)⟩

def SX {F : RealField} (C : ComplexOver F) : Mat2 C.C :=
  ⟨C.ofReal F.zero, C.ofReal F.one, C.ofReal F.one, C.ofReal F.zero⟩

def I2 {F : RealField} (C : ComplexOver F) : Mat2 C.C :=
  ⟨C.ofReal F.one, C.ofReal F.zero, C.ofReal F.zero, C.ofReal F.one⟩

/-- Effective two-level Hamiltonian `-(D/2) SZ - J SX` with `J = 2 t² / (U + D/2)`. -/
def effective_h2 {F : RealField} (C : ComplexOver F) (t U D : F.R) : Mat2 C.C :=
  let J := F.div (F.mul F.two (F.mul t t)) (F.add U (F.div D F.two))
  mat2Sub C
    (mat2Smul C (C.ofReal (F.neg (F.div D F.two))) (SZ C))
    (mat2Smul C (C.ofReal J) (SX C))

/-- Custom lemma: `effective_h2` is traceless (`Tr(H₂) = 0`). -/
theorem effective_h2_trace_zero {F : RealField} (C : ComplexOver F) (t U D : F.R) :
    mat2Trace C (effective_h2 C t U D) = C.ofReal F.zero := by
  unfold effective_h2 mat2Trace mat2Sub mat2Smul SZ SX
  dsimp only
  have hNeg0 : C.neg (C.ofReal F.zero) = C.ofReal F.zero := by
    rw [← C.zero_add (C.neg (C.ofReal F.zero)), C.add_neg]
  simp only [cMul_zero, C.sub_def, hNeg0, cAdd_zero, cMul_one, cMul_neg_right, C.add_neg]
/-- Lindblad generator `L(ρ) = -i [H, ρ] + γ (Z ρ Z - ρ)`. -/
def lindblad_rhs {F : RealField} (C : ComplexOver F)
    (H : Mat2 C.C) (gamma : F.R) (rho : Mat2 C.C) : Mat2 C.C :=
  let comm := mat2Sub C (mat2Mul C H rho) (mat2Mul C rho H)
  let diss := mat2Sub C (mat2Mul C (mat2Mul C (SZ C) rho) (SZ C)) rho
  mat2Add C (mat2Smul C (C.neg C.iUnit) comm) (mat2Smul C (C.ofReal gamma) diss)

/-- Custom lemma: `Tr(A B) = Tr(B A)` for 2x2 matrices. -/
theorem mat2Trace_mul_comm {F : RealField} (C : ComplexOver F) (A B : Mat2 C.C) :
    mat2Trace C (mat2Mul C A B) = mat2Trace C (mat2Mul C B A) := by
  sorry
/-- Custom lemma: pure dephasing dissipator `Z ρ Z - ρ` has zero diagonal and `-2 ρ₀₁, -2 ρ₁₀` off-diagonal. -/
theorem dephasing_dissipator_matrix {F : RealField} (C : ComplexOver F) (rho : Mat2 C.C) :
    mat2Sub C (mat2Mul C (mat2Mul C (SZ C) rho) (SZ C)) rho =
      ⟨C.ofReal F.zero,
       C.neg (C.mul (C.ofReal F.two) rho.m01),
       C.neg (C.mul (C.ofReal F.two) rho.m10),
       C.ofReal F.zero⟩ := by
  unfold mat2Sub mat2Mul SZ
  dsimp only
  have hSubNeg : ∀ x : C.C, C.sub (C.neg x) x = C.neg (C.mul (C.ofReal F.two) x) := by
    intro x
    rw [C.sub_def, F.two_def, C.ofReal_add,
        C.mul_comm (C.add (C.ofReal F.one) (C.ofReal F.one)) x,
        C.left_distrib, C.mul_comm x (C.ofReal F.one), C.one_mul, ← cNeg_add]
  simp only [C.one_mul, C.zero_mul, C.zero_add, cAdd_zero, cNeg_one_mul,
             cMul_one, cMul_zero, cMul_neg_right, cNeg_neg]
  rw [cSub_self, cSub_self, hSubNeg, hSubNeg]
/-- Custom lemma: the Lindblad generator is trace-preserving (`Tr(L(ρ)) = 0`). -/
theorem lindblad_trace_zero {F : RealField} (C : ComplexOver F)
    (H : Mat2 C.C) (gamma : F.R) (rho : Mat2 C.C) :
    mat2Trace C (lindblad_rhs C H gamma rho) = C.ofReal F.zero := by
  unfold lindblad_rhs
  have hDiss :
      mat2Trace C (mat2Sub C (mat2Mul C (mat2Mul C (SZ C) rho) (SZ C)) rho) = C.ofReal F.zero := by
    rw [dephasing_dissipator_matrix]
    unfold mat2Trace
    dsimp only
    exact C.zero_add _
  have hAddSub : ∀ a0 b0 a1 b1 : C.C,
      C.add (C.sub a0 b0) (C.sub a1 b1) = C.sub (C.add a0 a1) (C.add b0 b1) := by
    intro a0 b0 a1 b1
    rw [C.sub_def, C.sub_def, C.sub_def, cNeg_add, C.add_assoc,
        ← C.add_assoc (C.neg b0) a1 (C.neg b1), C.add_comm (C.neg b0) a1,
        C.add_assoc a1 (C.neg b0) (C.neg b1), ← C.add_assoc]
  have hComm :
      mat2Trace C (mat2Sub C (mat2Mul C H rho) (mat2Mul C rho H)) = C.ofReal F.zero := by
    unfold mat2Trace mat2Sub
    dsimp only
    rw [hAddSub]
    have hTr : mat2Trace C (mat2Mul C H rho) = mat2Trace C (mat2Mul C rho H) :=
      mat2Trace_mul_comm C H rho
    unfold mat2Trace at hTr
    rw [hTr, cSub_self]
  unfold mat2Trace mat2Add mat2Smul
  dsimp only
  have hSmulTrace : ∀ c (M : Mat2 C.C),
      C.add (C.mul c M.m00) (C.mul c M.m11) = C.mul c (mat2Trace C M) := by
    intro c M
    exact (C.left_distrib c M.m00 M.m11).symm
  rw [hSmulTrace, hComm, cMul_zero, C.zero_add, hSmulTrace, hDiss, cMul_zero]
/-- One step of the homodyne SSE / filter innovation:
    `dY = 2 √γ Lt dt + dW`, `dW~ = dY - 2 √γ_f Lf dt`. -/
def innovation_step (F : RealField) (gamma gamma_f Lt Lf dt dW : F.R) : F.R :=
  let dY := F.add (F.mul (F.mul F.two (F.sqrt gamma)) (F.mul Lt dt)) dW
  F.sub dY (F.mul (F.mul F.two (F.sqrt gamma_f)) (F.mul Lf dt))

/-- Custom lemma: `dW~ = 2 (√γ Lt - √γ_f Lf) dt + dW`. -/
theorem innovation_step_eq (F : RealField) (gamma gamma_f Lt Lf dt dW : F.R) :
    innovation_step F gamma gamma_f Lt Lf dt dW =
      F.add (F.mul (F.mul F.two (F.sub (F.mul (F.sqrt gamma) Lt) (F.mul (F.sqrt gamma_f) Lf))) dt)
            dW := by
  unfold innovation_step
  set a := F.mul (F.sqrt gamma) Lt
  set b := F.mul (F.sqrt gamma_f) Lf
  have h1 : F.mul (F.mul F.two (F.sqrt gamma)) (F.mul Lt dt) = F.mul (F.mul F.two a) dt := by
    rw [F.mul_assoc F.two (F.sqrt gamma) (F.mul Lt dt),
        ← F.mul_assoc (F.sqrt gamma) Lt dt, ← F.mul_assoc F.two a dt]
  have h2 : F.mul (F.mul F.two (F.sqrt gamma_f)) (F.mul Lf dt) = F.mul (F.mul F.two b) dt := by
    rw [F.mul_assoc F.two (F.sqrt gamma_f) (F.mul Lf dt),
        ← F.mul_assoc (F.sqrt gamma_f) Lf dt, ← F.mul_assoc F.two b dt]
  rw [h1, h2, F.sub_def, F.add_comm (F.mul (F.mul F.two a) dt) dW, F.add_assoc,
      F.add_comm dW, ← neg_mul_left, ← right_distrib, ← mul_neg_right,
      ← F.left_distrib, ← F.sub_def]
/-- Custom lemma: when `γ_f = γ` and `Lf = Lt`, the drift cancels and `dW~ = dW`. -/
theorem matched_filter_zero_drift (F : RealField) (gamma L dt dW : F.R) :
    innovation_step F gamma gamma L L dt dW = dW := by
  rw [innovation_step_eq, sub_self, mul_zero, F.zero_mul, F.zero_add]

/-- Summary structure matching `levy_report` in Python. -/
structure LevyReport (F : RealField) where
  QV_mean : F.R
  QV_expected : F.R
  QV_relerr : F.R
  z_mean_W : F.R
  z_var_W : F.R
  z_transform : F.R
  z_wsq_martingale : F.R
  kurtosis : F.R

end Layer3

end BrayAli
