# ==========================================
# Exercise 1: Student Marks Analysis
# ==========================================
# A teacher recorded the marks of 15 students.
#
# 1. Find the mean, median, variance and standard deviation.
# 2. Find the minimum, maximum and range.
# 3. Sort the marks in both ascending and descending order.
# 4. Find the positions of the five highest marks.
# 5. Count how many students scored:
#    - at least 80
#    - below 60
#    - between 60 and 80 (inclusive)
# 6. Replace every mark below 50 with 50.
# 7. Calculate the new mean.

marks <- c(78, 45, 91, 67, 88, 53, 72, 99, 61, 84, 75, 59, 93, 80, 68)

# Summary statistics
marks_mean <- mean(marks)
marks_median <- median(marks)
marks_var <- var(marks)
marks_sd <- sd(marks)

marks_mean
marks_median
marks_var
marks_sd

# Minimum, maximum and range
min(marks)
max(marks)
range(marks)

# Sorting
sort(marks)
sort(marks, decreasing = TRUE)

# highest 5
order(marks, decreasing = TRUE) [1:5]

# counts
sum(marks >= 80)
sum(marks < 60)
sum(marks >= 60 & marks <= 80)

# replace to 50
marks[marks < 50] <- 50
print(marks)

new_mean <- mean(marks)
new_mean