def InsertionSort(arr):
    for i in range(0,len(arr)-1):
        if(arr[i]>arr[i+1]):
            arr[i],arr[i+1] = arr[i+1],arr[i]
            for j in range(i,0,-1):
                if(arr[j]<arr[j-1]):
                    arr[j],arr[j-1] = arr[j-1],arr[j]
                else:
                    break

arr = list(map(int , input("Enter your array = ").strip().split()))
InsertionSort(arr)
print("Insertion Sorted array =",arr)
