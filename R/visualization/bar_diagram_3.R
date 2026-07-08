data <- read.csv("ai_student_impact_dataset.csv")

# stacked bar diagram
pdf("bar_beside.pdf", width = 12, height = 9)
par(bg = "black", fg = "white", mar = c(5, 5, 4, 2))
count <- table(data$Paid_Subscription, data$Year_of_Study)

# sorting however I want
order_year <- c("Freshman", "Sophomore", "Junior", "Senior", "Graduate")
count_custom <- count[, order_year]

max_bar_height <- max(count_custom)

b <- barplot(count_custom,
             col = c("maroon", "pink"),
             col.main = "white", col.lab = "white", col.axis = "white",
             main = "Year of Study and Prompt Skill comparison",
             ylab = "frequency",
             border = "white",
             space = c(0.2, 1),
             beside = TRUE,
             ylim = c(0, max_bar_height * 1.3), # Creates a 30% safety ceiling for the legend
             las = 1)                           # Keeps Y-axis frequency numbers sitting upright)

legend("topright",                      # Where to place it ("topright", "topleft", etc.)
       legend = c("False", "True"),     # Labels matching the row order
       fill = c("maroon", "pink"),      # Colors matching the row order
       bty = "n",                       # "n" removes the box outline around the legend
       text.col = "white")              # Makes the legend text white

dev.off()
