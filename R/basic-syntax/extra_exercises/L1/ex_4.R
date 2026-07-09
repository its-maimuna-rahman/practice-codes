# ==========================================
# Exercise 4: Mini Script
# ==========================================
# Write a script that:
#
# - Takes input of your age.
# - Takes input of your weight.
# - Takes input of your height.
# - Calculates BMI.
# - Rounds BMI to 2 decimal places.
# - Finds how many times 5 fits into your age.
# - Finds the remainder.
# - Prints every result.
# - Uses at least 5 comments.

# Take user input
weight <- as.numeric(readline(prompt = "Enter your weight (kg): "))
height <- as.numeric(readline(prompt = "Enter your height (m): "))
age <- as.numeric(readline(prompt = "Enter your age: "))

bmi <- weight / height^2
bmi_round <- round(bmi, digits = 2)
times5 <- age %/% 5
remainder5 <- age %% 5

cat("\n----- Results -----\n")
cat("Weight:", weight, "kg\n")
cat("Height:", height, "m\n")
cat("Age:", age, "years\n")
cat("BMI:", bmi, "\n")
cat("Rounded BMI:", bmi_round, "\n")
cat("5 fits into age", times5, "times.\n")
cat("Remainder:", remainder5, "\n")