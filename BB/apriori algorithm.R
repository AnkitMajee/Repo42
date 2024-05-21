# Install and load necessary packages
install.packages("arules")
install.packages("arulesViz")
library(arules)
library(arulesViz)

# Example transaction data (list format)
transactions <- list(
  c("milk", "bread", "butter"),
  c("milk", "bread"),
  c("milk", "butter"),
  c("bread", "butter"),
  c("milk", "bread", "butter", "eggs")
)

# Convert data to transaction format
transactions <- as(transactions, "transactions")

# Run the Apriori algorithm
rules <- apriori(transactions, parameter = list(support = 0.2, confidence = 0.5))

# Print the rules
inspect(rules)

# Summary of rules
summary(rules)

# Plot the rules
plot(rules)
