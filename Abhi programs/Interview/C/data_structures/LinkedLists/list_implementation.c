#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node_t add_front(node_t head, int ele)
{
	node_t temp = (node_t)malloc(sizeof(struct node));
	temp->value = ele;
	temp->link = head;
	return temp;
}


node_t add_end(node_t head, int ele)
{

	node_t temp = (node_t)malloc(sizeof(struct node));
	temp->value = ele;
	temp->link = NULL;

	if(head == NULL)
	{
		return temp;
	}

	else
	{
		node_t cur = head;
		while(cur->link != NULL)
		{
			cur = cur->link;
		}

		cur->link = temp;

		return head;
	}
}

node_t delete_front(node_t head)
{
	if(head==NULL)
	{
		printf("The list is empty \n");
		return head;
	}
	else
	{
		node_t temp;
		temp = head;
		head = head->link;
		free(temp);
		return head;
	}
}

node_t delete_rear(node_t head)
{
	if(head == NULL)
	{
		printf("The list is empty \n");
		return head;
	}

	else if(head->link == NULL)
	{
		free(head);
		head = NULL;
		return head;
	}

	node_t prev = NULL;
	node_t cur = head;

	while(cur->link != NULL)
	{
		prev = cur;
		cur = cur->link;
	}

	prev->link = NULL;
	free(cur);
	return head;

}


node_t insert_in_order(node_t head, int ele)
{
	node_t temp = (node_t)malloc(sizeof(struct node));
	temp->value = ele;
	temp->link = NULL;

	if(head == NULL)
	{
		return temp;
	}

	else if(ele <= head->value)
	{
		temp->link = head;
		return temp;
	}

	node_t cur = head;
	node_t prev = NULL;

	while(cur != NULL && ele >= cur->value)
	{
		prev = cur;
		cur = cur->link;
	}

	prev->link = temp;
	temp->link = cur;

	return head;


}

node_t merge_ordered_lists(node_t first, node_t second)
{
	node_t i;
	node_t j;
	node_t c;
	node_t k;
	

	i = first;
	j = second;
	c = k = (node_t)malloc(sizeof(struct node));

	while(i != NULL && j!= NULL)
	{
		if( i->value < j->value)
		{
			k->link = i;
			i = i->link;
		}


		else
		{
			k->link = j;
			j = j->link;
		}

		k = k->link;
	}

	if(i != NULL)
	{
		k->link = i;
	}

	else
	{
		k->link = j;
	}

	return c->link;

}

int search(node_t head, int ele)
{

	if(head == NULL)
	{
		printf("The list is empty");
		return -1;
	}

	node_t temp = head;
	int pos = 1;

	while(temp != NULL && temp->value != ele)
	{
			temp = temp->link;
			pos = pos+1;
	}

	if(temp == NULL)
	{
		return -1;
	}

	else
	{
		return pos;
	}


}

node_t delete_with_info(node_t head , int ele)
{
	if(head == NULL)
	{
		return (node_t)NULL;
	}

	if(head->value == ele)
	{
		node_t temp = head;
		head = head-> link;
		free(temp);
		return head;
	}

	node_t prev = NULL;
	node_t cur = head;

	while(cur != NULL && cur->value != ele)
	{
		prev = cur;
		cur = cur -> link;
	}

	if(cur == NULL)
	{
		return (node_t)NULL;
	}

	else
	{
		prev->link = cur->link;
		free(cur);
		return head;
	}
}

node_t delete_with_pos(node_t head , int ele)
{
	if(head == NULL)
	{
		return (node_t)NULL;
	}

	if(ele == 1)
	{
		node_t temp = head;
		head = head->link;
		free(temp);
		return head;
	}

	node_t prev = NULL;
	node_t cur = head;
	int count = 1;

	while(cur != NULL && ele != count)
	{
		prev = cur;
		cur = cur->link;
		count++;
	}

	if(cur == NULL)
	{
		return (node_t)NULL;
	}

	else
	{
		prev->link = cur->link;
		free(cur);
		return head;
	}


}


node_t reverse(node_t head)
{
	node_t temp;
	node_t cur = NULL;

	while(head != NULL)
	{
		temp = head;
		head = head->link;
		temp->link = cur;
		cur = temp;
	}


	return cur;
}
void display(node_t head)
{
	if(head == NULL)
	{
		printf("The list is empty \n");
	} 

	node_t temp = head;

	while(temp != NULL)
	{
		printf("%d \t", temp->value);
		temp = temp->link;
	}
	printf("\n");
}

