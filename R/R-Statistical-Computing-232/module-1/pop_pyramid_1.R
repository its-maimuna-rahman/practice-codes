# population pyramid
# Pabna District, mid year 2022 (illustrative figures)
age_group <- c("0-4",   "5-9",   "10-14", "15-19", "20-24",
               "25-29", "30-34", "35-39", "40-44", "45-49",
               "50-54", "55-59", "60-64", "65-69", "70-74",
               "75-79", "80+")

male   <- c(124500, 138200, 142300, 131400, 118200,
            104500, 96300,  88700,  78400,  67100,
            56800,  47200,  38500,  28700,  19600,
            11400,  8200)

female <- c(119800, 132400, 136700, 128900, 122600,
            110800, 102400, 94200,  82500,  70200,
            58900,  48400,  39200,  29800,  21200,
            13500,  11800)

pop <- data.frame(age_group, male, female)
pop

# 1. Male bars, negative so they go to the left of 0
barplot(-pop$male,
        horiz     = TRUE,
        names.arg = pop$age_group,
        space     = 0,
        col       = "steelblue",
        xlim      = c(-160000, 160000),
        xlab      = "Population",
        main      = "Pabna District, 2022",
        las       = 1,
        axes      = FALSE)

# 2. Female bars, positive so they go to the right; overlay same panel
barplot(pop$female,
        horiz = TRUE,
        space = 0,
        col   = "pink",
        add   = TRUE,
        axes  = FALSE)

# 3. Draw a clean x axis with positive labels on both sides
ticks <- seq(-150000, 150000, by = 50000)
axis(1, at = ticks, labels = abs(ticks))

# 4. Legend
legend("topright",
       legend = c("Male", "Female"),
       fill   = c("steelblue", "pink"),
       bty    = "n")
