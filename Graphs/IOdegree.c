#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/AdjacencyList.h"
#include "hdr/IOdegree.h"

//Complexity O(V+E)
void outputDegree(AdjacencyList *Graph[]){
	AdjacencyList *buffer;
	int i;
	for (i=0;i<VERTEX;i++){
		buffer=Graph[i];
		while (buffer->next!=NULL){
			Graph[i]->output++;
			buffer=buffer->next;
		}
	}
}

void printOutput(AdjacencyList *Graph[]){
	int i;
	printf("\nOutput Degree:\n");
	for (i=0;i<VERTEX;i++)
		printf("Vertex %d: %d\n",Graph[i]->vertexNumber,Graph[i]->output);
}

//Complexity O(V+E)
void inputDegree(AdjacencyList *Graph[]){
	AdjacencyList *buffer;
	int i;
	for (i=0;i<VERTEX;i++){
		buffer=Graph[i];
		while (buffer->next!=NULL){
			buffer=buffer->next;
			Graph[buffer->vertexNumber]->input += 1;
		}
	}   
}

void printInput(AdjacencyList *Graph[]){
	int i;
	printf("\nInput Degree:\n");
	for (i=0;i<VERTEX;i++)
		printf("Vertex %d: %d\n",Graph[i]->vertexNumber,Graph[i]->input);
}
