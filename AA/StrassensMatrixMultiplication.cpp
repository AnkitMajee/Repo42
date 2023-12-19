//Strassens Matrix Multiplication

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

using Matrix = vector<vector<int>>;

void print(const string& display, const Matrix& matrix, int start_row, int start_column, int end_row, int end_column) {
    cout << endl << display << " =>" << endl;
    for (int i = start_row; i <= end_row; i++) {
        for (int j = start_column; j <= end_column; j++) {
            cout << setw(10) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

Matrix add_matrices(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix multiply_matrices(const Matrix& A, const Matrix& B) {
    int n = A.size();

    if (n == 1) {
        Matrix C(1, vector<int>(1, A[0][0] * B[0][0]));
        return C;
    }

    int split = n / 2;

    Matrix A11(split, vector<int>(split, 0)), A12(split, vector<int>(split, 0)),
           A21(split, vector<int>(split, 0)), A22(split, vector<int>(split, 0)),
           B11(split, vector<int>(split, 0)), B12(split, vector<int>(split, 0)),
           B21(split, vector<int>(split, 0)), B22(split, vector<int>(split, 0));

    for (int i = 0; i < split; i++)
        for (int j = 0; j < split; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + split];
            A21[i][j] = A[i + split][j];
            A22[i][j] = A[i + split][j + split];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + split];
            B21[i][j] = B[i + split][j];
            B22[i][j] = B[i + split][j + split];
        }

    Matrix C11 = add_matrices(multiply_matrices(A11, B11), multiply_matrices(A12, B21));
    Matrix C12 = add_matrices(multiply_matrices(A11, B12), multiply_matrices(A12, B22));
    Matrix C21 = add_matrices(multiply_matrices(A21, B11), multiply_matrices(A22, B21));
    Matrix C22 = add_matrices(multiply_matrices(A21, B12), multiply_matrices(A22, B22));

    Matrix C(n, vector<int>(n, 0));

    for (int i = 0; i < split; i++)
        for (int j = 0; j < split; j++) {
            C[i][j] = C11[i][j];
            C[i][j + split] = C12[i][j];
            C[i + split][j] = C21[i][j];
            C[i + split][j + split] = C22[i][j];
        }

    return C;
}

int main() {
    Matrix A = {{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {2, 2, 2, 2}};
    print("Array A", A, 0, 0, A.size() - 1, A[0].size() - 1);

    Matrix B = {{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {2, 2, 2, 2}};
    print("Array B", B, 0, 0, B.size() - 1, B[0].size() - 1);

    Matrix result = multiply_matrices(A, B);
    print("Result Array", result, 0, 0, result.size() - 1, result[0].size() - 1);

    return 0;
}
