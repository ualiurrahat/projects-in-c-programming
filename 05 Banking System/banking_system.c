/*
    Author: MD. Ualiur Rahman Rahat

    About Project: Banking System Software
    This project implements a basic banking system where a user can open an account
    and perform several banking operations. Each account starts with a balance of $1000 as a bonus.
    Users can:
    1. Deposit money into their account.
    2. Withdraw money from their account (if sufficient balance is available).
    3. Transfer money to another account (simulated transfer).
    4. Check account details, including transaction summaries.
    The program ensures data integrity and provides a detailed summary of transactions before exit.
*/
// Necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variables to store account details and transaction information.
int totalAmount = 1000; // Initial balance for a new account.
int depositAmount;      // Amount to be deposited in a transaction.
int withdrawAmount;     // Amount to be withdrawn in a transaction.
int transferAmount;     // Amount to be transferred in a transaction.
int totalDeposit = 0;   // Total amount deposited during the session.
int totalWithdrawn = 0; // Total amount withdrawn during the session.
int totalTransfer = 0;  // Total amount transferred during the session.
int accountNumber;      // User's account number.
char userName[100];     // User's name.

// Function to display the main menu options to the user.
int menu()
{
    // Variable to store the user's menu choice.
    int choice;

    printf("\n======= Banking System Menu =======\n");
    printf("1. Deposit Money\n");
    printf("2. Withdraw Cash\n");
    printf("3. Transfer Money\n");
    printf("4. Check Account Details\n");
    printf("5. Exit\n");
    printf("===================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to handle depositing money.
void deposit_money()
{
    printf("Enter the amount you want to deposit: ");
    scanf("%d", &depositAmount);

    // checking valid amount for deposit.
    if (depositAmount <= 0)
    {
        printf("Invalid deposit amount! Please enter a positive value.\n");
        return;
    }

    totalAmount += depositAmount;  // Update the total balance.
    totalDeposit += depositAmount; // Update the total deposit amount.
    printf("Deposit successful! Current Balance: $%d\n", totalAmount);
}

// Function to handle withdrawing money.
void withdraw_money()
{
    printf("Enter the amount you wish to withdraw: ");
    scanf("%d", &withdrawAmount);

    // checking for valid amount.
    if (withdrawAmount <= 0)
    {
        printf("Invalid withdrawal amount! Please enter a positive value.\n");
        return;
    }
    // Check if the withdrawal amount is less than or equal to the available balance.
    if (withdrawAmount <= totalAmount)
    {
        totalAmount -= withdrawAmount;    // Deduct the withdrawal amount from the balance.
        totalWithdrawn += withdrawAmount; // Update the total withdrawn amount.
        printf("Withdrawal successful! Remaining Balance: $%d\n", totalAmount);
    }
    else
    { // Notify the user that the withdrawal cannot proceed due to insufficient balance.
        printf("Insufficient Balance! Withdrawal failed.\n");
    }
}
// Function to handle transferring money
void transfer_money()
{
    printf("Enter the amount you want to transfer: ");
    scanf("%d", &transferAmount);

    // Check whether the account has sufficient balance or not
    if (transferAmount <= totalAmount)
    {
        // Deduct the balance
        totalAmount = totalAmount - transferAmount;
        totalTransfer += transferAmount; // Update the total transfer amount.
        // Inform the user about the successful transfer
        printf("You have successfully transferred $%d.\n", transferAmount);
        printf("Your new balance is $%d.\n", totalAmount);
    }
    else
    {
        // Case: money transfer failed due to insufficient balance
        printf("Insufficient Balance!!! Your account doesn't have enough money to transfer.\n");
    }
}

// Function to display account details.
void checkDetails()
{
    printf("\n======= Account Details =======\n");
    printf("Account Name: %s\n", userName);
    printf("Account Number: %d\n", accountNumber);
    printf("Current Balance: $%d\n", totalAmount);
    printf("Total Deposited: $%d\n", totalDeposit);
    printf("Total Withdrawn: $%d\n", totalWithdrawn);
    printf("Total Transferred: $%d\n", totalTransfer);
    printf("================================\n");
}

// Function to display a summary of transactions before exiting.
void lastCheck()
{
    printf("\n======= Final Account Summary =======\n");
    printf("Account Name: %s\n", userName);
    printf("Account Number: %d\n", accountNumber);
    printf("Final Balance: $%d\n", totalAmount);
    printf("Total Deposited: $%d\n", totalDeposit);
    printf("Total Withdrawn: $%d\n", totalWithdrawn);
    printf("Total Transferred: $%d\n", totalTransfer);
    printf("=====================================\n");
    printf("Thank you for banking with U.R. Bank Limited. Goodbye!\n");
}

int main()
{
    printf("***********Welcome To U.R.  Bank Limited****************\n");
    printf("\n\n");

    // Account opening info.
    // Program will work fine for any valid name
    // and any arbitrary number being in the range of valid integer limit.
    printf("Enter the details below to open an account successfully........\n");

    // Prompt for user name and read it
    printf("Enter your name: ");
    fgets(userName, sizeof(userName), stdin); // Use fgets instead of gets()

    // Remove the newline character that fgets() might include
    size_t len = strlen(userName);
    if (len > 0 && userName[len - 1] == '\n')
    {
        userName[len - 1] = '\0'; // Replace the newline character with null terminator
    }

    printf("Enter your account number (write a number you would like but not more than 5 digits): ");
    scanf("%d", &accountNumber);
    printf("\n\n");

    // Account creation successful message and balance info.
    printf("Congrats! You have opened an account successfully!\n");
    printf("You got $1000 bonus for opening the account.\n");

    // Main loop to keep the program running until the user exits.
    while (1)
    {
        // Handle menu options based on user input.
        switch (menu())
        {
        case 1:
            deposit_money();
            break;

        case 2:
            withdraw_money();
            break;

        case 3:
            transfer_money();
            break;

        case 4:
            checkDetails();
            break;

        case 5:
            lastCheck(); // Display account summary before exiting.
            exit(0);

        default:
            printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}
