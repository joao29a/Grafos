#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/AdjacencyList.h"

int time;

void DFSvisit(AdjacencyList *Graph[], int selected){
	Graph[selected]->visit='g';
	time++;
	Graph[selected]->inputStamp=time;
	AdjacencyList *buffer=Graph[selected];
	while (buffer->next!=NULL){
		buffer=buffer->next;
		if (Graph[buffer->vertexNumber]->visit=='w'){
			Graph[buffer->vertexNumber]->father=selected;
			DFSvisit(Graph,buffer->vertexNumber);             
		}
	}
	Graph[selected]->visit='b';
	time=time+1;
	Graph[selected]->outputStamp=time;
	printf("Vertex: %2d | Father: %2d | inputStamp: %2d | OutputStamp: %2d\n",Graph[selected]->vertexNumber,Graph[selected]->father,
					Graph[selected]->inputStamp,Graph[selected]->outputStamp);	
}

void DFS(AdjacencyList *Graph[]){
	int i;
	for (i=0;i<VERTEX;i++){
		Graph[i]->visit='w';
		Graph[i]->father=-1;
	}
	time=0;
	for (i=0;i<VERTEX;i++)
		if (Graph[i]->visit=='w'){
			DFSvisit(Graph,Graph[i]->vertexNumber);
		}
}
