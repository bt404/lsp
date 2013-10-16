#include <stdio.h>
#include <sched.h>
#include <string.h>
#define _XOPEN_SOURCE
#include <stdlib.h>

int main(void)
{
    extern char int_to_char(int);
    int ret;
    struct sched_param sp={.sched_priority=10};
    ret=sched_setscheduler(0,SCHED_RR,&sp);
    if(ret==-1)
    {
        perror("setscheduler\n");
        return 1;
    }
    ret=sched_getscheduler(0);
    if(ret==-1)
    {
        perror("getscheduler\n");
        return 1;
    }
    /*if(ret==SCHED_RR)
    {
        struct sched_param sp2;
        int ret2=sched_getparam(0,&sp2);
        if(ret2==-1)
        {
            perror("getparam\n");
        }
        printf("the scheduler is sched_rr and the priority is %d\n",sp2.sched_priority);
    }*/  //method 1

    char cmd[40]="./getscheduler ";
    char strret=int_to_char(ret);
    char x[2]={strret,'\0'};
    strcat(cmd,x);
    ret=system(cmd);
    if(ret==-1)
    {
        perror("system\n");
        return 1;
    }

    return 0;
}

char int_to_char(int a)
{
    char b;
    sprintf(&b,"%d",a);
    return b;
}
