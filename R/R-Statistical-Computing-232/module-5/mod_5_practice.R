# Completely Randomized Design (CRD)

# The Bangladesh Agricultural Research Institute (BARI) ran a CRD trial
# comparing four fertilizer regimes on rice yield (Mg per hectare). Twenty
# homogeneous plots were assigned at random, five per fertilizer. Treatments
# are Urea, NPK, Compost, and Mixed (NPK + compost).

# 4 treatments and 5 replicate plots each.

treat <- rep(c("Urea", "NPK", "Compost", "Mixed"), each = 5)
yield <- c(4.2, 4.8, 4.0, 4.5, 4.4,    # Urea
           5.3, 4.7, 5.1, 5.5, 4.9,    # NPK
           4.1, 3.8, 4.3, 3.9, 4.2,    # Compost
           5.4, 5.9, 5.3, 5.7, 5.6)    # Mixed

rice <- data.frame(treat = factor(treat), yield)
rice
tapply(rice$yield, rice$treat, mean)

# boxplot
boxplot(yield ~ treat, data = rice,
        col = "maroon",
        xlab = "Fertilizer",
        ylab = "Rice yield (Mg/ha)",
        main = "BARI Rice Trial 2024")

#  The Mixed and NPK treatments visibly produce higher yields than Urea and
# Compost. The four boxes barely overlap. This is what we want to see before
# running the F test, a clear visual signal that treatment matters. The ANOVA
# will quantify that signal formally.

# ========================== ANOVA MODEL =====================================

a <- 4      # 4 factor
n <- 5      # 5 observation under each factor
N <- a * n  # total ovservation

CF <- sum(rice$yield)^2 / N
SST <- sum(rice$yield^2) - CF

treat_sum <- tapply(rice$yield, rice$treat, sum)
SS_treat <- sum(treat_sum^2) / n - CF

SSE <- SST - SS_treat

df_treat <- a - 1     # 3
df_error <- N - a     # 16

MS_treat <- SS_treat / df_treat
MSE <- SSE / df_error
F_calc <- MS_treat / MSE
F_table <- qf(0.95, df_treat, df_error)

c(SS_treat = SS_treat, SSE = SSE, MS_treat = MS_treat, MSE = MSE,
  F_calc = F_calc, F_table = F_table)

# as F_calc > F_tab at alpha = 0.05 (95% confidence interval), we reject
# the null hypothesis (Ho)

# ANOVA with aov() function
model <- aov(yield ~ treat, data = rice)
summary(model)

# ================ Model Adequacy Checks ================================

res <- residuals(model)
res
fit <- fitted(model)
fit

# 1. Normality : qq plot of residuals

qqnorm(res,
       pch = 19,
       col = "maroon",
       main = "Normal QQ plot of residuals")

qqline(res,
       col = "steelblue",
       lwd = 2)

# 2. Equal variance : residuals vs fitted

plot(fit, res,
     pch = 19,
     col = "maroon",
     xlab = "Fitted values",
     ylab = "Residuals",
     main = "Residuals vs Fitted")

abline(h = 0, lty = 2, col = "steelblue")

# 3. Independence : residuals in run order

plot(seq_along(res), res,
     type = "o",
     pch = 19,
     col = "maroon",
     xlab = "Run order",
     ylab = "Residuals",
     main = "Residuals vs Run order")

abline(h = 0, lty = 2, col = "steelblue")

# 1. Normality (Linearity)
#The Normal QQ plot of residuals shows that the data points hug the reference 
# diagonal line  well from end to end. Because the points form a straight,
# linear path with no heavy curving or distinct "S" shapes,
# the normality assumption is fully satisfied.

# 2. Equal Variance (Homoscedasticity)
# The Residuals vs Fitted plot shows the data split into four distinct vertical
# columns, corresponding to your four fertilizer groups. The vertical spread
# (from roughly -0.4 to 0.4) is consistently uniform across all four columns 
# with no visible "funnel" or expanding megaphone patterns,
# meaning the equal variance assumption holds true.

# 3. Independence
# The Residuals vs Run order plot displays a highly erratic, random zig-zag
# sequence that constantly bounces back and forth across the dashed zero
# baseline. There are no tracking waves, gradual arcs, or clear upward/downward
# trends over time, which confirms that the independence assumption is satisfied.

# ==============================================================================

# shortcut (4 plots)
# residuals vs fitted, QQ plot, scale location, leverage
plot(model)

# ==================== Confidence Intervals for Treatment Means ================

# 95% one at a time CI for the NPK mean
y_npk <- mean(rice$yield[rice$treat == "NPK"])
SE <- sqrt(MSE/n)
t_critical <- qt(0.975, df_error)

c(lower = y_npk - (t_critical * SE),
  upper = y_npk + (t_critical * SE))

# ================ Bonferroni simultaneous confidence intervals ================

r <- a   # number of intervals
t_critical_bonf <- qt(1-0.05 / (2*r), df_error)
means <- tapply(rice$yield, rice$treat, mean)

bonf_ci <- data.frame(
  treat = names(means),
  mean = means,
  lower = means - (t_critical_bonf * SE),
  upper = means + (t_critical_bonf * SE)
)
bonf_ci

# =============== Pairwise Comparison with Tukey HSD ===========================
# Honest Significant Difference (HSD)

TukeyHSD(model, conf.level = 0.95)

# diff: difference in sample means, the second group minus the first.
# lwr and upr: 95% family wise CI for the true difference.
# p adj: Tukey adjusted p value. If < 0.05, the pair is significantly
# different at the 5% family wise level.

# Mixed and NPK both clearly outperform Compost and Urea. The difference
# between Mixed and NPK is not quite significant at 5% (p = 0.057). For the
# next planting season, BARI could recommend either Mixed or NPK with 
# confidence, and avoid Compost