#include <stdio.h>
#include <time.h>

int main(void)
{
    clockid_t clocks[]={CLOCK_REALTIME,CLOCK_MONOTONIC,CLOCK_PROCESS_CPUTIME_ID\
        ,CLOCK_THREAD_CPUTIME_ID};
    int i;
    for(i=0;i<4;++i)
    {
        struct timespec res;
        int ret;
        ret=clock_gettime(clocks[i],&res);
        if(ret)
        {
            perror("getres\n");
            return 1;
        }

        printf("%d  resolution is %ld second and %ld nanosecond\n",clocks[i],\
                res.tv_sec,res.tv_nsec);
        
    }

    time_t t=time(NULL);
    printf("\nthe time now is %s\n",ctime(&t));


    return 0;
}
