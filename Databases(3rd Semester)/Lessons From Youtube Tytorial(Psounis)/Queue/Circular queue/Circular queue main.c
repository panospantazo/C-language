#include <stdio.h>
#include <stdlib.h>
#include "Circular queue.h"


int main(void) 
{
	QUEUE q;
	int x,choice;
	
	QU_init(&q);	
	
	while(1)
	{
		system("cls");
		printf("Queue's Menu\n");
		printf("------------\n");
		printf("1-Addition\n");
		printf("2-Removal\n");
		printf("3-Print\n");
		printf("4-Exit");
		printf("What's your choice? ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: 
				printf("Give me the element: ");
				scanf("%d",&x);
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
					printf("Dequeue Done!");
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
				printf("Bye Bye!");
				exit(0);
			
			default:
				printf("Wrong input!");	
		}
		system("pause");
		printf("\n\n");
	}
}
