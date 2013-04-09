#include <stdio.h>
#include "hdr/AdjacencyList.h"
#include "hdr/IOdegree.h"
#include "hdr/Queue.h"

//topological sort using input degree = 0 O(V+E)
void topologicalSort(AdjacencyList *Graph[]){
	int i;
	for (i = 0; i < VERTEX; i++) // O(V+E)
		Graph[i]->input = 0;
	inputDegree(Graph); // O(V+E)
	Queue *Q = NULL;
	for (i = 0; i < VERTEX; i++) // O(V)
		if (Graph[i]->input == 0)
			Enqueue(&Q,Graph[i]->vertexNumber);
	while (Q != NULL){ // O(V+E)
		int u = Dequeue(&Q);
		AdjacencyList *buffer = Graph[u];
		while (buffer->next != NULL){
			buffer = buffer->next;
			Graph[buffer->vertexNumber]->input--;
			if (Graph[buffer->vertexNumber]->input == 0)
				Enqueue(&Q,buffer->vertexNumber);
		}
	}
}
