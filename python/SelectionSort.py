def selection(arr):
    for i in range(0,len(arr)-1):
        min_index=i
        for j in range(i+1,len(arr)):
            if(arr[j]<arr[min_index]):
                min_index=j
        arr[min_index],arr[i]=arr[i],arr[min_index]
    return

li = list(map(int,input("Enter the array items = ").strip().split()))
selection(li)
print("Selection sorted array = ",li)
