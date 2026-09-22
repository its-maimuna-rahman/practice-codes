# Generate Exponential Variates via Inversion

# cdf for exponential = 1 - exp(-lambda * x)
# therefore X = (-1 / lambda) ln(1 - u) = (-1 / lambda) ln(U)

# --- Inverse CDF of exponential -------------------------------------
inverse_cdf_exp <- function(n, lambda = 2) {
  
  U <- runif(n)
  X <- -log(U) / lambda
  return(X)
}

simulated_exp <- inverse_cdf_exp(1000, 2)
hist(simulated_exp, breaks=30, main="Inverse CDF Exponential", col = "peachpuff")

# Compare with R's built-in rexp()
set.seed(2026)
exp_builtin <- rexp(1000, 2)

par(mfrow = c(1, 2))

hist(simulated_exp,
     breaks = 40,
     freq = FALSE, 
     main = "Custom Exponential Generator",
     xlab = "Value",
     col = "lightblue",
     border = "white")

hist(exp_builtin,
     breaks = 40,
     freq = FALSE,
     main = "R's rexp()",
     xlab = "Value",
     col = "lightgreen", 
     border = "white")

par(mfrow = c(1, 1))

# Check statistics
cat("Custom - Mean:", mean(simulated_exp), "Expected:", 1/0.5, "\n")
cat("Built-in - Mean:", mean(exp_builtin), "Expected:", 1/0.5, "\n")