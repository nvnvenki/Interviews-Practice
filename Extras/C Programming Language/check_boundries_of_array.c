#include <stdio.h>

/*
        this code checks whether the array passed to the function is of min 5 elements :D
        gothe irlila :D
        eega gothaaythu ;)
*/

void display(int a[]) // min of 5 elements
{
        int i = 0;
        for(i = 0; i < 5; ++i)
        {
                printf("%d\t", a[i]);

        }
        printf("\n");
}

int main()
{
        int a[3] = {1,2,3};
        display(a);
        return 0;
}
