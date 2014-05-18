#include <stdio.h>

int array_mine[] = {1,2,3,4,5};

#define TOTAL_ELEMENTS (sizeof(array_mine)/sizeof(array_mine[0]))



int main()
{
		int d = -1;
		int number_of_elements = TOTAL_ELEMENTS;
		printf("The total number of elements is: %d \n  ",number_of_elements);

		//if d is now compared with number_of_elements then the comparison yields strange results
		//this is because sizeof returns an unsigned integer and comparing this with d which is an integer converts d into unsigned which then results in a huge value thus making the comparison always false which is strange
}