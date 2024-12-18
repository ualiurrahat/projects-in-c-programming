/*
    Author: MD. Ualiur Rahman Rahat

    Project: A Comprehensive and Interactive Calculator Using C

    About the Project:
    This project implements a simple yet versatile calculator capable of performing basic arithmetic operations such as addition, subtraction, multiplication, and division.
    Additionally, it supports advanced features like finding remainders, calculating percentage values, and clearing all previous data. The program is interactive, allowing
    continuous operations and updates the result dynamically, while handling invalid inputs gracefully. It is designed to provide an efficient and user-friendly experience.
*/

// Including necessary header files.
#include <stdio.h>
#include <stdlib.h>

// Global variable to store the result after a calculation.
double result = 0;

// Variable to determine if one or two operands are needed as user input.
// If k = 0, the user needs to input two operands.
// If k > 0, the user needs to input only one operand.
int k = 0;

// Function to display the menu options and return the user's choice.
int menu()
{
    // Variable to store the user's choice.
    int choice;

    printf("\n\n    Result: %.2lf\n", result);
    // at first, no calculation has been performed.So initial result is shown as 0.00.
    printf("\n");
    // Showcasing all the features of our calculator.
    printf("1. Addition:\n");
    printf("2. Subtraction:\n");
    printf("3. Multiplication:\n");
    printf("4. Division:\n");
    printf("5. Get Remainder:\n");
    printf("6. Percentage Value:\n");
    printf("7. Clear All Data: \n");
    printf("8. Exit the program: \n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

// Function to perform addition.
void addition()
{

    double a, b; // Variables to store operands.

    if (k) // One operand is needed when k > 0.
    {
        printf("\nEnter a number: ");
        scanf("%lf", &a);
        result += a;
        printf("Result = %.2lf\n", result);
    }
    else // Two operands are needed when k == 0.
    {
        printf("Enter two operands: ");
        scanf("%lf %lf", &a, &b);
        result = a + b;
        printf("Result = %.2lf\n", result);
    }

    k = 1; // Updating k to 1 since the result can now be used as an operand.
}

// Function to perform subtraction.
void subtraction()
{
    double a, b; // Variables to store operands.

    if (k) // One operand is needed when k > 0.
    {
        printf("\nEnter a number: ");
        scanf("%lf", &a);
        result -= a;
        printf("Result = %.2lf\n", result);
    }
    else // Two operands are needed when k == 0.
    {
        printf("Enter two operands: ");
        scanf("%lf %lf", &a, &b);
        result = a - b;
        printf("Result = %.2lf\n", result);
    }

    k = 1; // Updating k to 1 since the result can now be used as an operand.
}

// Function to perform multiplication.
void multiplication()
{

    double a, b; // Variables to store operands.

    if (k) // One operand is needed when k > 0.
    {
        printf("\nEnter a number: ");
        scanf("%lf", &a);
        result *= a;
        printf("Result = %.2lf\n", result);
    }
    else // Two operands are needed when k == 0.
    {
        printf("Enter two operands: ");
        scanf("%lf %lf", &a, &b);
        result = a * b;
        printf("Result = %lf\n", result);
    }

    k = 1; // Updating k to 1 since the result can now be used as an operand.
}

// Function to perform division.
void division()
{

    double a, b; // Variables to store operands.

    if (k) // One operand is needed when k > 0.
    {
        printf("\nEnter a number: ");
        scanf("%lf", &a);

        if (a == 0) // Handling division by zero.
        {
            printf("Infinity!!\n");
            printf("Result reset to 0.\n");
            k = 0;
            result = 0;
            printf("Result = 0\n");
        }
        else
        {
            result /= a;
            printf("Result = %.2lf\n", result);
        }
    }

    else // Two operands are needed when k == 0.
    {
        printf("Enter two operands: ");
        scanf("%lf %lf", &a, &b);

        if (b == 0) // Handling division by zero.
        {
            printf("Infinity!!\n");
            printf("Result reset to 0.\n");
            k = 0;
            result = 0;
            printf("Result = 0\n");
        }

        else
        {
            result = a / b;
            printf("Result = %.2lf\n", result);
        }
    }

    k = 1; // Updating k to 1 since the result can now be used as an operand.
}

// Function to calculate the remainder.
void getRemainder()
{
    int a, b; // Integer operands for remainder operation.

    int rem = (int)result; // Converting result to an integer.

    if (k) // One operand is needed when k > 0.
    {
        printf("Integer value of the result: %d\n", rem);
        printf("\nEnter a number: ");
        scanf("%d", &a);

        rem = rem % a;
        result = rem;
        printf("Result = %.2lf\n", result);
    }

    else // Two operands are needed when k == 0.
    {
        printf("Enter two operands: ");
        scanf("%d %d", &a, &b);

        rem = a % b;
        result = rem;
        printf("Result = %d\n", result);
    }

    k = 1; // Updating k to 1 since the result can now be used as an operand.
}

// Function to calculate the percentage of a number.
void getPercentage()
{
    double percent, number;
    if (k) // If k > 0, the result is used to calculate the percentage.
    {
        printf("Enter percentage: ");
        scanf("%lf", &percent);

        result = (result * percent) / 100;
        printf("Result = %.2lf\n", result);
    }
    else // If k == 0, the user provides both the number and the percentage.
    {

        printf("Enter a number: ");
        scanf("%lf", &number);
        printf("Enter percentage: ");
        scanf("%lf", &percent);

        result = (number * percent) / 100;
        printf("Result = %.2lf\n", result);
    }
}
// Function to clear all stored data.
void clearData()
{
    k = 0;
    result = 0;

    printf("Data has been cleared Successfully!\n");
}

int main()
{
    // showing name on the screen.
    printf("                        ................Versatile Calculator...........\n\n");

    while (1) // Infinite loop to keep the calculator running until the user chooses to exit.
    {
        switch (menu()) // Handling user choice using a switch-case structure.
        {
        case 1:
            addition();
            break;

        case 2:
            subtraction();
            break;

        case 3:
            multiplication();
            break;

        case 4:
            division();
            break;

        case 5:
            getRemainder();
            break;

        case 6:
            getPercentage();
            break;
        case 7:
            clearData();
            break;

        case 8:
            printf("Thanks for using my software.\n");
            // termination of the program.
            exit(0);

        default:
            printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
