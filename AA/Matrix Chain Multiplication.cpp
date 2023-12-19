//Matrix Chain Multiplication

#include <iostream>
#include <limits.h>
using namespace std;

void printTables(int dp[][100], int splitGap[][100], int n) {
    cout << "DP Table:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nSplit Gap Table:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << splitGap[i][j] << "\t";
        }
        cout << endl;
    }
}

int mChain(int p[], int n, int dp[][100], int splitGap[][100]) {

    for (int i = 0; i < n - 1; i++)
        dp[i][i + 1] = 0;

    for (int gap = 2; gap < n; gap++) {
        for (int i = 0; i + gap < n; i++) {
            int j = i + gap;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                int cost = dp[i][k] + dp[k][j] + p[i] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    splitGap[i][j] = k;
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {

    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int arr[n + 1]; 
    cout << "Enter the dimensions of matrices:\n";
    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    int dp[100][100];
    int splitGap[100][100];

    int minCount = mChain(arr, n + 1, dp, splitGap);
    
    printTables(dp, splitGap, n + 1);
    cout <<"\n"<< "Minimum count of matrix multiplication: " << minCount << endl;



    return 0;
}
