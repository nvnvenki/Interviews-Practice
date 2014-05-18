#include <stdio.h>
#include <stdlib.h>
// Given rand5() generate rand7()
int rand5()
{
        return rand() % 5;
}

int rand7()
{
        return (rand5() + rand5()) % 7 + 1;
}


int main()
{
        srand(1);
        printf("%d\n",rand7());
        return 0;
}
