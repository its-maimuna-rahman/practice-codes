# ==========================================
# Exercise 2: Object Assignment and Updating
# ==========================================
# Create the following objects:
# length = 15
# width = 9
#
# Then:
# - Calculate area.
# - Calculate perimeter.
# - Increase length by 5 and update the object.
# - Recalculate the new area.
#
# Do not type the numbers again after creating the objects.

length <- 15
width <- 9

area <- length * width
perimeter <- 2 * (length + width)

cat("area = ", area, "\n")
cat("perimeter = ", perimeter, "\n")

length <- length + 5
area2 <- length * width

cat("new area = ", area2, "\n")