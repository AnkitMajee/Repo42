//#include <iostream>
//#include <vector>
//
//using namespace std; // Using 'using namespace std;' for simplicity; not recommended in larger projects
//
//// Function to find the maximum of two integers
//int max(int a, int b) {
//    return (a > b) ? a : b;
//}
//
//// Function to solve 0/1 Knapsack using dynamic programming
//void knapsack(int weights[], int values[], int n, int capacity) {
//    int table[n + 1][capacity + 1];
//
//    // Build the dynamic programming table
//    for (int i = 0; i <= n; i++) {
//        for (int w = 0; w <= capacity; w++) {
//            if (i == 0 || w == 0)
//                table[i][w] = 0;
//            else if (weights[i - 1] <= w)
//                table[i][w] = max(values[i - 1] + table[i - 1][w - weights[i - 1]], table[i - 1][w]);
//            else
//                table[i][w] = table[i - 1][w];
//        }
//    }
//
//    // Print the dynamic programming table
//    cout << "Dynamic Programming Table:\n";
//    for (int i = 0; i <= n; i++) {
//        for (int w = 0; w <= capacity; w++) {
//            cout << table[i][w] << "\t";
//        }
//        cout << endl;
//    }
//
//    // Backtrack to find the selected items
//    int i = n, w = capacity;
//    cout << "\nSelected items for 0/1 Knapsack:\n";
//    while (i > 0 && w > 0) {
//        if (table[i][w] != table[i - 1][w]) {
//            cout << "Item " << i << " (Weight: " << weights[i - 1] << ", Value: " << values[i - 1] << ")\n";
//            w -= weights[i - 1];
//        }
//        i--;
//    }
//}
//
//int main() {
//    int n, capacity;
//
//    cout << "Enter the number of items: ";
//    cin >> n;
//
//    int weights[n];
//    int values[n];
//
//    cout << "Enter the weight and value of each item:\n";
//    for (int i = 0; i < n; i++) {
//        cout << "Item " << i + 1 << ": ";
//        cin >> weights[i] >> values[i];
//    }
//
//    cout << "Enter the capacity of the knapsack: ";
//    cin >> capacity;
//
//    knapsack(weights, values, n, capacity);
//
//    return 0;
//}
#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;

void knapSack(int W, int wt[], int val[], int n) {
    int i, j;
    int dp[n + 1][W + 1];

    for (int i = 0; i <= W; i++) {
        dp[0][i] = 0;
    }

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= W; j++) {
            if (wt[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
        }
    }

    // Printing the dp table
    cout << "DP Table:\n";
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout<<"Maximum value: "<<dp[n][W];
}

int main() {

    int val[] = {10, 4, 12};
    int wt[] = {1, 3, 4};
    int W = 6;
    int n = 3;

    knapSack(W, wt, val, n);

    return 0;
}
