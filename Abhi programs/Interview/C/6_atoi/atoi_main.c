#include <stdio.h>
#include <stdlib.h>
#include "atoi_mine.h"

int main()
{
	char s[100];

	printf("Enter the string containing numbers: \n");
	scanf("%s",s);

	int n = atoi_mine(s);
	printf("the number is %d: \n", n);
}