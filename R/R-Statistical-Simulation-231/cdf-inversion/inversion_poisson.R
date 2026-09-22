# cdf inversion of poisson distribution

generate_poisson <- function(n, lambda) {
  X <- numeric(n) # Vector to store our simulated Poisson values
  
  for (i in 1:n) {
    U <- runif(1) # Generate a standard uniform random variable
    
    k <- 0
    p <- exp(-lambda) # Probability mass function (PMF) at k = 0
    F_k <- p          # Initial Cumulative Distribution Function (CDF) total
    
    # Keep summing probabilities until the cumulative step covers U
    while (U > F_k) {
      k <- k + 1
      # Efficiently compute the next probability: p_k = p_{k-1} * (lambda / k)
      p <- p * (lambda / k) 
      F_k <- F_k + p
    }
    
    X[i] <- k # Assign the resulting count to our data vector
  }
  
  return(X)
}

# Run the simulation
set.seed(123)
my_poisson_data <- generate_poisson(n = 1000, lambda = 4)