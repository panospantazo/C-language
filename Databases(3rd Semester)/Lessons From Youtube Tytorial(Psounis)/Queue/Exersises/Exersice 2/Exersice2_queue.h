/* queue.h : Initializations of the queue */

#define QUEUE_SIZE 10
#define MAX_NAME 80

struct data_array
{
	int priority;
	char * name[80];
};

typedef struct data_array DTARR;

struct queue
{
	DTARR array[QUEUE_SIZE];
	int start;
	int finish;
};

typedef struct queue QUEUE;

void QU_init(QUEUE *q);
int QU_empty(QUEUE q);
int QU_full(QUEUE q);
int QU_enqueue(QUEUE *q,DTARR x);
int QU_dequeue(QUEUE *q,DTARR *x);
void QU_print(QUEUE q);
