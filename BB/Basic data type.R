# string
d="AnkitMajee"

#no space in string
d="Aritra Bag"


#Vector
#logical
vtr1 = c(TRUE, FALSE)
class(vtr1)

#Numerical
vtr2 = c(15,5.67,999)
class(vtr2)

#Interger
vtr3 = c(35L, 67L, 78L)

#mixed data type

vtr5= c(TRUE,65L,3.14)
vrt6=c("Hello",34L,FALSE)

#matrix

# Creating a matrix with 3 rows and 4 columns
mat <- matrix(1:12, nrow = 3, ncol = 4)
mtr = matrix(c(5:29),5,5)  #creats a matrix of 5x5 from 5to29
arr= array(c(1:9),dim=c(3,3,4,2))

# Creating a list with different types of elements
my_list <- list(name = "John",age = 25,scores = c(85, 90, 88),is_student = TRUE)

# Accessing elements by name
name <- my_list$name

# Accessing elements by position
age <- my_list[[2]]

# Creating another list
another_list <- list(hobby = "reading",favorite_numbers = c(7, 14, 21))

# Combining lists using c()
combined_list <- c(my_list, another_list)






#dataframe

arr1 = c(1:5)
arr2 = c("sasd","dffd","fdf","dfdf","df")
arr3 = c(24,45,66,45,65)
data.frame(arr1,arr2,arr3) #insure all arr have same length value


df=data.frame(a=c(1,2,3),b=c(3,6,8))
#row.names(df) in terminal
#as.matrix(df) in terminal

#iris data set
data=iris
table(data$Species)
head(iris)
summary(iris)

# Load the iris dataset
data(iris)

# Write the iris dataset to a file named "iris.txt" with tab separation
write.table(iris, file="iris.txt", sep="\t", row.names=FALSE, col.names=TRUE)


# Read the iris.txt file into a data frame
data_iris <- read.table(file="iris.txt", sep="\t", header=TRUE)

# Print the data to confirm it was read correctly


# Data Types in R
# Note: we will never use print coz cat is more customizable

## numeric, integer & complex
{
  cat("\n---------------------------------------\n")
  cat("NUMERIC, INTEGER & COMPLEX\n")
  cat("---------------------------------------\n")
  a = 5
  b = 5.5
  c = 5L
  d = 9i + 3
  e = c(5, 5.5)
  f = c(5, 5.5, 5L)
  g = c(5, 5.5, 5L, 9i + 3)
  cat(sep = " ", a, class(a), "\n")
  cat(sep = " ", b, class(b), "\n")
  cat(sep = " ", c, class(c), "\n")
  cat(sep = " ", d, class(d), "\n")
  cat(sep = " ", e, class(e), "\n")
  cat(sep = " ", f, class(f), "\n")
  cat(sep = " ", g, class(g), "\n")
  
  # 5 numeric
  # 5.5 numeric
  # 5 integer
  # 3+9i complex
  # 5 5.5 numeric
  # 5 5.5 5 numeric
  # 5+0i 5.5+0i 5+0i 3+9i complex
  
  # i.e. integer < numeric < complex
  # in C terms, integer < double < complex
}

## character
{
  cat("\n---------------------------------------\n")
  cat("CHARACTER\n")
  cat("---------------------------------------\n")
  a = "hello"
  b = 'w'
  c = c("hello", "world")
  cat(sep = " ", a, class(a), "\n")
  cat(sep = " ", b, class(b), "\n")
  cat(sep = " ", c, class(c), "\n")
  
  # hello character
  # w character
  # hello world character
  
  # in R, single and double quotes are same
  # in C terms, c strings
}

## logical
{
  cat("\n---------------------------------------\n")
  cat("LOGICAL\n")
  cat("---------------------------------------\n")
  a = TRUE
  b = FALSE
  c = c(TRUE, FALSE)
  cat(sep = " ", a, class(a), "\n")
  cat(sep = " ", b, class(b), "\n")
  cat(sep = " ", c, class(c), "\n")
  
  # TRUE logical
  # FALSE logical
  # TRUE FALSE logical
  
  # in C terms, bool
}

