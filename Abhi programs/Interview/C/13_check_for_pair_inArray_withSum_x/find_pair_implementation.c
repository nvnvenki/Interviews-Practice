#include "find_pair.h"
#include <stdio.h>
#include <stdlib.h>


void find_pair(int* array, int n, int sum)
{
	int binary[MAX] = {0};
	int i = 0;
	int temp;

	for(i = 0 ; i < n; i++)
	{
		temp = sum - array[i];
		if(temp >= 0 && binary[temp] == 1)
		{
			printf("The pair is %d and %d \n", array[i], temp);
		}
		binary[array[i]] = 1;

	}

}