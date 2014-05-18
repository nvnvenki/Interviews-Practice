#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node_t add_front(node_t head, int ele)
{
	node_t temp = (node_t)malloc(sizeof(struct node));
	temp -> llink = NULL;
	temp -> rlink = NULL;
	temp -> ele = ele;

	if(head == NULL)
	{
		return temp;
	}

	temp -> rlink = head;
	return temp;
	

}


node_t add_end(node_t head, int ele)
{
	node_t temp = (node_t)malloc(sizeof(struct node));
	temp -> llink = NULL;
	temp -> rlink = NULL;
	temp -> ele = ele;

	if(head == NULL)
	{
		return temp;
	}

	node_t current = head;

	while(current -> rlink != NULL)
	{
		current = current -> rlink;
	}


	current -> rlink = temp;
	temp -> llink = current;

	return head;


}


node_t delete_front(node_t head)
{
	if(head == NULL)
	{
		return head;
	}

	node_t temp = head;
	head = head -> rlink;
	free(temp);
	head -> llink = NULL;
	return head;
}


node_t delete_rear(node_t head)
{
	if(head == NULL)
	{
		return head;
	}

	if(head -> rlink == NULL)
	{
		free(head);
		return NULL;
	}

	else
	{
		node_t prev = NULL;
		node_t current = head;

		while( current -> rlink != NULL)
		{
			prev = current;
			current = current -> rlink;
		}

		prev -> rlink = NULL;
		free(current);
		return head; 
	}
}



void display(node_t head)
{

	if(head == NULL)
	{
		printf("The list is empty \n");
		return;
	}

	node_t temp = head;

	while(temp != NULL)
	{
		printf("%d \t", temp -> ele);
		temp = temp -> rlink;
	}

	printf("\n");
}

