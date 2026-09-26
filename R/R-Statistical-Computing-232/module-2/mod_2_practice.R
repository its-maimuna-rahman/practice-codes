# Khulna District, mid year 2024 (illustrative figures)
age_group  <- c("15-19", "20-24", "25-29", "30-34",
                 "35-39", "40-44", "45-49")

births     <- c(8000, 15000, 11000, 7000,
                 2200, 600,   100)

female_pop <- c(110000, 105000, 100000, 95000,
                 85000,  75000,  65000)

L5x        <- c(494000, 491000, 488000, 484500,
                 480000, 474000, 466000)  # from a life table, radix 100,000

fert <- data.frame(age_group, births, female_pop, L5x)

# Two more constants we will use later
total_pop <- 2400000     # Khulna mid year total population
p_female  <- 0.487        # proportion of births that are girls (Bangladesh average)
fert
cat("\n\n")

total_birth <- sum(fert$births)
CBR <- total_birth / total_pop * 1000
cat("Crude Birth Rate (CBR):", round(CBR, 2),
    "live births per 1,000 population.\n\n")

# Khulna, March 2024: 31 days, 3,720 live births recorded
days <- 31 # march
pop_month <- 2400000
birth_month <- 3720

MBR <- (365/days) * (birth_month / pop_month * 1000)
cat("Monthly Birth Rate (MBR), annualised:", round(MBR, 2),
    "live births per 1,000 population. Sanity check against CBR",
    "(", round(CBR, 2), "): a big gap would flag a seasonal month.\n\n")

pop_f_15_49 <- sum(fert$female_pop)
GFR <- total_birth / pop_f_15_49 * 1000
cat("General Fertility Rate (GFR):", round(GFR, 2),
    "live births per 1,000 women aged 15-49, about",
    round(GFR / CBR, 1), "times the CBR.\n\n")

GFR2 <- 4.5 * CBR
cat("Rule of thumb (GFR2 = 4.5 x CBR):", round(GFR2, 2),
    "vs the actual GFR of", round(GFR, 2),
    "- the gap reflects this district's age/sex composition.\n\n")

fert$ASFR <- fert$births / fert$female_pop * 1000
cat("Age Specific Fertility Rate (ASFR) computed for each age",
    "group, see fert$ASFR. Rates typically rise from 15, peak",
    "around 20-29, then fall sharply.\n\n")

plot(fert$ASFR,
     type = "o",
     pch = 19,
     col = "#2563eb",
     xaxt = "n",
     xlab = "Age group",
     ylab = "ASFR (per 1000 women)",
     main = "Khulna 2024, Age Specific Fertility")
axis(1, at = 1:7, labels = fert$age_group)

n <- 5           # age band width
TFR <- n * sum(fert$ASFR) / 1000
cat("Total Fertility Rate (TFR):", round(TFR, 2),
    "live births per woman over her reproductive lifetime.\n\n")

# p is the proportion of live births that are girls
GRR <- TFR * p_female
cat("Gross Reproduction Rate (GRR):", round(GRR, 2),
    "daughters per woman, assuming every daughter survives to",
    "the end of her own reproductive period.\n\n")

l0 <- 100000
NRR <- sum((fert$ASFR) * p_female * (fert$L5x / l0)) / 1000
cat("Net Reproduction Rate (NRR):", round(NRR, 2),
    "surviving daughters per woman, adjusted for mortality via",
    "L5x/", l0, ". Above 1 means slow growth; below 1 means",
    "eventual decline.\n\n")

cat("\n\n")
