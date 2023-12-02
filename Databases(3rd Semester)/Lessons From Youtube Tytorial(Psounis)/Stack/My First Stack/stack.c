/* stack.c: Code of stack's libraby */
#include <stdio.h>
#include "stack.h"

/*ST_init() Initialization of the stack */
void ST_init(STACK *s)
{
	s->top = -1;
}

/*ST_empty(): returns 1 if stack is empty or 0 if its not*/
int ST_empty(STACK s)
{
	return s.top==-1;
}

/*ST_full(): returns 1 if stack is full or 0 if its not*/
int ST_full(STACK s)
{
	return s.top==STACK_SIZE - 1;
}

/*ST_push(): Adds a element into the stack. Returns 1 if the addition is done or 0 if the addition failed*/
int ST_push(STACK *s,int x)
{
	if(ST_full(*s))
	{
		return 0;
	}
	else
	{
		s->top++;
		s->array[s->top] = x;
		return 1;
	}
}

/*ST_pop(): Removes a element from the stack. Returns 1 if the removal is done or 0 if the removal failed*/
int ST_pop(STACK *s,int *x)
{
	if(ST_empty(*s))
	{
		return 0;
	}
	else
	{
		*x = s->array[s->top];
		s->top--;
		return 1; 
	}
}

/*ST_print(): Prints the current stack*/
void ST_print(STACK s)
{
	int i;
	for(i=0;i<=s.top;i++)
	{
		printf("%dst element: %d \n",i+1,s.array[i]);
	}
}
