# --- Inverse CDF for Uniform -------------------------

inverse_cdf_uniform <- function(n, a, b) {
  
  U <- runif(n)
  X <- (U*b) - (U*a) + a
  
  return(X)
}

simulated_unif <- inverse_cdf_uniform(1000, 1, 20)
hist(simulated_unif, breaks=30, main="Inverse CDF Uniform", col = "lavender")