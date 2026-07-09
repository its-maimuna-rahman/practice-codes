# ============================================
# Exercise 3: Sequence Construction and rep
# ============================================

# make the vector : 
# (1,2,3,4,5,10,20,30,40,50,100,200,300,-3,-2,-1,0,1,2,3)
# Use only: c(), :, seq()

obj <- c(1:5, seq(from = 10, to = 50, by = 10), seq(100, 300, by = 100), -3:3)
print(obj)

# Construct the following vectors using rep().
# A. ("A","A","B","B","C","C")
# B. (TRUE,FALSE,TRUE,FALSE,...) -> Length = 20

rep(c("A", "B", "C"), each = 2)
rep(c(TRUE, FALSE), times = 10)





