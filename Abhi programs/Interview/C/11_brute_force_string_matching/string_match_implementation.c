#include <stdio.h>
#include <stdlib.h>
#include "string_match.h"
#include <string.h>

int string_match(char* text, char* pattern)
{
		int n = strlen(text);
		int m = strlen(pattern);
		int i = 0;
		int j = 0;

		for(i = 0 ; i <= n - m ; i++)
		{
			j = 0;

			while(j < m && pattern[j] == text[i + j])
			{
				j = j + 1;
			}

			if(j == m)
			{
				return i;
			} 
		}

		return -1;
}