void delete_node_given_pointer(node_t node_pointer)
{
	if(node_pointer == NULL)
	{
		printf("There is no pointer that is passed \n");
		return;
	}


	if(node_pointer -> link != NULL)
	{
		node_t next = node_pointer -> link;
		node_pointer -> value = next -> value;
		node_pointer -> link = next -> link;
		free(next);

	}

	else
	{
		printf("The last node deletion is not possible with this \n");
		return;
	}
}


void print_middle(node_t head)
{
	node_t temp = head;
	node_t middle = head;
	int count = 0;
	
	while(temp != NULL)
	{
		if( count & 1 )
		{
				middle = middle -> link;
		}

		count ++;
		temp = temp -> link;
	}


	printf("the middle element of the list is %d \n", middle->value);

}


void print_nth_last(node_t head, int n)
{
	int count = count_nodes(head);

	if(n > count || n == 0)
	{
		printf("You can find no such node in this list moron! \n");
		return;
	}

	else
	{
		node_t forward = head;
		node_t nthlast = head;
		int i = 1;

		for(i = 1; i <= n; i++)
		{
			forward = forward -> link;
		}

		while(forward != NULL)
		{
			nthlast = nthlast -> link;
			forward = forward -> link;
		}

		printf("The nth last node is %d \n", nthlast -> value);

	}
}


static int count_nodes(node_t head)
{
	node_t temp = head;
	int count = 0;

	while(temp != NULL)
	{
		temp = temp -> link;
		count++;
	}

	return count;
}


node_t delete_list(node_t head)
{
	if(head == NULL)
	{
		return head;
	}

	else
	{
		node_t temp = head;
		node_t next = NULL;
		
		while(temp != NULL)
		{
				next = temp -> link;
				free(temp);
				temp = next;
		}

		head = NULL;
		return NULL;
	}
}


int find_cycle(node_t head)
{
	//This is called as floyds cycle finding algorithm
	//If the forward and previous pointers meet at some point then the cycle is found
	node_t forward = head;
	node_t previous = head;

	while(forward != NULL && previous != NULL && forward->link != NULL)
	{
		forward = forward -> link -> link;
		previous = previous -> link;

		if(forward == previous)
		{
			remove_loop(forward,head);
			return 1;
		}
	}

	return 0;
}

int is_palindrome(node_t* left, node_t right)
{
	if(!right)
	{
		return 1;
	}

	int is_true = is_palindrome(left, right->link);

	if(is_true == 0)
	{
		return 0;
	}

	int is_tr = (right -> value == (*left)-> value);
	*left = (*left) -> link;

	return is_tr;
}



int find_intersection(node_t first, node_t second)
{
	int c1 = count_nodes(first);
	int c2 = count_nodes(second);
	int d = 0;
	int intersection = 0;
	
	if(c1 < c2)
	{
		d = c2 - c1;
		intersection = get_intersection(d, second, first);
	}

	else if(c1 > c2)
	{

		d = c1 - c2;
		intersection = get_intersection(d, first, second);

	}

	return intersection;


}

static int get_intersection(int diff, node_t first, node_t second)
{

	int i = 0;
	node_t temp1 = first;
	node_t temp2 = second;

	for(i = 0; i < diff ; i++)
	{
		if(temp1 == NULL)
		{
			return -1;
		}

		temp1 = temp1 -> link;
	}

	while(temp1 != NULL && temp2 != NULL)
	{
		if(temp1 -> value == temp2 -> value)
		{
			return temp1 -> value;
		}

		temp1 = temp1 -> link;
		temp2 = temp2 -> link;
	}

	return -1;
}


void print_reverse_recursively(node_t head)
{
	if(head == NULL)
	{
		return;
	}

	print_reverse_recursively(head -> link);

	printf("%d \t",head -> value);

}

void remove_duplicates(node_t head)
{
	node_t cur = head;
	node_t next = NULL;


	if(head == NULL)
	{
		return;
	}

	while(cur -> link != NULL)
	{
		if(cur -> value == cur -> link -> value)
		{
			next = cur -> link -> link;
			free(cur -> link);
			cur -> link = next;
		}

		else
		{
			cur = cur -> link;
		}
	}
}


