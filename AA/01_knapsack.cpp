// 0/1 Knapsack Using Dynamic Programming

#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int weights[], int values[], int n, int capacity) {
    int table[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                table[i][w] = 0;
            else if (weights[i - 1] <= w)
                table[i][w] = max(values[i - 1] + table[i - 1][w - weights[i - 1]], table[i - 1][w]);
            else
                table[i][w] = table[i - 1][w];
        }
    }

    cout << "Dynamic Programming Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            cout << table[i][w] << "\t";
        }
        cout << endl;
    }
    cout << "\nSelected items for 0/1 Knapsack:\n"<<table[n][capacity];
}

int main() {
    int n, capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    int weights[n];
    int values[n];

    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> weights[i] >> values[i];
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    knapsack(weights, values, n, capacity);

    return 0;
}
