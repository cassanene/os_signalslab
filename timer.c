#include "timer.h"
#include <stdio.h>
#include <stdlib.h>

int seconds = 0;
void counter()
{
    seconds += 1;
}

void sigint_handler(int signum)
{ // signat signal handler
    printf("Total number of seconds ran: %d\n", seconds);
    exit(0);
}