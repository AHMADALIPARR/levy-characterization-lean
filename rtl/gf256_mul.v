// SPDX-License-Identifier: AGPL-3.0-only
// Combinational GF(2^8) multiply modulo x^8 + x^4 + x^3 + x + 1 (0x11B).
// Unrolled 8-stage xtime chain; zero flip-flops.

module gf256_mul (
    input  wire [7:0] a,
    input  wire [7:0] b,
    output wire [7:0] y
);
    wire [7:0] p [0:7];
    wire [7:0] acc [0:7];

    // Stage 0: a * x^0
    assign p[0]   = a;
    assign acc[0] = {8{b[0]}} & p[0];

    // Stages 1..7: unrolled xtime and conditional XOR accumulation
    genvar i;
    generate
        for (i = 1; i < 8; i = i + 1) begin : gen_mul
            assign p[i]   = {p[i-1][6:0], 1'b0} ^ ({8{p[i-1][7]}} & 8'h1b);
            assign acc[i] = acc[i-1] ^ ({8{b[i]}} & p[i]);
        end
    endgenerate

    assign y = acc[7];
endmodule
