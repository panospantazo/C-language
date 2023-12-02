/* queue.h : Initializations of the queue */

#define QUEUE_SIZE 5

struct queue
{
	char * array[QUEUE_SIZE];
	int start;
	int finish;
};

typedef struct queue QUEUE;

void QU_init(QUEUE *q);
int QU_empty(QUEUE q);
int QU_full(QUEUE q);
int QU_enqueue(QUEUE *q,char *x);
int QU_dequeue(QUEUE *q,char **x);
void QU_print(QUEUE q);
