#include <stdio.h>
#include <stdlib.h>
#include "circular.h"

node_t add_front(node_t head, int ele)
{
	node_t temp = (node_t)malloc(sizeof(struct node));
	temp->ele = ele;
	temp->link = head->link;
	head->link = temp;
	head->ele += 1;
	return head;
}


node_t add_rear(node_t head, int ele)
{
	node_t temp = (node_t)malloc(sizeof(struct node));
	temp->ele = ele;
	node_t cur = head->link;

	while(cur->link != head)
	{
		cur = cur->link;
	}

	temp->link = cur->link;
	cur->link = temp;
	head->ele += 1;
	return head;
}

node_t delete_front(node_t head)
{
	if(head->link == head)
	{
		printf("The list is empty \n");
		return head;
	}

	else
	{
		node_t first = head->link;
		head->link = first->link;
		free(first);
		head->ele -= 1;
		return head;
	}
}

node_t delete_rear(node_t head)
{
	if(head->link == head)
	{
		printf("The list is empty \n");
		return head;
	}

	else
	{
		node_t prev = head;
		node_t cur = head->link;

		while(cur->link == head)
		{
			prev = cur;
			cur = cur->link;
		}

		prev->link = cur->link;
		free(cur);
		return head;

	}
}
void display(node_t head)
{
	if(head->link == head)
	{
		printf("The list is empty \n");
		return;
	}

	node_t temp = head->link;

	while(temp != head)
	{
		printf("%d\t",temp->ele);
		temp = temp->link;
	}

	printf("\n");
}