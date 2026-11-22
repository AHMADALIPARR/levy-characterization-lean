#!/usr/bin/env python3
"""
Rule: Four proton configurations are placed on a vertical energy axis.
The dark state (antisymmetric charged combination) is an exact eigenvector
at energy U and is drawn as a decoupled horizontal bar. The two neutral
states lie at ±Δ/2 and couple only through the symmetric charged
intermediate via the tunneling amplitude t. The generator lays these
levels and the coupling skeleton on a fixed coordinate grid.
"""

def put(grid, r, c, text):
    if 0 <= r < len(grid):
        row = list(grid[r])
        for i, ch in enumerate(text):
            if 0 <= c + i < len(row):
                row[c + i] = ch
        grid[r] = "".join(row)

def generate(width=72, rows=22):
    grid = [" " * width for _ in range(rows)]
    for r in range(1, 19):
        put(grid, r, 2, "|")
    put(grid, 0, 1, "E")
    # levels
    put(grid, 2, 6, "U   ====================   |G+C->  |G-C+>   dark")
    put(grid, 6, 6, "+D/2   ---- t ----   |B>   symmetric charged")
    put(grid, 8, 42, "|G*C*> rare")
    put(grid, 10, 6, "0")
    put(grid, 14, 6, "-D/2  ================   |GC> ordinary")
    put(grid, 16, 6, "       no direct GC <-> G*C*")
    # connectors
    put(grid, 4, 18, "|")
    put(grid, 5, 18, "t")
    put(grid, 7, 18, "|")
    put(grid, 9, 18, "t")
    # footer
    put(grid, 19, 4, "p_rare ~ (2 t^2 / ((U + D/2) D))^2")
    put(grid, 20, 4, "no physical claim: mathematics of a published model")
    return [line.rstrip() for line in grid]

def main():
    art = generate()
    for line in art:
        assert len(line) <= 72
        print(line)

if __name__ == "__main__":
    main()
