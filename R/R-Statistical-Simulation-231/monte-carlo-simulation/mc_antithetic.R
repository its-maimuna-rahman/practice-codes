N <- 50; n <- 5
g <- function(x) 1 - x^2

# standard mc
u_std <- matrix(runif(2*N*n), ncol = N)
theta_std <- colMeans(g(u_std)) 

# antithetic mc
u_anti <- matrix(runif(N*n), ncol = N)
theta_anti <- 0.5 * (colMeans(g(u_anti)) + colMeans(g(1 - u_anti)))

cat("var std = ", var(theta_std), "| var anti = ", var(theta_anti))



# ------------- Antithetic for Beta Function B(0.5, 2) ------------------------
beta_anti <- function(a, b, n=10, N=100) {
  ftn <- function(x) x^(1-a) * (1-x)^(1-b)
  
  u.b_std <- matrix(runif(n*N), ncol = N)
  theta.b_std <- colMeans(matrix(ftn(u_std), ncol = N))
  
  u.b_anti <- matrix(runif(n*N/2), ncol = N/2)
  theta1.b_anti <- colMeans(matrix(ftn(u_anti), ncol = N/2))
  theta2.b_anti <- colMeans(matrix(ftn(1 - u_anti), ncol = N/2))
  theta.b_anti <- 0.5 * (theta1.b_anti + theta2.b_anti)
  
  cat("mean std = ", mean(theta.b_std), "| mean anti = ", mean(theta.b_anti), "\n")
  cat("var std = ", var(theta.b_std), "| mean var = ", var(theta.b_anti), "\n")
}

result_beta <- beta_anti(0.5, 2)

# ------------ Antithetic for Normal Distribution -----------------

antithetic_normal <- function(n = 1000, mu = 0, sigma = 1) {
  U <- runif(n/2)
  X1 <- qnorm(U, mu, sigma)
  X2 <- qnorm(1-U, mu, sigma)  # Antithetic pair
  return(c(X1, X2))
}
anti_norm <- antithetic_normal(10000)
std_norm <- rnorm(10000)
cat("Correlation between pairs:", cor(qnorm(U), qnorm(1-U)), "\n") # Should be -1



# ------ Estimating integral of e^x from 0 to 1 (True value = e-1 ≈ 1.718) ----
f_exp <- function(x) exp(x)
n_sims <- 1000
samples_per_sim <- 100

# Standard MC
U_std <- matrix(runif(n_sims * samples_per_sim), nrow = samples_per_sim)
est_std <- colMeans(apply(U_std, 2, f_exp))

# Antithetic MC
U_anti <- matrix(runif(n_sims * samples_per_sim / 2), nrow = samples_per_sim / 2)
est1 <- apply(U_anti, 2, f_exp)
est2 <- apply(1 - U_anti, 2, f_exp)
est_anti <- colMeans((est1 + est2) / 2)

cat("Variance Standard:", var(est_std), "\n")
cat("Variance Antithetic:", var(est_anti), "\n")
cat("Variance Reduced by:", 100 * (1 - var(est_anti)/var(est_std)), "%\n")