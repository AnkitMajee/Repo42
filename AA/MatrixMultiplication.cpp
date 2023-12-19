//Matrix Multiplication

#include <iostream>

using namespace std;

int main() {
    int rows1, cols1, rows2, cols2;

    cout << "Enter the number of rows for the first matrix: ";
    cin >> rows1;
    cout << "Enter the number of columns for the first matrix: ";
    cin >> cols1;

    cout << "Enter the number of rows for the second matrix: ";
    cin >> rows2;
    cout << "Enter the number of columns for the second matrix: ";
    cin >> cols2;

    if (cols1 != rows2) {
        cerr << "Error: Matrices cannot be multiplied. Number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
        return 1;
    }

    int matrix1[rows1][cols1];
    int matrix2[rows2][cols2];

    int resultMatrix[rows1][cols2];

    cout << "Enter elements for the first matrix:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            cout << "Enter element at position (" << i + 1 << "," << j + 1 << "): ";
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter elements for the second matrix:" << endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            cout << "Enter element at position (" << i + 1 << "," << j + 1 << "): ";
            cin >> matrix2[i][j];
        }
    }

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    cout << "Resultant Matrix:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            cout << resultMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
