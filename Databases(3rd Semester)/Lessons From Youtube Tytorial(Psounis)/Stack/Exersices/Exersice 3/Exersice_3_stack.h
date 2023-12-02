/* Stack.h : Stack declarations */

#define STACK_SIZE 10  /* Size of the Stack */

struct stack
{
	int  array[STACK_SIZE];   /* Array of elements*/
	int top;				 /* Top of the stack */
};

typedef struct stack STACK;  /* Synonym of stack */

void ST_init(STACK *s);
int ST_empty(STACK s);
int ST_full(STACK s);
int ST_push(STACK *s,int x);
int ST_pop(STACK *s,int *x);
void ST_print(STACK s);


