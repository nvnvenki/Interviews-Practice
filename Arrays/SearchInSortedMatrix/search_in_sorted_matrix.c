#include <stdio.h>


int isFound(int n,int matrix[][n],int key)
{
        int i = 0; 
        int j = n - 1;
        while(i < n && j >= 0)
        {
                if(matrix[i][j] == key)
                {
                        return 1;
                }
                if(matrix[i][j] > key)
                {
                        --j;
                }
                else
                {
                        ++i;
                }
        }
        return 0;
}


int main()
{
        int matrix[][4] = {{1, 2, 3, 4},
                          {5, 6, 7, 8},
                          {9,10,11,12},
                          {13,14,15,16}
                        };
        int n = 4;
        if(isFound(n,matrix,1))
        {
                printf("found\n");
        }
        else
        {
                printf("not found\n");
        }
}
