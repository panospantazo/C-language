#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Exersice1_queue.h"


int main(void) 
{
	srand((unsigned int)time(NULL));
	QUEUE q,q1;
	int choice , fund;
	unsigned int x;
	char * name;
	
	
	QU_init(&q);
	QU_init(&q1);	
	
	while(1)
	{
		system("cls");
		printf("Bank funds Menu\n");
		printf("---------------\n");
		printf("1-Addition\n");
		printf("2-Removal\n");
		printf("3-Print\n");
		printf("4-Exit\n");
		printf("What's your choice? ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: 
				printf("Give me a name: ");
				
				name = (char *)malloc(sizeof(char) * 80);
				if(!name)
				{
					printf("Error Allocated Memory!");
					exit(0);
				}
				
				scanf("%s",name);
				
				if(QU_enqueue(&q,name))
				{
					printf("Enqueue is done!\nYou %s are in the first fund.\n",name);
				}
				else if(QU_enqueue(&q1,name))
				{
					printf("Enqueue is done!\n You are in the second fund.\n");
				}
				else
				{
					printf("Both funds are full!The customer %s must leave\n",name);
				}
				
				break;
			
			case 2:
				x = rand() % 2 + 1;
				if(x == 1)
				{
					if(QU_empty(q))
					{
						printf("The first fund is empty!\n");
					}
					else
					{
						QU_dequeue(&q,&name);
						printf("The customer %s is out of the %dst fund!\n",name,x);
					}
				}
				else
				{
					if(QU_empty(q1))
					{
						printf("The second fund is empty!\n");
					}
					else
					{
						QU_dequeue(&q1,&name);
						printf("The customer %s is out of the %dst fund\n",name,x);
					}
				}
				
				break;
			
			case 3:
				if(QU_empty(q) == 1 && QU_empty(q1) == 1)
				{
					printf("Both funds are empty!\n");
				}
				else
				{
					printf("Which fund you want to print? ");
					scanf("%d",&fund);
					if(fund == 1)
					{
						QU_print(q);
					}
					else
					{
						QU_print(q1);
					}
				}
			
				break;
			
			case 4:
				if(QU_empty(q) == 1 && QU_empty(q1) == 1)
				{
					free(name);
					printf("Bye Bye!");
					exit(0);
				}
				else
				{
					printf("There are still customers in the funds!\n");
				}
				break;
			
			default:
				printf("Wrong input!");	
		}
		system("pause");
		printf("\n\n");
	}
}
