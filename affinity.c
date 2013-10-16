#include <stdio.h>

#define _GNU_SOURCE
#define __USE_GNU
#include <sched.h>

int main(void)
{
    cpu_set_t set;
    int ret,i;
    CPU_ZERO(&set);
    ret=sched_getaffinity(0,sizeof(cpu_set_t),&set);
    if(ret==-1)
    {
        perror("getaffinity");
    }
    for(i=0;i<CPU_SETSIZE;++i)
    {
        printf("cpu:%d is %s\n",i,CPU_ISSET(i,&set)?"set":"unset");
    }
    return 0;
}
