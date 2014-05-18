#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	node_t head = NULL;
	node_t first = NULL;
	node_t second = NULL;
	node_t merged = NULL;
	int choice = 0;
	int ele;
	int pos;
	node_t node_pointer = NULL;
	int n;
	int is_cycle = 0;
	node_t list_cycle = NULL;
	int isPalindrome = 0;
	int intersection = 0;
	node_t resultant_of_addition = NULL;
	int k = 0;
	int m;


	while(1)
	{
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("1. Add node in the front end \n");
		printf("2. Display the list \n");
		printf("3. Exit \n");
		printf("4. Add node at the rear end of the list \n");
		printf("5. Delete a node at the front end of the list \n");
		printf("6. Delete a node from the rear end of the list \n");
		printf("7. Insert a node in order to the list \n");
		printf("8. Merge two ordered linked lists \n");
		printf("9. Search for an item in the list \n");
		printf("10. Delete a node whose value is specified \n");
		printf("11. Delete a node at the specified position \n");
		printf("12. Reverse  list wihtout creating extra nodes \n");
		printf("13. Delete a node given only a pointer to the node \n");
		printf("14. Print middle element of the list \n");
		printf("15. Print the nth last element in the list \n");
		printf("16. Delete the entire list \n");
		printf("17. Detect a loop in the list \n");
		printf("18. Check whether a list is a palindrome \n");
		printf("19. Find the intersection of two lists \n");
		printf("20. Print reverse recursively \n");
		printf("21. Remove duplicates in a sorted linked list \n");
		printf("22. Move the last node in the list to the first node \n");
		printf("23. Reverse the list pairwise \n");
		printf("24. Find the intersection of two lists recursively \n");
		printf("25. Delete alternate nodes in the list \n");
		printf("26. Alternating split of the list \n");
		printf("27. Delete nodes whose neighbours value is greater \n");
		printf("28. Sepearate into even and odd in that order \n");
		printf("29. Add two lists and give the resultant list \n");
		printf("30. Rotate the list by k elements \n");
		printf("31. Separate into 0s and 1s \n");
		printf("32. Delete n nodes after the first m nodes \n");
		printf("-------------------------------------------------------------------------------------------------------\n");

		printf("Enter the choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:

					printf("Enter the element to enter to the front end of the list \n");
					scanf("%d", &ele);
					head = add_front(head, ele);
					break;

			case 2:
					display(head);
					break;

			case 3:
					exit(0);

			case 4:
					printf("Enter an element to be added to the end of the list \n");
					scanf("%d", &ele);
					head = add_end(head, ele);
					break;

			case 5:
					head = delete_front(head);
					break;

			case 6:
					head = delete_rear(head);
					break;

			case 7:
					printf("Enter the element to be inserted \n");
					scanf("%d", &ele);
					head = insert_in_order(head, ele);
					break;

			case 8:

					first = insert_in_order(first, 92);
					first = insert_in_order(first, 42);
					first = insert_in_order(first, 35);

					second = insert_in_order(second, 100);
					second = insert_in_order(second, 432);
					second = insert_in_order(second, 90);
					second = insert_in_order(second, 10);


					printf("The elements of the first list are: \n");
					display(first);

					printf("The elements of the second list are \n");
					display(second);

					merged = merge_ordered_lists(first, second);
					printf("The ordered list is: \n");
					display(merged);

			case 9:
					printf("Enter the element of the list to be searched for \n");
					scanf("%d", &ele);
					int pos = search(head, ele);
					if(pos != -1)
					{
						printf("The element is found at %d: \n", pos);
					}
					else
					{
						printf("The element is not found in the list \n");
					}

					break;

			case 10:
					printf("Enter the element of the list to be deleted: \n");
					scanf("%d", &ele);
					head = delete_with_info(head, ele);

					if(head == (node_t)NULL)
					{
						printf("The list is empty or the element u specified is not found: \n");
					}
					break;

			case 11:
					printf("Enter the position with the first node as position 1 \n");
					scanf("%d", &ele);
					head = delete_with_pos(head, ele);

					if(head == (node_t)NULL)
					{
						printf("Either the list is empty or the position specified is not appropriate \n");
					}

					break;

			case 12:

					head = reverse(head);
					break;

			case 13:
					node_pointer = head -> link -> link;
					delete_node_given_pointer(node_pointer);
					break;

			case 14:
					 print_middle(head);
					 break;

			case 15:
					printf("Enter the value of n \n");
					scanf("%d",&n);
					print_nth_last(head, n);
					break;

			case 16:
					head = delete_list(head);
					break;

			case 17:

					list_cycle = add_end(list_cycle,1);
					list_cycle = add_end(list_cycle,2);
					list_cycle = add_end(list_cycle,3);
					list_cycle = add_end(list_cycle,4);
					list_cycle = add_end(list_cycle,5);
					list_cycle -> link -> link -> link -> link -> link = list_cycle -> link;
					is_cycle = find_cycle(list_cycle);
					if(is_cycle)
					{
						printf("There is a cycle in the list \n");

					}

					else
					{
						printf("There is no cycle in the list \n");
					}



					break;

			case 18:

					isPalindrome = is_palindrome(&head, head);
					if(isPalindrome)
					{
						printf("The list is a palindrome \n");
					}

					else
					{
						printf("The list is not a palindrome \n");
					}
					break;

			case 19:

					first = add_end(first,10);
					first = add_end(first,20);
					


					second = add_end(second,43);
					second = add_end(second,3);
					second = add_end(second,34);
					second = add_end(second,44);

					first -> link -> link = second -> link;


					intersection = find_intersection(first, second);
					printf("The intersection point of the two lists are %d \n", intersection);
					break;

			case 20:
					print_reverse_recursively(head);
					printf("\n");
					break;

			case 21:

					remove_duplicates(head);
					break;

			case 22:

					head = move_last_to_first(head);
					break;

			case 23:

					head = pairwise_reverse(head);
					break;

			case 24:

					first = add_end(first, 10);
					first = add_end(first, 30);
					first = add_end(first, 40);
					first = add_end(first, 50);
					first = add_end(first, 60);


					second = add_end(second, 10);
					second = add_end(second, 20);
					second = add_end(second, 30);


					find_common_recursively(first, second);
					break;

			case 25:
					head = delete_alternate(head);
					break;

			case 26:
					 alternating_split_v2(head);
					 break;

			case 27:
					head = delete_node_when_neigbour_higher(head);
					break;

			case 28:
					head = separate_into_even_odd_v2(head);
					break;

			case 29:
						first = add_front(first, 2);
						first = add_front(first, 4);
						first = add_front(first, 8);


						second = add_front(second,2);
						second = add_front(second,4);
						second = add_front(second,5);
						second = add_front(second,3);

						resultant_of_addition = add_two_lists(first, second);

						printf("The resultant list is as follows \n");
						display(resultant_of_addition);

						break;	

			case 30:
					printf("Enter the value of k \n");
					scanf("%d",&k);
					head = rotate_by_k(head, k);
					break;

			case 31:
					head = separate_into_zeroes_ones(head);
					break;

			case 32:
					printf("Enter the value of m \n");
					scanf("%d", &m);
					printf("Enter the value of n \n");
					scanf("%d", &n);
					head = retain_m_delte_n(head, m , n);
					break;



			default:
					printf("Invalid choice... Please try again \n");
					break;

		}

	}
}