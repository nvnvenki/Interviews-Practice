#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <string.h>

node_t insert_node(node_t root, int ele)
{
	node_t temp = (node_t)malloc(sizeof(struct node));
	temp -> llink = NULL;
	temp -> rlink = NULL;
	temp -> ele = ele;
	char directions[10];
	int i = 0;

	if(root == NULL)
	{
		return temp;
	}

	printf("Enter the directions to enter the node in the tree \n");
	scanf("%s",directions);
	node_t cur = root;
	node_t prev = NULL;


	for(i = 0; i < strlen(directions) && cur != NULL ; i++)
	{
		prev = cur;

		if(directions[i] == 'L')
		{
			cur = cur -> llink;
		}

		else
		{
			cur = cur -> rlink;
		}
	}

	if(cur != NULL && i != strlen(directions))
	{
		printf("The node cant be inserted \n");
		free(temp);
		return root;
	}

	if(directions[i-1] == 'L')
	{
		prev -> llink = temp;
	}

	else
	{
		prev -> rlink = temp;
	}


	return root;

}



void pre_order(node_t root)
{
	if(root!=NULL)
	{
		printf("%d \t", root -> ele);
		pre_order(root -> llink);
		pre_order(root -> rlink);
	}

}


void post_order(node_t root)
{
	if(root!=NULL)
	{
		post_order(root -> llink);
		post_order(root -> rlink);
		printf("%d \t", root -> ele);

	}


}


void in_order(node_t root)
{
	if(root != NULL)
	{
		in_order(root -> llink);
		printf("%d \t", root -> ele);
		in_order(root -> llink);
	}

}


void search(node_t root, int ele, int* flag)
{
	if(root != NULL)
	{
		search(root -> llink, ele, flag);
		search(root -> rlink, ele, flag);
		if(root -> ele == ele)
		{
			*flag = 1;
			return;
		}
	}

}


node_t delete_tree(node_t root)
{
	//Why is the post order traversal done here
	//First we have to delete the children before deleting the parent
	if(root != NULL)
	{
		node_t curr = root;

		if(curr -> llink != NULL)
		{
			delete_tree(curr -> llink);
		}

		if(curr -> rlink != NULL)
		{
			delete_tree(curr -> rlink);
		}

		free(curr);
		root = NULL;
	}

	return root;
	
		
}


node_t create_exact_copy(node_t root)
{

	if(root == NULL)
	{
		return NULL;
	}

	node_t temp;
	temp = (node_t)malloc(sizeof(struct node));

	temp -> ele = root -> ele;
	temp -> llink = create_exact_copy(root -> llink);
	temp -> rlink = create_exact_copy(root -> rlink);

	return temp;

}


int find_whether_identical(node_t first, node_t second)
{
	if( first == NULL && second == NULL)
	{
		return 1;
	}

	else if(first != NULL && second != NULL)
	{
		return( first -> ele && second -> ele && find_whether_identical(first -> llink, second -> llink) && find_whether_identical(first->rlink ,second -> rlink));  
	}

	else
	{
		return 0;
	}
}



node_t create_mirror_copy(node_t root)
{
	if(root == NULL)
	{
		return NULL;
	}

	else
	{
		node_t temp;

		create_mirror_copy(root -> llink);
		create_mirror_copy(root -> rlink);
		temp = root -> llink;
		root -> llink = root -> rlink;
		root -> rlink = temp;

		return temp;
	}


}


void print_path_rootToLeaves(node_t root, int* path, int pathlen)
{
	if(root == NULL)
	{
		return;
	}

	path[pathlen] = root -> ele;
	pathlen = pathlen + 1;

	if(root -> llink == NULL && root -> rlink == NULL)
	{
		print_array(path, pathlen);
	}

	else
	{
		print_path_rootToLeaves(root -> llink, path, pathlen);
		print_path_rootToLeaves(root -> rlink, path, pathlen);
	}

}


static void print_array(int* array, int len)
{
	int i = 0;

	for(i = 0 ; i < len ; i++)
	{
		printf("%d\t",array[i]);
	}

	printf("\n");
}



static int  max(int a , int b)
{
	return a>b?a:b;
}


int height(node_t root)
{
	if(root == NULL)
	{
		return 0;
	}


	return 1 + max(height(root -> llink), height(root->rlink));
}


void print_level_order(node_t root)
{
	if(root == NULL)
	{
		return;
	}


	int h  = height(root);
	int i = 1;

	for(i = 1; i <=h ; i++)
	{
		print_each_level(root, i);
	}
}

static void print_each_level(node_t root, int level)
{


	if(root == NULL)
	{
		return;
	}

	if(level == 1)
	{
		printf("%d \t", root->ele);
	}

	else
	{
		print_each_level(root -> llink, level-1);
		print_each_level(root -> rlink, level -1);
	}



}


