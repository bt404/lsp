#include <stdio.h>
#include <sys/types.h>
#include <sys/poll.h>
#include <unistd.h>

#define TIMEOUT 5
int main(void)
{
    int ret;
    struct pollfd myfds[2];
    myfds[0].fd=STDIN_FILENO;
    myfds[0].events=POLLIN;
    myfds[1].fd=STDOUT_FILENO;
    myfds[1].events=POLLOUT;
    ret=poll(myfds,2,TIMEOUT*1000);
    if(ret==-1)
    {
        perror("poll");
    }
    if(!ret)
    {
        printf("%d seconds elapsed!\n",TIMEOUT);
        return 0;
    }
    /*if(ret>=0)
    {
        if(!ret)
        {
            printf("%d seconds elapsed!\n",TIMEOUT);
            return 0;
        }
        else
        {
            if(myfds[0].revents&&POLLIN)
            {
                char buf[1024];
                int len;
                len=read(myfds[0].fd,buf,1024);
                if(len==-1)
                {
                    perror("read");
                    return 1;
                }
                if(len)
                {
                    buf[len]='\0';
                    printf("%s\n",buf);
                    return 0;
                }
            }
        }
    }*/

    if(myfds[0].revents&&POLLIN)
    {
        printf("stdin is readable!\n");
    }
    if(myfds[1].revents&&POLLOUT)
    {
        printf("stdout is writable!\n");
    }
    return 0;
}
