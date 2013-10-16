#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *p=(char*)malloc(10);
    int i;
    for(i=0;i<10;++i)
        p[i]='a';
    char *r=(char*)realloc(p,6);
    printf("%d\n",(r==p));
    printf("%c,%c\n",r[0],p[0]);
    free(r);
    
    printf("%c,%c\n",r[0],p[0]);
    return 0;
}
