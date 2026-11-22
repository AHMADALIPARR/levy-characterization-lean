// SPDX-License-Identifier: AGPL-3.0-only
// AES S-Box: inversion via Fermat (a^254) using Itoh–Tsujii addition chain,
// followed by the standard affine transform (cyclic rotations XOR 0x63).
// Maps 0 -> 0 automatically.

module aes_sbox (
    input  wire [7:0] a,
    output wire [7:0] s
);
    wire [7:0] a2, a3, a6, a12, a15;
    wire [7:0] a30, a60, a120, a240, a252, inv;

    // 7 squarings + 4 multiplications to compute a^254
    gf256_sq  u_sq1  (.a(a),    .y(a2));
    gf256_mul u_mul1 (.a(a2),   .b(a),   .y(a3));

    gf256_sq  u_sq2  (.a(a3),   .y(a6));
    gf256_sq  u_sq3  (.a(a6),   .y(a12));
    gf256_mul u_mul2 (.a(a12),  .b(a3),  .y(a15));

    gf256_sq  u_sq4  (.a(a15),  .y(a30));
    gf256_sq  u_sq5  (.a(a30),  .y(a60));
    gf256_sq  u_sq6  (.a(a60),  .y(a120));
    gf256_sq  u_sq7  (.a(a120), .y(a240));
    gf256_mul u_mul3 (.a(a240), .b(a12), .y(a252));
    gf256_mul u_mul4 (.a(a252), .b(a2),  .y(inv));

    // AES affine transformation
    assign s = inv
             ^ {inv[6:0], inv[7]}
             ^ {inv[5:0], inv[7:6]}
             ^ {inv[4:0], inv[7:5]}
             ^ {inv[3:0], inv[7:4]}
             ^ 8'h63;
endmodule
