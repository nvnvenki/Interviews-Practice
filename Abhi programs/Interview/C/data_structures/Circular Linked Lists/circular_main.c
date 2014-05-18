#include <stdio.h>
#include <stdlib.h>
#include "circular.h"

int main()
{
	node_t last = NULL;
	int choice;
	int ele;


	while(1)
	{
		printf("---------------------------------------------------------------------------------------------\n");
		printf("1. Add a node to the front of the list \n");
		printf("2. Display \n");
		printf("3. Exit \n");
		printf("4. Add a node at the end of the list \n");
		printf("5. Delete a node from the front end of the list \n");
		printf("6. Delete a node from the rear end of the list \n");
		printf("7. Split the circular linked list into two halves \n");
		printf("8. Insert nodes in a sorted order \n");
		printf("---------------------------------------------------------------------------------------------\n");

		printf("Enter a choice \n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
					printf("Enter the element to be inserted to the front end of the list \n");
					scanf("%d",&ele);
					last = add_front(last, ele);
					break;

			case 2:

					display(last);
					break;
			case 3:
					exit(0);

			case 4:
					printf("Enter an element to be added to the rear end of the list \n");
					scanf("%d",&ele);
					last = add_last(last, ele);
					break;

			case 5:
					last = delete_front(last);
					break;

			case 6:
					last = delete_last(last);
					break;

			case 7:
					split_into_two(last);
					break;

			case 8:
					printf("Enter the element to be inserted into the list \n");
					scanf("%d", &ele);
					last = insert_in_sorted_order(last, ele);
					break;

			default:

					printf("Please enter a right choice \n");
					break;
		}

	}
}