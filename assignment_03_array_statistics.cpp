// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

 // Function to calculate the sum
double calculateSum(double numbers[], int size) {
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }

    return sum;
}

 // Function to calculate the average
double calculateAverage(double numbers[], int size) {
    return calculateSum(numbers, size) / size;
}

// Function to find the minimum
double findMinimum(double numbers[], int size) {
    double minimum = numbers[0];

    for (int i = 1; i < size; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }

    return minimum;
}

 // Function to find the maximum
double findMaximum(double numbers[], int size) {
    double maximum = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }

    return maximum;
}

 int main() {
    int size;

    cout << "Enter the number of values: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid number of values." << endl;
        return 1;
    }

    double numbers[size];

    // Read numbers from the user
    cout << "Enter " << size << " numbers:" << endl;

    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    // Calculate statistics
    double sum = calculateSum(numbers, size);
    double average = calculateAverage(numbers, size);
    double minimum = findMinimum(numbers, size);
    double maximum = findMaximum(numbers, size);

    // Display results
    cout << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;

    return 0;
}


