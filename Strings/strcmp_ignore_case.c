#include <stdio.h>

int strcmp(char *str1,char *str2)
{
        int i;
        for(i = 0; str1[i] && str2[i];++i)
        {
                if(str1[i] == str2[i] || (str1[i] ^ 32) == str2[i]) // Invert 6th bit
                {
                        continue;
                }
                else
                {
                        break;
                }
        }
        if(str1[i] == str2[i])
        {
                return 0;
        }
        if((str1[i] | 32) < (str2[i] | 32))
        {
                return -1;
        }
        return 1;
}


int main()
{
        printf("value: %d\n",strcmp("hi","He"));
        printf("value: %d\n",strcmp("venki","VeNkI"));
        return 0;
}
