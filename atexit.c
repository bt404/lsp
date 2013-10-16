#include <stdlib.h>
#include <stdio.h>

void myfunc(void)
{
    printf("myfunc has been run\n");
}

int main(void)
{
    int ret;
    ret=atexit(myfunc);
    if(ret==-1)
    {
        perror("atexit\n");
    }
    return 0;
}
