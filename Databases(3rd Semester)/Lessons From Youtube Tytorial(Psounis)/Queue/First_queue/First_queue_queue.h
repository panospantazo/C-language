/* Initialiazations of the queue */

#define MAX_QUEUE 10

struct queue
{
	int array[MAX_QUEUE];
	int finish;
};

typedef struct queue QUEUE;

void QU_init(QUEUE *s);
int QU_empty(QUEUE s);
int QU_full(QUEUE s);
int QU_enqueue(QUEUE *s , int x);
int QU_dequeue(QUEUE *s , int *x);
void QU_print(QUEUE s);
