#ifndef QUEUE_H
#define QUEUE_H
typedef struct queue{
        int number;
        struct queue *next;
}Queue;

extern Queue *fifo;
extern Queue *back;

void Enqueue(int value);

int Dequeue();

#endif
