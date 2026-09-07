# ================== exercise 1.1 ===================================

# calculate 5 squared
# Add 8 to 22 and then multiply the result by 3
# Divide 8 by 2.5 and then divide the result by 3

print(5*5)
print((8 + 22) * 3)
print((8 / 2.5) / 3)

# ================== exercise 1.2 ===================================

# Create an object x1 with value 73.
# Create x2 as the result of 101+36
# Multiply x1 and x2 and store it in x3.
# Subtract 1 from x3 and calculate its 4th root.
# The answer should be 10.

x1 <- 73
x2 <- 101 + 36
x3 <- x1 * x2
x4 <- (x3 - 1) ** (1 / 4)

print(x4)

# ================== exercise 1.3 ===================================

#Why does this code not work (in the console)?
  
# my_variable <- 10
# my_varıable
#> Error: object 'my_varıable' not found

# bec the spelling is not same of the object (i)


# ================== exercise 1.4 ====================================

# 1. Create an object myObject with a value between 1 and 100.
# 2. Add 13 to myObject and update the object.
# 3. Check if myObject is divisible by 2, 3, 13, or 21.
# 4. How many times can 5 fit into myObject?

myObject <- 29
myObject <- myObject + 13
cat("\nthe object is ", myObject, "\n")

if(myObject %% 2 == 0) {
  print("the object is divisible by 2")
  
} else {
  print("the object is NOT divisible by 2")
}

if(myObject %% 3 == 0) {
  print("the object is divisible by 3")
  
} else {
  print("the object is NOT divisible by 3")
}

if(myObject %% 13 == 0) {
  print("the object is divisible by 13\n")
  
} else {
  print("the object is NOT divisible by 13")
}

if(myObject %% 21 == 0) {
  print("the object is divisible by 21")
  
} else {
  print("the object is NOT divisible by 21")
}

counter_of_5 <- 0

for(i in 1:myObject) {
  if(i %% 5 == 0) {
    counter_of_5 = counter_of_5 + 1
  }
}

cat("total number of 5 fits : ", counter_of_5, "\n\n")

# ================== exercise 1.5 ====================================

x <- 5
y <- 10
print(x + y)