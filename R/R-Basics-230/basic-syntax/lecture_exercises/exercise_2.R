# 1. Create the vector (1, 2, 3, 4, 5, 6, 7, 8, 9, 10) in three ways:
#  using c(), :, and seq()

vec <- c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
print(vec)

print(1:10)

seq(from = 1, to = 10)

cat("\n")

# 2. Create the vector (2.1, 4.1, 6.1, 8.1) in two ways:
#  using c() and once seq()

vec2 <- c(2.1, 4.1, 6.1, 8.1)
print(vec2)

seq(from = 2.1, to = 8.1, by = 2)

cat("\n")

# 3. Create the vector (0, 5, 10, 15) in 3 ways:
#  using c(), seq() with a by argument, and seq() with a length.out argument.

vec3 <- c(0, 5, 10, 15)
print(vec3)

seq(from = 0, to = 15, by = 5)
seq(from = 0, to = 15, length.out = 4)

cat("\n")

# 4. Generate the following sequences using rep() or seq() functions.
# i) (1, 1, 2, 2, 3, 3, 4, 4)
# ii) (1, 2, 2, 3, 3, 3, 4, 4, 4, 4)
# iii) (-0.50, -0.25, 0, 0.25, 0.5, 0.75, 1)

cat("i)\n")
rep(1:4 , each = 2)

cat("\nii)\n")
rep(1:4, times = 1:4)

cat("\niii)\n")
seq(from = -0.50, to = 1, by = 0.25)

cat("\n")

# 5. Create the vector (101, 102, 103, 200, 205, 210, 1000, 1100, 1200) using a 
# combination of the c() and seq() functions.

vec5 <- c(seq(101, 103), seq(200, 205, by = 5), seq(1000, 1200, by = 100))
print(vec5)

cat("\n")

# 6. Create a vector that repeats the integers from 1 to 5, 10 times, i.e. (1, 2,
# 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...), and the length of the vector should
# be 50!

rep(1:5, times = 10, lenght = 50)
cat("\n")
  
#  Create the same vector as before, but this time repeat 1, 10 times, then
# 2, 10 times, etc., i.e. (1, 1, 1,..., 2, 2, 2,..., 5, 5, 5) and the length
# of the vector should also be 50

rep(1:5, each = 10, length = 50)
cat("\n")
