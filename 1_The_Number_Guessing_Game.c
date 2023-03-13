/*
    Author: MD.Ualiur Rahman Rahat.

*/

// Project: The Number Guessing Game.
// About Project:
//  The game is played between two players
//  you have to guess a number between 1 to 100.
// The player who guesses the number correctly with less attempt, becomes the winner.

/*
    Code Starts From Here...
*/

// Necessary header files for the program.
#include <stdio.h>
#include <stdlib.h> // to use rand() function.
#include <time.h>   // to use time() function.
#include <string.h>

int main()
{

    // var for generating seprate  numbers for each player.
    int number;
    int number2;
    // var to store player's names.
    char player1[50];
    char player2[50];

    // var to store player's guessed number and total attempts.
    int guessedNumber1, guessedNumber2;
    int attermpt1 = 1, attermpt2 = 1;

    // Rules of the game and welcome screen......
    printf("........................Welcome To The Number Guessing Game.................!!!\n");
    printf("\n");
    printf("Rules: \n");
    printf("1. The game is played between two players.\n");
    printf("2. you have to guess a number between 1 to 100.\n");
    printf("3.The player who guesses the number correctly with less attempt, becomes the winner.\n ");
    printf("\n");
    printf("............................ Let's Start...........................\n");

    printf("\n");
    printf("\n");

    // player name input......
    printf("Please enter name of player 1: ");
    gets(player1);
    printf("Please enter name of player 2: ");
    gets(player2);

    // annoucement of the game start.
    printf("\n");
    printf("Hello %s and %s. Let's start the number guessing game...\n", player1, player2);
    printf("RIGHT NOW!!!!!\n");

    // now will generate random numbers.
    // using rand function to generate a number. it generates the same number every time.
    // srand(time(0)) genertates numbers in seconds and different numbers everytime.
    // rand % 100 generates number between 0 to 99. so 1 added in the equation.
    srand(time(0));
    number = rand() % 100 + 1;

    // number guessing loop for player 1.
    printf("\n");
    printf("\n");
    printf("Game Starts for Player 1 : %s\n", player1);
    printf("Guess the number between 1 to 100: ");

    while (1)
    {
        scanf("%d", &guessedNumber1);

        if (guessedNumber1 < number)
        {
            printf("Higher number please!\n");
            attermpt1++;
        }

        else if (guessedNumber1 > number)
        {
            printf("Lower number please!\n");
            attermpt1++;
        }

        else
        {
            printf("Congrats!!! You guessed the number right!\n");
            printf("You nailed it with %d attempts\n", attermpt1);
            break;
        }
    }

    // now generating number for player 2.

    srand(time(0));
    number2 = rand() % 100 + 1;

    // game loop for player 2.
    printf("\n");
    printf("\n");
    printf("Now time to play for player 2 : %s\n", player2);
    printf("Guess the number between 1 to 100: ");

    while (1)
    {
        scanf("%d", &guessedNumber2);

        if (guessedNumber2 < number2)
        {
            printf("Higher number please!\n");
            attermpt2++;
        }

        else if (guessedNumber2 > number2)
        {
            printf("Lower number please!\n");
            attermpt2++;
        }

        else
        {
            printf("Congrats!!! You guessed the number right!\n");
            printf("You nailed it with %d attempts\n", attermpt2);
            break;
        }
    }

    // announcing the winners.
    printf("\n");
    printf("\n");

    // when player1 is winner.
    if (attermpt1 < attermpt2)
    {
        printf("%s did it with %d attempts and %s with %d attempts\n", player1, attermpt1, player2, attermpt2);
        printf("So %s is the winner!\n", player1);
        printf("Bravo %s!!!!\n", player1);
        printf("Wishing %s better luck next time.\n", player2);
    }
    // when player 2 is winner.
    else if (attermpt1 > attermpt2)
    {
        printf("%s did it with %d attempts and %s with %d attempts\n", player1, attermpt1, player2, attermpt2);
        printf("So %s is the winner!\n", player2);
        printf("Bravo %s!!!!\n", player2);
        printf("Wishing %s better luck next time.\n", player1);
    }
    // when there is a tie.
    else
    {
        printf("You both took %d attempts\n", attermpt2);
        printf("So it's a tie!!!\n");
        printf("Congrats you both %s %s !!!. Better Luck next time\n");
    }
    printf("\n");
    printf("............Thanks For Playing The Game....................\n");
    printf("\n");
    printf("...........................The End...........\n");

    return 0;
}
