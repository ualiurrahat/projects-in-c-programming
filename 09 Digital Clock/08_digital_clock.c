#include <stdio.h>
#include <time.h>

void fill_time(char *buffer)
{
    time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);
    strftime(buffer, 50, "%I:%M:%S %p", current_time);
}
int main()
{
    char time[50];
    fill_time(time);
    printf("Current Time: %s", time);

    return 0;
}