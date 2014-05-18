/* 
*      Given two strings str1 and str2, write code to find out if all non-unique elements in str2 are in str1?
*
*
*/

#include <stdio.h>
#include <string.h>

int search(char *string,int key)
{
        for(int i = 0; i < strlen(string); ++i)
        {
                if(string[i] == key)
                {
                        return 1;
                }
        }
        return 0;
}

void unique_chars(char *str1,char *str2)
{
        int char_set[256];
        for(int i = 0; i < 256; ++i)
        {
                char_set[i] = 0;
        }
        int i = 0;
        while(str2[i] != '\0')
        {
                char_set[str2[i]]++;
                ++i;
        }
        for(int i = 0; i < 256; ++i)
        {
                if(char_set[i] > 1 && search(str1,i))
                {
                        putchar(i);

                }
        }
        printf("\n");
}

int main()
{
        char *str2 = "aabbccd";
        char *str1 = "abcd";
        unique_chars(str1,str2);
}
