# Install and load necessary libraries
install.packages("ggplot2")
install.packages("factoextra")
library(ggplot2)
library(factoextra)

# Load the iris dataset
data <- iris[, -5]

# Standardize the data
data_scaled <- scale(data)

# Perform PCA
pca_result <- prcomp(data_scaled, center = TRUE, scale. = TRUE)

# Print the summary of PCA results
summary(pca_result)

# Print the loadings
print(pca_result$rotation)

# Print the principal components (scores)
print(pca_result$x)

# Scree plot
fviz_eig(pca_result, addlabels = TRUE, ylim = c(0, 50))

# Biplot
fviz_pca_biplot(pca_result, repel = TRUE,
                col.var = "blue", # Color for variable vectors
                col.ind = iris$Species) # Color for individuals by groups
