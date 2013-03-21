#include <stdio.h>
#include <stdlib.h>
#include "hdr/Stack.h"

Stack *lifo;

void Push(int value){
	if (lifo == NULL){
		lifo = malloc(sizeof(Stack));
		lifo->number = value;
		lifo->next = NULL;
	}
	else{
		Stack *buffer;
		buffer = malloc(sizeof(Stack));
		buffer->number = value;
		buffer->next = lifo;
		lifo = buffer;
	}
}

int Pop(){
	Stack *buffer;
	buffer = lifo;
	lifo = lifo->next;
	int value = buffer->number;
	free(buffer);
	return value;
}
