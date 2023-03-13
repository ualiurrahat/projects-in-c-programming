/*
 * Author: MD.Ualiur Rahman Rahat.
 *
 */

// project: A car parking maintenance software.
/*
    About Project:
    private car, bus,bike,CNG,taxi can be parked there.

    Amount to pay per vehicle.....
    private car/taxi = $20
    CNG = $10
    bus = $50
    bike = $5

    We have to calculate.....
    total amount earned....
    total count of transports.
    maximum no. of vehicles can be parked in each type.

    */

// necessary header files for the program.

#include <stdio.h>
#include <stdlib.h>

// var for vehicles of each type, total number of vehicles, total amount of money earned.

int no_of_bus = 0;
int no_of_private_car_taxi = 0;
int no_of_cng = 0;
int no_of_bike = 0;
int count = 0;
int amount = 0;

//function for menu screen.

int menu()
{
    int choice;
    printf("\n\nChoose your option: \n");
    printf("1. Enter Bus: \n");
    printf("2. Enter Private Car/Taxi : \n");
    printf("3. Enter CNG: \n");
    printf("4. Enter Bike: \n");
    printf("5. Show Status: \n");
    printf("6. Delete Data: \n\n\n");
    printf("7. Exit from the program.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// function for showing data.
//will show total number of vehicles parked in each item.
//total vehicle parked of all type.
//total amount earned.
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

//function for deleting data
//will erase all the data saved before.
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
// function for private car / taxi.
void private_car_taxi()
{
    printf("\n\nEntry Successful!\n");
    printf("Please pay $20.\n");
    no_of_private_car_taxi++;
    amount = amount + 20;
    count++;
}

// function for bus
void bus()
{
    printf("\n\nEntry Successful!\n");
    printf("Please pay $50.\n");
    no_of_bus++;
    amount = amount + 50;
    count++;
}

// function for CNG.
void cng()
{
    printf("\n\nEntry Successful!\n");
    printf("Please pay $10.\n");
    no_of_cng++;
    amount = amount + 10;
    count++;
}

// function for bike.
void bike()
{
    printf("\n\nEntry Successful!\n");
    printf("Please pay $5.\n");
    no_of_bike++;
    amount = amount + 5;
    count++;
}

int main()
{

    //welcome screen message.
    printf("................Welcome To Ayash Car Parking Center...........\n\n\n");

    // will show option menu to the user.
    // call the function according to the user's choice.
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
    printf("Thanks for using our service.\n");

    return 0;
}
