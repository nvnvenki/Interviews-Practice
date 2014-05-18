#include <stdio.h>
#include <stdlib.h>

void swap(char* a,char* b)
{
        char temp = *a;
        *a = *b;
        *b = temp;
}

void permute(char* string,int start,int end)
{
        if(start == end)
        {
                printf("%s\n",string);
        }
        else
        {
                for(int j = start;j < end; ++j)
                {
                        swap((string + start), (string + j));
                        permute(string,start + 1,end);
                        swap((string + start), (string + j));
                }
        }
}


int main()
{
        char string[] = "ABC";
        int n = 3;
        
        // call the permute
        permute(string,0,n);

        return 0;
}
