def insertionSort(arr):
    if(n:=len(arr))<=1:
        return
    for i in range(1,n):
        key=arr[i]
        j=i-1
        while j>=0 and key<arr[j]:
            arr[j+1]=arr[j]
            j-=1
            arr[j+1]=key


arr=[]
n=int(input("Enter the list size "))
print("\n")
for i in range(0,n):
    item=int(input("Enter item "))
    arr.append(item)
insertionSort(arr)
print("The sorted element",arr)
