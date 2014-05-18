#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "atoi_mine.h"

int atoi_mine(char s[])
{
	int n;
	int i;
	int sign;

	for(i = 0 ; isspace(s[i]);i++)
	{
		;
	}

	sign = (s[i] == '-' ? -1 : 1);

	if(s[i] == '+' || s[i] == '-')
	{
		i++;
	}


	for(n = 0 ; isdigit(s[i]); i++)
	{
		n = 10 * n + (s[i] - '0');
	}

	return sign * n;
}