# ### 1. Combining vectors

x <- c(10, 500)
c(1:3, x, 1000, x+1, x*2)

# ### 2. Arithmetic operations and functions

z <- c(4, 5, 6, 1, 7, 1, 4, 1)

log(z)
sort(z)     # acsending sorting
sort(z, decreasing = T)
order(z)    # position of element of sorted version
table(z)    # frequency distribution
unique(z)   # removes duplicate

y <- c(100, 3)
x*y

# ### 3. The recycling rule of vectors

# It is not necessary to have vectors of the same length in an expression

# If two vectors in an expression are not of the same length then the shorter one will be repeated until it has the same length as the longer one.

m <- c(1, 2, 3); n <- c(3, 4, 5, 7, 50)
m*n

# ### 4. Extracting elements of vectors

age <- c(11, 9, 8, 10, 5)
age

# 3rd element
age[3]

# 2nd and 4th element
age[c(2, 4)]

# if want to exclude specific element
age[-c(1, 3)]

# ### 5. Indexing vectors with \[\] (Logical indexing)

age
age >= 8
sum(age >= 8)   # it shows how many children are above 8, 
                # not the sum of their age (frequency)
age[age >= 8]   # shows element that are above 8 (element)

# childern with age 11 or 8 years
age[age %in% c(8, 11)]

# Children with ages not equal to 11 or 8 years
age[!age %in% c(8, 11)]

# Observations with age greater than 9 or less than 8
age[age > 9 | age < 8]

# Observations with ages between 8 to 10 inclusive
age[age >= 8 & age <= 10]

# The mean age of observations between 8 to 10 inclusive
mean(age[age >= 8 & age <= 10])

# ### 6. Replacing elements

# changing values of a vector
age_rep <- age
age_rep

# changing element
age_rep[1] <- 15
age_rep

age_rep[age_rep > 9] <- 20
age_rep

# ## Exercise 3

# The following code generates a vector nage of size 1000. set.seed(100) nage \<- sample(x = 30:80, size = 1000, replace = T)

# Show that the number of observations 1. greater than 70 is 176
# 2.less than 40 is 185
# 3. equal to 39 is 19
# 4. greater than 77 or less than 35 is 140
# 5. between 50 and 55 (inclusive) is 110
# 6. What percentage of observations lies between 70 to 75 (inclusive)?

set.seed(100)
nage <- sample(x = 30:80, size = 1000, replace = T)

sum(nage > 70)
sum(nage < 40)
sum(nage == 39)
sum(nage > 77 | nage < 35)
sum(nage >= 50 & nage <= 55)
(sum(nage >= 70 & nage <= 75) / 1000) * 100

# ### 7. Handling missing value

mval <- c(12:15, NA)
mval

mean(mval)
mean(mval, na.rm = T)
is.na(mval)

sum(!is.na(mval))
sum(is.na(mval))

# ### 8. Coercion

# In R, atomic vectors are homogeneous, i.e., all elements of an atomic vector will be of the same data type

# An atomic vector with more than one data type, e.g. nvec \<- c(1, 2, "x"), then R will create an atomic vector, i.e. all elements of nvec will be of the same data type, which is known as coercion

nvec <- c(1, 2, "all")
nvec

typeof(nvec)

c(1L, 5L, FALSE, TRUE)
typeof(c(1L, 2L, 4.0))

typeof(c(2.0, "new"))
typeof(1:5)

p <- c("a", "b", "0", "522")
as.numeric(p)

# ### 9. Attribute

# an atomic vector that initially has no attributes
die <- 1:6
attributes(die)

# Setting an attribute named "x"
attr(die, "x") <- "abcd"
attributes(die)

die

# ### 10. Names (an attribute of an R object)

# Naming vector when creating it:
n <- c(a = 1, b = 2, c = 3)
n

# Naming vector by assigning a character vector to names()

m <- 1:3
m

names(m) <- c("a", "b", "c")
m

# Subsetting vector by names
n[["a"]]

# ### 11. Dimentions

# Adding the dim attribute
die1 <- 1:6

dim(die1) <- c(2, 3)
die1

dim(die1) <- c(3,2)
die1

attributes(die1)

# 3d array

# Creating 3 dimensional array 
# by adding dim attributes
die <- 1:6
dim(die) <- c(1, 2, 3)
die

# Creating 3 dimensional array 
# by adding dim attributes
die12 <- 1:12
dim(die12) <- c(2, 2, 3)
die12
