#include <stdio.h>

void DtoB(int n)
{
	if(n > 0)
	{
		DtoB(n/2);
		printf("%d", n%2);	
	}
}

int main()
{
	int n;
	printf("Enter the decimal number:\n");
	scanf("%d",&n);
	
	printf("%d in Binary is:\n",n);
	DtoB(n);
	printf("\n");
}
