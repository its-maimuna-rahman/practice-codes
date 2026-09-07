# ==========================================
# Exercise 2: Vectorized Data Cleaning
# ==========================================
# 1. Count the number of missing values.
# 2. Count the number of available values.
# 3. Compute the mean ignoring NA.
# 4. Replace every NA with the mean of the available scores.
# 5. Replace every score below 40 with 40.
# 6. Count how many students now have marks >= 80.
# 7. Produce a frequency table of the cleaned scores.

scores <- c(45, NA, 78, 90, 65, 34, NA, 88, 72, 51, 100, 29, NA, 83)

sum(is.na(scores))
sum(!is.na(scores))

mean_score <- mean(scores, na.rm = TRUE)
mean_score

scores[is.na(scores)] <- mean_score
scores[scores < 40] <- 40
scores

sum(scores >= 80)
table(scores)