node_t move_last_to_first(node_t head)
{
	if(head == NULL)
	{
		printf("The list is empty \n");
		return head;
	}

	else if(head -> link == NULL)
	{
		return head;
	}


	else
	{
		node_t prev = NULL;
		node_t cur = head;

		while(cur -> link != NULL)
		{
			prev = cur;
			cur = cur -> link;
		}

		prev -> link = NULL;
		cur -> link = head;
		head = cur;
		return head;


	}
}

node_t pairwise_reverse(node_t head)
{
	if(head == NULL)
	{
		return NULL;
	}

	node_t temp = head;
	
	while(temp != NULL && temp -> link != NULL)
	{
		swap(&temp -> value , &temp -> link -> value);
		temp = temp -> link -> link;
	}

	return head;

}

static void swap(int* a , int* b)
{
	int temp = *a;
	*a = *b; 
	*b = temp;
}

void find_common_recursively(node_t first, node_t second)
{
	node_t temp1 = first;
	node_t temp2 = second;
	node_t temp3 = NULL;
	__find_common_recursively_utility(temp1, temp2, temp3);
}

static void __find_common_recursively_utility(node_t temp1, node_t temp2, node_t temp3)
{
	if(temp1 == NULL || temp2 == NULL)
	{
		return;
	}

	
	if(temp1 -> value == temp2 -> value)
	{
		
		temp3 = add_front(temp3, temp1 -> value);
		display(temp3);
		__find_common_recursively_utility(temp1 -> link, temp2 -> link,temp3);
	}

	else if(temp1 -> value < temp2 -> value)
	{
		__find_common_recursively_utility(temp1 -> link , temp2, temp3);
	}

	else if(temp1 -> value > temp2 -> value)
	{
		__find_common_recursively_utility(temp1, temp2 -> link, temp3);
	}
	
}


node_t delete_alternate(node_t head)
{
	if(head == NULL)
	{
		return head;
	}

	node_t prev = head;
	node_t temp = head -> link;

	while(prev != NULL && temp != NULL)
	{
		prev -> link = temp -> link;
		free(temp);
		prev = prev -> link;

		if(prev != NULL)
		{
			temp = prev -> link;
		}
	}

	return head;
}


void alternating_split(node_t head)
{
	if(head == NULL)
	{
		return;
	}

	node_t temp = head;
	node_t first = NULL;
	node_t second = NULL;
	int count = 1;

	while(temp != NULL)
	{
		if(count & 1)
		{
			second = add_end(second, temp -> value);
		}

		else
		{
			first = add_end(first, temp -> value);
		}

		count = count +1;
		temp = temp -> link;
	}

	printf("The first split is \n");
	display(first);
	printf("The second split is \n");
	display(second);

}


node_t delete_node_when_neigbour_higher(node_t head)
{
	if(head == NULL)
	{
		return head;
	}	

	node_t current = head;
	node_t next = NULL;

	while(current -> link != NULL)
	{
		if(current -> value < current -> link -> value)
		{
			
			//This is same as gven a pointer to a node delete the node
			//became useful here
			node_t next = current -> link;
			current -> value = next -> value;
			current -> link = next -> link;
			free(next);
			
		}

		else
		{
			current = current -> link;
		}
	}

	return head;

}


node_t separate_into_even_odd(node_t head)
{
	if(head == NULL)
	{
		return head;
	}

	node_t last = head;
	node_t temp = head;
	node_t next;

	while(last -> link != NULL)
	{
		last = last -> link;
	}


	while(temp != last)
	{
		if( (temp -> value %2) != 0)
		{
			last = add_end(last, temp-> value);
			next = temp -> link;
			temp -> value = next -> value;
			temp -> link = next -> link;
			free(next);
		}

		temp = temp -> link;
	}


	return head;

}

static void remove_loop(node_t loop_node, node_t head)
{
	int count = 1;
	node_t first = loop_node;
	node_t second = loop_node;

	while(first -> link != second)
	{
		first = first -> link;
		count++;

	}

	first = head;
	second = head;

	int i = 0;

	for(i = 0; i < count; i++)
	{
		second = second -> link;
	}


	while(second != first)
	{
		second = second -> link;
		first = first -> link;
	}

	second = second -> link;

	while(second -> link != first)
	{
		second = second -> link;
	}


	second -> link = NULL;

	printf("The loop has been removed \n");
	int is_cycle = find_cycle(head);
	if(is_cycle)
	{
		printf("There is a loop in the list \n");
	}

	else
	{
		printf("There is no loop in the list \n");
	}
}


