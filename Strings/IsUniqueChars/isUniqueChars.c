#include <stdio.h>
#include <string.h>

int isUiniqueChars(char *string)
{
        int check = 0;
        for(int i = 0; i < strlen(string); ++i)
        {
                int temp = string[i] - 'a';
                if((check & (1 << temp)) > 0)
                {
                        return 0;
                }
                check = check | (1 << temp);
        }
        return 1;
}

int main()
{
        char *string1 = "abc";
        char *string2 = "aba";
        if(isUiniqueChars(string2) == 1)
        {
                printf("Contains unique chars\n");
        }
        else
        {
                printf("contains repeated chars\n");
        }
        return 0;
}
