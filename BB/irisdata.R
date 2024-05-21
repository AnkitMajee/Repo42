df = iris

# see the first 6 rows of the data
print(head(df))
cat("\n")

# find the dimensions of the data
print(dim(df))
cat("\n")

# find the column names
print(colnames(df))
cat("\n")

# rename the columns
colnames(df) = c("sepal_length", "sepal_width", "petal_length", "petal_width", "species")
print(colnames(df))
cat("\n")

# info of the data
print(str(df))
cat("\n")

# describe the data
print(summary(df))
cat("\n")

# find the unique values in a column
print(unique(df$species))
cat("\n")

# average petal length for each species
print(tapply(df$petal_length, df$species, mean))
cat("\n")

# find missing vals for each column
print(colSums(is.na(df)))
cat("\n")

# add new column = ratio of sepal length to sepal width
# add new column = ratio of petal length to petal width
df$s_ratio = df$sepal_length / df$sepal_width
df$p_ratio = df$petal_length / df$petal_width

# remove original columns
df = df[, c("s_ratio", "p_ratio", "species")]

# save as csv
write.csv(df, "~/DSc Data/iris_mod.csv", row.names = FALSE)

# read csv
df = read.csv("~/DSc Data/iris_mod.csv")

# random sample
print(df[sample(nrow(df), 5), ])
cat("\n")