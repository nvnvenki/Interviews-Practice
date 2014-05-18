#include <stdio.h>
#include <stdlib.h>
#include "itoa.h"

int main()
{
	char* s;
	int n;

	printf("Enter an integer: \n");
	scanf("%d", &n);

	itoa_mine(n, s);
}