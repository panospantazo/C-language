/* The exersice is to make my library work for char*/

#include <stdio.h>
#include <stdlib.h>
#include "Exersice_1_stack.h"

int main(void)
{
	int choice,i;
	char elem;
	STACK st;
	
	ST_init(&st);
	
	while(1)
	{
		system("cls");
		printf("Stack's Menu: ");
		printf("\n-------------");
		printf("\n1-Push");
		printf("\n2-Pop");
		printf("\n3-Print");
		printf("\n4-Exit");
		printf("\nWhat do you want to do? ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: 
					printf("\nGive me the character you want to push: ");
					fflush(stdin);
					scanf("%c",&elem);
					if(ST_push(&st,elem))
					{
						printf("Push Done!");
					}
					else
					{
						printf("Push Failed!");
					}
					break;
			case 2:
					if(ST_pop(&st,&elem))
					{
						printf("Pop Done!");
					}
					else
					{
						printf("Pop Failed!");
					}
					break;
			case 3:
					ST_print(st);
					break;
			case 4:
					printf("Bye Bye!!");
					exit(0);
			default:
					printf("Wrong input!");
					break;
		}
		printf("\n\n");
		system("pause");
	}
}
