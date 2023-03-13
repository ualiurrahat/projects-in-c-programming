/*
    Author: MD.Ualiur Rahman Rahat
*/

//Project: Simple betting game or casino game.
/*
    Game Rules: 
    There are 3 cards - Jack, Queen and King.Computer Shuffles these cards.
    You have to guess the position of Queen.
    If you win, you take 3 times of the bet. If lose, then lose the bet amount.
    You have $100 at the start of the game.

*/

// header files for the program.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// var for player' cash.
int cash = 100;

// var to count total round of betting.
int rounds = 0;

// function for the game.
void play(int bet)
{

    if (bet != 0)
    {
        char cards[3] = {'J', 'Q', 'K'}; // initialization of cards with initial position.
        int i;

        // seed random numbers.
        srand(time(NULL));

        printf("Shuffling the cards...........\n");
        // code for swapping the cards position for five times.
        for (i = 0; i < 5; i++)
        {
            int m = rand() % 3; // m , n both generates number among 0,1 and 2 only.
            int n = rand() % 3;

            // now interchanging card's positions.
            int temp = cards[m];
            cards[m] = cards[n];
            cards[n] = temp; // swap cards between position m and n.
        }

        // var for player guessed position of the cards
        int guessed;

        printf("What's the position of the Queen? 1, 2 or 3: ");
        scanf("%d", &guessed);

        if (cards[guessed - 1] == 'Q')
        {
            cash += 3 * bet;
            rounds++;
            printf("You Won ! Result = \"%c %c %c\" .Total Cash: %d.\n End of Round: %d\n", cards[0], cards[1], cards[2], cash, rounds);
        }
        else
        {
            rounds++;
            cash -= bet;
            printf("You Lost ! Result = \"%c %c %c\" Total Cash: %d\n. End of Round: %d\n", cards[0], cards[1], cards[2], cash, rounds);
        }
    }
}

int main()
{
    //welcome screen.
    printf("**************Welcome To Virtual Casino Game*************\n");
    printf("\n\n");

    //game rules.
    printf("Game Rules:\n");
    printf("There are 3 cards - Jack, Queen and King.Computer Shuffles these cards.\nYou have to guess the position of Queen.\n");
    printf("If you win, you take 3 times of the bet. If lose, then lose the bet amount.\n");
    printf("You have $100 at the start of the game.\n");
    printf("\n\n");
    printf("..........Let's Begin..............\n");

    // var for bet amount.
    int bet;

    printf("Your Total Cash: $%d\n", cash);

    //betting arguments.
    while (cash > 0)
    {
        printf("What's your bet? $(enters 0 to exit):");
        scanf("%d", &bet);

        // if players wants to end the game, press 0.
        if (bet == 0)
        {
            break;
        }
        // if bet is more than player's cash.
        while (bet > cash)
        {
            printf("You do not have enough money ! Bid less.\n");
            printf("What's your bet? $:");
            scanf("%d", &bet);
            //if(bet == 0)break;
            if (bet <= cash)
            {
                break;
            }
        }
        play(bet);
        printf("*************************\n");
    }

    printf("\n\n");
    if (cash == 0)
    {
        printf("You got bankrupt at round %d ! Can't play anymore.\n", rounds);
        printf("Better luck next time\n");
    }

    printf("Thanks For Playing The Game. Hope you enjoyed it.\n");

    return 0;
}
