#include <stdio.h>
#include <stdlib.h>
#include "Exersice3-4_queue.h"
#include "stack.h"

void QU_print(QUEUE q);
void QU_reverse(QUEUE *q);

int main(void) 
{
	QUEUE q;

	int x,choice,choice1;
	
	QU_init(&q);	
	
	while(1)
	{
		system("cls");
		printf("Queue's Menu\n");
		printf("------------\n");
		printf("1-Addition\n");
		printf("2-Removal\n");
		printf("3-Print\n");
		printf("4-Reverse the queue\n");
		printf("5-Exit\n");
		printf("\nWhat's your choice? ");
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
				
				QU_reverse(&q);
				break;
			
			case 5:
				printf("Bye Bye!");
				exit(0);
			
			default:
				printf("Wrong input!");	
		}
		system("pause");
		printf("\n\n");
	}
}

void QU_print(QUEUE q)
{
	int x,i,counter = 1;
	QUEUE temp;
	QU_init(&temp);	
		
	while(!QU_empty(q))
	{
		QU_dequeue(&q,&x);
		printf("%dst element is | %d |\n",counter,x);
		QU_enqueue(&temp,x);
		counter++;
	}
	
	while(QU_empty(temp))
	{
		QU_dequeue(&temp,&x);
		QU_enqueue(&q,x);
	}
}

void QU_reverse(QUEUE *q)
{
	STACK s;
	int x;
	
	ST_init(&s);
	
	while(!QU_empty(*q))
	{
		QU_dequeue(q,&x);
		ST_push(&s,x);
	}
	
	while(!ST_empty(s))
	{
		ST_pop(&s,&x);
		QU_enqueue(q,x);
	}

}
	