node_t add_two_lists(node_t first,node_t second)
{
	node_t temp = NULL;
	int sum = 0;
	int carry = 0;

	while(first != NULL || second != NULL)
	{


		sum = carry + (first?first->value:0) + (second? second-> value:0);

		carry = (sum >=10)?1:0;

		sum = sum % 10;

		temp =add_front(temp, sum);

		if(first)
		{
			first = first -> link;
		}

		if(second)
		{
			second = second -> link;

		}
	}

	return temp;
}


node_t rotate_by_k(node_t head, int k)
{
	
	/*node_t temp = head;
	int i = 0;
	int j = 0;
	int count = count_nodes(head);

	for(i = 0 ; i < count - k -1; i++)
	{
		temp = temp -> link;
	}


	for(i = k ; i > 0; i--)
	{
		node_t temp1 = temp;

		for(j = i; j > 0; j--)
		{
			temp1 = temp1 -> link;
		}

		head = add_front(head, temp1 -> value);
		head = delete_rear(head);
		display(head);
	}

	return head;*/

	//revamping the code now

	int i = 0;
	int count = count_nodes(head);
	int n = count - 1 - k;
	node_t temp = head;

	for(i= 0; i < n; i++)
	{
		temp = temp -> link;
	}

	node_t next = temp -> link;
	temp -> link = NULL;
	node_t temp1 = next;

	while(temp1 != NULL)
	{
		temp1 = next -> link;
		next -> link = head;
		head = next;
		next = temp1;
	}

	return head;
}


node_t separate_into_zeroes_ones(node_t head)
{
	//Traverse the list
	//If you find a one increment the count of one by 1
	//Delete the node
	//Do this till the last node
	//The last node doesnt matter if it is a zero or a one
	//use the last node as the head and then add count number of ones to the last

	node_t temp = head;
	int number_of_ones = 0;
	node_t next;
	int i = 0;

	while(temp -> link != NULL)
	{
		if(temp -> value == 1)
		{
			number_of_ones += 1;
			next = temp -> link;
			temp-> value = next -> value;
			temp -> link = next -> link;
			free(next);
		}
		else
		{
			temp = temp -> link;
		}
	}

	//now temp points to the last node
	printf("The value now of temp is %d \n", temp -> value);

	for(i = 0; i< number_of_ones ; i++)
	{
		temp = add_end(temp,1);
	}

	return head;

}

node_t retain_m_delte_n(node_t head, int m, int n)
{
	if(m == 0)
	{
		delete_list(head);
	}

	else
	{
		int count = 0;
		node_t temp = head;

		for(count = 1; count < m; count ++)
		{
			temp = temp -> link;
		}

		node_t temp1 = temp -> link;
		node_t next = NULL;

		for(count = 1; count <= n && temp1 != NULL; count++)
		{
			next = temp1 -> link;
			free(temp1);
			temp1 = next;
		}

		temp -> link = temp1;

	}

	return head;


}

void alternating_split_v2(node_t head)
{
	if(head == NULL || head -> link == NULL)
	{
		return;
	}

	node_t first = head;
	node_t second = head -> link;
	node_t temp1 = head;
	node_t temp2 = head -> link;
	while( temp1 != NULL && temp2 != NULL)
	{
		if(temp2 != NULL)
		{
			temp1 -> link = temp2 -> link;
			temp1 = temp1 -> link;
		}

		if(temp1 != NULL)
		{
			temp2 -> link = temp1 -> link;
			temp2 = temp2 -> link;
		}
	}

	display(first);
	display(second);

}

node_t separate_into_even_odd_v2(node_t head)
{
	if(head == NULL || head -> link == NULL)
	{
		return head;
	}
	node_t last = head;

	while(last -> link != NULL)
	{
		last = last -> link;
	}

	node_t initial_last = last;
	node_t temp = head;

	while(temp -> value % 2 != 0)
	{
		head = head -> link;
		temp -> link = NULL;
		last -> link = temp;
		last = last-> link;
		temp = head;
	}

	node_t prev = temp;
	temp = temp -> link;

	while(temp != initial_last)
	{
		if(temp -> value % 2 != 0)
		{
			prev -> link = temp -> link;
			temp -> link = NULL;
			last -> link = temp;
			temp = prev -> link;
		}

		else if(temp -> value % 2 == 0)
		{
			prev = temp;
			temp = temp-> link;
		}
	}

	return head;
}



