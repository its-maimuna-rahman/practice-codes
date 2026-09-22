# Simulate Customer Inter-Arrival Times

# Scenario: Customers arrive at a coffee shop
# Inter-arrival times follow exponential distribution
# But first, let's use uniform random numbers as building blocks

set.seed(2026)
n_cust <- 100
uniform_times <- runif(n_cust, min = 1, max = 15)

# cumulative arrival times
arrival_times <- cumsum(uniform_times)

customer_data <- data.frame(
  Customer_ID = 1:n_cust,
  Inter_Arrival_Min = round(uniform_times, 2),
  Arrival_Time_Min = round(arrival_times, 2)
)
customer_data

summary(customer_data$Inter_Arrival_Min)

plot(x = customer_data$Customer_ID,
     y = customer_data$Arrival_Time_Min,
     pch = 19,
     col = "maroon",
     main = "Coffee Shop customer arrival",
     xlab = "customer number",
     ylab = "cumulative arrival time")