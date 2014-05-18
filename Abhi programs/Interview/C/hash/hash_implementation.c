#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

node_t add_front(node_t head, int ele)
{
	node_t temp = (node_t)malloc(sizeof(struct node));
	temp -> ele = ele;

	temp -> link = head -> link;
	head -> link = temp;
	head -> ele = head -> ele + 1;

	return head;
}

node_t add_end(node_t head, int ele)
{
	node_t temp = (node_t)malloc(sizeof(struct node));
	temp -> ele = ele;
	temp -> link = NULL;

	node_t traversal = head;

	while(traversal -> link != NULL)
	{
		traversal = traversal -> link;
	}

	traversal -> link = temp;
	head -> ele = head -> ele + 1;

	return head;

}

node_t delete_rear(node_t head)
{
	if(head -> link == NULL)
	{
		return head;
	}

	node_t cur = head;
	node_t prev = NULL;

	while(cur -> link != NULL)
	{
		prev = cur;
		cur = cur -> link;
	}

	prev -> link = cur -> link;
	cur -> link = NULL;
	free(cur);
	head -> ele  = head -> ele - 1;
	return head;
}

void display(node_t head)
{
	printf("--------------------------------------------------------------------------------------------------------------\n");

	node_t temp = head -> link;

	while(temp != NULL)
	{
		printf("%d \t", temp -> ele);
		temp = temp -> link;
	}

	printf("\n");

	printf("--------------------------------------------------------------------------------------------------------------\n");

}

void initialise_hash(node_t* hash_array)
{
	int i = 0;
	for(i = 0; i < HASH_LENGTH; i++)
	{
		node_t head = (node_t)malloc(sizeof(struct node));
		head -> ele = 0;
		head -> link = NULL;
		hash_array[i] = head;
	}
}

int hash_function(int page_number)
{
	return page_number % HASH_LENGTH;
}

node_t insert_in_table(node_t head, int ele)
{
	head = add_end(head, ele);
	return head;
}


int search(int page_number, node_t head)
{

	node_t temp = head;

	if(temp -> link == NULL)
	{
		return -1;
	}
	temp = temp -> link;

	while(temp != NULL)
	{
		if(temp -> ele == page_number)
		{
			return 1;
		}
		temp = temp -> link;
	}

	return -1;
}


node_t create_cache()
{
	node_t head = (node_t)malloc(sizeof(struct node));
	head -> ele = 0;
	head -> link = NULL;
	return head;
}

/*
	- The page number is searched for in the cache
	- If it is found in the cache then it is returned that the page is found in the cache and detach the node and bring it to the front end of the queue
	- If it is not found then it is added to the front end of the queue and also
	- Add the page number to the hash table
	- If it is not there in the cache and the cache is full delete the node at the end and then add the page number to the front end of the queue and update the hash


*/
node_t reference_page(node_t* hash, node_t head, int page_number)
{
	int search_result = search(page_number, head);

	if(search_result != -1)
	{
		//The page is found in the cache
		printf("There has been a cache hit \n");
		head = remove_and_bring_front(head, page_number);
	}

	else
	{
		printf("There is no cache hit \n");
		//The page is not found in the cache
		if(head -> ele == LRU_SIZE)
		{
			printf("The cache is full \n");
			head = delete_rear(head);
			head = add_front(head, page_number);
		}

		else
		{
			//Add the page to the front end of the queue and
			printf("Adding the page to the front end of the queue \n");
			head = add_front(head, page_number);
		}

	}

	return head;
}

static node_t remove_and_bring_front(node_t head, int page_number)
{
	if(head -> link == NULL)
	{
		return head;
	}


	node_t prev = NULL;
	node_t cur = head;

	while(cur -> link != NULL && cur -> ele != page_number)
	{
		prev = cur;
		cur = cur -> link;
	}

	prev -> link = cur -> link;
	cur -> link = head -> link;
	head -> link = cur;

	return head;

}
