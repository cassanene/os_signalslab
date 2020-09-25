#include "timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int global = 0;
const int ALARM_CONST = 1;

void handler(int signum)
{ //signal handler
    printf("Hello World!\n");
    global = 1;
    alarm(ALARM_CONST);
}

int main(int argc, char *argv[])
{
    signal(SIGALRM, handler); //register handler to handle SIGALRM
    alarm(ALARM_CONST);       //schedule a SIGALRM for 1 second

    while (ALARM_CONST)
    {
        while (global == 0)
            ; //infinite loop
        printf("Turing was right!\n");
        global = 0;
        counter();
        signal(SIGINT, sigint_handler);
    };
}