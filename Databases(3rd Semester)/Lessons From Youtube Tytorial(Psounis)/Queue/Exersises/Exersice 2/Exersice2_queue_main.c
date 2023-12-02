#include <stdio.h>
#include <stdlib.h>
#include "Exersice2_queue.h"


int main(void) 
{
	QUEUE q;
	int choice;
	char* name;
	DTARR x;
	
	QU_init(&q);	
	
	while(1)
	{
		system("cls");
		printf("Queue's Menu\n");
		printf("------------\n");
		printf("1-Addition\n");
		printf("2-Removal\n");
		printf("3-Print\n");
		printf("4-Exit\n");
		printf("What's your choice? \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
				printf("Give me the priority of the customer: ");
				scanf("%d",&x.priority);
				
				name = (char *)malloc(sizeof(char) * 80);
				if(!name)
				{
					printf("Error allocating memory\n");
					exit(0);
				}
				printf("Give me the name of the customer: ");
				scanf("%s",x.name);
				
				if(QU_enqueue(&q,x))
				{
					printf("Enqueue is done!");
				}
				else
				{
					printf("Enqueue failed!\nQueue full");
				}
				
				break;
			
			case 2:
				if(QU_dequeue(&q,&x))
				{
					printf("Dequeue Done!\nCustomer %s with priority (%d) is done!\n",x.name,x.priority);
				}
				else
				{
					printf("Dequeue Failed!\nQueue empty");
				}
				break;
			
			case 3:
				QU_print(q);
				break;
			
			case 4:
				free(name);
				printf("Bye Bye!");
				exit(0);
			
			default:
				printf("Wrong input!");	
		}
		system("pause");
		printf("\n\n");
	}
}
