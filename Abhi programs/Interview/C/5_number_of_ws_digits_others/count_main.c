#include <stdio.h>
#include <stdlib.h>

int main()
{

	int c;
	int spaces = 0;
	int digits[10];
	int others = 0;
	int i = 0;


	while((c= getchar()) != EOF)
	{
		switch(c)
		{
			case '0':	
			case '1':	
			case '2':	
			case '3':	
			case '4':	
			case '5':	
			case '6':	
			case '7':	
			case '8':	
			case '9':
				digits[c-'0']++;
				break;

			case ' ':
			case '\n':
			case '\t':
				spaces++;
				break;

			default:
			others++;	
		}
	}


	for(i = 0 ; i < 10 ; i++)
	{
		printf("%d:\t",digits[i]);
	}

	printf("\n");

	printf("The number of white spaces is: %d \n", spaces);
	printf("The number of other characters that are entered are: %d \n",others);

	return 0;
}