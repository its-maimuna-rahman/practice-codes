# Setup Code
set.seed(016) # Example: set.seed(007)
ages <- rnorm(150, mean = 40, sd = 10) |> floor()
weights <- rnorm(150, mean = 70, sd = 10) |> floor()

ages
weights

# 1. Compute the mean, median, and standard deviation of ages.
mean(ages)
median(ages)
sd(ages)

# 2. Write one line of code to count how many individuals have age > 30.
sum(ages > 30)

# 3. Calculate each individual's BMI using the formula: BMI = weight / 1.7^2
#    and save it as a vector named bmi.
bmi <- weights / 1.7^2
bmi

# 4. From ages, extract all values between 20 and 30 (inclusive).
ages[ages >= 20 & ages <= 30]

# 5. Replace every value below 32 in ages with NA and report the total number
# of missing values.
ages[ages < 32] <- NA
sum(is.na(ages))

# 6. Create a logical vector indicating which BMI values exceed 30.
bmi_30 <- bmi > 30
bmi_30  
  
# 7. Combine ages, weights, and bmi into a data frame named health_df. 
#    Convert the data frame into a tibble.
library(tibble)
health_df <- data.frame(ages, weights, bmi)
health_df <- as_tibble(health_df) 

# 8. Add a new column gender where two consecutive entries are "Male"
# followed by one "Female". Start with a Male.
health_df$gender <- rep(c("Male", "Male", "Female"),
                        length = nrow(health_df))
health_df

# 9. Convert health_df (excluding gender) to a matrix and find column-wise means.
health_matrix <- as.matrix(health_df[, c("ages", "weights", "bmi")])
colMeans(health_matrix, na.rm = T)

# 10. Show only ages and bmi for female participants aged 60 or older.
female_60 <- health_df$gender == "Female" & health_df$ages >= 60 & !is.na(health_df$ages)
health_df[female_60, c("ages", "bmi")]

# 11. Sort the data frame by bmi in descending order and display the top five
# rows.
ordered_bmi <- order(health_df$bmi, decreasing = TRUE)
sorted_bmi <- health_df[ordered_bmi, ]
head(sorted_bmi, 5)

# 12. Using a for loop, add another column age_group such that
#     - "Young" if age < 25,
#     - "Middle" if 25 <= age <= 35,
#     - "Older" otherwise.

health_df$age_group <- NA
for(i in 1:nrow(health_df)) {
  if(is.na(health_df$ages[i])) health_df$age_group[i] <- NA
  else if(health_df$ages[i] < 25) health_df$age_group[i] <- "Young"
  else if(health_df$ages[i] <= 35) health_df$age_group[i] <- "Middle"
  else health_df$age_group[i] <- "Older"
}

health_df$age_group

# 13. Find the average BMI for each gender in health_df.
aggregate(bmi ~ gender, data = health_df, FUN = mean)
