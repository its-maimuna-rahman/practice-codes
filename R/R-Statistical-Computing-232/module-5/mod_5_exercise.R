treat <- c("F1", "F1", "F1", "F1", "F2", "F2", "F2", "F2", "F3", 
           "F3", "F3", "F3", "F4", "F4", "F4", "F4")
gain <- c(18.4, 19.2, 17.8, 18.6, 22.3, 21.5, 22.8, 22.0, 16.5, 17.2, 16.8, 17.5,
          24.1, 23.5, 24.6, 23.8)

shr <- data.frame(treat = factor(treat), gain)
shr

# 1
boxplot(gain ~ treat, data = shr,
        col = "maroon",
        border = "black",
        xlab = "Feed", 
        ylab = "Weekly gain (g)",
        main = "Satkhira shrimp feed trial")

# 2
a <- 4; n <- 4; N <- a*n

CF <- sum(shr$gain)^2 / N
SST <- sum(shr$gain^2) - CF

SS_treat_sum <- tapply(shr$gain, shr$treat, sum)
SS_treat <- sum(SS_treat_sum^2) / n - CF

SSE <- SST - SS_treat

df_treat <- a-1
df_error <- N-a

MS_treat <- SS_treat / df_treat
MSE <- SSE / df_error

F_calc <- MS_treat / MSE
F_value <- qf(0.95, df_treat, df_error)

c(SS_treat = SS_treat, SSE = SSE, MS_treat = MS_treat, MSE = MSE, F_calc = F_calc,
  F_value = F_value)


model <- aov(gain ~ treat, data = shr)
model
summary(model)
# p < 0.001, and F_calc > F_value, so we reject Ho

# 1. normality check : qq plot
res <- residuals(model)
fit <- fitted(model)

qqnorm(res,
       col = "maroon",
       pch = 19,
       main = "QQ plot of residuals")
qqline(res, lwd = 1, col = "navy")

#  variance equality check : residual vs fitted
plot(fit, res,
     col = "maroon",
     pch = 19,
     xlab = "fitted",
     ylab = "residual",
     main = "fitted vs residual")
abline(h = 0, lty = 2, col = "navy")

# bonferroni's inequality
r <- a
se <- sqrt(MSE / n)

t_critical_bonf <- qt(1-0.05 / (2*r), df_error)
means <- tapply(shr$gain, shr$treat, mean)

bonf_interval <- data.frame(
  
  treat = names(means),
  mean = means,
  min = means - t_critical_bonf * se,
  max = means + t_critical_bonf * se
)
bonf_interval

# TukeyHSD()

TukeyHSD(model, conf.level = 0.95)

# Recommendation: F4. It is significantly higher than every
# other feed at the 5% family wise level, with a gap of
# about 1.85 g over F2 and roughly 5 to 7 g over F1 and F3.