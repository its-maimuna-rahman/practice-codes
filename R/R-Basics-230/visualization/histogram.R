data <- read.csv("ai_student_impact_dataset.csv")

# histogram
pdf("pre_semester_gpa_histogram.pdf")
par(bg = "black", fg = "white")
h <- hist(data$Pre_Semester_GPA,
          main = "Pre Semester GPA",
          col = "pink",
          xlab = "GPA",
          ylab = "Frequency",
          breaks = 14,
          labels = TRUE,
          axes = "FALSE")

# 4. Draw the custom X-axis using R's perfectly calculated class intervals (h$breaks)
axis(side = 1, at = h$breaks, col = "white", col.axis = "white")

# 5. Draw the custom Y-axis
axis(side = 2, col = "white", col.axis = "white", las = 1)

dev.off()