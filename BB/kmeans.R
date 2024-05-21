# Load necessary libraries
install.packages("ggplot2")
install.packages("factoextra")
library(ggplot2)
library(factoextra)

# Load and prepare the data
data(iris)
iris_data <- iris[, -5]

# Determine the optimal number of clusters
fviz_nbclust(iris_data, kmeans, method = "wss") + 
  geom_vline(xintercept = 3, linetype = 2) +
  labs(subtitle = "Elbow method")

# Perform K-means clustering
set.seed(123)
kmeans_result <- kmeans(iris_data, centers = 3, nstart = 25)

# Print the clustering result
print(kmeans_result)

# Visualize the clusters
fviz_cluster(kmeans_result, data = iris_data, 
             palette = c("#2E9FDF", "#00AFBB", "#E7B800"), 
             ellipse.type = "convex", 
             geom = "point", 
             stand = FALSE, 
             ggtheme = theme_minimal())
