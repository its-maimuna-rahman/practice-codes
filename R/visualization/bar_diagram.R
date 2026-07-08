data <- read.csv("ai_student_impact_dataset.csv")

# bar diadram
pdf("major_category_barchart.pdf", width = 10, height = 8)
par(bg = "black", fg = "white", mar = c(5, 8, 4, 3))
counts <- table(data$Major_Category)

b <- barplot(counts,
             horiz = TRUE,     # horizontal bar diagram
             las = 1,          # Make text stand upright
             space = 0.3,      # Add a nice gap between bars
             col = "maroon",
             border = "white",
             col.main = "white", col.lab = "white", col.axis = "white",
             main = "Major Category Bar Diagram",
             xlab = "frequency")

dev.off()