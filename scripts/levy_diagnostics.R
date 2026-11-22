# SPDX-License-Identifier: AGPL-3.0-only

# Levy-characterization diagnostics on innovation records written by export_csv.py.
# Run:  Rscript levy_diagnostics.R        (from the brayali/ directory)
# NOTE: written without an R interpreter available; the Python module computes the same
# statistics (see levy_report in brayali.py) and is the tested reference.

meta <- as.matrix(read.csv("out/meta.csv", header = FALSE))
T_end <- meta[1, 1]; dt <- meta[1, 2]

check <- function(tag) {
  dW <- as.matrix(read.csv(sprintf("out/%s_dW.csv", tag), header = FALSE))
  L  <- as.matrix(read.csv(sprintf("out/%s_L.csv",  tag), header = FALSE))
  n <- nrow(dW)
  z <- function(x, mu = 0) (mean(x) - mu) / (sd(x) / sqrt(length(x)))

  W    <- rowSums(dW)                    # W_T per path
  QV   <- rowSums(dW^2)                  # realized quadratic variation
  S    <- rowSums(L * dW)                # int <Z>_filter dW  (martingale transform)
  Wpre <- t(apply(dW, 1, cumsum)) - dW   # W_{t_k} (left endpoint)
  S2   <- rowSums(Wpre * dW)             # int W dW           (W^2 - t martingale)

  cat(sprintf("\n== %s (paths = %d) ==\n", tag, n))
  cat(sprintf("QV mean %.4f vs T %.4f   (blind to drift)\n", mean(QV), T_end))
  cat(sprintf("z[E W_T = 0]        = %6.2f\n", z(W)))
  cat(sprintf("z[E W_T^2 = T]      = %6.2f\n", z(W^2, T_end)))
  cat(sprintf("z[E int L dW = 0]   = %6.2f   (drift detector)\n", z(S)))
  cat(sprintf("z[E int W dW = 0]   = %6.2f\n", z(S2)))
  x <- as.vector(dW) / sqrt(dt)
  cat(sprintf("increment kurtosis  = %6.3f   (Gaussian = 3)\n", mean(x^4) / mean(x^2)^2))
  cat(sprintf("KS vs N(0,1), 5000 increments: p = %.3f\n",
              ks.test(sample(x, 5000), "pnorm")$p.value))
}

check("good")
check("bad")
