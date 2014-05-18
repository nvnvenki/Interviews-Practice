#include <stdio.h>

int main()
{
        int matrix[][4] = {
                {1,2,3,4},
                {5,6,7,8},
                {9,10,11,12},
                {13,14,15,16}
        };

        int i,j,k,middle,size;
        size = 4;
        for(i = size - 1, j = 0; i > 0; i--, j++)
        {
                for(k = j; k < i; ++k)
                {
                        printf("%d ",matrix[j][k]);
                }
                for(k = j; k < i; ++k)
                {
                        printf("%d ",matrix[k][i]);
                }
                for(k = i; k > j; --k)
                {
                        printf("%d ",matrix[i][k]);
                }
                
                for(k = i; k > j; --k)
                {
                        printf("%d ",matrix[k][j]);
                }
        }

        middle = (size - 1)/2;
        if(size % 2 == 1)
        {
                printf("%d",matrix[middle][middle]);
        }
        printf("\n\n");
        return 0;
}
