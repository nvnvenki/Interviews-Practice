#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int main()
{
	int n;
	printf("Enter the number of elements of the array \n");
	scanf("%d", &n);
	int array[n];

	printf("Enter the elements of the array: \n");
	int i;
	for(i = 0 ; i < n; i++)
	{
		scanf("%d",&array[i]);
	}

	shell_sort(array, n);
	disp(array, n);
}