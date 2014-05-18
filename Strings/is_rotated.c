#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int areRotations(char *str1,char *str2)
{
        int len1 = strlen(str1);
        int len2 = strlen(str2);

        char temp[len1 * 2 + 1];
        if(len1 != len2)
        {
                return 0;
        }

        temp[0] = '\0';
        strcat(temp,str1);
        strcat(temp,str1);
        //puts(temp);
        if(strstr(temp,str2))
        {
                return 1;
        }
        else
        {
                return 0;
        }

}

int main()
{
        char *str1 = "waterbottle";
        char *str2 = "erbottlewat";
        char *str3 = "ACDA";

        printf("%s and %s are %s\n",str1,str2,areRotations(str1,str2) ? "rotations": "not rotations");
        printf("%s and %s are %s\n",str1,str3,areRotations(str1,str3) ? "rotations": "not rotations");
        return 0;
}