## vectors
{
  cat("\n---------------------------------------\n")
  cat("VECTORS\n")
  cat("---------------------------------------\n")
  a = 1:3
  b = c(1, 2, 3, 4)
  c = c(a, b)
  cat(sep = " ", a, class(a), "\n")
  cat(sep = " ", b, class(b), "\n")
  cat(sep = " ", c, class(c), "\n")
  
  # 1 2 3 integer
  # 1 2 3 4 numeric
  # 1 2 3 1 2 3 4 numeric
  # R vectors are weird and they aren't same as R arrays
}

## array
{
  cat("\n---------------------------------------\n")
  cat("ARRAY\n")
  cat("---------------------------------------\n")
  a = array(1:3, dim = c(2, 3))
  b = array(1:3, dim = c(2, 3, 2))
  cat(sep = " ", a, class(a), "\n")
  cat(sep = " ", b, class(b), "\n")
  
  # 1 2 3 1 2 3 matrix array 
  # 1 2 3 1 2 3 1 2 3 1 2 3 array
  
  # in R, array is a multi-dimensional vector
  # in C terms, multi-dimensional array
}

## list
{
  cat("\n---------------------------------------\n")
  cat("LIST\n")
  cat("---------------------------------------\n")
  a = list(1, "hi", 3)
  b = list(4, 5, 7+2i)
  c = c(a, b)
  # cat can't print lists and print produces ugly output
  cat(sep = " ", as.character(a), class(a), "\n")
  cat(sep = " ", as.character(b), class(b), "\n")
  cat(sep = " ", as.character(c), class(c), "\n")
  
  # 1 hi 3 list
  # 4 5 7+2i list
  # 1 hi 3 4 5 7+2i list
}

## dictionary using list
{
  cat("\n---------------------------------------\n")
  cat("DICTIONARY USING LIST\n")
  cat("---------------------------------------\n")
  a = list(
    list("name" = "John", "age" = 25, "married" = TRUE),
    list("name" = "Jane", "age" = 23, "married" = FALSE),
    list("name" = "Jack", "age" = 27, "married" = TRUE)
  )
  print(a[1])
  print(a[[1]]$name)
  print(a[1]$name)
  
  # [[1]]
  # [[1]]$name
  # [1] "John"
  # 
  # [[1]]$age
  # [1] 25
  # 
  # [[1]]$married
  # [1] TRUE
  # 
  # 
  # [1] "John"
  # NULL
}

## dictionary using data.frame
{
  cat("\n---------------------------------------\n")
  cat("DICTIONARY USING DATA.FRAME\n")
  cat("---------------------------------------\n")
  a = data.frame(
    "name" = c("John", "Jane", "Jack"),
    "age" = c(25, 23, 27),
    "married" = c(TRUE, FALSE, TRUE)
  )
  print(a)
  print(a[1,])
  print(a$name[1])
  
  #   name age married
  # 1 John  25    TRUE
  # 2 Jane  23   FALSE
  # 3 Jack  27    TRUE
  #   name age married
  # 1 John  25    TRUE
  # [1] "John"
}

## array
{
  cat("\n---------------------------------------\n")
  cat("ARRAY\n")
  cat("---------------------------------------\n")
  a = array(0, dim = c(2, 3))
  print(a)
  a[1, 2] = 5
  print(a)
  
  #      [,1] [,2] [,3]
  # [1,]    0    0    0
  # [2,]    0    0    0
  #      [,1] [,2] [,3]
  # [1,]    0    5    0
  # [2,]    0    0    0
}

## matrix
{
  cat("\n---------------------------------------\n")
  cat("MATRIX\n")
  cat("---------------------------------------\n")
  a = matrix(1:3, nrow = 2, ncol = 3)
  b = matrix(1:3, 1:3, nrow = 2, ncol = 3)
  # cat can't print matrices
  print(a)
  print(b)
  cat(sep=" ", class(a), "\n")
  
  #      [,1] [,2] [,3]
  # [1,]    1    3    2
  # [2,]    2    1    3
  #      [,1] [,2] [,3]
  # [1,]    1    2    3
  # [2,]    1    2    3
  # matrix array
  
  # in R, matrix is a 2D array
  # in C terms, 2D array
}

## data.frame
{
  cat("\n---------------------------------------\n")
  cat("DATA.FRAME\n")
  cat("---------------------------------------\n")
  a = data.frame(a = 1:3, b = c("a", "b", "c"))
  # cat can't print data.frames
  print(a)
  cat(sep=" ", class(a), "\n")
  
  #   a b
  # 1 1 a
  # 2 2 b
  # 3 3 c
  # data.frame
  
  # in R, data.frame is a table
  # in C terms, struct
}

