# --- Basic Distributions ---
normal_data <- rnorm(500, mean = 10, sd = 2)
hist(normal_data, main = "normal", col = "pink")

uniform_data <- runif(500, min = 5, max = 15)
hist(uniform_data, main = "uniform", col = "steelblue")

poisson_data <- rpois(200, lambda = 3)
barplot(poisson_data, main = "poisson", col = "maroon")
