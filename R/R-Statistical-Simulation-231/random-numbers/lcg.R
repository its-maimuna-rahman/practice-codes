# Linear Congruential Generator

# LCG function
lcg_generator <- function(n, seed, a = 1103515245, c = 12345, m=2^31 - 1) {
  
  x <- numeric(n)
  x[1] <- seed
  
  for(i in 2:n) {
    x[i] <- (a * x[i-1] + c) %% m
  }
  
  # uniform conversion
  u <- x / m
  
  return (u)
}

# test the generator
random_numbers <- lcg_generator(1000, 42)
mean(random_numbers)   # should be close to 0.5

par(mfrow = c(1, 2))

hist(random_numbers, 
     breaks = 30, 
     main = "LCG-Generated Numbers",
     xlab = "Value", 
     col = "steelblue")


# Compare Custom LCG with R's runif()
set.seed(42)
r_random <- runif(1000)

hist(r_random,
     breaks = 30,
     main = "R's runif()",
     xlab = "value",
     col = "steelblue")

par(mfrow = c(1,1))

# statistical comparison
cat("R's runif() : mean =", mean(r_random), "SD = ", sd(r_random), "\n")
cat("LCG function : mean =", mean(random_numbers), "SD = ", sd(random_numbers), "\n")