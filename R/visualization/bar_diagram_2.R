data <- read.csv("ai_student_impact_dataset.csv")

# stacked bar diagram
pdf("stacked_bar.pdf", width = 8, height = 10)
par(bg = "black", fg = "white", mar = c(3, 5, 6, 5))
count <- table(data$Paid_Subscription, data$Year_of_Study)

# sorting however I want
order_year <- c("Freshman", "Sophomore", "Junior", "Senior", "Graduate")
count_custom <- count[, order_year]

b <- barplot(count_custom,
             col = c("maroon", "pink"),
             col.main = "white", col.lab = "white", col.axis = "white",
             main = "Year of Study and Prompt Skill comparison",
             ylab = "frequency",
             border = "white",
             space = 0.2)

legend("topright",                      # Where to place it ("topright", "topleft", etc.)
       legend = c("False", "True"),     # Labels matching the row order
       fill = c("maroon", "pink"),      # Colors matching the row order
       bty = "n",                       # "n" removes the box outline around the legend
       text.col = "white")              # Makes the legend text white

dev.off()
