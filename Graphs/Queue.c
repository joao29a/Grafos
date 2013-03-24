#include <stdio.h>
#include <stdlib.h>
#include "hdr/Queue.h"


void Enqueue(Queue **fifo, int value){
	if ((*fifo) == NULL){
		(*fifo) = malloc(sizeof(Queue));
		(*fifo)->number = value;
		(*fifo)->next = NULL;
	}
	else{
		Queue *buffer;
		buffer=(*fifo);
		while (buffer->next!=NULL)
			buffer=buffer->next;
		buffer->next = malloc(sizeof(Queue));
		buffer=buffer->next;
		buffer->number = value;
		buffer->next = NULL;
	}
}

int Dequeue(Queue **fifo){
	Queue *buffer;
	buffer = (*fifo);
	(*fifo) = (*fifo)->next;
	int value = buffer->number;
	free(buffer);
	return value;
}
