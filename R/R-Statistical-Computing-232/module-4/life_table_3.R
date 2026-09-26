life_table <- function(age, n, nMx, l0=100000) {
  
  last <- length(nMx)
  
  nqx <- 1 - exp(-n * nMx)
  nqx[last] <- 1
  npx <- 1 - nqx
  
  lx <- l0 * cumprod(c(1, npx[-last]))
  ndx <- lx * nqx
  
  nLx <- numeric(last)
  for(i in 1:(last-1)) {
    nLx[i] <- (n[i]/2) * (lx[i] + lx[i+1])
  }
  nLx[last] <- lx[last] / nMx[last]
  
  Tx <- rev(cumsum(rev(nLx)))
  ex <- Tx / lx
  
  lt <- data.frame(age, n, nMx, nqx, npx, lx, ndx, nLx, Tx, ex)
}

age <- c(0, 5, 10, 15, 20, 25, 30, 35, 40, 45)
n <- c(5, 5, 5, 5, 5, 5, 5, 5, 5, NA)
nMx <- c(0.0070, 0.0010, 0.0010, 0.0015, 0.0020, 
         0.0030, 0.0040, 0.0055, 0.0080, 0.0320)

life_tab <- life_table(age, n, nMx)
life_tab