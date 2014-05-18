#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


int main()
{
	node_t root = NULL;
	int choice;
	int ele;
	node_t highest = NULL;
	node_t lowest = NULL;
	int height = 0;
	int count = 0;
	int no_of_leaves = 0;
	int value1;
	int value2;
	int lca;

	while(1)
	{
		printf("----------------------------------------------------------------------------------------------\n");
		printf("1. Insert a node in the Binary search tree \n");
		printf("2. Display the tree in pre-order \n");
		printf("3. Exit \n");
		printf("4. Search iterative \n");
		printf("5. Find the address of the highest item in the BST \n");
		printf("6. Find the address of the lowest item in the BST \n");
		printf("7. Find the height of the tree \n");
		printf("8. Find the number of nodes in the tree \n");
		printf("9. Find the number of leaf nodes in the tree \n");
		printf("10. Delete a node from the tree \n");
		printf("11. Given two values in a tree(assuming that they are there) find the least common ancestor \n");
		printf("----------------------------------------------------------------------------------------------\n");

		printf("Enter the choice \n");
		scanf("%d", &choice);


		switch(choice)
		{
			case 1:
					printf("Enter the element to be inserted into the tree \n");
					scanf("%d", &ele);
					root = insert(root, ele);
					break;

			case 2:
					display(root);
					printf("\n");
					break;

			case 3:
					exit(0);

			case 4:
					printf("Enter the element to be searched in the tree \n");
					scanf("%d", &ele);

					if(search(root, ele) != NULL)
					{
						printf("The element is found in the tree \n");
					}

					else
					{
						printf("The element is not found in the tree \n");
					}
					break;

			case 5:
					highest = find_highest(root);

					if(highest != NULL)
					{	
						printf("The highest element in the tree is %d \n", highest->ele);
						break;
					}

					else
					{
						printf("The tree is empty");
					}

					break;


			case 6:
					lowest = find_lowest(root);

					if(lowest != NULL)
					{
						printf("The lowest element in the tree is %d \n", lowest -> ele);
						break;
					}

					else
					{
						printf("The tree is empty \n");
					}


					break;

			case 7:

					height = find_height(root);
					printf("The height of the tree is %d \n",height);
					break;

			case 8:
					count = 0;
					find_count(root, &count);
					printf("The number of nodes in the tree is %d \n", count);
					break;


			case 9:
					no_of_leaves = 0;
					find_leaves(root, &no_of_leaves);
					printf("The number of leaves in the tree are %d \n", no_of_leaves);
					break;

			case 10:
					printf("Enter the element that has to be delted from the tree \n");
					scanf("%d", &ele);
					root = delete(root, ele);
					break;

			case 11:
					printf("Enter the value 1 in the tree \n");
					scanf("%d", &value1);
					printf("Enter the value 2 in the tree \n");
					scanf("%d", &value2);
					lca = find_lca(root, value1, value2);
					printf("The least common ancestor of both the values is: %d \n", lca);
					break;



			default:
					printf("The choice you have entered is wrong. Please enter the right choice \n");
					break;

		}

	}

}