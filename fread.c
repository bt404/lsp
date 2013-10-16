#include <stdio.h>
#include <sys/types.h>

int main(void)
{
    char buf[64];
    FILE *stream=fopen("./BubbleSort.c","r");
    size_t ret=fread(buf,sizeof(buf)-1,1,stream);
    fclose(stream);
    buf[63]='\0';
    printf("%s",buf);
    
}
