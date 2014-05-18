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
void reverse_words(char* sentence,char* string_end)
{
        if(strlen(sentence) > 1)
        {

                /* 
                *       Steps:
                *               1.Reverse the whole sentence
                *               2.Reverse each word individually
                */
                strrev(sentence,string_end);
                char *x;
                char *y;
                x = sentence;
                y = sentence;
                while(x++ < string_end)
                {
                        if(*x == '\0' || *x == ' ')
                        {
                                strrev(y,x-1);
                                y = x + 1;
                        }
                }
                if(y < string_end)
                {
                        strrev(y,string_end);
                }

        }
}

int main()
{
        char sentence[] = "Shreya Ghoshal the melody queen";
        reverse_words(sentence,&sentence[strlen(sentence)] - 1);
        puts(sentence);
}
