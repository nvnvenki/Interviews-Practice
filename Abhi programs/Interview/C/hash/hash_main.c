#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main()
{
	//this is the head node that contains the information such as the number of nodes that are currently present in the cache
	//this is necessary because we require the cache to be of limited size

	node_t head = (node_t)malloc(sizeof(struct node));
	head -> ele = 0;
	head -> link = NULL;


	node_t list_of_pointers[HASH_LENGTH];

	//initialise the list of pointers with the head node
	initialise_hash(list_of_pointers);

	node_t cache = create_cache();


	cache = reference_page(list_of_pointers,cache, 10);
	cache = reference_page(list_of_pointers,cache, 20);
	cache = reference_page(list_of_pointers,cache, 30);
	cache = reference_page(list_of_pointers,cache, 40);
	cache = reference_page(list_of_pointers,cache, 50);
	display(cache);
	cache = reference_page(list_of_pointers,cache, 10);
	display(cache);
	cache = reference_page(list_of_pointers,cache, 60);
	display(cache);




	
}