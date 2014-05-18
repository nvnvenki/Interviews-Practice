#include <stdio.h>
#include <stdlib.h>
#include "string_match.h"

int main()
{
	int result;
	char pattern[100];
	char text[100];


	printf("Enter the text: \n");
	scanf("%s", text);
	printf("Enter the pattern \n");
	scanf("%s", pattern);

	result = string_match(text, pattern);

	if(result < 0)
	{
		printf("There is no match \n");
	}

	else
	{
		printf("There is a match in the string at %d \n", result);
	}

	return 0;

}