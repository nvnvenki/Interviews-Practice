#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toUpper(int ch)
{
        if(ch >= 'a' && ch <= 'z')
        {
                return 'A' + ch - 'a';
        }
        else
        {
                return ch;
        }
}

int toLower(int ch)
{
        if(ch >= 'A' && ch <= 'Z')
        {
                return 'a' + ch - 'A';
        }
        else
        {
                return ch;
        }
}

int isUpper(int ch)
{
        if(ch >= 'A' && ch <= 'Z')
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

int isLower(int ch)
{
        if(ch >= 'a' && ch <= 'z')
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

char *strDup(char *s)
{
        char *dup = (char*)malloc(strlen(s) + 1);
        if(dup == (char*)0)
        {
                return (char*)0;
        }
        strcpy(dup,s);
        return dup;
}

int stringLength(char *s)
{
        int len = 0;
        while(*s++)
        {
                ++len;
        }
        return len;
}

char *strCat(char *string1, const char *string2)
{
        char *p = string1;
        if(string1 == NULL || string2 == NULL)
        {
                return string1;
        }
        while(*string1)
        {
                string1++;
        }
        while(*string1++ = *string2++);
        return p;
}
int main()
{
        printf("toUpper(c): %c\n", toUpper('c'));
        printf("toUpper(C): %c\n", toUpper('C'));

        printf("toLower(c): %c\n", toLower('c'));
        printf("toLower(C): %c\n", toLower('C'));

        printf("isUpper(c): %s\n", isUpper('c')?"yes":"no");
        printf("isUpper(C): %s\n", isUpper('C')?"yes":"no");

        printf("isLower(c): %s\n", isLower('c')?"yes":"no");
        printf("isLower(C): %s\n", isLower('C')?"yes":"no");

        char *original = "hi";
        char *dup = strDup(original);
        puts(dup);
        
        printf("StringLenght('hello'): %d\n",stringLength("0"));

        char string1[100];
        strcpy(string1,"hi");
        printf("strCat('hi',' hello'): %s\n", strCat(string1," hello"));
        return 0;
}
