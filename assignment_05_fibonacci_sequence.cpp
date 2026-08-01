// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// Part A: Print the first N Fibonacci terms
void printFibonacci(int N) {
    int first = 0;
    int second = 1;

    for (int i = 0; i < N; i++) {
        cout << first << " ";

        int next = first + second;
        first = second;
        second = next;
    }

    cout << endl;
}

// Part B: Check if a number is a Fibonacci number
bool isFibonacci(int number) {
    int first = 0;
    int second = 1;

    while (first <= number) {
        if (first == number) {
            return true;
        }

        int next = first + second;
        first = second;
        second = next;
    }

    return false;
}

int main() {
    // Part A
    int N;

    cout << "PART A: Fibonacci Sequence" << endl;
    cout << "How many terms do you want to display? ";
    cin >> N;

    if (N <= 0) {
        cout << "Please enter a positive number." << endl;
    } else {
        cout << "First " << N << " Fibonacci terms: ";
        printFibonacci(N);
    }

    // Part B
    int number;

    cout << "\nPART B: Check Fibonacci Number" << endl;
    cout << "Enter a number: ";
    cin >> number;

    if (number < 0) {
        cout << number << " is not a Fibonacci number." << endl;
    } else if (isFibonacci(number)) {
        cout << number << " is a Fibonacci number." << endl;
    } else {
        cout << number << " is not a Fibonacci number." << endl;
    }

    return 0;
}

