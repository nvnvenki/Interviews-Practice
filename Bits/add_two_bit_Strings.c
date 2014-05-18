#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void makeEqualLength(char *n1,char *n2)
{
        int l1 = strlen(n1);
        int l2 = strlen(n2);

        if(l1 < l2)
        {
                char *temp = malloc(l2 + 1);
                char *left_zeros = malloc(l2 - l1 + 1);
                strcpy(left_zeros,"");
                for(int i = 0;i < l2 - l1; ++i)
                {
                        strcat(left_zeros,"0");
                }
                strcat(left_zeros,"\0");
                strcat(temp,left_zeros);
                strcat(temp,n1);
                strcpy(n1,temp);
                //puts(left_zeros);
                //puts(n1);
        }
        else if(l1 > l2)
        {
                char *temp = malloc(l1 + 1);
                char *left_zeros = malloc(l1 - l2 + 1);
                strcpy(left_zeros,"");
                for(int i = 0;i < l1 - l2; ++i)
                {
                        strcat(left_zeros,"0");
                }
                strcat(left_zeros,"\0");
                strcat(temp,left_zeros);
                strcat(temp,n2);
                strcpy(n2,temp);
        }

}

char *addBitStrings(char *n1,char *n2)
{
        makeEqualLength(n1,n2);
        // puts(n1);
        // puts(n2);
        int length = strlen(n1);
        char *result = malloc(length + 2);
        strcpy(result,"");
        int carry = 0;
        for(int i = length - 1;i >= 0; --i)
        {
                int first_bit = n1[i] - '0';
                int second_bit = n2[i] - '0';

                int sum = (first_bit ^ second_bit ^ carry) + '0';
                char t[] = {sum,'\0'};
                char *temp = malloc(length + 1);
                strcpy(temp,"");
                strcat(temp,t);
                strcat(temp,result);
                strcpy(result,temp);

                carry = (first_bit & second_bit) | (second_bit & carry) | (first_bit & carry);
        }

        if(carry)
        {
                char *temp = malloc(length + 1);
                strcpy(temp,"");
                strcat(temp,"1");
                strcat(temp,result);
                strcpy(result,temp);

        }
        return result;
}


int main()
{
        char n1[100] = "10";
        char n2[100] = "1";
        
        char *sum = addBitStrings(n1,n2);
        puts(sum);
        return 0;
}
