#include <stdio.h>
#include <stdlib.h>
#include "itoa.h"
#include <string.h>

void itoa_mine(int n, char* s)
{
	int sign;
	int i =0;

	if((sign =n) < 0)
	{
		n = -n;
	}


	while((n = n / 10))
	{
		s[i++] = n % 10 + '0';
	}

	if(sign < 0)
	{
		s[i++] = '-'
	}
	s[i] = '\0';
	reverse(s);
}


static void reverse(char* s)
{
	int i = 0;
	int j = 0;

	for(i = 0, j=strlen(s)-1 ; i < j ; i++, j--)
	{
		int temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}