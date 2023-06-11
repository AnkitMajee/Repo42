def bubble(arr):
    n=len(arr)
    for i in range(0,n-1):
        for j in range(0,n-1-i):
            if(arr[j]>arr[j+1]):
                arr[j],arr[j+1] = arr[j+1],arr[j]
    return

while(True):
    arr=list(map(int,input("Enter the array items").strip().split()))
    bubble(arr)
    print("Bubble sorted array =",arr)
    break
