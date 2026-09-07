#The following code generates a vector nage of size 1000.
#set.seed(100)
#nage <- sample(x = 30:80, size = 1000, replace = T)

#Show that the number of observations
# 1. greater than 70 is 176
# 2.less than 40 is 185
# 3. equal to 39 is 19
# 4. greater than 77 or less than 35 is 140
# 5. between 50 and 55 (inclusive) is 110
# 6. What percentage of observations lies between 70 to 75 (inclusive)?

set.seed(100)
nage <- sample(x = 30:80, size = 1000, replace = T)
print(nage)

cat("\n")
sum(nage > 70)                   # 1
sum(nage < 40)                   # 2
sum(nage == 39)                  # 3
sum(nage > 77 | nage < 35)       # 4
sum(nage >= 50 & nage <= 55)     # 5

(sum(nage >= 70 & nage <= 75) / 1000) * 100    # 6

