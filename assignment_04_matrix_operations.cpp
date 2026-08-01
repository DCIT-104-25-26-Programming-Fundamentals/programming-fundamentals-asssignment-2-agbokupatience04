// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int A[][10], int B[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(int A[][10], int B[][10], int result[][10], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int matrix[10][10];
    int transpose[10][10];
    int A[10][10];
    int B[10][10];
    int sum[10][10];
    int product[10][10];
    int M, N, P;

    // =========================
    // PART A: TRANSPOSE
    // =========================
    cout << "PART A: MATRIX TRANSPOSE" << endl;
    cout << "Enter number of rows (M): ";
    cin >> M;
    cout << "Enter number of columns (N): ";
    cin >> N;
    cout << "Enter the matrix elements:" << endl;
    readMatrix(matrix, M, N);
    transposeMatrix(matrix, transpose, M, N);
    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix, M, N);
    cout << "\nTranspose:" << endl;
    displayMatrix(transpose, N, M);

    // =========================
    // PART B: ADDITION
    // =========================
    cout << "\nPART B: MATRIX ADDITION" << endl;
    cout << "Enter Matrix A (" << M << " x " << N << "):" << endl;
    readMatrix(A, M, N);
    cout << "Enter Matrix B (" << M << " x " << N << "):" << endl;
    readMatrix(B, M, N);
    addMatrices(A, B, sum, M, N);
    cout << "\nMatrix A + Matrix B:" << endl;
    displayMatrix(sum, M, N);

    // =========================
    // PART C: MULTIPLICATION
    // =========================
    cout << "\nPART C: MATRIX MULTIPLICATION" << endl;
    cout << "Matrix A has size M x N." << endl;
    cout << "Matrix B has size N x P." << endl;
    cout << "Enter M: ";
    cin >> M;
    cout << "Enter N: ";
    cin >> N;
    cout << "Enter P: ";
    cin >> P;
    cout << "\nEnter Matrix A (" << M << " x " << N << "):" << endl;
    readMatrix(A, M, N);
    cout << "Enter Matrix B (" << N << " x " << P << "):" << endl;
    readMatrix(B, N, P);
    multiplyMatrices(A, B, product, M, N, P);
    cout << "\nMatrix A x Matrix B:" << endl;
    displayMatrix(product, M, P);
    return 0;
}

