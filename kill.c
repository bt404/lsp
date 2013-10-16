#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
    int ret;
    ret=kill(18014,SIGHUP);   //因为login是setuid程序，所以它的进程user是root，
    if(ret)                   //因此必须以root来执行该程序关闭另一个login。
    {
        perror("kill\n");
        return EXIT_FAILURE;
    }
    printf("kill success!\n");
    return EXIT_SUCCESS;
}
