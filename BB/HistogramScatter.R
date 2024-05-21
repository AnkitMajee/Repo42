# Sample data
# Histogram
data <- rnorm(100)  # Generate 100 random numbers from a normal distribution

# Histogram
hist(data, 
     main = "Histogram of Sample Data", 
     xlab = "Values", 
     ylab = "Frequency", 
     col = "lightblue", 
     border = "black")


#Scatter

# Sample data
x <- rnorm(100)
y <- rnorm(100)

# Scatter plot
plot(x, y, 
     main = "Scatter Plot of X vs Y", 
     xlab = "X values", 
     ylab = "Y values", 
     pch = 19, 
     col = "blue")


# Example

install.packages("ggplot2")
library(ggplot2)

# Sample data
data <- data.frame(value = rnorm(100))

# Histogram
ggplot(data, aes(x = value)) +
  geom_histogram(binwidth = 0.5, fill = "lightblue", color = "black") +
  ggtitle("Histogram of Sample Data") +
  xlab("Values") +
  ylab("Frequency")


library(ggplot2)

# Sample data
data <- data.frame(x = rnorm(100), y = rnorm(100))

# Scatter plot
ggplot(data, aes(x = x, y = y)) +
  geom_point(color = "blue") +
  ggtitle("Scatter Plot of X vs Y") +
  xlab("X values") +
  ylab("Y values")


