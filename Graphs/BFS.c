#include <stdio.h>
#include <stdlib.h>
#include "hdr/Queue.h"
#include "hdr/AdjacencyList.h"
#include "hdr/BFS.h"

void BFS(AdjacencyList *Graph[], int selected){
	resetVisit(Graph);
	Graph[selected]->visit='g';
	Graph[selected]->distance=0;
	Graph[selected]->father=NULL;
	Queue *Q;
	Q=NULL;
	Enqueue(&Q,selected);
	while (Q!=NULL){
		int element=Dequeue(&Q);
		AdjacencyList *buffer=Graph[element];
		while (buffer->next!=NULL){
			buffer=buffer->next;
			if (Graph[buffer->vertexNumber]->visit=='w'){
				Graph[buffer->vertexNumber]->visit='g';
				Graph[buffer->vertexNumber]->distance=Graph[element]->distance+1;
				Graph[buffer->vertexNumber]->father=Graph[element];
				Enqueue(&Q,buffer->vertexNumber);
			}
		}
		Graph[element]->visit='b';
	}
}

void printBFS(AdjacencyList *Graph[]){
	printf("\n\nBreadth-first search VERTEX %d:\n",START);
	int i;
	for (i=0;i<VERTEX;i++)
		printf("VERTEX %d: %d\n",Graph[i]->vertexNumber,Graph[i]->distance);
	printf("\n");
}
