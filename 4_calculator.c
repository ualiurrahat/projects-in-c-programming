/*
    
    Author: MD.Ualiur Rahman Rahat.

*/
//Project: Creating a simple calculator using C programming language.
// About Project: here I am gonna make a simple calculator to perform addition, subtraction,
// multiplication, division and finding remainders, getting percentages of a numbeer and many more.

// header files....
#include <stdio.h>
#include <stdlib.h>

// var to store result after calculation.
double result = 0;

// var to decide if one or two operands are needed as user input.
// if k = 0, user have to input two operands.
// if k is any positive value, then user needs to input only one operands.
int k = 0;

// function to show menu option.
int menu()
{
    // var to store user's choice from menu option.
    int choice;

    printf("\n\n    Result: %.2lf\n", result);
    printf("\n");
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

// function to perform addition

void addition()
{

    // var to store operands.
    double a, b;

    // when k > 0, one operand is needed.
    if (k)
    {
        printf("\nEnter a number: ");
        scanf("%lf", &a);
        result += a;
        printf("Result = %.2lf\n", result);
    }

    //when k == 0, we need two operands.
    else
    {
        printf("Enter two operands: ");
        scanf("%lf %lf", &a, &b);
        result = a + b;
        printf("Result = %.2lf\n", result);
    }

    // changing value of k after calculation.
    // k is 1, cause we have 1 operand as result.
    // so we need only 1 operands to perform any other operation.

    k = 1;
}

// function to perform subtraction.

void subtraction()
{

    // var to store operands.
    double a, b;

    // when k > 0, one operand is needed.
    if (k)
    {
        printf("\nEnter a number: ");
        scanf("%lf", &a);
        result -= a;
        printf("Result = %.2lf\n", result);
    }

    //when k == 0, we need two operands.
    else
    {
        printf("Enter two operands: ");
        scanf("%lf %lf", &a, &b);
        result = a - b;
        printf("Result = %.2lf\n", result);
    }

    // changing value of k after calculation.
    // k is 1, cause we have 1 operand as result.
    // so we need only 1 operands to perform any other operation.

    k = 1;
}

// function to perform multiplication.

void multiplication()
{

    // var to store operands.
    double a, b;

    // when k > 0, one operand is needed.
    if (k)
    {
        printf("\nEnter a number: ");
        scanf("%lf", &a);
        result *= a;
        printf("Result = %.2lf\n", result);
    }

    //when k == 0, we need two operands.
    else
    {
        printf("Enter two operands: ");
        scanf("%lf %lf", &a, &b);
        result = a * b;
        printf("Result = %lf\n", result);
    }

    // changing value of k after calculation.
    // k is 1, cause we have 1 operand as result.
    // so we need only 1 operands to perform any other operation.

    k = 1;
}

// function to perform division.

void division()
{

    // var to store operands.
    double a, b;

    // when k > 0, one operand is needed.
    if (k)
    {
        printf("\nEnter a number: ");
        scanf("%lf", &a);

        // showing error or infinity value if any number is divided by zero.
        // if so, then var result is reset to zero to perform other operations.
        if (a == 0)
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

    //when k == 0, we need two operands.
    else
    {
        printf("Enter two operands: ");
        scanf("%lf %lf", &a, &b);

        if (b == 0)
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

    // changing value of k after calculation.
    // k is 1, cause we have 1 operand as result.
    // so we need only 1 operands to perform any other operation.

    k = 1;
}

// function to perform remainder operation.

void getRemainder()
{

    // var to store operands.
    int a, b;

    // remainder can be found only for integer values.
    // so taking a new var to store integer value of result var.

    int rem = (int)result;

    // when k > 0, one operand is needed.
    if (k)
    {
        printf("Integer value of the result: %d\n", rem);
        printf("\nEnter a number: ");
        scanf("%d", &a);

        rem = rem % a;
        result = rem;
        printf("Result = %.2lf\n", result);
    }

    //when k == 0, we need two operands.
    else
    {
        printf("Enter two operands: ");
        scanf("%d %d", &a, &b);

        rem = a % b;
        result = rem;
        printf("Result = %d\n", result);
    }

    // changing value of k after calculation.
    // k is 1, cause we have 1 operand as result.
    // so we need only 1 operands to perform any other operation.

    k = 1;
}

// function to get percentage value of a number.

void getPercentage()
{
    double percent;
    double number;
    // k > 0, then there is already a number exist in the result var.
    // we need to ask how many percentage of the number user wants to know.
    if (k)
    {
        printf("Enter percentage: ");
        scanf("%lf", &percent);

        result = (result * percent) / 100;
        printf("Result = %.2lf\n", result);
    }
    // when k == 0, we need a number and the percentage of the number we want to know.
    else
    {

        printf("Enter a number: ");
        scanf("%lf", &number);
        printf("Enter percentage: ");
        scanf("%lf", &percent);

        result = (number * percent) / 100;
        printf("Result = %.2lf\n", result);
    }
}
void clearData()
{
    k = 0;
    result = 0;

    printf("Data has been cleared Successfully!\n");
}

int main()
{
    // showing name on the screen.
    printf("                        ................Rahat Calculator...........\n\n");
    //showing menu option to the user until chose to exit the program.

    while (1)
    {
        switch (menu())
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
            //termination of the program.
            exit(0);

        default:
            printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
