#include <stdio.h>
#include <stdlib.h>

int findCandidate(int *a,int n)
{
        int majority_index = 0; 
        int count = 1;
        for(int i = 0; i < n; ++i)
        {
                if(a[majority_index] == a[i])
                {
                        ++count;
                }
                else
                {
                        --count;
                }
                if(count == 0)
                {
                        majority_index = i;
                        count = 1;
                }
        }
        return a[majority_index];
}

int isMajority(int *a,int n,int candidate)
{
        int count = 0;
        for(int i = 0; i < n; ++i)
        {
                if(a[i] == candidate)
                {
                        ++count;
                }
        }
        return (count > (n/2));
}

void getMajorityElement(int* a,int n)
{
       int candidate = findCandidate(a,n); 
       printf("%d\n", candidate);
       if(isMajority(a,n,candidate))
       {
               printf("%d\n",candidate);
       }
       else
       {
               printf("No majority element\n");
       }

}

int main()
{
        int a[] = {3,3,4,4,2,4,4,2,4,4};
        int n = 10;
        getMajorityElement(a,n);
        return 0;
}
