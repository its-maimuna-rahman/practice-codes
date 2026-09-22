# method 1

hit_miss <- function(ftn, a, b, f.min, f.max, n){
  Z.sum <- 0
  for(i in 1:n){
    X <- runif(1, a, b)
    Y <- runif(1, f.min, f.max)
    Z <- (ftn(X) >= Y)
    Z.sum <- Z.sum + Z
  }
  I <- (b-a)*f.min + (Z.sum/n)*(b-a)*(f.max-f.min)
  return(I)
}
f <- function(x) x^3 - 7*x^2 + 1
hit_miss(f, 0, 1, -6, 2, 1000000) # True value ≈ -1.0833



# --- Improved Monte Carlo (Vectorized) ---
mc_integral <- function(ftn, a, b, n){
  u <- runif(n, a, b)
  x <- sapply(u, ftn)      # Evaluate function at all points
  return(mean(x) * (b - a))# Multiply by interval width
}
mc_integral(f, 0, 1, 10000) # Converges much faster!
