#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replace(char *url)
{
        int length = strlen(url);
        char *temp =(char *)malloc(length + 1);
        int i = 0;
        while(*url)
        {
                if(*url == '%')
                {
                        url = url + 3;
                }
                temp[i++] = *url;
                ++url;
        }   
        temp[i++] = '\0';
        return temp;
}

int main()
{
        char url[] = "www.go%20=com?a%20=10%20";
        puts(url);
        strcpy(url,replace(url));
        puts(url);
}

