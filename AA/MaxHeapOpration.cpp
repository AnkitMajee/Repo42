// Max Heap Oprations

#include <bits/stdc++.h> 
using namespace std; 

class MaxHeap {
    int *arr;
    int size;
    int capacity;
    
public:
    
    MaxHeap(int c) {
        size = 0; 
        capacity = c; 
        arr = new int[c];
    }

    int left(int i) { return (2 * i + 1); } 
    int right(int i) { return (2 * i + 2); } 
    int parent(int i) { return (i - 1) / 2; } 
    
    void insert(int x) { 
        if (size == capacity) return;
        size++; 
        arr[size - 1] = x; 

        for (int i = size - 1; i != 0 && arr[parent(i)] < arr[i];) { 
            swap(arr[i], arr[parent(i)]); 
            i = parent(i); 
        } 
    }
    
    void maxHeapify(int i) { 
        int lt = left(i); 
        int rt = right(i); 
        int largest = i; 
        if (lt < size && arr[lt] > arr[i]) 
            largest = lt; 
        if (rt < size && arr[rt] > arr[largest]) 
            largest = rt; 
        if (largest != i) { 
            swap(arr[i], arr[largest]); 
            maxHeapify(largest); 
        } 
    }
    
    int extractMax() { 
        if (size <= 0) 
            return INT_MIN; 
        if (size == 1) { 
            size--; 
            return arr[0]; 
        }  
        swap(arr[0], arr[size - 1]);
        size--; 
        maxHeapify(0); 
  
        return arr[size]; 
    }
    
    void decreaseKey(int i, int x) { 
        arr[i] = x; 
        while (i != 0 && arr[parent(i)] < arr[i]) { 
            swap(arr[i], arr[parent(i)]); 
            i = parent(i); 
        } 
    }
    
    void deleteKey(int i) { 
if (i >= size) {
        return;
    }

    arr[i] = arr[size - 1];
    size--;
    maxHeapify(i);
    }
};

int main() { 
    MaxHeap h(11);
    h.insert(3); 
    h.insert(2);
    cout << "Max element extracted: " << h.extractMax() << endl;
    h.insert(15);
    h.insert(20);
    cout << "Max element extracted: " << h.extractMax() << endl;
    h.decreaseKey(2, 30);
    cout << "Max element extracted: " << h.extractMax() << endl;
    h.deleteKey(1);
    cout << "Max element extracted: " << h.extractMax() << endl;

    return 0;
}
