/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  given an array of length n and r generate arrays of length r of all possible combinations
 *
 *        Version:  1.0
 *        Created:  Friday 02 August 2013 01:09:11  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Venki (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

void printRec(int *a,int *data,int start,int end,int index,int r)
{
        if(index == r)
        {
                for(int i = 0; i < r; ++i)
                {
                        printf("%d\t",data[i]);
                }
                printf("\n");
                return;
        }
        for(int i = start; i <= end && end - i + 1 >= r - index; ++i)
        {
                data[index] = a[i];
                printRec(a,data,i + 1,end,index + 1, r);
        }
}

void printCombination(int *a,int n,int r)
{
        int result[r];

        printRec(a,result,0,n - 1,0, r);
}

int main()
{
        int a[] = {1,2,3,4,5};
        int r = 3;
        int n = sizeof(a) / sizeof(a[0]);
        printCombination(a,n,r);
        return 0;
}
