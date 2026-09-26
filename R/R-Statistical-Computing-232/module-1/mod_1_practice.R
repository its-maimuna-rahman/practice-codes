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
cat("\n\n")

M <- sum(pop$male)
F <- sum(pop$female)
tot_pop <- M + F

MP <- M / tot_pop  * 100
cat("Masculinity Proportion (MP):", round(MP, 2),
    "% of the population is male, the rest",
    round(100 - MP, 2), "% is female.\n\n")

SR <- M / F * 100
cat("Sex Ratio (SR):", round(SR, 2),
    "males for every 100 females.\n\n")

excess <- M - F
cat("Excess/Deficit of Males (excess):", round(excess, 2),
    "- males minus females; negative means a deficit of males.\n\n")

# excess with a custom target
sr_target <- 105
excess_target <- M - (sr_target / 100) * F
cat("Excess/Deficit at a target SR of", sr_target,
    "(excess_target):", round(excess_target, 2), "\n\n")

pop$total <- pop$male + pop$female
p_0_14 <- sum(pop$total[1:3])
p_15_64 <- sum(pop$total[4:13])
p_65 <- sum(pop$total[14:17])

ACR <- p_65 / p_0_14 * 100
cat("Aged Child Ratio (ACR):", round(ACR, 2),
    "aged people (65+) per 100 children (0-14).\n\n")

TDR <- (p_0_14 + p_65) / p_15_64 * 100
cat("Total Dependency Ratio (TDR):", round(TDR, 2),
    "dependents (children + aged) per 100 working-age people.\n\n")

CDR <- p_0_14 / p_15_64 * 100
cat("Child Dependency Ratio (CDR):", round(CDR, 2),
    "children per 100 working-age people.\n\n")

OADR <- p_65 / p_15_64 * 100
cat("Old Age Dependency Ratio (OADR):", round(OADR, 2),
    "aged people per 100 working-age people.\n\n")

# 1. Male bars, negative so they go to the left of 0
barplot(-pop$male,
        horiz     = TRUE,
        names.arg = pop$age_group,
        space     = 0,
        col       = "#2563eb",
        xlim      = c(-160000, 160000),
        xlab      = "Population",
        main      = "Pabna District, 2022",
        las       = 1,
        axes      = FALSE)

# 2. Female bars, positive so they go to the right; overlay same panel
barplot(pop$female,
        horiz = TRUE,
        space = 0,
        col   = "#f472b6",
        add   = TRUE,
        axes  = FALSE)

# 3. Draw a clean x axis with positive labels on both sides
ticks <- seq(-150000, 150000, by = 50000)
axis(1, at = ticks, labels = abs(ticks))

# 4. Legend
legend("topright",
       legend = c("Male", "Female"),
       fill   = c("#2563eb", "#f472b6"),
       bty    = "n")

cat("Population Pyramid: a wide base with a narrow top means a young,",
    "growing population; a narrow base with a wide top means an ageing",
    "one. Indentations point to past shocks (famine, war, migration);",
    "asymmetric bars at older ages reflect female longevity.\n\n")

cat("\n\n")
