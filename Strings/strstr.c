#include <stdio.h>

int strlen(char* s)
{
        int c = 0;
        while(*s != '\0')
        {
                c++;
        }

        return c;
}

int findStartIndex(char* src,char* test)
{
        if(src == NULL || test == NULL)
        {
                return -1;
        }
        int flag = 0;
        int i;
        int j;
        for(i = 0; src[i] != '\0';++i)
        {
                if(src[i] == test[0])
                {
                        for(j = i; ; ++j)
                        {
                                if(test[j - i] == '\0')
                                {
                                        flag = 1;
                                        break;
                                }
                                if(src[j] == test[j - i])
                                {
                                        continue;
                                }
                                else
                                {
                                        break;
                                }
                        }
                }
                if(flag == 1)
                {
                        break;
                }
        }
        if(flag == 1)
        {
                return i;
        }
        else
        {
                return -1;
        }
}


int main(int argc, char const *argv[])
{
	printf("%d\n", findStartIndex("AAABBCC","ABB"));
	return 0;
}
