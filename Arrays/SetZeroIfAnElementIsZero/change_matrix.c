#include <stdio.h>

void change(int n,int matrix[][n])
{
        int row[n];
        int column[n];
        // Assuming square matrix
        for(int i = 0; i < n; ++i)
        {
                row[i] = 0;
                column[i] = 0;
        }
        for(int i = 0; i < n; ++i)
        {
                for(int j = 0; j < n ;++j)
                {
                        if(matrix[i][j] == 0)
                        {
                                row[i] = 1;
                                column[j] = 1;
                        }
                }
        }


        for(int i = 0; i < n; ++i)
        {
                for(int j = 0; j < n ;++j)
                {
                        if(row[i] == 1 || column[j] == 1)
                        {
                                matrix[i][j] = 0;
                        }
                }
        }

}


void display(int n,int matrix[][n])
{
        for(int i = 0; i < n; ++i)
        {
                for(int j = 0; j < n; ++j)
                {
                        printf("%4d",matrix[i][j]);
                }
                printf("\n");
        }
}


int main()
{
        int matrix[][5] = {
                {1,3,4,0,1},
                {4,0,5,7,1},
                {2,0,5,6,8},
                {0,6,7,1,0},
                {1,2,3,4,5}
        };
        int n = 5;

        printf("Matrix before operation\n");
        display(n,matrix);
        change(n,matrix);
        printf("Matrix after change\n");
        display(n,matrix);
        return 0;
}
