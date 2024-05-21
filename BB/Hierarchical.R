# Install and load necessary libraries
install.packages("ggplot2")
install.packages("dendextend")
library(ggplot2)
library(dendextend)

# Load the iris dataset
data <- iris[, -5]

# Compute the distance matrix
distance_matrix <- dist(data, method = "euclidean")

# Perform hierarchical clustering
hc <- hclust(distance_matrix, method = "complete")

# Plot the dendrogram
plot(hc, main = "Hierarchical Clustering Dendrogram", xlab = "", sub = "", cex = 0.9)

# Cut the dendrogram into 3 clusters
clusters <- cutree(hc, k = 3)

# Add the clusters to the original data
iris$Cluster <- as.factor(clusters)

# Visualize the clusters using ggplot2
ggplot(iris, aes(x = Sepal.Length, y = Sepal.Width, color = Cluster)) +
  geom_point(size = 3) +
  theme_minimal() +
  labs(title = "Hierarchical Clustering of Iris Data", x = "Sepal Length", y = "Sepal Width")