int isBST(node_t root)
{

	static struct node *prev = NULL;
     
    // traverse the tree in inorder fashion and keep track of prev node
    if (root)
    {
        if (!isBST(root->llink))
          return 0;
 
        // Allows only distinct valued nodes 
        if (prev != NULL && root->ele <= prev->ele)
          return 0;
 
        prev = root;
 
        return isBST(root->rlink);
    }
 
    return 1;
}

void print_level_order_spirally(node_t root)
{
	int h = height(root);
	int rtl = 0;
	int i = 1;

	for(i = 1; i <= h; i++)
	{
		print_each_level_spirally(root, i, rtl);
		rtl = (!rtl);
	}
}


static void  print_each_level_spirally(node_t root, int level, int rtol)
{
	if(root == NULL)
	{
		return;
	}

	if(level == 1)
	{
		printf("%d \t", root -> ele);
	}
	else
	{
		if(rtol)
		{
			print_each_level_spirally(root->rlink, level-1, rtol);
			print_each_level_spirally(root->llink, level-1, rtol);
		}

		else
		{
			print_each_level_spirally(root->llink, level-1, rtol);
			print_each_level_spirally(root -> rlink, level-1, rtol); 
		}
	}

}

int check_children_sum_property(node_t root)
{
	int left_int = 0;
	int right_int = 0;

	if(root == NULL || (root -> llink == NULL && root -> rlink == NULL) )
	{
		return 1;
	}

	else
	{
		if(root -> llink != NULL)
		{
			left_int = root -> llink -> ele;
		}

		if(root -> rlink != NULL)
		{
			right_int = root -> rlink -> ele;
		}

		if(root->ele == left_int + right_int && check_children_sum_property(root -> llink) && check_children_sum_property(root -> rlink))
		{
			return 1;
		}

		else
		{
			return 0;
		}

	}

	return 1;

}

void convert_to_children_sum(node_t root)
{
	int left_int = 0;
	int right_int = 0;

	if(root == NULL || (root -> rlink == NULL && root -> llink == NULL))
	{
		return;
	}

	else
	{
		//Follow the post order traversal and visit the left and the right subtrees recursively
		//If the sum of the two children is equal to their parents node then dont do anything
		// If either of them dont exist then their nodes value is considered as zero
		// If the difference is greater thean zero then increment their parents value by the difference
		// If the difference is less than zero:
		// 	Consider the left subtree of their parent and recursively increment their values to satisfy the difference rule
		//  If the left subtree of their parent is null then recursively increment the right subtree's value to satisfy the difference value

		convert_to_children_sum(root -> llink);
		convert_to_children_sum(root -> rlink);


		if(root -> llink != NULL)
		{
			left_int = root -> llink -> ele;
		}

		if(root -> rlink != NULL)
		{
			right_int = root -> rlink -> ele;
		}


		int difference = (left_int + right_int) - root -> ele;

		if(difference > 0)
		{
			root -> ele = root -> ele + difference;
		}

		if(difference < 0)
		{
			increment(root, -difference);
		}


	}
}


static void increment(node_t root, int difference)
{

	if(root -> llink != NULL)
	{
		root -> llink -> ele = root -> llink -> ele + difference;

		increment(root -> llink, difference);
	}


	else if(root -> rlink != NULL)
	{
		root -> rlink -> ele = root -> rlink -> ele + difference;

		increment(root -> rlink, difference);
	}

}


int find_diameter(node_t root)
{
	//The diameter is defined as the logest path that can be found along two leaves in the tree
	// The diameter of the tree can be found by finding out the heigh of the tree
		/*
			1. Find the left height of the tree
			2. Find the right height of the tree
			3. Find the diameter of the tree through the root node of the tree
			4. Calculate maximum(left height+right height+1, maximum(left diameter, right_diameter))
		*/

			if(root == NULL)
			{
				return 0;
			}

			int left_height = height(root -> llink);
			int right_height = height(root -> rlink);

			int left_dia = find_diameter(root -> llink);
			int right_dia = find_diameter(root -> rlink);

			return max(left_height+right_height+1, max(left_dia,right_dia));

}

int my_isBst(node_t root)
{

	/*
	This is also perfectly working
	Yaay :p
	*/

	
	if(root == NULL)
	{
		return 1;
	}

	else if(root -> llink == NULL && root -> rlink != NULL)
	{
		if ( (root -> ele) < (root -> rlink -> ele) )
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}

	else if(root -> rlink == NULL && root -> llink != NULL)
	{
		if( (root -> ele) > (root -> llink -> ele))
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}

	else if(root -> rlink == NULL && root -> rlink == NULL)
	{
		return 1;
	}

	else
	{
		if( ((root -> ele) > (root -> llink -> ele)) && ((root -> ele) < (root -> rlink -> ele)) )
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}

	return my_isBst(root -> llink);
	return my_isBst(root -> rlink);

}

