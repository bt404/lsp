#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc,char **argv)
{
#ifdef  WRONG
    int fd=open(".",O_RDONLY);
    if(fd==-1)
    {
        perror("fopen\n");
        return 1;
    }
    char buf[256];
    ssize_t ret=read(fd,buf,256);
    if(ret==-1)
    {
        perror("read");
    }
    printf("%d\n",buf);
    close(fd);
    return 0;
#endif

    struct dirent* ent=NULL;
    DIR * menu=opendir(".");
    while(ent=readdir(menu))
    {
        printf("%s\n",ent->d_name);
    }
    return 0;
}
