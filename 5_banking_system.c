/*
    Author: MD. Ualiur Rahman Rahat

*/

/* About Project: Banking System Software.
    The project is about creating a banking system
    where user can creat an account and
    perform various task like depositing, transfering, withdrwaing money.

*/

#include <stdio.h>
#include <stdlib.h>

// var to store valuable data.
int totalAmount = 1000; // each account is given 1000$ with the opening of the account.
int depositAmount;
int withdrawAmount;
int transferAmount;
int totalDeposit = 0;
int totalWithdrawn = 0;
int totalTransfer = 0;
int accountNumber;
char userName[100];

// function to show menu.
int menu()
{
    // var to store user's option.
    int choice;

    printf("\n1. Deposit Money: \n");
    printf("2. Withdraw Cash: \n");
    printf("3. Transfer Money: \n");
    printf("4. Check Details: \n");
    printf("5. Exit: \n");
    printf("\n Enter your choice: \n");
    scanf("%d", &choice);
    return choice;
}

// function to use for depositing money.
void deposit_money()
{
    //  user input for amount of money to be deposited.
    printf("Enter the amount you want to deposit: ");
    scanf("%d", &depositAmount);

    //updating total amount of money on the account.
    totalAmount = totalAmount + depositAmount;
}

// function to be used for money withdrawal.
void withdraw_money()
{
    //  user input for amount of money to be withdrawn.
    printf("Enter the amount you wish to withdraw: ");
    scanf("%d", &withdrawAmount);

    // checking whether account has enough amount or not.
    if (withdrawAmount <= totalAmount)
    {
        // successful withdrawal case.
        //updating total amount.
        totalAmount = totalAmount - withdrawAmount;
        // updated data to be shown to the user.
        printf("You have successfully withdrawn $%d.\n", withdrawAmount);
        printf("Your new balance is $%d.\n", totalAmount);
    }
    else
    {
        // case: money withdrwan failed due to insufficient balance
        printf("Insufficient Balance!!! Your account don't have that amount of money.\n");
    }
}

// function to perform money transfer operation.
void transfer_money()
{
    printf("Enter the amount you want to transfer: ");
    scanf("%d", &transferAmount);
    //checking whether the account has sufficient balance or not.
    if (transferAmount <= totalAmount)
    {
        // in case of sufficient balance.
        //updating total amount.
        totalAmount = totalAmount - transferAmount;
        //updated data shown to the user.
        printf("You have successfully transferred $%d.\n", transferAmount);
        printf("Your new balance is $%d.\n", totalAmount);
    }
    else
    { // case: money transfer failed due to insufficient balance
        printf("Insufficient Balance!!! Your account don't have that amount of money to be transferred.\n");
    }
}

// function to be performed to show detail info.
void checkDetails()
{
    printf("Your Balance: $%d\n", totalAmount);
    printf("Total Deposited: $%d\n", totalDeposit);
    printf("Total Withdrawn: $%d\n", totalWithdrawn);
    printf("Total Transferred: $%d\n", totalTransfer);
}

// funtion to show user all data before leaving the site.

void lastCheck()
{
    printf("............Showing Your Info before you leave.........\n");
    printf("Account Name: %s\n", userName);
    printf("Account Number: %d\n", accountNumber);
    printf("Your Balance: $%d\n", totalAmount);
    printf("Total Deposited: $%d\n", totalDeposit);
    printf("Total Withdrawn: $%d\n", totalWithdrawn);
    printf("Total Transferred: $%d\n", totalTransfer);
    printf("\n");
    // greetings on leaving the program.
    printf("Thanks for using our service. Wish you will contact us soon.\n");
    printf("....................****.................");
}

int main()
{
    printf("***********Welcome To Ualiur Rahat Bank Limited****************\n");
    printf("\n\n");

    // account opening info.
    // program will work fine for any valid name
    // and any arbitrary number being in the range of valid integer limit.
    printf("Enter the details below to open an account successfully........\n");
    printf("Enter your name: ");
    gets(userName);
    printf("Enter your account number (write a number you would like but not more than 5 digit): ");
    scanf("%d", &accountNumber);
    printf("\n\n");

    //account creation successful message and balance info.
    printf("Congrats! You have opened an account succesfully!\n");
    printf("You got $1000 bonus for opening the account.\n");

    while (1)
    {
        // running the loop until user exit the program.
        switch (menu())
        {
        case 1:
            deposit_money();
            totalDeposit = totalDeposit + depositAmount;
            break;

        case 2:
            withdraw_money();
            if (withdrawAmount <= totalAmount)
            {
                totalWithdrawn += withdrawAmount;
            }
            break;

        case 3:
            transfer_money();
            if (transferAmount <= totalAmount)
            {
                totalTransfer += transferAmount;
            }
            break;

        case 4:
            checkDetails();
            break;

        case 5:
            // to show all info before leaving the program.
            lastCheck();
            exit(0);

        default:
            printf("Invalid choice!!!\n");
        }
    }

    return 0;
}
