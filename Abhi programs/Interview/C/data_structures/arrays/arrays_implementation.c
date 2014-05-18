#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include <limits.h>

void display(int* array, int n)
{
	int i = 0;
	printf("------------------------------------------------------------------------------------------------------\n");
	for(i = 0; i < n; i++)
	{
		printf("%d\t",array[i]);
	}
	printf("\n");
	printf("------------------------------------------------------------------------------------------------------\n");
}

int find_odd_occurence(int* array, int n)
{
	int res = 0;
	int i = 0;

	for(i = 0 ; i < n; i++)
	{
		res = res ^ array[i];
	}

	return res;
}

void find_union(int* a, int m, int*b, int n)
{
	int i = 0;
	int j = 0;
	int k = (m > n)? 2 * m: 2 *n;
	printf("The value of k is %d \n",k);
	int c[k];
	int t = 0;

	while(i < m && j < n)
	{
		if(a[i] < b[j])
		{
			c[t++] = a[i++];
		}

		else if(a[i] > b[j])
		{
			c[t++] = b[j++];
		}

		else
		{
			c[t++] = a[i++];
			j++;
		}
	}


	while(i < m)
	{
		c[t++] = a[i++];
	}

	while(j < n)
	{
		c[t++] = b[j++];
	}

	display(c,t);
}


void find_intersection(int* a, int m, int*b, int n)
{
	int i = 0;
	int j = 0;
	int k = (m > n)? m: n;
	printf("The value of k is %d \n",k);
	int c[k];
	int t = 0;

	while(i < m && j < n)
	{
		if(a[i] < b[j])
		{
			i++;
		}

		else if(a[i] > b[j])
		{
			j++;
		}

		else
		{
			c[t++] = a[i++];
			j++;
		}
	}


	display(c,t);
}

int find_max_difference(int* array, int n)
{
	int i = 0;
	int difference_array[n-1];

	for(i = 0 ; i < n - 1 ; i++)
	{
		difference_array[i] = array[i + 1] - array[i];
	}

	int max_difference = difference_array[0];

	for(i = 1; i < n-1; i++)
	{
		if(difference_array[i - 1] > 0)
		{
			difference_array[i] += difference_array[i - 1];
		}

		if(max_difference < difference_array[i])
		{
			max_difference = difference_array[i];
		}
	}

	return max_difference;
}


void separate_into_zeroes_ones(int* array,int n)
{
	//Make a pass of the array and convert all zeroes to ones on the way
	//At the same time count the number of ones
	// from (n - number of ones found) fill the ones


	int i = 0;
	int no_ones = 0;

	for(i = 0 ; i < n ; i++)
	{
		if(array[i] == 1)
		{
			array[i] = 0;
			no_ones += 1;
		}
	}

	for(i = n - no_ones; i < n; i++)
	{
		array[i] = 1;
	}
}


struct pair find_min_max(int* array, int n)
{
	struct pair min_max;
	int i = 0;

	if(n % 2 == 0)
	{
		if(array[0] > array[1])
		{
			min_max.max = array[0];
			min_max.min = array[1];
		}

		else
		{
			min_max.max = array[1];
			min_max.min = array[2];
		}

		i = 2;
	}

	else
	{
		//Just making sure that the rest of the array has even number of elements;
		min_max.max = min_max.min = array[0];
		i = 1;
	}


	while(i < n - 1)
	{
		if(array[i] > array[i+1])
		{
			if(array[i] > min_max.max)
			{
				min_max.max = array[i];
			}

			if(array[i + 1] < min_max.min)
			{
				min_max.min = array[i+1];
			}
		}

		else
		{
			if(array[i] < min_max.min)
			{
				min_max.min = array[i];
			}

			if(array[i + 1] > min_max.max)
			{
				min_max.max = array[i+1];
			}
		}

		i += 2;
	}


	return min_max;


}


int is_majority(int* array, int n, int x)
{
	int low = 0;
	int high = n -1;
	int mid = 0;

	while(low < high)
	{
		mid = (low+high)/2;
		printf("The middle element is %d \n",mid);

		if(x == array[mid])
		{
			printf("The element is found \n");
			return majority_helper(array,n,mid,x);
		}

		else if(x < array[mid])
		{
			high = mid -1;
		}


		else if(x > array[mid])
		{
			low = mid + 1;
		}

		else
		{
			printf("There is something wrong \n");
		}

	}


	printf("The element is not found in the array \n");
	return -1;


}


int majority_helper(int* array, int n, int index, int x)
{
	int i = index + 1;
	int count = 1;

	while(i < n && (array[i] == x))
	{
		
		count++;
		i++;
	}

	return ( count >= (n/2) );
}

