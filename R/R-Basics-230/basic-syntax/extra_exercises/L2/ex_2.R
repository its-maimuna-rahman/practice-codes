# ==========================================
# Exercise 2: Vector Types and Missing Values
# ==========================================
# Create the following vectors:
#
# scores <- c(85, 90, NA, 78, 92, NA, 88)
# gender <- c("Male", "Female", "Female", "Male")
# passed <- c(TRUE, TRUE, FALSE, TRUE, FALSE)
#
# For each vector:
# - Determine its type.
# - Check the appropriate is.xxx() function.
#
# Then:
# - Find the length of scores.
# - Calculate the mean of scores.
# - Calculate the mean again by ignoring missing values.
#
# Explain why the two means are different.

scores <- c(85, 90, NA, 78, 92, NA, 88)
gender <- c("Male", "Female", "Female", "Male")
passed <- c(TRUE, TRUE, FALSE, TRUE, FALSE)

typeof(scores)
typeof(gender)
typeof(passed)

is.double(scores)
is.character(gender)
is.logical(passed)

length(scores)
mean(scores)
mean(scores, na.rm = TRUE)