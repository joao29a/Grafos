#include <stdio.h>
#include "hdr/AdjacencyList.h"
#include "hdr/IOdegree.h"
#include "hdr/Queue.h"

int ex5(AdjacencyList *Graph[]){
	int semestre = 0;
	inputDegree(Graph);
	Queue *Q = NULL;
	Queue *Q2 = NULL;
	int i;
	for (i=0;i<VERTEX;i++){
		if (Graph[i]->input==0)
			Enqueue(&Q,Graph[i]->vertexNumber);
	}
	while (Q!=NULL){
		int u = Dequeue(&Q);
		AdjacencyList *buffer = Graph[u];
		while (buffer->next!=NULL){
			buffer = buffer->next;
			Graph[buffer->vertexNumber]->input--;
			if (Graph[buffer->vertexNumber]->input == 0){
				Enqueue(&Q2,buffer->vertexNumber);
			}
		}
		if (Q==NULL){
			while (Q2!=NULL){
				Enqueue(&Q,Dequeue(&Q2));
			}
			semestre++;
		}
	}
	return semestre;
}

int main(){
	AdjacencyList *Graph[VERTEX];
	initializeGraph(Graph);
	createGraph(Graph);
	printGraph(Graph);
	printf("Quantidade minima de semestre(s): %d\n",ex5(Graph));
	return 0;
}
