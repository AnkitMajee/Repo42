def insert(arr,idx,var):
    for i in range(len(arr)-1,idx-1,-1):

        arr[i+1]=arr[i]
    arr[idx]=val

arr=eval(input("\n Enter array in python: "))
print(arr)
n=int(input("Enter value:"))
i=int(input("Enter Index:"))
insert(arr,i,n)
print(arr)
