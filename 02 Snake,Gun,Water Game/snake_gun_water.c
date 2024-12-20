
/*
Author: MD.Ualiur Rahman Rahat
 Project: Snake-Gun-Water Game.
 Rules of the game:

    Game is played between a player(user) and computer(AI).
    Player has to choose between snake, gun or water.
    The AI  automatically chooses an option.
    If player chooses snake and AI chooses water, then snake drinks water. So player wins and vice versa.
    If player chooses snake and AI chooses gun, then snake gets shot. So AI wins and vice versa.
    If you choose water and AI chooses gun, then gun gets sunk in the water. Player wins and vice versa.
    If both choose the same thing, match is drawn.
*/

// header files for the program.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to determine the result of a round.
int SnakeGunWater(char you, char computer)
{
    // This function will return an integer:
    // 1 if the player wins, -1 if the player loses, and 0 if the match is drawn.

    if (you == computer) // Match is drawn.
    {
        return 0;
    }

    // Win/Loss conditions based on the game rules:
    if (you == 's' && computer == 'w')
        return 1; // Snake drinks water (player wins).
    if (you == 'w' && computer == 's')
        return -1; // Snake drinks water (AI wins).
    if (you == 's' && computer == 'g')
        return -1; // Snake gets shot (AI wins).
    if (you == 'g' && computer == 's')
        return 1; // Snake gets shot (player wins).
    if (you == 'w' && computer == 'g')
        return 1; // Gun sinks in water (player wins).
    if (you == 'g' && computer == 'w')
        return -1; // Gun sinks in water (AI wins).
}

// Function to run the whole game loop.
void play_game()
{
    // Welcome message.
    printf("................Welcome To Snake, Gun Or Water Game.............\n");
    printf("\n\n\n");

    // Game Rules:
    printf("Game Rules:\n");
    printf("1. Game is played between you and computer(AI).\n");
    printf("2. You have to choose between snake, gun or water.\n");
    printf("   The AI  automatically chooses an option.\n");
    printf("3. If you choose snake and AI chooses water, then snake drinks water. So you win and vice versa.\n");
    printf("4. If you choose snake and AI chooses gun, then snake gets shot. So AI wins and vice versa.\n");
    printf("5. If you choose water and AI chooses gun, then gun gets sunk in the water. You win and vice versa.\n");
    printf("6. If both choose the same thing, match is drawn.\n");
    printf("\n\n");
    printf(".........Let's Start The Game..........\n");
    printf("\n\n\n");

    // var to store player's and computer's input.
    char you, computer;

    // var to count total round of play, and total no. of times player won.
    int round = 0, win = 0;

    // Game loop to keep playing until the user chooses to exit.
    while (1)
    {
        // Take the player's input.
        printf("Enter s for snake, g for gun, w for water (0 to exit): ");
        scanf(" %c", &you); // Space before %c is to handle the newline character from previous input.

        if (you == '0')
        {
            break; // Exit the game if the player enters '0'.
        }

        // Input validation: checking for valid choices.
        while (you != 's' && you != 'g' && you != 'w')
        {
            printf("Invalid input\n");
            printf("Enter s for snake, g for gun, w for water (0 to exit): ");
            scanf(" %c", &you);
            if (you == '0')
            {
                break; // Exit if the player enters '0'.
            }
        }

        if (you == '0')
            break; // Exit if the player enters '0'.

        round++;

        // Generate the computer's random choice.
        int number;
        srand(time(0));            // Random number generator based on current time.
        number = rand() % 100 + 1; // Generate a random number between 1 and 100.

        // Computer's input based on the random number.
        if (number <= 33)
        {
            computer = 's'; // 1 to 33 -> Snake.
        }
        else if (number > 33 && number <= 66)
        {
            computer = 'g'; // 34 to 66 -> Gun.
        }
        else
        {
            computer = 'w'; // 67 to 100 -> Water.
        }

        // Calculate the result using the SnakeGunWater function.
        int result = SnakeGunWater(you, computer);

        // Display the result.
        if (result == 1)
        {
            win++; // Increment the win count if the player wins.
            printf("You chose '%c' and computer chose '%c'. You win!\n", you, computer);
        }
        else if (result == -1)
        {
            printf("You chose '%c' and computer chose '%c'. You lose!\n", you, computer);
        }
        else
        {
            printf("You and computer both entered '%c'. Match is drawn.\n", you);
        }

        // Display the stats.
        printf("Total Rounds: %d\t Total Wins: %d\n", round, win);
        printf("\n\n");
    }

    // Goodbye message.
    printf("\n\n");
    printf("............Thanks For Playing The Game.............\n");
}

int main()
{
    // Call the play_game function to start the game.
    play_game();
    return 0;
}
