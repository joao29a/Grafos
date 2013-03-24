#ifndef STACK_H
#define STACK_H

typedef struct stack{
        int number;
        struct stack *next;
}Stack;

void Push(Stack **lifo, int value);

int Pop(Stack **lifo);

#endif
