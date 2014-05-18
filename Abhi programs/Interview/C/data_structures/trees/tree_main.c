#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
	node_t root = NULL;



	int choice;
	int ele;
	int result = 0;
	node_t copy = NULL;
	node_t mirror_copy = NULL;
	int identical_flag = 0;
	int pathlen = 0;
	int path[1000];
	int is_BST;
	int children_sum  = 0;
	int diameter;



	while(1)
	{
		printf("---------------------------------------------------------------------------------------------\n");
		printf("1. Insert a node to the tree \n"); //Done
		printf("2. Pre order traversal of the tree \n"); //Done
		printf("3. Post order traversal of the tree \n"); //Done
		printf("4. In order traversal of the tree \n"); //Done
		printf("5. Exit \n"); //Done
		printf("6. Search for an item in the tree \n"); //Done
		printf("7. Delete an entire tree \n"); //Done
		printf("8. Create an exact copy of tree \n"); //Done
		printf("9. Find whether two trees are identical \n"); //Done
		printf("10. Create a mirror copy of the tree \n"); //Done
		printf("11. Print the path of the tree from root to every leaf \n"); //Done
		printf("12. Print the level order of the tree \n"); //Done
		printf("13. Check whether the tree is a binary search tree or not \n");
		printf("14. Print the level order of the tree in spiral form \n");
		printf("15. Check for children sum property in the binary tree \n");
		printf("16. Convert a given tree into a tree satisfying the children sum property \n");
		printf("17. Find the diameter of the tree \n");
		printf("---------------------------------------------------------------------------------------------\n");

		printf("Enter the choice \n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
						printf("Enter the element to be inserted into the tree \n");
						scanf("%d", &ele);
						root = insert_node(root, ele);
						break;
			
			case 2:
						pre_order(root);
						printf("\n");
						break;

		
			case 3:
						post_order(root);
						printf("\n");
						break;

			case 4:
						in_order(root);
						printf("\n");
						break;

			case 5:
						exit(0);

			case 6:
						printf("Enter the element to be searched \n");
						scanf("%d", &ele);
						search(root, ele, &result);
						if(result == 1)
						{
							printf("The element is  found \n");
						}

						else
						{
							printf("The element is not found in the tree \n");
						}

						break;

			case 7:
						root = delete_tree(root);
						break;

			case 8:
						copy = create_exact_copy(root);
						printf("The copy is created and the post order of the new copy looks like this \n");
						post_order(copy);
						printf("\n");
						break;

			case 9:
						identical_flag = find_whether_identical(root, copy);

						if(identical_flag != 0)
						{
							printf("They are identical to one another \n");
						}

						else
						{
							printf("They are nor identical \n");
						}

						break;

			case 10:
						mirror_copy = create_mirror_copy(root);
						printf("The mirror copy of the tree has been created and its post order traversal looks like this \n");
						post_order(mirror_copy);
						printf("\n");
						break;

			case 11:
						print_path_rootToLeaves(root, path, pathlen);
						break;

			case 12:
						printf("The level order of the tree is as follows \n");
						print_level_order(root);
						printf("\n");
						break;

			case 13:
						is_BST = my_isBst(root);
						if(is_BST == 1)
						{
							printf("The tree is a binary search tree \n");

						}

						else
						{
							printf("The tree is not a binary search tree \n");
						}

						break;

			case 14:
						print_level_order_spirally(root);
						printf("\n");
						break;

			case 15:
						 children_sum = check_children_sum_property(root);
						 printf("The children sum property satisfied??: %d \n", children_sum);
						 break;

			case 16:
						convert_to_children_sum(root);
						break;

			case 17:
						diameter = find_diameter(root);
						printf("The diameter of the tree os %d \n", diameter);
						break;



			default:
						printf("You have a wrong choice which is entered..Please enter a right one! \n");
						break;

		}


	}
}
