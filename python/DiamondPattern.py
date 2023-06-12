n = int(input("\nEnter the no. of rows of Diamond pattern = "))

for i in range(n//2+1):
    for j in range(n//2,i,-1):
        print(' ',end=" ")
    for j in range(2*i+1):
        print('*',end=" ")
    print()
for i in range(n//2,0,-1):
    for j in range(n//2,i-1,-1):
        print(' ',end=" ")
    for j in range(2*i-1):
        print('*',end=" ")
    print()
    
