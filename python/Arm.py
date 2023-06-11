
print("\n The armstrong numbers from 1 to 10000 are :- ",end="")
for num in range(1,10000):
    NewNum = num
    sum=0
    while(num>0):
        last = num%10
        sum += last**3
        num = num//10
    if(sum == NewNum):
        print(sum,end=" ")
