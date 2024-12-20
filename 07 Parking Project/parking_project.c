/*
 * Author: MD. Ualiur Rahman Rahat.
 *
 * Project: Car Parking Maintenance Software
 */

/*
 * About Project:
 * This software manages a parking lot where the following vehicles can be parked:
 * - Private cars
 * - Buses
 * - Bikes
 * - CNGs
 * - Taxis
 *
 * Payment Rates:
 * - Private car/Taxi: $20
 * - CNG: $10
 * - Bus: $50
 * - Bike: $5
 *
 * Functionality:
 * - Calculates the total amount earned.
 * - Tracks the total count of each type of vehicle.
 * - Displays the maximum number of vehicles parked in each type.
 */

// Required header files for input/output operations and utility functions.
#include <stdio.h>
#include <stdlib.h>

// Global variables for tracking vehicle counts, total vehicles, and total revenue.
int no_of_bus = 0;              // Number of buses parked.
int no_of_private_car_taxi = 0; // Number of private cars/taxis parked.
int no_of_cng = 0;              // Number of CNGs parked.
int no_of_bike = 0;             // Number of bikes parked.
int count = 0;                  // Total number of vehicles parked.
int amount = 0;                 // Total revenue earned.

// Function to display the main menu and get user input for actions.
int menu()
{
    int choice;
    printf("\n\nChoose your option: \n");
    printf("1. Enter Bus: \n");
    printf("2. Enter Private Car/Taxi : \n");
    printf("3. Enter CNG: \n");
    printf("4. Enter Bike: \n");
    printf("5. Show Status: \n");
    printf("6. Delete Data: \n");
    printf("7. Exit from the program.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to display the current parking status.
// Displays counts of all vehicle types, total vehicles parked, and total revenue earned.
void showData()
{
    printf("\n\n......Please Wait....\n");
    printf(".......Fetching Data.......\n");
    printf(" Bus parked: %d\n", no_of_bus);
    printf(" Private car/Taxi parked: %d\n", no_of_private_car_taxi);
    printf(" CNG parked: %d\n", no_of_cng);
    printf(" Bike Parked: %d\n", no_of_bike);
    printf(" Total vehicle parked: %d\n", count);
    printf(" Total amount gained: %d\n", amount);
    printf("\n\n\n");
}

// Function to delete all data.
// Resets the counts and revenue to zero.
void deleteData()
{
    printf("............Loading...........\n");
    printf("Deleted data successfully!\n");
    no_of_bus = 0;
    no_of_private_car_taxi = 0;
    no_of_bike = 0;
    no_of_cng = 0;
    amount = 0;
    count = 0;
}

// Function to handle the entry of private cars or taxis.
// Increments the count and adds $20 to the total revenue.
void private_car_taxi()
{
    printf("\n\nEntry Successful!\n");
    printf("Please pay $20.\n");
    no_of_private_car_taxi++;
    amount += 20;
    count++;
}

// Function to handle the entry of buses.
// Increments the count and adds $50 to the total revenue.
void bus()
{
    printf("\n\nEntry Successful!\n");
    printf("Please pay $50.\n");
    no_of_bus++;
    amount += 50;
    count++;
}

// Function to handle the entry of CNGs.
// Increments the count and adds $10 to the total revenue.
void cng()
{
    printf("\n\nEntry Successful!\n");
    printf("Please pay $10.\n");
    no_of_cng++;
    amount += 10;
    count++;
}

// Function to handle the entry of bikes.
// Increments the count and adds $5 to the total revenue.
void bike()
{
    printf("\n\nEntry Successful!\n");
    printf("Please pay $5.\n");
    no_of_bike++;
    amount += 5;
    count++;
}

int main()
{
    // Welcome message displayed at the start of the program.
    printf("................Welcome To U. R. Parking Center...........\n");

    // Main program loop: Displays menu and executes corresponding actions.
    while (1)
    {
        switch (menu())
        {
        case 1:
            bus();
            break;

        case 2:
            private_car_taxi();
            break;
        case 3:
            cng();
            break;
        case 4:
            bike();
            break;
        case 5:
            showData();
            break;

        case 6:
            deleteData();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid option!!!\n");
        }
    }

    // Exit message (unreachable in the current program design).
    printf("Thanks for using our service.\n");

    return 0;
}
