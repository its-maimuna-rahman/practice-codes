## ---------------------------------------------------------
## Statistical Simulation (AST231)
## Assignment 1
## Maimuna Rahman (Roll : 016)
## ---------------------------------------------------------

## ============================================================
## Introduction
## ============================================================
# A Linear Congruential Generator produces pseudo-random numbers using the
# recurrence X_{i+1} = (a*X_i + c) mod m, with R_i = X_i / m.

## ============================================================
## The lcg Function
## ============================================================
lcg <- function(n, m, a, c, seed) {
  x <- numeric(n)
  x[1] <- seed
  for (i in 2:n) {
    x[i] <- (a * x[i - 1] + c) %% m
  }
  x / m
}

## ============================================================
## Set A - Good Parameters
## m = 2^31, a = 65539, c = 0, X0 = 1
## ============================================================
mA <- 2^31
aA <- 65539
cA <- 0
seedA <- 1

a_50   <- lcg(50,   mA, aA, cA, seedA)
a_100  <- lcg(100,  mA, aA, cA, seedA)
a_5000 <- lcg(5000, mA, aA, cA, seedA)

## --- n = 50 -------------------------------------------------
# fig-width: 9, fig-height: 4
par(mfrow = c(1, 2))
hist(a_50,
     main = "Histogram, Set A (n=50)",
     xlab = "R")
plot(a_50[1:49], a_50[2:50],
     pch = 20,
     xlab = "R[i]",
     ylab = "R[i+1]",
     main = "Set A (n=50)")

## --- n = 100 ------------------------------------------------
# fig-width: 9, fig-height: 4
par(mfrow = c(1, 2))
hist(a_100,
     main = "Histogram, Set A (n=100)",
     xlab = "R")
plot(a_100[1:99], a_100[2:100],
     pch = 20,
     xlab = "R[i]",
     ylab = "R[i+1]",
     main = "Set A (n=100)")

## --- n = 5000 -----------------------------------------------
# fig-width: 9, fig-height: 4
par(mfrow = c(1, 2))
hist(a_5000,
     main = "Histogram, Set A (n=5000)",
     xlab = "R")
plot(a_5000[1:4999], a_5000[2:5000],
     pch = 20,
     xlab = "R[i]",
     ylab = "R[i+1]",
     main = "Set A (n=5000)")

## --- Observations - Set A ------------------------------------
# The period of this generator is close to 2^31, which completely dwarfs
# even our biggest sample of 5000 values, so there's no chance of the
# sequence repeating within the plots above. The histograms look
# reasonably flat across all three lengths, getting smoother as n grows,
# and the scatterplots show no visible lines, clusters or gaps - just a
# scattered cloud of points. This is exactly what a "good" set of
# parameters should look like in two dimensions.

## ============================================================
## Set B - Bad Parameters
## m = 16, a = 5, c = 3, X0 = 1
## ============================================================
mB <- 16
aB <- 5
cB <- 3
seedB <- 1

b_50   <- lcg(50,   mB, aB, cB, seedB)
b_100  <- lcg(100,  mB, aB, cB, seedB)
b_5000 <- lcg(5000, mB, aB, cB, seedB)

## --- n = 50 -------------------------------------------------
# fig-width: 9, fig-height: 4
par(mfrow = c(1, 2))
hist(b_50,
     main = "Histogram, Set B (n=50)",
     xlab = "R")
plot(b_50[1:49], b_50[2:50],
     pch = 20,
     xlab = "R[i]",
     ylab = "R[i+1]",
     main = "Set B (n=50)")

## --- n = 100 ------------------------------------------------
# fig-width: 9, fig-height: 4
par(mfrow = c(1, 2))
hist(b_100,
     main = "Histogram, Set B (n=100)",
     xlab = "R")
plot(b_100[1:99], b_100[2:100],
     pch = 20,
     xlab = "R[i]",
     ylab = "R[i+1]",
     main = "Set B (n=100)")

## --- n = 5000 -----------------------------------------------
# fig-width: 9, fig-height: 4
par(mfrow = c(1, 2))
hist(b_5000,
     main = "Histogram, Set B (n=5000)",
     xlab = "R")
plot(b_5000[1:4999], b_5000[2:5000],
     pch = 20,
     xlab = "R[i]",
     ylab = "R[i+1]",
     main = "Set B (n=5000)")

## --- Observations - Set B ------------------------------------
# With m = 16 the generator can only ever take 16 different values, and
# it turns out to cycle through all of them before landing back on
# X0 = 1 - so the true period is just 16. The histogram reflects this
# directly: instead of a smooth spread, there are exactly 16 evenly
# spaced spikes, no matter whether n is 50, 100 or 5000. The scatterplot
# is even more telling - for n=100 and n=5000 it just retraces the same
# 16 points over and over in a fixed loop, and what might pass for
# "random" at n=50 turns into an obviously deterministic, repeating
# pattern once n exceeds the period. This is a direct consequence of
# picking a modulus that's far too small.
