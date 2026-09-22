# cdf inversion of weibull distribution

generate_weibull <- function(n, k, lambda) {
  U <- runif(n)
  X <- lambda * (-log(1-U))^(1/k)
  
  return(X)
}

set.seed(448)
weibull <- generate_weibull(n=1000, k=1.5, lambda=2)
hist(weibull, breaks = 200, col = "maroon")