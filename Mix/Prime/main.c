#include <stdio.h>

void getPrimes(int *a,int n)
{
        int end = n;
        for(int i = 1; i <= end; ++i)
        {
                a[i] = i + 1;
        }

        for(int i = 1; i <= end; ++i)
        {
                if(a[i] != 0)
                {

                        for(int j = i + 1; j <= end; ++j)
                        {
                                if(a[j] % a[i] == 0)
                                {
                                        a[j] = 0;
                                }
                        }
                }
        }

}

int getNumberOfPrimes(int N) {
    
    int c = 0;
    int a[N];
    getPrimes(a,N);

    for(int i = 1; i < N; ++i)
    {
        if(a[i] != 0)
        {
            c++;
        }
    }
    
    return c;

}

int main()
{
        int n;
        scanf("%d",&n);
        printf("%d\n", getNumberOfPrimes(1000000));
        printf("\n");
        return 0;
}
