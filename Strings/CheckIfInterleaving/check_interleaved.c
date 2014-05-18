#include <stdio.h>

int isInterleaved(char *string1,char *string2,char *string3)
{
        if(*string1 == '\0' || string2 == '\0')
        {
                return 0;
        }

        while(*string3 != '\0')
        {
                if(*string1 == *string3)
                {
                        ++string1;
                }

                else if(*string2 == *string3)
                {
                        ++string2;
                }
                else
                {
                        return 0;
                }

                ++string3;
        }
        // length of string3 is smaller :P
        if(*string1 || *string2)
        {
                return 0;               
        }
        return 1;
}


int main()
{
        char *string1 = "ab";
        char *string2 = "cd";
        char *string3 = "acbd";

        if(isInterleaved(string1,string2,string3) == 1)
        {
                printf("%s is interleaving of %s and %s \n", string3,string1,string2);
        }
        else
        {
                printf("no\n");
        }
        return 0;
}
