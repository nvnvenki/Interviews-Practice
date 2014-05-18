#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main()
{
	int choice;
	int n;
	int array[MAX_ARRAY];
	int i = 0;
	int merge_sort_result[MAX_ARRAY];

	while(1)
	{
		printf("---------------------------------------------------------------------------------------------------\n");
		printf("1. Selection sort \n");
		printf("2. Bubble sort \n");
		printf("3. Merge Sort \n");
		printf("4. Exit \n");
		printf("---------------------------------------------------------------------------------------------------\n");

		printf("Enter the choice \n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
					printf("Enter the number of elements of the array \n");
					scanf("%d", &n);
					printf("Enter the elements of the array with a space and then press enter when finished \n");
					for(i = 0 ; i < n ; i++)
					{
						scanf("%d",&array[i]);
					}

					selection_sort(array, n);
					display(array, n);

					break;

			case 2:
					printf("Enter the number of elements of the array \n");
					scanf("%d", &n);
					printf("Enter the elements of the array with a space and then press enter when finished \n");
					for(i = 0 ; i < n ; i++)
					{
						scanf("%d",&array[i]);
					}

					bubble_sort(array, n);
					display(array, n);

					break;

			case 3:
					printf("Enter the number of elements of the array \n");
					scanf("%d", &n);
					printf("Enter the elements of the array with a space and then press enter when finished \n");
					for(i = 0 ; i < n ; i++)
					{
						scanf("%d",&array[i]);
					}
					
					merge_sort(array, 0, n-1);
					display(array, n);

					break;

			case 4:
					exit(1);

		}

	}

	return 0;
}