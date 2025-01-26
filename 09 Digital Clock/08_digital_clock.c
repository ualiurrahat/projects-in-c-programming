/*
 * Digital Clock in C
 * --------------------
 * About:
 * This program implements a digital clock that displays the current date and time.
 * The user can choose between a 24-hour format or a 12-hour format for time display.
 * The clock updates every second without user intervention. It utilizes the
 * standard C libraries for time management and system interaction.
 *
 * Features:
 * - Displays current date and time
 * - Offers 24-hour and 12-hour time format options
 * - Continuously updates every second
 *
 * Instructions:
 * Compile and run the program. Choose the time format when prompted.
 * The program will continuously display the current date and time until manually terminated.
 */

#include <stdio.h>  // Standard input/output functions
#include <stdlib.h> // For system() function
#include <time.h>   // For time and date handling functions
#include <unistd.h> // For sleep() function to add delay

// Function to get the current time in the specified format
void fill_time(char *buffer, int format)
{
    /*
     * Parameters:
     * - buffer: A character array to store the formatted time string
     * - format: 1 for 24-hour format, 2 for 12-hour format
     *
     * This function uses the strftime() function to format the current time
     * and store it in the provided buffer.
     */

    time_t raw_time;         // Variable to store raw time
    struct tm *current_time; // Pointer to a tm structure for formatted time

    time(&raw_time);                     // Get the current calendar time
    current_time = localtime(&raw_time); // Convert to local time

    if (format == 1) // 24-hour format
    {
        strftime(buffer, 50, "%H:%M:%S", current_time);
    }
    else // 12-hour format
    {
        strftime(buffer, 50, "%I:%M:%S %p", current_time);
    }
}

// Function to get the current date
void fill_date(char *buffer)
{
    /*
     * Parameters:
     * - buffer: A character array to store the formatted date string
     *
     * This function formats the current date using strftime() and stores
     * it in the provided buffer.
     */

    time_t raw_time;         // Variable to store raw time
    struct tm *current_time; // Pointer to a tm structure for formatted time

    time(&raw_time);                     // Get the current calendar time
    current_time = localtime(&raw_time); // Convert to local time

    strftime(buffer, 100, "%A %B %d %Y", current_time); // Format as "Day Month Date Year"
}

// Function to clear the console screen
void clear_screen()
{
    /*
     * This function clears the console screen using platform-specific commands.
     * - For Windows, it uses the "cls" command.
     * - For Unix/Linux/MacOS, it uses the "clear" command.
     */

#ifdef _WIN32
    system("cls"); // Clear screen for Windows
#else
    system("clear"); // Clear screen for Unix/Linux/MacOS
#endif
}

// Function to get the user's choice for time format
int input_format()
{
    /*
     * This function prompts the user to choose the time format.
     * - Returns 1 for 24-hour format
     * - Returns 2 for 12-hour format
     */

    int format;
    printf("\nChoose the time format: ");
    printf("\n1. 24 Hour format");
    printf("\n2. 12 Hour format (default)");
    printf("\nMake a choice (1/2): ");
    scanf("%d", &format);
    return format; // Return the user's choice
}

// Main function
int main()
{
    char time[50], date[100];    // Arrays to hold formatted time and date strings
    int format = input_format(); // Get the user's choice for time format

    while (1) // Infinite loop to continuously update the clock
    {
        fill_time(time, format);            // Get the current time
        fill_date(date);                    // Get the current date
        clear_screen();                     // Clear the console screen
        printf("Current Time: %s\n", time); // Display the current time
        printf("Current Date: %s\n", date); // Display the current date
        sleep(1);                           // Wait for 1 second before updating
    }

    return 0; // Exit the program (this line is unreachable due to the infinite loop)
}
