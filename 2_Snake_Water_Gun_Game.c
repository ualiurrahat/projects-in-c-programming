/*
    Author: MD.Ualiur Rahman Rahat
*/

// Project: Snake-Gun-Water Game.
/* Rules of the game:
    Game is played between a player(user) and computer(AI).
    Player has to choose between snake, gun or water.
    The AI  automatically chooses an option.
    If player chooses snake and AI chooses water, then snake drinks water. So player wins and vice versa.
    If player chooses snake and AI chooses gun, then snake gets shot. So AI wins and vice versa.
    If you choose water and AI chooses gun, then gun gets sunk in the water. Player wins and vice versa.
    If both choose the same thing, match is drawn.

*/

/*
    Code for the game.
*/

// header files for the program.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to run the whole game.
int SnakeGunWater(char you, char computer)
{
    // this function will return an integer.
    // Returns 1 if player wins. Returns -1 if player loses.
    // Return -1 if match is drawn drawn.

    //cases for match to be a draw:
    //ss, ww, gg.

    //logic when match is drawn.
    if (you == computer)
    {
        return 0;
    }

    // cases for win or lose.
    //you vs computer: sw/ws, sg/gs, wg/gw.

    if (you == 's' && computer == 'w')
    {
        return 1; // player won
    }

    else if (you == 'w' && computer == 's')
    {
        return -1; // player lost
    }

    else if (you == 's' && computer == 'g')
    {
        return -1; // player lost.
    }

    else if (you == 'g' && computer == 's')
    {
        return 1; // player won;
    }

    else if (you == 'w' && computer == 'g')
    {
        return 1; // player won.
    }

    else if (you == 'g' && computer == 'w')
    {
        return -1; // player lost.
    }
}

int main()
{
    // welcome screen.
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

    //var to count total round of play, and total no. of time player won.
    int round = 0, win = 0;

    // take players input and check input validation.
    while (1)
    {

        printf("Enter s for snake, g for gun, w for water(0 to exit):");
        scanf(" %c", &you);
        if (you == '0')
        {
            break;
        }
        //checking valid input.
        while (you != 's' && you != 'g' && you != 'w')
        {
            printf("Invalid input\n");
            printf("Enter s for snake, g for gun, w for water(0 to exit):");
            scanf(" %c", &you); // space is given for the new line("\n") of the previous line of code.
            if (you == '0')
            {
                break;
            }
        }
        round++;

        // code for computer's auto input.

        int number;
        srand(time(0));            // generates numbers in seconds and different numbers in each runtime.
        number = rand() % 100 + 1; //  generate random numbers between 1 to 100;

        // computer's input selection.
        //  computer chooses snake if number is between 0 to 33, gun when number is from 33 to 66 and water for number 66 to 100.
        if (number <= 33)
        {
            computer = 's';
        }

        else if (number > 33 && number <= 66)
        {
            computer = 'g';
        }
        else
        {
            computer = 'w';
        }

        // using the function to calculate the result.
        int result = SnakeGunWater(you, computer);

        // result = 1 , you win. result = -1, you lose. result = 0, math drawn.

        if (result == 1)
        {
            win++;
            printf("You chose '%c' and computer chose '%c'. You win!\n", you, computer);
            printf("Congrats! Total Round:%d\t Total Win:%d\n", round, win);
        }
        else if (result == -1)
        {
            printf("You chose '%c' and computer chose '%c'. You lose!\n", you, computer);
            printf("Total Round:%d\t Total Win:%d\n", round, win);
        }
        else if (result == 0)
        {
            printf("You and computer both enterd '%c' Match is drawn.\n", you);
            printf("Total Round:%d\t Total Win:%d\n", round, win);
        }
        printf("\n\n");
    }

    // Good-bye message.
    printf("\n\n");
    printf("............Thanks For Playing The Game.............\n");

    return 0;
}
