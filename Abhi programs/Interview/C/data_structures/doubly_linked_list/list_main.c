#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	
	node_t head = NULL;

	int choice;
	int ele;

	while(1)
	{
		printf("-------------------------------------------------------------------------------------------\n");
		printf("1. Add a node on the front end of the list \n");
		printf("2. Display \n");
		printf("3. Exit \n");
		printf("4. Add a node  on the rear end of the list \n");
		printf("5. Delete a node in the front end of the list \n");
		printf("6. Delete a node in the rear end of the list \n");
		printf("-------------------------------------------------------------------------------------------\n");

		printf("Enter the choice \n");
		scanf("%d", &choice);


		switch(choice)
		{
			case 1:
					printf("Enter the element to be inserted \n");
					scanf("%d", &ele);
					head = add_front(head, ele);
					break;

			case 2:
					display(head);
					break;

			case 3:
					exit(0);
					break;

			case 4:
					printf("Enter the element to be inserted \n");
					scanf("%d", &ele);
					head = add_end(head, ele);
					break;

			case 5:
					head = delete_front(head);
					break;

			case 6:
					head = delete_rear(head);
					break;

			default:
					printf("The choice you entered is wrong \n");
					break;
		}
	}
}