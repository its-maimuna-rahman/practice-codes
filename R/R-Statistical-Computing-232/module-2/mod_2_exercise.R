age_group  <- c("15-19","20-24","25-29","30-34","35-39","40-44","45-49")
births     <- c(7500, 15000, 11000, 6300, 1900, 510, 75)
female_pop <- c(125000, 115000, 110000, 105000, 95000, 85000, 75000)
L5x        <- c(494000, 491000, 488000, 484500, 480000, 474000, 466000)
raj <- data.frame(age_group, births, female_pop, L5x)
raj
n <- 5
total_pop <- 2700000
p_female = 0.487

cat("\n\n")
CBR <- sum(raj$births) / total_pop * 1000
cat("Crude Birth Rate (CBR):", round(CBR, 2),
    "live births per 1,000 population.\n\n")

birth_march <- 3580
march_pop <- 270000
days <- 31

MBR <- (365/days) * (birth_march / march_pop) * 1000
cat("Monthly (annualised) Birth Rate (MBR), based on March:",
    round(MBR, 2), "live births per 1,000 population.\n\n")

GFR <- sum(raj$births) / sum(raj$female_pop) * 1000
cat("General Fertility Rate (GFR):", round(GFR, 2),
    "live births per 1,000 women aged 15-49.\n\n")

raj$ASFR <- raj$births / raj$female_pop * 1000
cat("Age-Specific Fertility Rate (ASFR) computed for each age group, see raj$ASFR.\n\n")

TFR <- sum(raj$ASFR) * n / 1000
cat("Total Fertility Rate (TFR):", round(TFR, 3),
    "children per woman over her reproductive lifetime.\n\n")

GRR <- TFR * p_female
cat("Gross Reproduction Rate (GRR):", round(GRR, 3),
    "daughters per woman.\n\n")

NRR <- sum(raj$ASFR * p_female * (raj$L5x/100000)) / 1000
cat("Net Reproduction Rate (NRR):", round(NRR, 3),
    "surviving daughters per woman, adjusted for mortality via 5Lx/100000.\n\n")

raj
cat("\n\n")

name <- c("CBR", "MBR", "GFR", "TFR", "GRR", "NRR")

val <- c(round(CBR, 3),
round(MBR, 3),
round(GFR, 3),
round(TFR, 3),
round(GRR, 3),
round(NRR, 3))

result <- data.frame(name, val)
result
cat("\n\n")

# a line plot of ASFR against age group.
plot(raj$ASFR,
     pch = 19,
     type = "o",
     xlab = "age group",
     ylab = "ASFR (per 1000 women)",
     main = "ASFR vs Age_group",
     col = "maroon")
axis(1, at = 1:7, labels = raj$age_group)
