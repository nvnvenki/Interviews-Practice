#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

void sort(int* array , int n)
{
	int i = 0;
	int j = 0;

	for(i = 0 ; i < n-1; i++)
	{
		int low = i;

		for(j = i+1 ; j < n ; j++)
		{
			if(array[j] < array[low])
			{
				low = j;
			}
		}

			int temp = array[i];
			array[i] = array[low];
			array[low] = temp;
		
		
	}
}


void display(int* array , int n)
{
	int i = 0;

	printf("------------------------The array elements are-------------------------- \n");
	for(i = 0 ; i < n ; i++)
	{
		printf("%d \n",array[i]);
	}
}


int b_search(int* array , int n , int search)
{
	int low = 0;
	int high = n -1;
	int mid = (low+high)/2;

	while(low <= high && array[mid] != search)
	{
		if(search > array[mid])
		{
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}

		mid = (low+high)/2;
	}

	if(search == array[mid])
	{
		return mid;
	}

	else
	{
		return -1;
	}


}