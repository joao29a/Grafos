#ifndef QUEUE_H
#define QUEUE_H
typedef struct queue{
        int number;
        struct queue *next;
}Queue;

void Enqueue(Queue **fifo, int value);

int Dequeue(Queue **fifo);

#endif
