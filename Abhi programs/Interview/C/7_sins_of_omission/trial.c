#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p;
	int q = 100;

	p = &q;

	int number = sizeof(int)*p;
	// invalid arguments to the binary operator *

	printf("the number is: %d \n", number);

	return 0;
}