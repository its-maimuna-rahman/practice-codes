# ==========================================
# Exercise 6: Matrix Without matrix()
# ==========================================

vec <- 1:24
vec

# 1. Convert it into a 4 × 6 matrix
dim(vec) <- c(4, 6)
vec

# 2. Verify its attributes
attributes(vec)
# or
dim(vec)

# 3. Convert it into a 6 × 4 matrix
dim(vec) <- c(6, 4)
vec

# 4. Convert it into a 2 × 3 × 4 array
dim(vec) <- c(2, 3, 4)
vec

# 5. Print the second slice
vec[, , 2]

# 6. Determine:
#    - number of rows
#    - number of columns
#    - total number of elements

rows <- dim(vec)[1]
cols <- dim(vec)[2]
total_elements <- length(vec)

rows
cols
total_elements