#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printAllRec(char *chars,char *prefix,int n,int k)
{
        if(k == 0)
        {
                puts(prefix);
                return;
        }

        for(int i = 0; i < n; ++i)
        {

                char newPrefix[n];
                strcpy(newPrefix,"");
                strcat(newPrefix,prefix);
                char temp [] = {chars[i],'\0'};
                strcat(newPrefix,temp);
                printAllRec(chars,newPrefix,n,k - 1);
        }
}


void printAllKthLength(char *chars,int k)
{
        int n = strlen(chars);
        char *prefix = "";
        printAllRec(chars,prefix,n,k);
}


int main()
{
        char *chars1 = "ab";
        int k1 = 2;

        printAllKthLength(chars1,k1);

        return 0;
}
