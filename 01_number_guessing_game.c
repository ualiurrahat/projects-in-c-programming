/*
    Author: MD.Ualiur Rahman Rahat.
    Project: The Number Guessing Game.
    Description:
    - This game is played between two players.
    - Players guess a number between 1 and 100.
    - The player who guesses the number correctly with fewer attempts wins.
*/

#include <stdio.h>
#include <stdlib.h> // For rand() and srand()
#include <time.h>   // For time() to seed random number generation
#include <string.h>

/* Function to display the game rules and welcome message
   This function introduces the game, explains the rules,
   and welcomes the players to the game. */
void displayRules()
{
    printf("........................Welcome To The Number Guessing Game.................!!!\n");
    printf("\nRules: \n");
    printf("1. The game is played between two players.\n");
    printf("2. You have to guess a number between 1 to 100.\n");
    printf("3. The player who guesses the number correctly with fewer attempts becomes the winner.\n");
    printf("\n............................ Let's Start...........................\n\n");
}

/* Function to input player names
   Parameters:
   - player1: Array to store the name of player 1
   - player2: Array to store the name of player 2 */
void inputPlayerNames(char player1[], char player2[])
{
    printf("Please enter the name of Player 1: ");
    gets(player1); // Read Player 1's name
    printf("Please enter the name of Player 2: ");
    gets(player2); // Read Player 2's name
}

/* Function to generate a random number between 1 and 100
   Returns:
   - An integer random number in the range [1, 100] */
int generateRandomNumber()
{
    return rand() % 100 + 1; // Generate a random number between 1 and 100
}

/* Function for a single player to guess the number
   Parameters:
   - playerName: The name of the player currently playing
   - number: The random number that the player needs to guess
   Returns:
   - The number of attempts the player took to guess the number correctly */
int playGame(char playerName[], int number)
{
    int guessedNumber; // To store the player's guessed number
    int attempts = 1;  // Counter for the number of attempts

    printf("\nGame Starts for %s\n", playerName);
    printf("Guess the number between 1 to 100: ");

    while (1)
    {
        scanf("%d", &guessedNumber); // Read the player's guessed number

        if (guessedNumber < number)
        {
            printf("Higher number please!\n");
            attempts++; // Increment attempts if the guess is too low
        }
        else if (guessedNumber > number)
        {
            printf("Lower number please!\n");
            attempts++; // Increment attempts if the guess is too high
        }
        else
        {
            printf("Congrats!!! You guessed the number right!\n");
            printf("You nailed it with %d attempts\n", attempts);
            break; // Exit the loop when the player guesses correctly
        }
    }

    return attempts; // Return the total attempts taken by the player
}

/* Function to announce the winner
   Parameters:
   - player1: Name of player 1
   - attempts1: Number of attempts taken by player 1
   - player2: Name of player 2
   - attempts2: Number of attempts taken by player 2 */
void announceWinner(char player1[], int attempts1, char player2[], int attempts2)
{
    printf("\n\n");

    if (attempts1 < attempts2)
    {
        printf("%s did it with %d attempts and %s with %d attempts\n", player1, attempts1, player2, attempts2);
        printf("So %s is the winner!\n", player1);
        printf("Bravo %s!!!!\n", player1);
        printf("Wishing %s better luck next time.\n", player2);
    }
    else if (attempts1 > attempts2)
    {
        printf("%s did it with %d attempts and %s with %d attempts\n", player1, attempts1, player2, attempts2);
        printf("So %s is the winner!\n", player2);
        printf("Bravo %s!!!!\n", player2);
        printf("Wishing %s better luck next time.\n", player1);
    }
    else
    {
        printf("You both took %d attempts\n", attempts1);
        printf("So it's a tie!!!\n");
        printf("Congrats to both %s and %s!!! Better luck next time\n", player1, player2);
    }

    printf("\n............Thanks For Playing The Game....................\n");
    printf("...........................The End...........\n");
}

int main()
{
    char player1[50], player2[50]; // Arrays to store player names
    int number1, number2;          // Random numbers for both players
    int attempts1, attempts2;      // Attempts taken by both players

    // Seed the random number generator once at the start
    srand(time(0));

    // Display the game rules and introduction
    displayRules();

    // Input player names
    inputPlayerNames(player1, player2);

    // Generate random numbers for both players
    number1 = generateRandomNumber();
    number2 = generateRandomNumber();

    // Game for Player 1
    attempts1 = playGame(player1, number1);

    // Game for Player 2
    attempts2 = playGame(player2, number2);

    // Announce the winner
    announceWinner(player1, attempts1, player2, attempts2);

    return 0;
}