void find_first_second_smallest(int* array,int n)
{
	int i = 0;
	int first = INT_MAX;
	int second = INT_MAX;

	if(n < 2)
	{
		printf("Invalid input \n");
		return;
	}
	for(i = 0 ; i < n; i++)
	{
		if(array[i] < first)
		{
			second = first;
			first = array[i];
		}

		else if(array[i] < second)
		{
			second = array[i];
		}
	}

	printf("The first smallest element of the array = %d \n",first);
	printf("The second smallest element of the array = %d \n", second);
}

void find_leader(int* array, int n)
{
	//scan from the right hand side and keep track of the maximum element
	//anytime it changes then print the array
	int max = array[n-1];
	printf("%d \t", max);
	int i = 0;

	for(i = n -2 ; i >= 0; i--)
	{
		if(array[i] > max)
		{
			printf("%d \t",array[i]);
			max = array[i];
		}
	}
	printf("\n");
}

int find_largest_sum_contiguous(int* array,int n)
{
	int max_so_far = 0;
	int max_ending_here = 0;
	int i = 0;

	for(i = 0 ; i < n; i++)
	{
		max_ending_here += array[i];

		if(max_ending_here < 0)
		{
			max_ending_here = 0;
		}

		if(max_so_far < max_ending_here)
		{
			max_so_far = max_ending_here;
		}
	}


	return max_so_far;

}

int find_missing_number(int* array, int n)
{
	int sum = ((n+1) * (n+2)) / 2;
	int i =0;

	for(i = 0 ; i < n ; i++)
	{
		sum -= array[i];
	}

	return sum;
}

int find_element_in_rotated(int* array,int n, int searchElement)
{
	int pivot = find_pivot(array,n);
	int result = -1;

	if(pivot == -1)
	{
		printf("error: the array is not rotated \n");
		return -1;
	}

	else
	{
		//the array is rotated
		if(searchElement < array[0])
		{
			result = binary_search(array,pivot+1,n-1,searchElement);
		}

		else
		{
			result = binary_search(array,0,pivot,searchElement);
		}
	}

	return result;
}


int binary_search(int* array, int start,int end, int searchElement)
{
	int low = start;
	int high = end;
	int mid = 0;

	while(low < high)
	{
		mid = (low + high)/2;

		if(searchElement < array[mid])
		{
			high = mid - 1;
		}

		else if(searchElement > array[mid])
		{
			low = mid +1;
		}

		else if(searchElement == array[mid])
		{
			return mid;
		}

		else
		{
			printf("There is something wrong \n");
		}

	}

	return -1; //The element is not found in the array

}

static int find_pivot(int* array, int n)
{
	int first_element = array[0];
	int i  = 1;
	
	while(i < n && array[i] > first_element)
	{
		i++;
	}

	if(i == n)
	{
		return -1;
		//the array is not rotated at all
	}

	else
	{
		return i -1;
	}
}

void reverse(int* array, int start, int end)
{
	int temp;

	if( start >= end)
	{
		return;
	}

	temp = array[start];
	array[start] = array[end];
	array[end] = temp;

	reverse(array, start +1, end -1);
}

void rotate(int* array, int d, int n)
{
	if(d > n)
	{
		printf("error: The problem seriously is you are a moron \n");
	}

	else
	{
		reverse(array,0,d-1);
		reverse(array,d,n-1);
		reverse(array,0,n-1); 
	}
}

void make0rows0columns(int a[][3])
{


	int map_array[3][3];
	int i = 0;
	int j = 0;
	int k = 0;


	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d \t",a[i][j]);
		}

		printf("\n");
	}




	for(i = 0 ; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(a[i][j] == 0)
			{
				map_array[i][j] = 1;
			}

			else
			{
				map_array[i][j] = 0;
			}	
		}
	}

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(map_array[i][j] == 1)
			{
				//set the corresponding ith row and the jth column to zeroes
				for(k = 0; k < 3; k++)
				{
					a[i][k] = 0;

				}

				for(k = 0; k < 3; k++)
				{
					a[k][j] = 0;

				}
			}
		}
	}


	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d \t",a[i][j]);
		}

		printf("\n");
	}


}

void findTwoElementsTarget(int* sorted_array,int target_sum, int n)
{
	int r = n - 1;
	int l = 0;

	while(l < r)
	{
		int sum = sorted_array[l] + sorted_array[r];

		if(sum == target_sum)
		{
			printf("The two numbers are %d and %d \n",sorted_array[l], sorted_array[r]);
			break;
		}

		else if(sum > target_sum)
		{
			r--;
		}

		else if(sum < target_sum)
		{
			l++;
		}
	}
}

void right_rotate(int* array, int d, int n)
{
	reverse(array,0,d);
	reverse(array,d+1,n-1);
	reverse(array,0,n-1);
}




