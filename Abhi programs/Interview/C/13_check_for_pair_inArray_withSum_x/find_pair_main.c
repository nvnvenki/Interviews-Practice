#include "find_pair.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Enter the number of elements of the array \n");
	scanf("%d",&n);
	printf("Enter the elements of the array \n");
	int array[n];
	int i = 0;
	for(i = 0 ; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	int sum;

	printf("Enter the sum \n");
	scanf("%d", &sum);
	find_pair(array, n, sum);
}