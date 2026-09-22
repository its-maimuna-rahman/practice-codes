# # --- 1. Basic Reproducibility ---

# run 1
set.seed(123)
sample1 <- runif(5)
cat("1st run, seed 123 = ", sample1, "\n")

# run 2
set.seed(123)
sample2 <- runif(5)
cat("2nd run, seed 123 = ", sample1, "\n")

cat("comparison : ", all.equal(sample1, sample2), "\n")

# run 3
set.seed(123)
sample1 <- runif(5)
cat("3rd run, seed 123 = ", sample1, "\n")

# --- 2. Save, Advance, Restore ---
set.seed(100)
RNG_state <- .Random.seed

u1 <- runif(2)
u2 <- runif(2)

u1
u2

.Random.seed <- RNG_state    # Save state S0
v <- runif(4)
v

print(identical(v, c(u1, u2)))

# --- 3. Branching ---
set.seed(2025)
base_state <- .Random.seed

.Random.seed <- base_state
a <- runif(2)                # branch a

.Random.seed <- base_state   # restore seed
b <- runif(5)                # branch b

a
b

cat("is indentical : ", identical(b[1:2],a))

# --- 4. Inspecting State ---
set.seed(1)
str(.Random.seed)
RNGkind()