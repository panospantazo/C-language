/* This exersice is that i get a positive integer from the user and with a stack i print his binary form */
#include <stdio.h>
#include <stdlib.h>
#include "Exersice_3_stack.h"



int main(void) 
{
	int elem;
	STACK st;
	
	ST_init(&st);
	
	do
	{
		printf("Give me a positive number: ");
		scanf("%d",&elem);
	}while(elem <=0);
	
	while(elem > 0)
	{
		ST_push(&st,elem%2);
		elem = elem/2;	
	}
	
	while(!ST_empty(st))
	{
		ST_pop(&st,&elem);
		printf("%d\n",elem);
	}
	
	return 0;
}
