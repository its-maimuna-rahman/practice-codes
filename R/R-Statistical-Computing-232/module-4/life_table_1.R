# Dhaka District 2024, abridged age specific death rates (per person year)
age      <- c(0, 5, 10, 15, 20, 25, 30, 35, 40, 45)
n        <- c(5, 5, 5, 5, 5, 5, 5, 5, 5, NA)   # last band is open
nMx      <- c(0.0060, 0.0008, 0.0008,
              0.0012, 0.0018, 0.0025,
              0.0035, 0.0050, 0.0075,
              0.0300)

lt <- data.frame(age, n, nMx)
l0 <- 100000      # standard radix
lt

# nqx calc
lt$nqx <- 1-exp(-lt$n * lt$nMx)
last <- nrow(lt)
lt$nqx[last] <- 1
# npx calc
lt$npx <- 1 - lt$nqx


# lx clac
lt$lx <- l0 * cumprod(c(1, lt$npx[-last]))
# ndx calc
lt$ndx <- lt$lx * lt$nqx

# sanity check
sum(lt$ndx) # ans should be 100000
lt$lx[last] == lt$ndx[last] # should be true


#nLx clac

# closed band
for(i in 1:(last-1)) {
  lt$nLx[i] <- (lt$n[i] / 2) * (lt$lx[i] + lt$lx[i+1])
}

# open band
lt$nLx[last] <- lt$lx[last] / lt$nMx[last]

# Tx calc
lt$Tx <- rev(cumsum(rev(lt$nLx)))
# ex calc
lt$ex <- lt$Tx / lt$lx

lt