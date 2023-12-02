/* Stack.h : Stack declarations */

#define STACK_SIZE 10  /* Size of the Stack */
#define STUDENT_NAME 50 /*Max size of student's name*/
struct student
{
	char name[STUDENT_NAME];
	int grade;
};

typedef struct student STUDENT;

struct stack
{
	STUDENT  array[STACK_SIZE];   /* Array of elements*/
	int top;				 /* Top of the stack */
};

typedef struct stack STACK;  /* Synonym of stack */

void ST_init(STACK *s);
int ST_empty(STACK s);
int ST_full(STACK s);
int ST_push(STACK *s,STUDENT x);
int ST_pop(STACK *s,STUDENT *x);
void ST_print(STACK s);

