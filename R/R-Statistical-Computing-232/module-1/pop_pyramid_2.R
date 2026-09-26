age_group <- c("0-4", "5-9", "10-14", "15-19", "20-24", "25-29",
               "30-34", "35-39", "40-44", "45-49", "50-54", "55-59",
               "60-64", "65-69", "70-74", "75-79", "80+")

male <- c(196500, 213400, 218700, 198500, 168300, 142800, 128400, 114700,
          98300, 82600, 67800, 54300, 42800, 31200, 21400, 12700, 8900)

female <- c(188200, 204800, 209300, 192400, 178500, 152400, 138600, 121200,
            102800, 85400, 70200, 56800, 44500, 32800, 23500, 14800, 12200)

syl <- data.frame(age_group, male, female)
syl

barplot(-syl$male,
        horiz = T,
        names.arg = pop$age_group,
        space = 0,
        col = "steelblue",
        xlim = c(-210000, 210000),
        xlab = "Population",
        main = "population pyramid",
        las = 1,
        axes = F)

barplot(syl$female,
        horiz = T,
        space = 0,
        col = "pink",
        add = T,
        axes = F)

ticks <- seq(-200000, 200000, by = 50000)
axis(1, at = ticks, labels = abs(ticks))

legend("topright",
       legend = c("male", "female"),
       fill = c("steelblue", "pink"),
       bty = "n")