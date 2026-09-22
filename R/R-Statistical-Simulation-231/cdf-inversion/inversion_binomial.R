# --- Inverse CDF for Discrete (Binomial) --------------------------
inverse_cdf_binom <- function(n, p) {
  x_vals <- 0:n
  
  pmf <- dbinom(x_vals, n, p)
  cdf <- cumsum(pmf)
  
  U <- runif(n)
  X <- min(x_vals[cdf >= U])
  return(X)
}

simulated_binomial <- inverse_cdf_binom(1, 0.5)
cat("U = ", U, "| Simulated X = ", X, "\n")

# ================= Part 2 ====================== 

# 1. Define the Binomial CDF function
binom_cdf <- function(x, n, p) {
  Fx <- 0
  for(i in 0:x) {
    Fx = Fx + (choose(n, i) * p^i * (1-p)^(n-i))
  }
  
  return(Fx)
}

# 2. Define the general CDF Simulation function
cdf_sim <- function(F, ...) {
  X <- 0
  U <- runif(1)
  
  while(F(X, ...) < U) {
    X <- X + 1
  }
  
  return(X)
}

# 3. Generate one Binomial random variable
#Sets n = 10, p = 0.5. It will output an integer between 0 and 10.
cdf_sim(binom_cdf, n = 10, p = 0.5)