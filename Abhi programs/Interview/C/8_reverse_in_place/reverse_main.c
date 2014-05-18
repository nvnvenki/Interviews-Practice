#include <stdio.h>
#include <stdlib.h>
#include "reverse_in_place.h"


int main()
{
	char s[100];
	printf("Enter a string \n");
	scanf("%s",s);
	reverse(s);
	printf("The reversed string is %s \n",s);
}