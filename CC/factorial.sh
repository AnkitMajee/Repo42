#!/bin/bash

echo "Enter a number:"
read num

factorial=1
counter=1

while [ $counter -le $num ]; do
    factorial=$((factorial * counter))
    counter=$((counter + 1))
done

echo "Factorial of $num is $factorial"


#Methond 2:
# #!/bin/bash

# echo "Enter a number"
# read n

# f=1
# c=1

# for((c=1;c<=n;c++)); do
# 	f=$((f*c));
# done

# echo "Factorail of $n is $f"
