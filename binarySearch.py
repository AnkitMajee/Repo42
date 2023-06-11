def BinarySearch(arr, item):
    mid, left = 0, 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2

        if arr[mid] == item:
            return mid
        elif arr[mid] < item:
            left = mid + 1
        else:
            right = mid - 1

    return -1

while True:
    arr = list(map(int, input("Enter Sorted Array item =").strip().split()))
    item = int(input("Enter item to search ="))
    ans = BinarySearch(arr, item)
    if ans == -1:
        print("The Searched element is not found")
    else:
        print("The Searched element is Found at index=", ans)
