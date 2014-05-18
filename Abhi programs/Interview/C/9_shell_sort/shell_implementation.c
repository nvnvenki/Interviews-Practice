#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

void shell_sort(int* array , int n)
{
	int i = 0;
	int j = 0;
	int gap =0;

	for(gap = n/2; gap > 0 ; gap = gap/2)
	{
		for(i = gap; i < n; i++)
		{
			for(j = i - gap; j >= 0 && array[j] > array[j+gap] ; j -= gap)
			{
				int temp = array[j];
				array[j] = array[j+gap];
				array[j+gap] = temp;
			}
		}
	}
}


void disp(int* array , int n)
{
	int i = 0;

	for(i = 0 ; i < n; i++)
	{
		printf("%d \t",array[i]);
	}

	printf("\n");
}