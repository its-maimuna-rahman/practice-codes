age_group <- c("0-4", "5-9", "10-14", "15-19", "20-24", "25-29",
               "30-34", "35-39", "40-44", "45-49", "50-54", "55-59",
               "60-64", "65-69", "70-74", "75-79", "80+")

male <- c(196500, 213400, 218700, 198500, 168300, 142800, 128400, 114700,
          98300, 82600, 67800, 54300, 42800, 31200, 21400, 12700, 8900)

female <- c(188200, 204800, 209300, 192400, 178500, 152400, 138600, 121200,
            102800, 85400, 70200, 56800, 44500, 32800, 23500, 14800, 12200)

pop <- data.frame(age_group, male, female)
pop

F <- sum(pop$female)
M <- sum(pop$male)
pop$total <- pop$female + pop$male
T <- sum(pop$total)

MP <- M / T * 100
cat("Masculinity Proportion (MP):", round(MP, 2),
    "% of the population is male, the rest", 
    round(100 - MP, 2), "% is female.\n\n")

SR <- M / F * 100
cat("Sex Ratio (SR):", round(SR, 2), "males for every 100 females.\n\n")

p_0_14 <- sum(pop$total[1:3])
p_15_64 <- sum(pop$total[4:13])
p_65 <- sum(pop$total[14:17])

ACR <- p_65 / p_0_14 * 100
cat("Aged Child Ratio (ACR):", round(ACR, 2),
    "aged people (65+) per 100 children (0-14).\n\n")

f_20_39 <- sum(pop$female[5:8])
cat("Total female population aged 20-39:", f_20_39, "\n\n")

TDR <- (p_0_14 + p_65) / p_15_64 * 100
cat("Total Dependency Ratio (TDR):", round(TDR, 2),
    "dependents (children + aged) per 100 working-age people.\n\n")

CDR <- p_0_14 / p_15_64 * 100
cat("Child Dependency Ratio (CDR):", round(CDR, 2),
    "children per 100 working-age people.\n\n")

OADR <- p_65 / p_15_64 * 100
cat("Old Age Dependency Ratio (OADR):", round(OADR, 2),
    "aged people per 100 working-age people.\n\n")

deficit1 <- M - F
cat("Deficit1 (M - F):", deficit1,
    "- difference between male and female population.\n\n")

deficit2 <- M - (102/100) * F
cat("Deficit2 (M - 1.02*F):", round(deficit2, 2), "- male population compared 
    against 102 males per 100 females (expected sex ratio at birth).\n\n")

pop
cat("\n\n")

name <- c("MP", "SR", "ACR", "f_20_39", "TDR", "CDR", "OADR", "deficit1", "deficit2")

val <- c(round(MP, 3),
         round(SR, 3),
         round(ACR, 3),
         round(f_20_39, 3),
         round(TDR, 3),
         round(CDR, 3),
         round(OADR, 3),
         round(deficit1, 3),
         round(deficit2, 3))

result <- data.frame(name, val)
result

cat("\n\n")