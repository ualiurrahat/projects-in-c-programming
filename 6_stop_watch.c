/*
    Author: MD. Ualiur Rahman Rahat

*/

/* Project Title: Digital Stop-watch using C programming.
    About Project: The stop-watch will start its countdown from 00:00:00 (hour:minute:sec)
    and it will stop at user's given time.
    that's it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // header file for Sleep() function

// sleep() function uses header file <unistd.h>
// it doesn't work on windows machine.
// so here, defining macros to use sleep() function in windows machine.
#ifdef _WIN32
#define sleep(x) Sleep(x * 1000) // Sleep(x) in defined in <Windows.h> works in miliseconds.
#else                            // so mulitiplying x with 1000 to get value in seconds.
#include <unistd.h>
#endif

int main()
{

    // var to store user's input for time.
    int hour, minute, second;

    printf("Digital Stop Watch.....Using C programming.\n");
    printf("Made by MD.Ualiur Rahman Rahat.\n");
    printf("\n\n\n");
    printf("The stop-watch will start from 00:00:00 and stop at your given time.\n");

    // user input for time in hour, minute and second.
    printf("Enter hour: ");
    scanf("%d", &hour);

    printf("Enter minute: ");
    scanf("%d", &minute);

    printf("Enter second: ");
    scanf("%d", &second);

    // checking input.
    // printf("%.2d : %.2d : %.2d\n", hour, minute, second);

    // var for stop-watch time check-up.
    int h = 0, s = 0, m = 0;

    while (1)
    {
        printf("\n\n##########   STOP WATCH   ############\n");
        printf("\n\n");
        printf("            %.2d : %.2d : %.2d\n", h, m, s);
        printf("\n\n#####################################\n");
        if (h == hour && m == minute && s == second)
        {
            // stop-watch will stop when user given time is reach.
            printf("Stop Watch reached the destination time!!!\n");
            break;
        }

        // increasing time 1 second every time the loop runs.
        s++;

        // using sleep() function.
        // to make the program output wait for 1 second.
        // for 1 second waiting, the input value inside the sleep() function is given one.
        sleep(1);

        // after 60 seconds of completion,
        // increaing minute value by 1
        // and restarting second value from 0.
        if (s == 60)
        {
            s = 0;
            m++;
        }

        // after 60 minutes of completion,
        // increaing hour  value by 1
        // and restarting minute value from 0.
        if (m == 60)
        {
            m = 0;
            h++;
        }

        // clearing the screen every time the loop runs.
        system("CLS");
    }

    return 0;
}