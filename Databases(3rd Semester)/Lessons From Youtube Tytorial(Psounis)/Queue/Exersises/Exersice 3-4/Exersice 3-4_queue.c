/* Code of the library */
#include <stdio.h>
#include "Exersice3-4_queue.h"

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
int QU_enqueue(QUEUE *q,int x)
{
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
		return 1;
	}
}

/*QU_dequeue(): Removes a element from the queue. Returns 1 if the removal is done right or 0 if it failed */
int QU_dequeue(QUEUE *q,int *x)
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

