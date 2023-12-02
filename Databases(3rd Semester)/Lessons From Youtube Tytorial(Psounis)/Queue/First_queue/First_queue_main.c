#include <stdio.h>
#include <stdlib.h>
#include "First_queue_queue.h"


int main(void) 
{
	int choice,elem,i;
	QUEUE q;
	
	QU_init(&q);
	
	while(1)
	{
		system("cls");
		printf("Queue's Menu\n");
		printf("------------\n");
		printf("1-Enqueue\n");
		printf("2-Dequeue\n");
		printf("3-Print\n");
		printf("4-Exit\n");
		printf("What do you want to do? ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Give me the element you want to enqueue: ");
				scanf("%d",&elem);
				if(QU_enqueue(&q,elem))
				{
					printf("Enqueue Done!\n");
				}
				else
				{
					printf("Enqueue Failed!\n");
				}
				break;
		    case 2:
				if(QU_dequeue(&q,&elem))
				{
					printf("Dequeue Done!\n");
				}
				else
				{
					printf("Dequeue Failed!\n");
				}
				break;
			case 3:
				QU_print(q);
				break;
			case 4:
				printf("Bye Bye!\n");
				exit(0);
			default:
				printf("Wrong input\n");
		}
		printf("\n\n");
		system("pause");
	}
	
}
