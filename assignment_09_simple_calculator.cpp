// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Addition function
double addition(double a, double b)
{
    return a + b;
}

// Subtraction function
double subtraction(double a, double b)
{
    return a - b;
}

// Multiplication function
double multiplication(double a, double b)
{
    return a * b;
}

// Division function
double division(double a, double b)
{
    return a / b;
}

// Modulus function
int modulusOperation(int a, int b)
{
    return a % b;
}

// Exponentiation function
double exponentiation(double a, double b)
{
    return pow(a, b);
}

int main()
{
    int choice;

    cout << fixed << setprecision(2);

    do
    {
        cout << "\n=====================================\n";
        cout << "       SIMPLE CALCULATOR\n";
        cout << "=====================================\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. Modulus (%)\n";
        cout << "6. Exponentiation (^)\n";
        cout << "7. Quit\n";
        cout << "=====================================\n";

        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (choice >= 1 && choice <= 6)
        {
            double num1, num2;

            cout << "Enter first number: ";
            cin >> num1;

            cout << "Enter second number: ";
            cin >> num2;

            switch (choice)
            {
                case 1:
                    cout << "Result = "
                         << addition(num1, num2) << endl;
                    break;

                case 2:
                    cout << "Result = "
                         << subtraction(num1, num2) << endl;
                    break;

                case 3:
                    cout << "Result = "
                         << multiplication(num1, num2) << endl;
                    break;

                case 4:
                    if (num2 == 0)
                    {
                        cout << "Error: Division by zero is not allowed."
                             << endl;
                    }
                    else
                    {
                        cout << "Result = "
                             << division(num1, num2) << endl;
                    }
                    break;

                case 5:
                {
                    int int1 = static_cast<int>(num1);
                    int int2 = static_cast<int>(num2);

                    if (int2 == 0)
                    {
                        cout << "Error: Modulus by zero is not allowed."
                             << endl;
                    }
                    else
                    {
                        cout << "Result = "
                             << modulusOperation(int1, int2) << endl;
                    }
                    break;
                }

                case 6:
                    cout << "Result = "
                         << exponentiation(num1, num2) << endl;
                    break;
            }
        }
        else if (choice == 7)
        {
            cout << "Goodbye!" << endl;
        }
        else
        {
            cout << "Invalid choice. Please select a number from 1 to 7."
                 << endl;
        }

    } while (choice != 7);

    return 0;
}


