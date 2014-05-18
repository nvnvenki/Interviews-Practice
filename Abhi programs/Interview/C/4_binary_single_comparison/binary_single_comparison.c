#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

int main()
{
	int n;

	printf("Enter the number of elements of the array \n");
	scanf("%d",&n);

	int array[n];
	int i =0;

	for(i = 0; i < n; i++)
	{
		printf("Eneter element %d of the array \n",i);
		scanf("%d",&array[i]);
	}

	sort(array,n);
	display(array, n);

	int search;
	printf("Enter the element that u want to search: \n");
	scanf("%d",&search);

	int ele = b_search(array , n ,search);
	printf("the return value of the search is %d: \n",ele);

}