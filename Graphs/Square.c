#include <stdio.h>
#include <stdlib.h>
#include "hdr/AdjacencyList.h"
#include "hdr/Square.h"

void Square(AdjacencyList *Graph[], AdjacencyList *SquareGraph[]){
	int i;
	for (i=0;i<VERTEX;i++){
		AdjacencyList *buffer;
		buffer=Graph[i];
		while (buffer->next!=NULL){
			buffer=buffer->next;
			AdjacencyList *buffer2;
			buffer2=Graph[buffer->vertexNumber];
			while (buffer2->next!=NULL){
				buffer2=buffer2->next;
				if (buffer->vertexNumber!=buffer2->vertexNumber)
					insertVertex(SquareGraph[i],buffer2->vertexNumber,0);
			}
		}
	}
}
