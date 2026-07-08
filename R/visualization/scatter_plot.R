data <- read.csv("ai_student_impact_dataset.csv")

# scatter plot
pdf("gpa_vs_ai_plot.pdf")
par(bg = "black", fg = "white")
plot(x = data$Perceived_AI_Dependency,
     y = data$Post_Semester_GPA,
     col.main = "white",
     col.lab = "white",
     col.axis = "white",
     col = "pink",                             # Line/point color
     type = "p",
     main = "Post GPA vs AI Dependency",
     xlab = "AI Dependency",
     ylab = "Post GPA",
     pch = 19,                                 # Solid circles for points
     cex = 0.1)                                # Point size

dev.off()