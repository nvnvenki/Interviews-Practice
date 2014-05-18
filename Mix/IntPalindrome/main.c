#include <stdio.h>

int isPalindrome(int num,int *dupNum)
{       
        // printf("num : %d\t dup: %d\n",num,*dupNum);
        if(num >= 0 && num < 10) // if its on digit
        {
                return (num == (*dupNum) % 10);
        }

        if(!isPalindrome(num / 10,dupNum))
        {
                return 0;
        }
        // 
        printf("2 num : %d\t dup: %d\n",num,*dupNum);
        *dupNum = *dupNum / 10;
        return (num  % 10 == (*dupNum) % 10);
}

int isNumPalindrome(int n)
{
        if(n < 0)
        {
                n = -n;
        }
        
        int *dupNum = &n;

        return isPalindrome(n,dupNum);
}

int main()
{
        int n = 101;
        isNumPalindrome(n)? printf("Yes\n"): printf("No \n");
        return 0;
}
