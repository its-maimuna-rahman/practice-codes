# ### 1. Vector and it's basic functions

vec1 <- c(2, 3, 1, 6, 4, 3, 3, 7)
vec1

typeof(vec1)
mean(vec1)
var(vec1)
sd(vec1)
length(vec1)
is.logical(vec1)
is.double(vec1)

# ### 2. Logical vector

vec2 <- c(TRUE, FALSE, TRUE)
vec2

typeof(vec2)
is.logical(vec2)
is.character(vec2)

# ### 3. logical operations

10 == 15
10 != 15
10 > 15
10 < 15

3 == 3
3 != 3
3 > 3
3 >= 3
3 < 3
3 <= 3

# ### 4. Numeric vectors

# double
vec3 <- c(1., 5.5, 20.134, .32)
vec3

typeof(vec3)
is.double(vec3)

# even though int numbers are double by default,
# they can be made strictly int by adding L

vec4 <- c(5L, 10L, 15L)
typeof(vec4)
is.double(vec4)
is.integer(vec4)

# ### 5. Character vectors

vec5 <- c("boy", "girl", "boy", "girl")
vec5

typeof(vec5)
is.character(vec5)

# ### 6. Missing Values

# NULL ---> absence of a vector
vec6 <- NULL
vec6 <- c(vec6, 10)
vec6

# NA ---> represent the absence of a value in a vector
vec7 <- c(18, 21, NA, 25)
vec7

# ### 7. Sequence of numbers

# Sometimes it can be useful to create a vector that contains a regular sequence of values in steps of one.

seq1 <- 1:10
seq1

seq2 <- 8:-4
seq2

# ### 8. seq() function

seq(from = 1, to = 5, by = 0.5)
seq(1, 10, by = 2)

seq(1, 5, length.out = 8)

# ### 9. Repeat vectors using rep()

rep(2, times = 10)
rep("meow", time = 100)

rep(c("meow", "mooo"), each = 3)

rep(c("meow", "mooo"), each = 2, times = 3)

# vector with "each" creates like a single iteration of a sequence (like a loop); and "times" is the number of iteration

rep(c("meow", "mooo"), length.out = 6)

# ### Exercise 2

# 1.  Create the vector (1, 2, 3, 4, 5, 6, 7, 8, 9, 10) in three ways: using c(), :, and seq()

c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
1:10
seq(1,10)

# 2.  Create the vector (2.1, 4.1, 6.1, 8.1) in two ways: using c() and once seq()

c(2.1, 4.1, 6.1, 8.1)
seq(2.1, 8.1, length.out = 4)

# 3.  Create the vector (0, 5, 10, 15) in 3 ways: using c(), seq() with a by argument, and seq() with a length.out argument.

c(0, 5, 10, 15)
seq(0, 15, by = 5)
seq(0, 15, length.out = 4)

# 4.  Generate the following sequences using rep() or seq() functions.

# <!-- -->

# i)  (1, 1, 2, 2, 3, 3, 4, 4)
# ii) (1, 2, 2, 3, 3, 3, 4, 4, 4, 4)
# iii) (-0.50, -0.25, 0, 0.25, 0.5, 0.75, 1)

rep(1:4, each = 2)
rep(1:4, times = 1:4)
seq(-0.50, 1, length.out = 7)

# 5.  Create the vector (101, 102, 103, 200, 205, 210, 1000, 1100, 1200) using a combination of the c() and seq() functions.

c(seq(101, 103), seq(200, 210, by = 5), seq(1000, 1200, by = 100))

# 6.  Create a vector that repeats the integers from 1 to 5, 10 times, i.e. (1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...), and the length of the vector should be 50!

rep(1:5, times = 10, length.out = 50)

# 7.  Create the same vector as before, but this time repeat 1, 10 times, then 2, 10 times, etc., i.e. (1, 1, 1,..., 2, 2, 2,..., 5, 5, 5) and the length of the vector should also be 50

rep(1:10, each = 10, length.out = 50)
