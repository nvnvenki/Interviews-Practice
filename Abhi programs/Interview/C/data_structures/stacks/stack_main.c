#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
	my_stack_t st;
	st.top = -1;

	int choice;
	int ele = 0;

	while(1)
	{
		printf("-----------------------------------------------------------------------------------------------------\n");
		printf("1. Push \n");
		printf("2. Exit \n");
		printf("3. Pop \n");
		printf("-----------------------------------------------------------------------------------------------------\n");

		printf("Enter the choice \n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
					printf("Enter the element you want to add to the stack \n");
					scanf("%d", &ele);
					push(&st,ele);
					break;

			case 2:
					exit(0);


			case 3:
					 
					printf("The element that is popped from the stack is %d \n",pop(&st));
					break;

			default:
					break;

		}

	}
}