## data frame using list
{
  cat("\n---------------------------------------\n")
  cat("DATA FRAME USING LIST\n")
  cat("---------------------------------------\n")
  a = list(
    "name" = c("John", "Jane", "Jack"),
    "age" = c(25, 23, 27),
    "married" = c(TRUE, FALSE, TRUE)
  )
  print(a[1])
  print(a$name[1])
}

## indexing arrays (or matrices)
{
  cat("\n---------------------------------------\n")
  cat("INDEXING ARRAYS (OR MATRICES)\n")
  cat("---------------------------------------\n")
  ## array
  a = array(1:6, dim = c(2, 3))
  print(a[1, 2])     # exact index
  print(a[1, ])      # row 1, i.e. first row coz R is stupid
  print(a[, 2])      # column 2, i.e. second column, coz again, R is stupid
  print(a[1:2, 2:3]) # rows 1 to 2, columns 2 to 3
  cat("\n")
  ## matrix
  a = matrix(1:6, nrow = 2, ncol = 3)
  print(a[1, 2])
  print(a[1, ])
  print(a[, 2])
  print(a[1:2, 2:3])
  cat("\n")
}

## indexing data frames
{
  cat("\n---------------------------------------\n")
  cat("INDEXING LISTS\n")
  cat("---------------------------------------\n")
  a = list(103, 233, "hi", FALSE, "zima" = "HOLA")
  print(a[1])
  print(a[[1]])
  print(a["zima"])
  print(a[["zima"]])
  print(a$zima)
  cat("\n")
}

## factor
{
  cat("\n---------------------------------------\n")
  cat("FACTOR\n")
  cat("---------------------------------------\n")
  a = factor(c("a", "b", "c"))
  b = factor(c("a", "b", "c"), levels = c("a", "b", "c", "d"))
  cat(sep = " ", a, class(a), "\n")
  cat(sep = " ", b, class(b), "\n")
  
  # 1 2 3 factor
  # 1 2 3 factor
  
  # in R, factor is a categorical variable
  # in C terms, enum
}

## Date
{
  cat("\n---------------------------------------\n")
  cat("DATE\n")
  cat("---------------------------------------\n")
  a = as.Date("2020-01-01")
  b = as.Date("2020-01-01", format = "%Y-%m-%d")
  c = as.Date("2020-01-01", format = "%Y-%m-%d", tz = "UTC")
  cat(sep = " ", a, as.character(a), class(a), "\n")
  cat(sep = " ", b, as.character(b), class(b), "\n")
  cat(sep = " ", c, as.character(c), class(c), "\n")
  
  # 18262 2020-01-01 Date
  # 18262 2020-01-01 Date
  # 18262 2020-01-01 Date
  
  # in R, date is a number of days since Unix epoch
}

# Means
# Create a numeric vector
data <- c(10, 20, 30, 40, 50)

# Calculate the mean
mean_value <- mean(data)
print(mean_value)

#Median
# Create a numeric vector
data <- c(10, 20, 30, 40, 50)

# Calculate the median
median_value <- median(data)
print(median_value)


#SD
# Create a numeric vector
data <- c(10, 20, 30, 40, 50)

# Calculate the standard deviation
sd_value <- sd(data)
print(sd_value)


#Correlation

# Create two numeric vectors
data1 <- c(10, 20, 30, 40, 50)
data2 <- c(15, 25, 35, 45, 55)

# Calculate the correlation
correlation_value <- cor(data1, data2)
print(correlation_value)

# Create numeric vectors
data <- c(10, 20, 30, 40, 50)
data1 <- c(10, 20, 30, 40, 50)
data2 <- c(15, 25, 35, 45, 55)

# Calculate mean
mean_value <- mean(data)
print(paste("Mean:", mean_value))

# Calculate median
median_value <- median(data)
print(paste("Median:", median_value))

# Calculate standard deviation
sd_value <- sd(data)
print(paste("Standard Deviation:", sd_value))

# Calculate correlation
correlation_value <- cor(data1, data2)
print(paste("Correlation:", correlation_value))

