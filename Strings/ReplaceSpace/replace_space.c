#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void replaceSpace(char *string)
{
        int space = 0;
        int length = strlen(string);
        for(int i = 0; i < length; ++i)
        {
                if(string[i] == ' ')
                {
                        ++space;
                }
        }

        int newLength = length + space * 2;
        for(int i = length - 1; i >= 0; --i)
        {
                if(string[i] == ' ')
                {
                        string[newLength - 1] = '0';
                        string[newLength - 2] = '2';
                        string[newLength - 3] = '%';
                        newLength = newLength - 3;
                }
                else
                {
                        string[newLength - 1] = string[i];
                        newLength = newLength - 1;
                }
        }
        
}

int main()
{
        char string[] = "Hello Hi ";
        replaceSpace(string);
        puts(string);
        return 0;
}

