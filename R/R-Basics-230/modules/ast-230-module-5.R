# ### 1. Subsetting matrics

mat <- matrix(1:9, nrow = 3)
mat

# Select specific element of a matrix
mat[1,3]    # row 1, col 3
mat[1:2, 3] # row 1 and 2, col 3
mat[, 2:3]  # all row, col 2 and 3
mat[c(1,3), c(1,3)]  # row 1 and 3, col 1 and 3

mat[1, ]   # returns a vector; row 1, all col
mat[ , 3]  # returns a vector; all row, col 3

mat[1, , drop = F]   # returns a matrix; row 1, all col
mat[ , 3, drop = F]  # returns a matrix; all row, col 3


# ### 2. Subsetting dataframes

df <- data.frame(x = 1:4, y = letters[1:4], z = 11:14)
df

str(df)
names(df)
row.names(df)
# #### Positional Indexing

df[1:2, 2:3] 
df[2:3, ] # not specifying column index means we want all columns
df[ ,1:2] # similar

df[c(1, 3), c("x", "z")]

# Extract a specific variable (col) x from data frame

# method 1
df$x

# method 2
df[[1]]

# method 3
df[["x"]]

# method 4
df["x"]

# #### Logical Indexing
df

df[, c("x", "z")]
df[c("x", "z")]

df[c(1, 3), ]
df$x > 2

# Rows that satisfy x>2
df[df$x > 2, ]

# ### Exercise 5

# 1. How many variables are in mtcars? Show the list of these variables.

# 2. Extract the vector mpg from mtcars, and calculate its mean and standard deviation.

# 3. Check whether there is any missing value in wt of mtcars

# 4. Obtain a data frame with mpg > 22

# 5. Obtain a data frame from mtcars with gear=5 and cyl=4 and keep only the variables gear, and cyl

mtcars

# 1
ncol(mtcars)
names(mtcars)

# 2
mtcars_mpg <- mtcars[,"mpg"]
mtcars_mpg
mean(mtcars_mpg)
sd(mtcars_mpg)

# 3
any(is.na(mtcars["wt"]))

# 4
df_mtcars <- mtcars[mtcars$mpg > 22, ]
df_mtcars

# 5
df2_mtcars <- mtcars[mtcars$gear == 5 & mtcars$cyl == 4, c("gear", "cyl")]
df2_mtcars


# ### 3. Subsetting lists

my_list <- list(1:3, "a", c(TRUE, FALSE, FALSE), c(2L, 5L, 9L))
my_list

str(my_list)

typeof(my_list[[1]])
typeof(my_list[1])

my_list[[1]]
my_list[1]

l2 <- list(x = 1:5,
           y = c(TRUE, FALSE),
           z = matrix(1:4, 2))
l2

l2$x
l2[["x"]]
l2["x"]
l2[1]

