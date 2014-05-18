#include <stdio.h>

int strcmp(const char *string1,const char *string2)
{
        while(*string1 == *string2)
        {
                if(*string1 == '\0')
                {
                        return 0;
                }
                ++string1;
                ++string2;
        }
        return *string1 - *string2;
}

int main()
{
        if(strcmp("aaaaaaaa","hi") == 0)
        {
                printf("String are equal\n");
        }
        else
        {
                printf("Strings are different\n");
        }
        return 0;
}
