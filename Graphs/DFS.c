#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/AdjacencyList.h"
#include "hdr/DFS.h"
#include "hdr/Stack.h"

int time;
Stack *topologicalSort;
int find=0;

void DFSStack(AdjacencyList *Graph[]){
	resetVisit(Graph);
	time=0;
	Stack *Q;
	Q=NULL;
	int i;
	for (i=0;i<VERTEX;i++){
		if (Graph[i]->visit=='w'){
			Graph[i]->visit='g';
			Push(&Q,Graph[i]->vertexNumber);
			int element;
			while (Q!=NULL){
				int pushed=0;
				element=Pop(&Q);
				time++;
				Graph[element]->inputStamp=time;
				AdjacencyList *buffer;
				buffer=Graph[element];
				while (buffer->next!=NULL){
					buffer=buffer->next;
					if (Graph[buffer->vertexNumber]->visit=='w'){
						pushed=1;
						Graph[buffer->vertexNumber]->visit='g';
						Graph[buffer->vertexNumber]->father=Graph[element];
						Push(&Q,buffer->vertexNumber);
					}
				}
				if (!pushed){
					time++;
					Graph[element]->outputStamp=time;
				}
				Graph[element]->visit='b';
			}
			AdjacencyList *buffer;
			buffer=Graph[element];
			while (buffer->father!=NULL){
				time++;
				Graph[buffer->vertexNumber]->father->outputStamp=time;
				buffer=buffer->father;
			}
		}
		printf("Vertex: %2d | inputStamp: %2d | OutputStamp: %2d\n",Graph[i]->vertexNumber,
				Graph[i]->inputStamp,Graph[i]->outputStamp);
	}
}

void DFSvisit(AdjacencyList *Graph[], int selected){
	Graph[selected]->visit='g';
	time++;
	Graph[selected]->inputStamp=time;
	AdjacencyList *buffer=Graph[selected];
	while (buffer->next!=NULL){
		buffer=buffer->next;
		if (Graph[buffer->vertexNumber]->visit=='w'){
			Graph[buffer->vertexNumber]->component=Graph[selected]->component;
			Graph[buffer->vertexNumber]->father=Graph[selected];
			DFSvisit(Graph,buffer->vertexNumber);             
		}
	}
	Graph[selected]->visit='b';
	time=time+1;
	Graph[selected]->outputStamp=time;
	Push(&topologicalSort,Graph[selected]->vertexNumber);
	printf("Vertex: %2d | Component: %2d | inputStamp: %2d | OutputStamp: %2d\n",Graph[selected]->vertexNumber,
		Graph[selected]->component,Graph[selected]->inputStamp,Graph[selected]->outputStamp);	
}

void DFS(AdjacencyList *Graph[]){
	resetVisit(Graph);
	time=0;
	int i;
	for (i=0;i<VERTEX;i++)
		if (Graph[i]->visit=='w'){
			DFSvisit(Graph,Graph[i]->vertexNumber);
		}
}

void printTopologicalSort(AdjacencyList *Graph[]){
	Stack *buffer;
	buffer=topologicalSort;
	while (buffer!=NULL){
		int element=buffer->number;
		printf("%d: %d/%d | ",element,Graph[element]->inputStamp,Graph[element]->outputStamp);
		buffer=buffer->next;
	}
}

void pathVertex(AdjacencyList *Graph[], int s, int t){
	if (s==t)
		find=1;
	AdjacencyList *buffer;
	buffer=Graph[s];
	Graph[s]->visit='g';
	while (buffer->next!=NULL && !find){
		buffer=buffer->next;
		if (Graph[buffer->vertexNumber]->visit=='w')
			pathVertex(Graph,buffer->vertexNumber,t);
	}
	Graph[s]->visit='b';
	if (find)
		Push(&topologicalSort,s);
}
