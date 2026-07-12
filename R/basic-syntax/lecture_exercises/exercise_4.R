# 1. Create a vector called x consisting of the first fifteen integers of the
#number line.

x <- 1:15

# 2. Use the function dim() to assign dimension to vector x with three rows and 
#    five columns. What is the class of x now?

dim(x) <- c(3, 5)
class(x) # It becomes a "matrix" (and an "array")

# 3. Given the following matrices,
#    A = [ 2  9  0  0 ]     b = [ -1 ]
#        [ 0  4  1  4 ]         [  6 ]
#        [ 7  5  5  1 ]         [  0 ]
#        [ 7  8  7  4 ]         [  9 ]

A <- matrix(c(2, 9, 0, 0,
              0, 4, 1, 4, 
              7, 5, 5, 1, 
              7, 8, 7, 4), byrow = TRUE, nrow = 4)

b <- matrix(c(-1, 6, 0, 9), nrow = 4)

# i. Calculate A^T * b.
t(A) %*% b

# ii. Find the inverse of matrix A.
solve(A)

# iii. Solve the equation for x, where Ax = b.
solve(A, b)

# 4
# i. Generate a vector x0 of order 20 with all elements as 1
x0 <- rep(1, 20)

# ii. Generate a vector x1 of order 20 with elements randomly selected from 30:70, 
#     consider a seed 80
set.seed(80)
x1 <- sample(30:70, 20, replace = TRUE)

# iii. Create a matrix X with the first column x0 and the second column x1
X <- cbind(x0, x1)

# iv. Generate a vector Y of order 20 using the equation y_i = 1.2 + 1.8*x1 + e_i, 
#     where e_i ~ N(0, 9)
#     Note: Since variance = 9, the standard deviation is sqrt(9) = 3 for rnorm()

epsilon <- rnorm(20, mean = 0, sd = 3)
Y <- 1.2 + 1.8 * x1 + epsilon

# v. Obtain the value of (X'X)^(-1)X'Y, use the R function solve() to obtain 
#    an inverse of a square matrix

beta_hat <- solve(t(X) %*% X) %*% t(X) %*% Y

# Print the resulting OLS parameter estimates (intercept and slope)
print(beta_hat)
