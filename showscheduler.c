#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(int argc,char **argv)
{
    char *str=argv[1];
    int arg=atoi(str);
    switch(arg)
    {
        case SCHED_RR:
            printf("the scheduler is sched_rr\n");
            break;
        case SCHED_FIFO:
            printf("the scheduler is sched_fifo\n");
            break;
        case SCHED_OTHER:
            printf("the scheduler is sched_other\n");
            break;
        default:
            return 0;
    }
    return 0;
}
