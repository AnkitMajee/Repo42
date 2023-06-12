def print_pattern(row):
    # Upper half of the pattern
    for i in range(row):
        print(" " * (row - i - 1) + "* " * (i + 1))

    # Lower half of the pattern
    for i in range(row - 2, -1, -1):
        print(" " * (row - i - 1) + "* " * (i + 1))

# Example usage
row = 5
print_pattern(row)
