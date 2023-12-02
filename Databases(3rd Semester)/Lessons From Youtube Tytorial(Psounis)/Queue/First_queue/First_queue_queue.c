#include <stdio.h>
#include "First_queue_queue.h"

void QU_init(QUEUE *s)
{
	s->finish = -1;
}

int QU_empty(QUEUE s)
{
	return s.finish == -1;
}

int QU_full(QUEUE s)
{
	return s.finish == MAX_QUEUE - 1;
}

int QU_enqueue(QUEUE *s , int x)
{
	if(QU_full(*s))
	{
		printf("Queue is full!\n");
		return 0;
	}
	else
	{
		s->finish++;
		s->array[s->finish] = x;
		return 1;
	}
}

int QU_dequeue(QUEUE *s , int *x)
{
	int i;
	
	if(QU_empty(*s))
	{
		printf("The queue is empty!\n");
		return 0;
	}
	else
	{
		*x = s->array[0];
		
		for(i=0 ; i<s->finish ; i++)
		{
			s->array[i] = s->array[i+1];
		}
		
		s->finish--;
		return 1;
	}
}

void QU_print(QUEUE s)
{
	int i;
	for(i = 0;i<=s.finish;i++)
	{
		printf("%dst element is: %d\n",i+1,s.array[i]);
	}
}
