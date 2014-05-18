#include <stdio.h>
#include <stdlib.h>
#include "circular.h"

int main()
{
	node_t head;
	head = (node_t)malloc(sizeof(struct node));
	head->link = head;
	head->ele = 0;


	int choice;
	int ele;


	while(1)
	{
		printf("----------------------------------------------------------------------------------------------------------\n");
		
		printf("1. Add a node to the front end of the list \n");
		printf("2. Display \n");
		printf("3. Exit\n");
		printf("4. Add a node to the rear end of the list \n");
		printf("5. Delete a node on the front end of the list \n");
		printf("6. Delete a node from the rear end of the list \n");
		printf("----------------------------------------------------------------------------------------------------------\n");

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
					printf("Enter an element to add to the rear end of the list \n");
					scanf("%d", &ele);
					head = add_rear(head, ele);
					break;

			case 5:
					head = delete_front(head);
					break;

			case 6:
					head = delete_rear(head);
					break;
			default:
					printf("Enter a correct choice jim \n");
					break;
		}

	}
}
