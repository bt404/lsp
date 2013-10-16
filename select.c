#include <stdio.h>
#include <sys/types.h>>
#include <sys/time.h>
#include <unistd.h>

#define TIME  5
#define LEN 1024
int main(void)
{
    fd_set myset;
    struct timeval time;
    time.tv_sec=TIME;
    time.tv_usec=0;
    FD_ZERO(&myset);
    FD_SET(STDIN_FILENO,&myset);
    int ret;

    ret=select(STDIN_FILENO+1,&myset,NULL,NULL,&time);
    if(ret==-1)
    {
        perror("select");
        return 1;
    }
    else if(ret>0)
    {
        printf("%d secondes elapsed. time is left with %d\n",TIME,time.tv_sec);
        return 0;
    }

    /*if(FD_ISSET(STDIN_FILENO,&myset))
    {
        char buf[LEN];
        int len;
        len=read(STDIN_FILENO,buf,LEN);
        if(len==-1)
        {
            perror("read");
        }
        if(len)
        {
            buf[len]='\0';
            printf("%s",buf);
        }
        return 0;
    }*/
}
