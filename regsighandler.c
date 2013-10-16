#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler(int signo)
{
    printf("caught sigint!\n");
    exit(EXIT_SUCCESS);
}

int main(void)
{
    if(signal(SIGINT,handler)==SIG_ERR)
    {
        fprintf(stderr,"register failure!\n");
        return EXIT_FAILURE;
    }

    for(;;)
    {
        pause();
    }

    return EXIT_SUCCESS;
}
