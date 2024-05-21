# Reading a .txt file line by line
lines <- readLines("file.txt")
print(lines)

# Reading a .txt file into a data frame
data <- read.table("file.txt", header=TRUE, sep="\t")  # Adjust 'header' and 'sep' as needed
print(data)

# Writing lines to a .txt file
lines_to_write <- c("First line", "Second line", "Third line")
writeLines(lines_to_write, "output.txt")

# Writing a data frame to a .txt file
write.table(data, "output.txt", sep="\t", row.names=FALSE)






#CSV
# Reading a .csv file into a data frame
data <- read.csv("file.csv")
print(data)

# Writing a data frame to a .csv file
write.csv(data, "output.csv", row.names=FALSE)




# Create sample data
sample_data <- data.frame(
  Name = c("John", "Jane", "Doe"),
  Age = c(30, 25, 35)
)

# Write sample data to a .txt file
write.table(sample_data, "sample_data.txt", sep="\t", row.names=FALSE)

# Read the .txt file into a data frame
read_data <- read.table("sample_data.txt", header=TRUE, sep="\t")

# Print the data frame
print(read_data)

# Write the data frame to a .csv file
write.csv(read_data, "sample_data.csv", row.names=FALSE)

# Read the .csv file to verify
csv_data <- read.csv("sample_data.csv")
print(csv_data)

