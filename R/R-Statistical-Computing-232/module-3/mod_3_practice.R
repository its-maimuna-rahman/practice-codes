# Mymensingh District, mid year 2024 (illustrative figures)
age_group <- c("0-14", "15-29", "30-44", "45-59", "60-74", "75+")

deaths <- c(560, 520, 1100, 2550, 9000, 18750)

population <- c(1400000, 1300000, 1100000, 850000,  600000,  250000)

mort <- data.frame(age_group, deaths, population)

# Completeness of registration (fractions)
C_d <- 0.88      # deaths registration is 88% complete
C_p <- 0.92      # census coverage is 92% complete

# Inputs for the infant and child mortality measures (Slide 4)
B            <- 125000   # total live births in 2024
deaths_neo   <- 1875     # deaths aged 0 to 28 days
deaths_inf   <- 3000     # deaths aged 0 to 12 months
deaths_child <- 1568     # deaths aged 1 to 4 years
P_1_4        <- 448000   # mid year population aged 1 to 4

# Reference standard population (per 100,000), used in Slide 6
std_pop <- c(28000, 25000, 20000, 15000, 8000, 4000)

# Standard age specific death rates (per 1000), used in Slide 8
M_std <- c(0.4, 0.5, 1.2, 3.5, 17.0, 80.0)
M_std_crude <- 5.56   # crude rate in the standard population (per 1000)

mort
cat("\n\n")

total_death <- sum(mort$deaths)
total_pop <- sum(mort$pop)

CDR <- total_death / total_pop * 1000
cat("Crude Death Rate (CDR):", round(CDR, 3),
    "deaths per 1,000 population.\n\n")

CDR_corr1 <- (total_death/C_d) / (total_pop/C_p) * 1000
cat("CDR corrected for registration/census completeness",
    "(CDR_corr1):", round(CDR_corr1, 3), "deaths per 1,000.\n\n")

CDR_corr2 <- CDR * (C_p / C_d)
cat("CDR corrected, alternate formula (CDR_corr2):",
    round(CDR_corr2, 3), "deaths per 1,000 population.\n\n")

NMR <- deaths_neo / B * 1000
cat("Neonatal Mortality Rate (NMR):", round(NMR, 3),
    "neonatal deaths per 1,000 live births.\n\n")

IMR <- deaths_inf / B * 1000
cat("Infant Mortality Rate (IMR):", round(IMR, 3),
    "infant deaths per 1,000 live births.\n\n")

CMR <- deaths_child / P_1_4 * 1000
cat("Child Mortality Rate (CMR):", round(CMR, 3),
    "deaths per 1,000 children aged 1-4.\n\n")

mort$ASDR <- mort$deaths / mort$population * 1000
cat("Age Specific Death Rate (ASDR) computed for each age",
    "group, see mort$ASDR.\n\n")

plot(mort$ASDR,
     type = "o",
     pch = 19,
     col = "maroon",
     xaxt = "n",
     xlab = "Age group",
     ylab = "ASDR (per 1000)",
     main = "ASDR (Age Specific Death Rate) plot for Mymensingh 2024")
axis(1, at = 1:6, labels = mort$age_group)

weights <- mort$population / sum(mort$population)
CDR2 <- sum(mort$ASDR * weights)
cat("CDR as a population-weighted average of the ASDRs (CDR2):",
    round(CDR2, 3), "deaths per 1,000 population.\n\n")

expected <- mort$ASDR * std_pop
ASR <- sum(expected) / sum(std_pop)
cat("Age Standardised Death Rate (ASR):", round(ASR, 3),
    "deaths per 1,000 - usable to compare against another",
    "district's ASR.\n\n")

# Total observed deaths in Mymensingh
D_obs <- sum(mort$deaths)

# Expected deaths if Mymensingh had the standard's ASDRs
expected <- sum(M_std * mort$population) / 1000
cat("Expected deaths at the standard population's ASDRs:",
    round(expected, 0), "\n\n")

# Standardised Mortality Ratio
SMR <- D_obs / expected
cat("Standardised Mortality Ratio (SMR):", round(SMR, 3),
    "- observed deaths over expected deaths.\n\n")

# Indirectly standardised death rate (per 1000)
IDR <- SMR * M_std_crude
cat("Indirectly Standardised Death Rate (IDR):", round(IDR, 3),
    "deaths per 1,000 population.\n\n")

cat("\n\n")
