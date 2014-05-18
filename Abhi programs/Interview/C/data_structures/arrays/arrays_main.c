#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int main()
{
	int choice;
	int array[MAX];
	int second_array[MAX];
	int n;
	int n1;
	int odd_occurences;
	int i = 0;
	int max_difference;

	struct pair min_max;
	int x;
	int isMajority;
	int maxSumContiguous;
	int missing;
	int searchElement;
	int searchIndex;
	int rotateBy;
	int twod[3][3];
	int j = 0;

	int sorted_array[] = {-8,1,4,6,10,45};
	int target_sum = 16;

	while(1)
	{
		printf("------------------------------------------------------------------------------------------------------\n");
		printf("1. Find the element occuring odd number of times in the array \n"); 
		printf("2. Exit \n"); 
		printf("3. Find the union of two arrays \n"); 
		printf("4. Find the intersection of two sorted arrays \n"); 
		printf("5. Find the maximum difference between two elements in an array \n");
		printf("6. Separate into zeroes and ones in a binary array of one dimentsion \n");
		printf("7. Find the minimum and maximum elements of the array \n");
		printf("8. Check for majority element in the array \n"); 
		printf("9. Find the first and the second smallest element in an array \n"); 
		printf("10. Find all the elements in the araay which have all the elements on the right which are lesser than the element \n"); 
		printf("11. Largest sum contiguous sub array \n");
		printf("12. Find the missing number among n contiguous elements in an array \n"); 
		printf("13. Find an element in a rotated sorted array(find element in this array 4567123) \n"); 
		printf("14. Reverse the array \n");
		printf("15. Left rotate an array \n"); 
		printf("16. If an element in a matrix make the corresponding row and column as zero \n");
		printf("17. Given a sorted array and a target integer find two elements of the array whose sum equals the target integer \n");
		printf("18. Right rotate an array \n"); 
		printf("------------------------------------------------------------------------------------------------------\n");

		printf("Enter the choice \n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
					printf("Enter the number of elements of the array \n");
					scanf("%d", &n);

					printf("Enter the elements of the array \n");
					for(i = 0 ; i < n ; i++)
					{
						scanf("%d", &array[i]);
					}
					odd_occurences =  find_odd_occurence(array,n);
					printf("The element occuring odd number of times is %d \n", odd_occurences);
					break;

			case 2:
					exit(1);

			case 3:
					printf("Enter the number of elements of the array1 \n");
					scanf("%d",&n);

					printf("Enter the elements of the array 1 \n");
					for(i = 0 ; i < n; i++)
					{
						scanf("%d",&array[i]);
					}


					printf("Enter the number of elements of the array2 \n");
					scanf("%d", &n1);

					printf("Enter the elements of the array 2 \n");
					for(i = 0; i < n1; i++)
					{
						scanf("%d",&second_array[i]);
					}

					find_union(array,n,second_array,n1);
					break;

			case 4:
					printf("Enter the number of elements of the array1 \n");
					scanf("%d",&n);

					printf("Enter the elements of the array 1 \n");
					for(i = 0 ; i < n; i++)
					{
						scanf("%d",&array[i]);
					}


					printf("Enter the number of elements of the array2 \n");
					scanf("%d", &n1);

					printf("Enter the elements of the array 2 \n");
					for(i = 0; i < n1; i++)
					{
						scanf("%d",&second_array[i]);
					}

					find_intersection(array,n,second_array,n1);
					break;

			case 5:
					printf("Enter the number of elements of the array \n");
					scanf("%d", &n);
					printf("Enter the elements of the array \n");

					for(i = 0 ; i < n; i++)
					{
						scanf("%d", &array[i]);
					}

					max_difference = find_max_difference(array,n);
					printf("The maximum difference in the array %d \n", max_difference);
					break;

			case 6:
					printf("Enter the number of elements of the array \n");
					scanf("%d",&n);
					printf("Enter the elements of the array \n");

					for(i = 0 ; i < n; i++)
					{
						scanf("%d",&array[i]);
					}

					separate_into_zeroes_ones(array,n);
					display(array,n);
					break;

			case 7:
					printf("Enter the number of elements of the array \n");
					scanf("%d", &n);
					printf("Enter the elements of the array \n");

					for(i = 0 ; i < n; i++)
					{
						scanf("%d", &array[i]);
					}

					min_max =  find_min_max(array, n);
					printf("The maximum element of the array is %d \n",min_max.max);
					printf("The minimum element of the array is %d \n", min_max.min);
					break;

			case 8:
					printf("Enter the number of elements in the array \n");
					scanf("%d", &n);
					printf("Enter the element to be searched for \n");
					scanf("%d", &x);

					printf("Enter the elements of the array \n");

					for(i = 0 ; i < n; i++)
					{
						scanf("%d",&array[i]);
					}

					isMajority = is_majority(array,n,x);

					if(isMajority)
					{
						printf("The element you entered is a majority element \n");

					}

					else
					{
						printf("The element you enetered is not a majority element \n");
					}

					break;

			case 9:
					printf("Enter the number of elements of the array \n");
					scanf("%d", &n);

					printf("Enter the elements of the array one by one \n");
					for(i = 0 ; i < n; i++)
					{
						scanf("%d", &array[i]);
					}

					find_first_second_smallest(array,n);
					break;

			case 10:
					printf("Enter the number of elements of the array \n");
					scanf("%d",&n);

					printf("Enter the elements of the array \n");
					for(i = 0; i < n; i++)
					{
						scanf("%d",&array[i]);
					}

					find_leader(array,n);

					break;

			case 11:

					printf("Enter the number of elements of the array \n");
					scanf("%d",&n);
					printf("Enter the elements of the array \n");
					for(i = 0 ; i < n; i++)
					{
						scanf("%d",&array[i]);
					}

					maxSumContiguous = find_largest_sum_contiguous(array,n);
					printf("The maximum sum is %d \n",maxSumContiguous);
					break;

			case 12:
					printf("Enter the number of elements of the array \n");
					scanf("%d", &n);
					printf("Enter the elements of the array \n");
					for(i = 0 ; i < n; i++)
					{
						scanf("%d",&array[i]);
					}

					missing = find_missing_number(array,n);
					printf("The missing number is %d \n", missing);


					break;

			case 13:
					printf("Enter the number of elements of the array \n");
					scanf("%d",&n);

					printf("Enter the elements of the array \n");
					for(i = 0 ; i < n; i++)
					{
						scanf("%d",&array[i]);
					}

					printf("Enter the search element \n");
					scanf("%d",&searchElement);

					searchIndex = find_element_in_rotated(array,n,searchElement);
					if(searchIndex != -1)
					{
						printf("The element is found in the array at %d \n",searchIndex);
					}

					else
					{
						printf("The element is not found in the array \n");
					}

					break;

			case 14:
					printf("Enter the number of elements of the array \n");
					scanf("%d",&n);
					
					printf("Enter the elements of the array \n");
					for(i = 0; i < n; i++)
					{
						scanf("%d",&array[i]);
					}

					reverse(array,0,n-1);
					display(array,n);
					break;

			case 15:
					printf("Enter the number of elements of the array \n");
					scanf("%d",&n);
					printf("Enter the elements of the array \n");
					for(i = 0; i <n; i++)
					{
						scanf("%d",&array[i]);
					}

					printf("Enter the number of elements by which the array has to be rotated \n");
					scanf("%d",&rotateBy);
					rotate(array,rotateBy,n);
					display(array,n);
					break;


			case 16:
					
					printf("Enter the elements of the array \n");
					for(i = 0; i < 3; i++)
					{
						for(j = 0; j < 3; j++)
						{
							scanf("%d",&twod[i][j]);
						}
					}

					printf("This is from main \n");
					for(i = 0; i < 3; i++)
					{
						for(j = 0; j < 3; j++)
						{
							printf("%d \t",twod[i][j]);
						}

						printf("\n");
					}

					make0rows0columns(twod);

					break;

			case 17:

					findTwoElementsTarget(sorted_array,target_sum,6);
					break;

			case 18:
					printf("Enter the number of elements of the array \n");
					scanf("%d", &n);
					printf("Enter the elements of the array \n");
					for(i = 0; i <n; i++)
					{
						scanf("%d",&array[i]);
					}

					printf("Enter the number of elements by which the array has to be rotated \n");
					scanf("%d",&rotateBy);
					right_rotate(array,rotateBy, n);
					display(array,n);
					break;
			default:
					break;




		}

	}
}