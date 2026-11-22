// SPDX-License-Identifier: AGPL-3.0-only
// Squaring in GF(2^8) is linear: y = a^2 mod (x^8 + x^4 + x^3 + x + 1).
// Single layer of XOR gates.

module gf256_sq (
    input  wire [7:0] a,
    output wire [7:0] y
);
    assign y[0] = a[0] ^ a[4] ^ a[6];
    assign y[1] = a[4] ^ a[6] ^ a[7];
    assign y[2] = a[1] ^ a[5];
    assign y[3] = a[4] ^ a[5] ^ a[6] ^ a[7];
    assign y[4] = a[2] ^ a[4] ^ a[7];
    assign y[5] = a[5] ^ a[6];
    assign y[6] = a[3] ^ a[5];
    assign y[7] = a[6] ^ a[7];
endmodule
