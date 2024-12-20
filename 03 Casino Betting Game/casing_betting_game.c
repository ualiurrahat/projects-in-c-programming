/*
    Author: MD. Ualiur Rahman Rahat
    Project: Simple betting game or casino game.

    Game Rules:
    There are 3 cards - Jack, Queen, and King. The computer shuffles these cards.
    You have to guess the position of the Queen.
    If you win, you take 3 times the bet. If you lose, you forfeit the bet amount.
    You start the game with $100.
*/

// Header files required for the program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variable to store the player's cash balance
int cash = 100;

// Global variable to track the total number of betting rounds
int rounds = 0;

// Function to handle the betting game logic
// Parameters:
// - bet: The amount of money the player bets
void play(int bet)
{
    if (bet != 0)
    {
        // Initialize the cards with their initial positions
        char cards[3] = {'J', 'Q', 'K'};
        int i;

        // Seed the random number generator with the current time
        srand(time(NULL));

        printf("Shuffling the cards...........\n");

        // Randomly swap card positions five times to shuffle
        for (i = 0; i < 5; i++)
        {
            int m = rand() % 3; // Generate a random index between 0 and 2
            int n = rand() % 3;

            // Swap the positions of cards[m] and cards[n]
            int temp = cards[m];
            cards[m] = cards[n];
            cards[n] = temp;
        }

        // Variable to store the player's guessed position of the Queen
        int guessed;

        printf("What's the position of the Queen? 1, 2, or 3: ");
        scanf("%d", &guessed);

        // Check if the player's guess is correct
        if (cards[guessed - 1] == 'Q')
        {
            cash += 3 * bet; // Player wins 3 times the bet
            rounds++;
            printf("You Won! Result = \"%c %c %c\". Total Cash: %d.\nEnd of Round: %d\n",
                   cards[0], cards[1], cards[2], cash, rounds);
        }
        else
        {
            cash -= bet; // Player loses the bet
            rounds++;
            printf("You Lost! Result = \"%c %c %c\". Total Cash: %d.\nEnd of Round: %d\n",
                   cards[0], cards[1], cards[2], cash, rounds);
        }
    }
}

// Main function to start the game
int main()
{
    // Display welcome message
    printf("************** Welcome To Virtual Casino Game *************\n\n");

    // Display game rules
    printf("Game Rules:\n");
    printf("There are 3 cards - Jack, Queen, and King. The computer shuffles these cards.\n");
    printf("You have to guess the position of the Queen.\n");
    printf("If you win, you take 3 times the bet. If you lose, you forfeit the bet amount.\n");
    printf("You start the game with $100.\n\n");
    printf(".......... Let's Begin ..............\n");

    // Variable to store the player's bet amount
    int bet;

    printf("Your Total Cash: $%d\n", cash);

    // Main betting loop
    while (cash > 0)
    {
        printf("What's your bet? $(Enter 0 to exit): ");
        scanf("%d", &bet);

        // If the player wants to end the game
        if (bet == 0)
        {
            break;
        }

        // Ensure the bet does not exceed the player's available cash
        while (bet > cash)
        {
            printf("You do not have enough money! Please bet a smaller amount.\n");
            printf("What's your bet? $: ");
            scanf("%d", &bet);

            if (bet <= cash)
            {
                break;
            }
        }

        // Play the game round
        play(bet);
        printf("*************************\n");
    }

    // Handle game-ending scenarios
    printf("\n\n");
    if (cash == 0)
    {
        printf("You went bankrupt in round %d! You can't play anymore.\n", rounds);
        printf("Better luck next time.\n");
    }

    printf("Thanks for playing the game. Hope you enjoyed it.\n");

    return 0;
}
