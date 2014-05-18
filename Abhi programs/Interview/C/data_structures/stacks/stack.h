#ifndef STACK_H
#define STACK_H


#define MAX_SIZE 10
struct my_stack
{
	int array[MAX_SIZE];
	int top;
};

typedef struct my_stack my_stack_t;

static int is_empty(my_stack_t* s);
static int is_full(my_stack_t* s);
void push(my_stack_t* s, int ele);
int pop(my_stack_t* s);

#endif