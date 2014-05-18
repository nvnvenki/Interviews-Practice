#include <stdio.h>

void display(int n,int matrix[][n])
{
        for(int i = 0; i < n; ++i)
        {
                for(int j = 0; j < n; ++j)
                {
                        printf("%d\t",matrix[i][j]);
                }
                printf("\n");
        }
}

void swap(int *a,int *b)
{
        int temp = *a;
        *a = *b;
        *b = temp;
}

void transpose(int n,int matrix[][n])
{
        for(int i = 0; i < n; ++i)
        {
                for(int j = 0; j < n; ++j)
                {
                        if(i < j)
                        {
                                swap(&matrix[i][j],&matrix[j][i]);
                        }
                }
        }
}

void reverseRow(int row,int n,int matrix[][n])
{
        int i = 0;
        int j = n - 1;
        while(i < j)
        {
                swap(&matrix[row][i],&matrix[row][j]);
                ++i;
                --j;
        }
}

void reverseColumn(int column,int n, int matrix[][n])
{
        int i = 0;
        int j = n - 1;
          
        while(i < j)
        {
                swap(&matrix[i][column],&matrix[j][column]);
                ++i;
                --j;
        }
        
}

void rotate90(int n,int matrix[][n])
{
        /*
                steps:
                        1.Transpose
                        2.Reverse each row
        */
        /*  
        transpose(n,matrix);
        for(int i = 0; i < n; ++i)
        {
                reverseRow(i,n,matrix);
        }
        */


        for(int layer = 0; layer < (n / 2); ++layer)
        {
                int first = layer;
                int last = n - 1 - layer;
                for(int i = first; i < last; ++i)
                {
                        int offset = i - first;
                        int top = matrix[first][i];
                        // left top
                        matrix[first][i] = matrix[last - offset][first];

                        // bottom left
                        matrix[last-offset][first] = matrix[last][last - offset];

                        // right bottom
                        matrix[last][last - offset] = matrix[i][last];

                        // top right
                        matrix[i][last] = top;


                }
        }
}


void rotatem90(int n,int matrix[][n])
{
        /* 
                steps:
                        1.Transpose
                        2.Reverse each column
        */
        transpose(n,matrix);
        for(int i = 0; i < n; ++i)
        {
                reverseColumn(i,n,matrix);
        }
}

void rotate180(int n,int matrix[][n])
{
        /*
                Steps:
                        1.Rotate 90 twice
        */
        rotate90(n,matrix);
        rotate90(n,matrix);
}

void rotatem180(int n,int matrix[][n])
{
        /* 
                Steps:
                        2.Rotate -90 twice
        */
        rotatem90(n,matrix);
        rotatem90(n,matrix);
}

int main()
{
        int matrix[][3] = {
                {1,2,3},
                {4,5,6},
                {7,8,9}
        };
        int n = 3;
        display(n,matrix);
        printf("--------------------------------------\n");
        //rotatem180(n,matrix);
        rotate90(n,matrix);
        display(n,matrix);
        return 0;
}
