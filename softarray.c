#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct hehe
    {
        int len;
        char name[];
    };

    struct hehe *haha=(struct hehe*)malloc(sizeof(struct hehe)+100*sizeof(char));
    haha->name[0]='a';
    haha->name[1]='b';
    haha->name[2]='\0';
    printf("%s\n",haha->name);
    free(haha);
    return 0;
}
