# life table funtion

age      <- c(0, 5, 10, 15, 20, 25, 30, 35, 40, 45)
n        <- c(5, 5, 5, 5, 5, 5, 5, 5, 5, NA)   # last band is open
nMx      <- c(0.0060, 0.0008, 0.0008,
              0.0012, 0.0018, 0.0025,
              0.0035, 0.0050, 0.0075,
              0.0300)
l0 <- 100000

life_table <- function(age, n, nMx, l0) {
  
  last <- length(nMx)
  
  nqx <- 1 - exp(-n * nMx)
  nqx[last] <- 1
  npx <- 1 - nqx
  
  lx <- l0 * cumprod(c(1, npx[-last]))
  ndx <- lx * nqx
  
  nLx <- numeric(last)
  for(i in 1:(last-1)) {
    nLx[i] <- (n[i] / 2) * (lx[i] + lx[i+1])
  }
  nLx[last] <- lx[last] / nMx[last]
  
  Tx <- rev(cumsum(rev(nLx)))
  ex <- Tx / lx
  
  lt <- data.frame(age, n, nMx, nqx, npx, lx, ndx, nLx, Tx, ex)
}

lt <- life_table(age, n, nMx, l0)
lt