//Binary Search Recursive

#include <iostream>
using namespace std;

int bSearch(int arr[], int low, int high, int x) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == x)
        return mid;
    else if (arr[mid] > x)
        return bSearch(arr, low, mid - 1, x);
    else
        return bSearch(arr, mid + 1, high, x);
}

int main() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int x;

    cout << "Enter the value to be searched: ";
    cin >> x;

    int result = bSearch(arr, 0, n - 1, x);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array.\n";

    return 0;
}
