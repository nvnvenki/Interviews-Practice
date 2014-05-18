#include <stdio.h>

void strcpy(char *destn,char *src)
{
        while(*destn++ = *src++);
}

int main()
{
        char destn[30];
        char *src = "namaskara";
        strcpy(destn,src);
        puts(destn);
        return 0;
}
