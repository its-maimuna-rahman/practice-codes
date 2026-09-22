# ============================================
# LAB 4: Estimate Pi Using Hit-and-Miss
# ============================================

# Problem: Estimate π by computing area of quarter circle
# ∫₀¹ √(1-x²) dx = π/4

monte_carlo_pi_hitmiss <- function(n) {
  # Generate n random points in unit square [0,1] × [0,1]
  x <- runif(n)
  y <- runif(n)
  
  # Count points under quarter circle: y <= sqrt(1-x^2)
  inside <- sum(y <= sqrt(1 - x^2))
  
  # Area of square = 1, so estimate = proportion inside
  pi_estimate <- 4 * (inside / n)
  return(pi_estimate)
}
# xxxxxxxxxxxxxxxxxxxx main code over xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

# Test with different sample sizes
sample_sizes <- c(100, 1000, 10000, 100000)
pi_estimates <- sapply(sample_sizes, monte_carlo_pi_hitmiss)

results <- data.frame(
  Sample_Size = sample_sizes,
  Pi_Estimate = pi_estimates,
  Error = abs(pi_estimates - 3.14159265359) 
)

print(results)

# Visualization for n=10000
set.seed(2026)
n_viz <- 10000
x_viz <- runif(n_viz)
y_viz <- runif(n_viz)
inside_viz <- y_viz <= sqrt(1 - x_viz^2)

plot(x_viz, y_viz, pch = 20, cex = 0.5,
     col = ifelse(inside_viz, "steelblue", "pink"),
     main = paste("Hit-and-Miss Estimation of π (n =", n_viz, ")"),
     xlab = "x", ylab = "y",
     xlim = c(0, 1), ylim = c(0, 1))

# Add quarter circle
theta <- seq(0, 3.14159265359/2, length.out = 100)
lines(cos(theta), sin(theta), col = "black", lwd = 2)
