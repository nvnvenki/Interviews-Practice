#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print(char *string,int low,int high)
{
        for(int i = low; i <= high; ++i)
        {
                printf("%c",string[i]);
        }
        printf("\n");
}

void longest_palindrome(char *string)
{
        int maxlength = 1;
        int start = 0;
        int length = strlen(string);

        int low,high;
        for(int i = 1; i < length; ++i)
        {
                // Find the longest even length palindrome with center points as i - 1 and i
                low = i - 1;
                high = i;
                while(low >= 0 && high < length && string[low] == string[high])
                {
                        if(high - low + 1 > maxlength)
                        {
                                start = low;
                                maxlength = high - low + 1; 
                        }
                        --low;
                        ++high;
                }

                // Find the longest odd length palindrome with centre as i;
                low = i - 1;
                high = i + 1;
                while(low >= 0 && high < length && string[low] == string[high])
                {
                        if(high - low + 1 > maxlength)
                        {
                                start = low;
                                maxlength = high - low + 1;
                        }
                        --low;
                        ++high;
                }
        }
        print(string,start,start + maxlength - 1);

}

int main()
{
        char string[] = "abaaaabaa";
        longest_palindrome("forgeeksskeegfor");
        return 0;
}
