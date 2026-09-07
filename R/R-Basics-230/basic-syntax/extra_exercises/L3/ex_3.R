# ==========================================
# Exercise 3: Logical Indexing Challenge
# ==========================================
# Generate the vector:
# set.seed(123)
# age <- sample(18:60, 200, replace = TRUE)
#
# 1. Count people:
#    - younger than 25
#    - between 25 and 40
#    - above 40
#
# 2. Find every age divisible by 5.
#
# 3. Find every age that is:
#    - greater than 30 and even
#    - less than 25 or greater than 55
#
# 4. Replace every age below 21 with 21.
# 5. Find the average age after replacement.
# 6. Produce a frequency table.
# 7. Which age occurs most frequently?

set.seed(123)
age <- sample(18:60, 200, replace = TRUE)

sum(age < 25)
sum(age >= 25 & age <= 40)
sum(age > 40)

age[age %% 5 == 0]

age[age > 30 & age %% 2 == 0]
age[age < 25 | age > 55]

age[age < 21] <- 21
avg <- mean(age)
avg
table(age)

# Most frequent age
table_age <- table(age)

names(table_age)[which.max(table_age)]

max(table_age)