#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{
    char buf[256]={"hehe"};
    int ret;
    ret=open("/dev/sda7",O_RDONLY);
    if(ret==-1)
    {
        perror("open\n");
        return EXIT_FAILURE;
    }
    ssize_t nr;
    nr=read(ret,buf,255);
    if(nr==-1)
    {
        perror("read\n");
        return EXIT_FAILURE;
    }
    buf[255]='\0';
    printf("%s\n",buf);
    return EXIT_SUCCESS;
}
