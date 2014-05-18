#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static int is_empty(my_stack_t* s)
{
	if(s->top == -1)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

static int is_full(my_stack_t* s)
{
	if((s->top) == (MAX_SIZE - 1))
	{
		return 1;
	}

	else
	{
		return 0;
	}
}


void push(my_stack_t* s, int ele)
{
	if(is_full(s))
	{
		printf("The stack is full and the element cant be pushed \n");
		return;
	}

	else
	{
		s->array[++ s->top] = ele;
	}
}

int pop(my_stack_t* s)
{
	if(is_empty(s))
	{
		printf("The stack is empty \n");
		return 0;
	}

	else
	{
		return s->array[(s->top)--];
	}
}
