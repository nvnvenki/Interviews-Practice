/*
 * =====================================================================================
 *
 *       Filename:  reverse_words.c
 *
 *    Description:  Reverse the words order in (logn) complexity
 *
 *        Version:  1.0
 *        Created:  03/13/2013 09:44:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Venki (), 
 *   Organization:  Benki ;)
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strrev(char* string_beg,char* string_end)
{
//        puts(string_beg);
//        puts(string_end);

        while(string_beg)
        {
                char* temp = *string_beg++;
                puts(temp);
        }
}

void reverseWords(char* sentence)
{
        strrev(&sentence,&sentence[strlen(sentence)]);
}

int main()
{
        char *sentence = "Hello All This is Venki";
        reverseWords(sentence);
        return 0;
}
