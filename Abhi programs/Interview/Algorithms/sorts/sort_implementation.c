#include <stdio.h>
#include <stdlib.h>
#include "sort.h"



void display(int* array, int n)
{
	printf("-------------------------------The elements of the array are---------------------------------------\n");
	int i = 0;

	for(i = 0 ; i < n; i++)
	{
		printf("%d\n",array[i]);
	}

	printf("---------------------------------------------------------------------------------------------------\n");

}


void selection_sort(int* array, int n)
{
	int i = 0;
	int j = 0;
	int min;

	for(i = 0; i < n-1; i++)
	{
		min = i;

		for(j = i +1 ; j < n ; j++)
		{
			if(array[j] < array[min])
			{
				min = j;
			}
		}

		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;

	}
}

void bubble_sort(int* array, int n)
{
	int i = 0;
	int j = 0;
	int temp;

	for(i = 0 ; i < n-1; i++)
	{
		for(j = 0 ; j < n - 1 -i; j++)
		{
			if(array[j+1] < array[j])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

void merge_sort(int* array, int low, int high)
{
	int mid;

	if(low < high)
	{
		mid = (low + high)/2;
		merge_sort(array, low, mid);
		merge_sort(array, mid + 1,  high);
		merge(array, low, mid, high);
	}
}


void merge(int* array,int low , int mid, int high)
{
	int i = low;
	int j = mid+1;
	int k = low;
	int temp[MAX_ARRAY];

	while(i <= mid && j <= high)
	{
		if(array[i] < array[j])
		{
			temp[k++] = array[i++];
		}

		else if(array[i] > array[j])
		{
			temp[k++] = array[j++];

		}

		else
		{
			temp[k++] = array[i++];
			temp[k++] = array[j++];
		}
	}

	while(i <= mid)
	{
		temp[k++] = array[i++];
	}


	while(j <= high)
	{
		temp[k++] = array[j++];
	}


	for(k = low; k <= high; k++)
	{
		array[k] = temp[k];
	}
}