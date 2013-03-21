#include <stdio.h>
#include <stdlib.h>
#include "hdr/Queue.h"

Queue *fifo;
Queue *back;

void Enqueue(int value){
	if (fifo == NULL){
		fifo = malloc(sizeof(Queue));
		fifo->number = value;
		fifo->next = NULL;
		back = fifo;
	}
	else{
		Queue *buffer;
		buffer = malloc(sizeof(Queue));
		buffer->number = value;
		buffer->next = NULL;
		back->next = buffer;
		back = buffer;
	}
}

int Dequeue(){
	Queue *buffer;
	buffer = fifo;
	fifo = fifo->next;
	int value = buffer->number;
	free(buffer);
	return value;
}
