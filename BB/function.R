add_numbers <- function(x, y) {
  return(x + y)
}

result <- add_numbers(3, 5)
print(result)  # This will print 8

# Define the function
add_numbers <- function(x, y) {
  return(x + y)
}

# Call the function
result <- add_numbers(3, 5)

# Print the result
print(result)


# Define the factorial function
factorial <- function(n) {
  if(n == 0) {
    return(1)
  } else {
    return(n * factorial(n - 1))
  }
}

# Call the function
result <- factorial(5)

# Print the result
print(result)  # This will print 120


