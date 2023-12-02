/* Code of the library */
#include <stdio.h>
#include "Exersice2_queue.h"

/*QU_init(): Initialiaze the queue*/
void QU_init(QUEUE *q)
{
	q->start = -1;
	q->finish -1;
}

/* QU_empty(): Returns 1 if the queue is empty or 0 if the queue is not empty */
int QU_empty(QUEUE q)
{
	return q.start ==-1;
}

/* QU_full(): returns 1 if the queue is full or 0 if the queue is not full */
int QU_full(QUEUE q)
{
	return q.start==(q.finish+1)%QUEUE_SIZE;
}

/* QU_enqueue(): Adds a element into the queue. Returns 1 if the addition is done right or 0 if it failed */
int QU_enqueue(QUEUE *q,DTARR x)
{
	int i;
	DTARR temp;
	
	if(QU_full(*q))
	{
		return 0;
	}
	else
	{
		if(QU_empty(*q))
		{
			q->start = 0;
			q->finish = 0;
		}
		else
		{
			q->finish = (q->finish+1)%QUEUE_SIZE;
		}
		q->array[q->finish] = x;
		
		i = q->finish;
		
		while(i != q->start)
		{
			if(i>0)
			{
				if(q->array[i-1].priority < q->array[i].priority)
				{
					temp = q->array[i-1];
					q->array[i-1] = q->array[i];
					q->array[i] = temp;
					i--; 
				}
				else
				{
					break;
				}
			}
			else
			{
				if(q->array[QUEUE_SIZE-1].priority > q->array[i].priority)
				{
					temp = q->array[QUEUE_SIZE-1];
					q->array[QUEUE_SIZE-1] = q->array[i];
					q->array[i] = temp;
					i=QUEUE_SIZE-1; 
				}
				else
				{
					break;
				}	
			}
		
		}
		
		return 1;
	}
}

/*QU_dequeue(): Removes a element from the queue. Returns 1 if the removal is done right or 0 if it failed */
int QU_dequeue(QUEUE *q,DTARR *x)
{
	if(QU_empty(*q))
	{
		return 0;
	}
	else
	{
		*x = q->array[q->start];
		if(q->start == q->finish)
		{
			q->start = -1;
			q->finish = -1;
		}
		else
		{
			q->start = (q->start + 1) % QUEUE_SIZE;
		}
		return 1;
	}	
}

void QU_print(QUEUE q)
{
	int i;
	if(q.start != -1)
	{
		i = q.start;
		while(1)
		{
			printf("Customer is %s with priority (%d)\n",q.array[i].name,q.array[i].priority);
			if(i == q.finish)
				break;
			i = (i+1)%QUEUE_SIZE;
		}
	}
}
