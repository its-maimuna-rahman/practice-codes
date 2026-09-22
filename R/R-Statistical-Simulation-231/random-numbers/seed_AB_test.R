# Using state restoration for fair A/B testing comparison

set.seed(99)
baseline_state <- .Random.seed

# ---- mean change ----------
.Random.seed <- baseline_state
system_A <- rnorm(100, mean = 50, sd = 10) 

.Random.seed <- baseline_state
system_B <- rnorm(100, mean = 52, sd = 10)

plot(system_A, system_B,
     main = "scatter plot",
     xlab = "system A (mean 50)",
     ylab = "system B (mean 52)",
     pch = 16)

cat("Mean A:", mean(system_A), " | Mean B:", mean(system_B), "\n")

# -------- variance change -------------

.Random.seed <- baseline_state
system_A2 <- rnorm(100, mean = 50, sd = 10) 

.Random.seed <- baseline_state
system_B2 <- rnorm(100, mean = 50, sd = 8)

plot(system_A2, system_B2,
     main = "scatter plot",
     xlab = "system A2 (sd 10)",
     ylab = "system B2 (sd 8)",
     pch = 16)

cat("sd A2:", sd(system_A2), " | sd B2:", sd(system_B2), "\n")