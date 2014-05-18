#include <stdio.h>
#include <stdlib.h>
#include "circular.h"

node_t add_front(node_t last, int ele)
{
	node_t temp = (node_t)malloc(sizeof(struct node));
	temp->ele = ele;

	if(last == NULL)
	{
		last =  temp;
	}

	else
	{
		temp->link = last->link;
	}

	last->link = temp;
	return last;
}

node_t add_last(node_t last, int ele)
{
	node_t temp = (node_t)malloc(sizeof(struct node));
	temp->ele = ele;

	if( last == NULL )
	{
		last = temp;
	}

	else
	{
		temp->link = last->link;
	}

	last->link = temp;
	return temp;
}

node_t delete_front(node_t last)
{
	if(last == NULL)
	{
		return (node_t)NULL;
	}

	else if(last->link == last)
	{
		free(last);
		return NULL;
	}

	else
	{
		node_t first = last->link;
		last->link = first->link;
		free(first);
		return last;
	}



}


node_t delete_last(node_t last)
{
	if(last == NULL)
	{
		printf("The list is empty \n");
		return NULL;
	}

	else if(last -> link == last)
	{
		free(last);
		return NULL;
	}

	else
	{
		node_t cur = last->link;

		while(cur->link == last)
		{
			cur = cur->link;
		}

		cur->link = last->link;
		free(last);
		return cur;
	}

}

void display(node_t last)
{
	if(last == NULL)
	{
		printf("The list is empty \n");
		return;
	}

	node_t temp = last->link;

	while(temp != last)
	{
		printf("%d\t",temp->ele);
		temp = temp -> link;
	}

	printf("%d\t",temp->ele);
	printf("\n");
}

void split_into_two(node_t last)
{

	if(last == NULL)
	{
		printf("The list is empty \n");
	}

	node_t head1 = last -> link;
	node_t hare = head1;
	node_t tortoise = head1;

	while(hare -> link != head1 && hare -> link -> link != head1)
	{
		hare = hare -> link -> link;
		tortoise = tortoise -> link;
	}

	printf("The middle element is %d \n", tortoise -> ele);
	//now the tortoise is the middle element and the `last` for the first list
	//the second head is the tortoise -> link

	node_t head2 = tortoise -> link;
	last -> link = head2;
	//make the first list circular

	tortoise -> link = head1;


	display(tortoise);
	display(last);

}

node_t insert_in_sorted_order(node_t last, int ele)
{
	node_t temp = (node_t)malloc(sizeof(struct node));
	temp -> ele = ele;

	if(last == NULL)
	{
		temp -> link = temp;
		return temp;
	}

	node_t head = last -> link;

	if(ele < head -> ele)
	{
		temp -> link = head;
		last -> link = temp;

		return last;
	}

	node_t current = head;
	node_t prev = NULL;

	while(current -> link != head && current -> ele < ele)
	{
		prev = current;
		current = current -> link;
	}

	if(current == last && current -> ele < ele)
	{
		//The node has to be inserted in the last position
		temp -> link = head;
		last -> link = temp;

		last = temp;
	}

	else
	{
		//The node is inserted somewhere in the middle of the list
		prev -> link = temp;
		temp -> link = current;
	}

	return last;
	

}

