#if-else
print("value is less than 6")
a=5
if(a<6)
{
  print("value is less than 6")
}
a=5
if(a<6)
{
  print("value is less than 6")
}

#-------------------------------------------------------

a=5
if(a==5)
{
  print("a=5")
}else if(a<6){
  a=5
   if(a==5)
  {
    print("a=5")
  }else if(a<6)
  {
    print("value is less than 6")
  }
}else
{
  print("a>=6")
}

#-----------------------------------------------

a=5
if(a==5|a==6)
{
  print("a=5 or 6")
}else if(a<6)
{
  print("value is less than 6")
}else
{
  print("a>=6")
}

#---------------------------------------------------
#for loop

#x=1:10
for(i in seq(1,10,by=1))
{
  print("hello")
}

#x=1:10
for(i in seq(1,10,by=2))
{
  print(i)
}
for(i in seq(1,10,by=2))
{
  print("hi",i)
}
for(i in seq(1,10,by=2))
{
  print("hi",i,"hello")
}
for(i in seq(1,10,by=2))
{
  print(paste0(("hi",i,"hello"))
}

#while loop

# Initialize the counter variable
counter <- 1

# Start the while loop
while (counter <= 5) {
  # Print the current value of the counter
  print(counter)
  
  # Increment the counter
  counter <- counter + 1
}

while(i<5)
{
  print(i)
  i=i+1
}


#Sequences
seq1 <- 1:10
seq2 <- seq(from = 1, to = 10, by = 1)
seq3 <- seq(from = 1, to = 10, length.out = 10)  # specify length

seq4 <- rep(1:3, times = 3)     # Repeat entire vector 3 times
seq5 <- rep(1:3, each = 3)      # Repeat each element 3 times
seq6 <- rep(1:3, times = c(2, 3, 4))  # Repeat each element different times


element1 <- seq1[1]    # Access the first element of seq1
element2 <- seq1[5]    # Access the fifth element of seq1


# Create a sequence from 1 to 10
seq1 <- 1:10

# Access the first element
first_element <- seq1[1]  # 1

# Access the fifth element
fifth_element <- seq1[5]  # 5

# Access elements greater than 5
greater_than_5 <- seq1[seq1 > 5]  # 6, 7, 8, 9, 10

# Access all elements except the first
all_but_first <- seq1[-1]  # 2, 3, 4, 5, 6, 7, 8, 9, 10

# Access the first, third, and fifth elements
selected_elements <- seq1[c(1, 3, 5)]  # 1, 3, 5


## while loop
{
  cat("\n---------------------------------------\n")
  cat("WHILE LOOP\n")
  cat("---------------------------------------\n")
  i = 1
  while (i <= 5) {
    cat(sep = " ", i, " ")
    i = i + 1
  }
  cat("\n")
  
  # 1 2 3 4 5
}

## for loop
{
  cat("\n---------------------------------------\n")
  cat("FOR LOOP\n")
  cat("---------------------------------------\n")
  for (i in 1:5) {
    cat(sep = " ", i, " ")
  }
  cat("\n")
  
  # on list
  a = list(1, 2, 3)
  for (i in a) {
    cat(sep = " ", i, " ")
  }
  cat("\n")
  
  # 1 2 3 4 5
  # 1 2 3
}

## if, else, else if
{
  cat("\n---------------------------------------\n")
  cat("IF, ELSE, ELSE IF\n")
  cat("---------------------------------------\n")
  a = 5
  if (a < 5) {
    cat("a < 5\n")
  } else if (a == 5) {
    cat("a == 5\n")
  } else {
    cat("a > 5\n")
  }
  
  # a == 5
}

# apply functions

## apply
{
  cat("\n---------------------------------------\n")
  cat("APPLY: only works on dimensional data, i.e array, matrix, or data.frame\n")
  cat("       vectors and lists have no dimensions\n")
  cat("---------------------------------------\n")
  a = matrix(1:6, nrow = 2, ncol = 3)
  print(a)
  print(apply(a, 1, sum)) # sum per row
  print(apply(a, 2, sum)) # sum per column
  
  #      [,1] [,2] [,3]
  # [1,]    1    3    5
  # [2,]    2    4    6
  # [1]  9 12
  # [1] 3 7 11
}

## lapply
{
  cat("\n---------------------------------------\n")
  cat("LAPPLY\n")
  cat("---------------------------------------\n")
  a = matrix(1:6, nrow = 2, ncol = 3)
  x = lapply(a, sum) # takes any data and returns list
  print(class(x))
  print(x)
  cat("\n")
}

## sapply is lapply + simplify
{
  cat("\n---------------------------------------\n")
  cat("SAPPLY\n")
  cat("---------------------------------------\n")
  a = matrix(1:6, nrow = 2, ncol = 3)
  x = sapply(a, sum) # takes any data and returns vector
  print(class(x))
  print(x)
  cat("\n")
}

## tapply is apply + grouping factor
{
  cat("\n---------------------------------------\n")
  cat("TAPPLY\n")
  cat("---------------------------------------\n")
  a = data.frame(a = c(1, 2, 3, 1, 2, 3), b = c("W", "X", "Y", "W", "X", "Y"))
  x = tapply(a$a, a$b, sum) # takes any data and returns vector
  print(class(x))
  print(x)
  cat("\n")
}
