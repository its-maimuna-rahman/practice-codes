# ==========================================
# Exercise 1: Vector Analysis
# ==========================================
# Create the vector:
# c(12, 18, 25, 31, 42, 56, 63, 77)
#
# Without modifying the vector:
# 1. Find its type.
# 2. Find its length.
# 3. Calculate the mean, variance and standard deviation.
# 4. Store each result in separate objects.
# 5. Verify whether the vector is integer or double.

vec <- c(12, 18, 25, 31, 42, 56, 63, 77)
vec_type <- typeof(vec)
vec_length <- length(vec)
vec_mean <- mean(vec)
vec_variance <- var(vec)
vec_std_dev <- sd(vec)

cat("type = ", vec_type, "\n")
cat("length = ", vec_length, "\n")
cat("mean = ", vec_mean, "\n")
cat("variance = ", vec_variance, "\n")
cat("standard deviation = ", vec_std_dev, "\n")

is.integer(vec)
is.double(vec)
