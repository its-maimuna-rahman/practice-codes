# cdf inversion of pareto distribution
generate_pareto <- function(n, xm, alpha) {
  U <- runif(n)
  X <- xm / (1-U)^(1/alpha)
  return(X)
}

set.seed(456)
pareto <- generate_pareto(n=100, xm=100, alpha=2)
hist(pareto, breaks = 200, col = "maroon")