#ifndef STACK_H
#define STACK_H

typedef struct stack{
        int number;
        struct stack *next;
}Stack;

extern Stack *lifo;

void Push(int value);

int Pop();

#endif
