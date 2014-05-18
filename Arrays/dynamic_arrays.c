#include <stdio.h>
#include <stdlib.h>

int main()
{
        /*----------------------------1d array---------------------*/
        int n1 = 5;
        int *array1 = malloc(n1 * sizeof(int));
        for(int i = 0;i < n1; ++i)
        {
                array1[i] = i;
        }

        for(int i = 0; i < n1; ++i)
        {
                printf("%d\t",array1[i]);
        }
        printf("\n-----------------------------------------------------------------\n");
        /* ------------------2d array -------------------- */
        int row = 4;
        int column = 4;
        int **array2 = (int **)malloc(row * sizeof(int *));
        for(int i = 0; i < row; ++i)
        {
                array2[i] = malloc(column * sizeof(int));
        }

        for(int i = 0; i < row; ++i)
        {
                for(int j = 0; j < column; ++j)
                {
                        array2[i][j] = i == j ? 1:0;
                }
        }

        for(int i = 0; i < row; ++i)
        {
                for(int j = 0; j < column; ++j)
                {
                        printf("%d\t",array2[i][j]);
                }
                printf("\n");
        }

        printf("\n----------------------------------------------------------------------\n");
}
