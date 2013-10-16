#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int ret;
    ret=execl("/bin/vim","vim","/home/knd2/mycode/algri/HeapSort.c",NULL);
    if(ret==-1)
    {
        perror("execl\n");
    }
    return 0;
}
