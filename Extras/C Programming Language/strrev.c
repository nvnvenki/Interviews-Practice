#include <stdio.h>
#include <string.h>

void strrev(char* string_begining,char* string_end)
{  
        while(string_begining < string_end)
        {
                char temp = *string_begining;
                *string_begining++ = *string_end;
                *string_end-- = temp;
        }
}

int main()
{
        char string[] = "this is the string";
        strrev(string,&string[strlen(string)] - 1);
        puts(string);
        return 0;
}
