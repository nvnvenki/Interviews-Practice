#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


node_t insert(node_t root, int ele)
{
	node_t temp = (node_t)malloc(sizeof(struct node));
	temp -> llink = NULL;
	temp -> rlink = NULL;
	temp -> ele = ele;

	if(root == NULL)
	{
		return temp;
	}

	node_t cur = root;
	node_t prev = NULL;


	while(cur != NULL)
	{
		prev = cur;

		cur = (ele < cur -> ele)?cur->llink:cur->rlink;
	}

	if(ele < prev -> ele)
	{
		prev -> llink = temp;
	}

	else
	{
		prev -> rlink = temp;
	}


	return root;
}


void display(node_t root)
{
	if(root != NULL)
	{
		printf("%d \t", root->ele);
		display(root -> llink);
		display(root -> rlink);
	}
}


node_t search(node_t root, int ele)
{
	while(root != NULL && ele != root->ele)
	{
		root = (ele < root->ele)?root->llink:root->rlink;
	}


	return root;
}


node_t find_highest(node_t root)
{
	if(root == NULL)
	{
		return root;
	}

	node_t cur = root;

	while(cur -> rlink != NULL)
	{
		cur = cur -> rlink;
	}

	return cur;
}


node_t find_lowest(node_t root)
{
	if(root == NULL)
	{
		return root;
	}

	node_t cur = root;

	while(cur -> llink != NULL)
	{
		cur = cur -> llink;
	}


	return cur;
}


int find_height(node_t root)
{
	if(root == NULL) return 0;

	return 1 + max(find_height(root->llink),find_height(root->rlink));
}


static int max(int a, int b)
{
	return a>b?a:b;
}


void find_count(node_t root, int* count)
{
	if(root != NULL)
	{
		find_count(root -> llink, count);
		*count = *count + 1;
		find_count(root -> rlink, count);
	}
}

void find_leaves(node_t root, int* count)
{
	if(root != NULL)
	{
		find_leaves(root -> rlink, count);

		if(root -> llink == NULL && root -> rlink == NULL)
		{
			*count = *count + 1;
		}

		find_leaves(root -> llink, count);
	}
}

node_t delete(node_t root, int ele)
{
	if(root == NULL)
	{
		return root;
	}
	node_t cur = root;
	node_t parent = NULL;
	node_t q = NULL;
	node_t suc = NULL;

	while(cur != NULL && cur -> ele != ele)
	{
		parent = cur;
		cur = (ele < cur -> ele)?cur->llink : cur->rlink;
	}

	if(cur == NULL)
	{
		printf("The element is not found in the tree \n");
		return root;
	}

	if(cur -> llink == NULL)
	{
		q = cur -> rlink;
	}

	else if(cur -> rlink == NULL)
	{
		q = cur -> llink;
	}


	else
	{
		suc = cur -> rlink;

		while(suc -> llink == NULL)
		{
			suc = suc -> llink;
		}

		suc -> llink = cur -> llink;

		q = cur -> rlink;

	}

	if(parent == NULL)
	{
		return q;
	}

	else if(cur == parent -> llink)
	{
		parent -> llink = q;
	}

	else
	{
		parent -> rlink = q;
	}


	return root;

}


int find_lca(node_t root, int value1, int value2)
{

	//While traversing the tree if you find a value inbetween that of value1 and value2 then that is the lca
	//This applies because of the fact that the tree we are traversing is a binary search tree
	if(root == NULL || root -> ele == value1 || root -> ele == value2)
	{
		return -1;
	}
	
	//If any of the input node is the child of the current node being traversed then the node being traversed becomes the least common ancestor in an obvious manner and this is done in the next two steps
	if(root -> llink != NULL && (root -> llink -> ele == value1 || root -> llink -> ele == value2))
	{
		return root -> ele;
	}

	if(root -> rlink != NULL && (root -> rlink -> ele == value1 || root -> rlink -> ele == value2))
	{
		return root -> ele;
	}

	//If you find any node whose value is in the middle of the two input nodes then that node is the lease common ancestor that is being traversed
	if( root -> ele > value1 && root->ele < value2)
	{
		return root -> ele;
	}

	//If the node being traversed has greater value than the two of the values that are entered then search for the ancestor in the left subtree
	if( root -> ele > value1 && root->ele > value2)
	{
		return find_lca(root -> llink , value1, value2);
	}

	//If the node being traversed has greater value than the two of the values that are enterd then search for the ancestor in the right subtree
	if( root -> ele < value1 && root->ele < value2)
	{
		return find_lca(root -> rlink , value1, value2);
	}


	
}







