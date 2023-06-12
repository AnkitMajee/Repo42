def right(row):
    for i in range(1,row+1):
        for j in range(i):
            print("*",end=" ")
        print()
    return

while(True):
    row = int(input("\n Enter the numbers of rows = "))
    right(row)
    break
