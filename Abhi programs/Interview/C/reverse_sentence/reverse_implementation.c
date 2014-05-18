#include <stdio.h>
#include <stdlib.h>
#include "reverse.h"

void reverse_string(char* string)
{
    int i = 0;
    int length = 0;

    while(*(string + i) != '\0')
    {
        length++;
        i++;
    }

    i = 0;

    for(i = 0; i < length/2; i++)
    {
        char temp = string[i];
        string[i] = string[length -1 -i];
        string[length -1 -i] = temp;
    }

    printf("%s \n",string);
}

