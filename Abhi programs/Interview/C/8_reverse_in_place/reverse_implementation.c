#include <stdio.h>
#include <stdlib.h>
#include "reverse_in_place.h"
#include <string.h>
void reverse(char* str)
{
	int i;
	int j;
	int temp;

	for(i = 0, j = strlen(str)-1; i < j ;i++, --j )
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}