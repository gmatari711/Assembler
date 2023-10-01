#ifndef ASSEMBLER_QUEUE_H
#define ASSEMBLER_QUEUE_H

typedef struct queue* queue;
typedef void* item;

queue queue_create();
void queue_destroy(queue *a_queue_ptr);
void enqueue(queue a_queue, item);
item dequeue(queue a_queue);
item queue_peak(queue a_queue);



#endif

