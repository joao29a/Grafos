#include <stdio.h>
#include <stdlib.h>
#include "hdr/AdjacencyList.h"

void createGraph(AdjacencyList *Graph[]){
	//exemple 22.3 from Cormen 3rd edition
	/*
	insertVertex(Graph[0],1,0);
	insertVertex(Graph[0],3,0);
	insertVertex(Graph[1],0,0);
	insertVertex(Graph[1],2,0);
	insertVertex(Graph[2],1,0);
	insertVertex(Graph[3],0,0);
	insertVertex(Graph[3],4,0);
	insertVertex(Graph[3],5,0);
	insertVertex(Graph[4],3,0);
	insertVertex(Graph[4],5,0);
	insertVertex(Graph[4],6,0);
	insertVertex(Graph[5],3,0);
	insertVertex(Graph[5],4,0);
	insertVertex(Graph[5],6,0);
	insertVertex(Graph[5],7,0);
	insertVertex(Graph[6],4,0);
	insertVertex(Graph[6],5,0);
	insertVertex(Graph[6],7,0);
	insertVertex(Graph[7],5,0);
	insertVertex(Graph[7],6,0);
	*/
	//exemple 22.2 from Cormen 3rd edition
	/*
	insertVertex(Graph[0],1,0);
     	insertVertex(Graph[0],3,0);
     	insertVertex(Graph[1],2,0);
	insertVertex(Graph[2],3,0);
	insertVertex(Graph[3],1,0);
	insertVertex(Graph[4],2,0);
	insertVertex(Graph[4],5,0);
	//insertVertex(Graph[5],5,0);
	*/
	//exemple 22.7 from Cormen 3rd edition
	/*
	insertVertex(Graph[1],6,0);
	insertVertex(Graph[3],6,0);
	insertVertex(Graph[3],4,0);
	insertVertex(Graph[4],6,0);
	insertVertex(Graph[4],5,0);
	insertVertex(Graph[5],8,0);
	insertVertex(Graph[0],5,0);
	insertVertex(Graph[0],7,0);
	insertVertex(Graph[7],8,0);
	*/
	//exemple 22.8 from Cormen 3rd edition
	//*
	insertVertex(Graph[0],4,0);
	insertVertex(Graph[0],5,0);
	insertVertex(Graph[0],7,0);
	insertVertex(Graph[1],2,0);
	insertVertex(Graph[1],4,0);
	insertVertex(Graph[1],8,0);
	insertVertex(Graph[2],5,0);
	insertVertex(Graph[2],6,0);
	insertVertex(Graph[2],9,0);
	insertVertex(Graph[3],2,0);
	insertVertex(Graph[3],6,0);
	insertVertex(Graph[3],13,0);
	insertVertex(Graph[4],7,0);
	insertVertex(Graph[5],8,0);
	insertVertex(Graph[5],12,0);
	insertVertex(Graph[6],5,0);
	insertVertex(Graph[8],7,0);
	insertVertex(Graph[9],10,0);
	insertVertex(Graph[9],11,0);
	insertVertex(Graph[10],13,0);
	insertVertex(Graph[12],9,0);
	//*/
}

void insertVertex(AdjacencyList *Graph, int adjVertex, int edge){
	
	AdjacencyList *buffer;
	buffer = Graph;

	while (buffer->next != NULL)
		buffer = buffer->next;      
	buffer->next = malloc(sizeof(AdjacencyList));
	buffer = buffer->next;
	buffer->vertexNumber = adjVertex;
	buffer->edge = edge;
	buffer->next = NULL;
}

void printGraph(AdjacencyList *Graph[]){
	AdjacencyList *buffer;
	int i;
	for (i=0;i<VERTEX;i++){
		buffer = Graph[i];
		printf("Vertex %d: ",Graph[i]->vertexNumber);
		while (buffer->next!=NULL){
			buffer=buffer->next;
			printf("%d->%d| ",buffer->vertexNumber,buffer->edge);
		}
		printf("\n");
	}
}

void printFather(AdjacencyList *Graph[]){
	int i;
	for (i=0;i<VERTEX;i++){
		printf("Father of vertex %d: ",Graph[i]->vertexNumber);
		if (Graph[i]->father!=NULL)
			printf("%d\n",Graph[i]->father->vertexNumber);
		else
			printf("nil\n");
	}
}

void initializeGraph(AdjacencyList *Graph[]){
	int i;
	for (i=0;i<VERTEX;i++){
		Graph[i]=malloc(sizeof(AdjacencyList));
		Graph[i]->vertexNumber=i;
		Graph[i]->output=0;
		Graph[i]->input=0;
		Graph[i]->next=NULL;
	}
}

void resetVisit(AdjacencyList *Graph[]){
	int i;
	for (i=0;i<VERTEX;i++){
		Graph[i]->visit='w';
		Graph[i]->distance=-1;
		Graph[i]->father=NULL;
		Graph[i]->component=i;
	}
}
