#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#define VERTEX 6
#define START 0

typedef struct adjacency {
	int vertexNumber;
	int output;
	int input;
	int distance;
	int edge;
	char visit;
	int father;
	int outputStamp;
	int inputStamp;
	struct adjacency *next;
}AdjacencyList;

void createGraph(AdjacencyList *Graph[]);

void insertVertex(AdjacencyList *Graph, int adjVertex, int edge);

void printGraph(AdjacencyList *Graph[]);

void initializeGraph(AdjacencyList *Graph[]);

void resetVisit(AdjacencyList *Graph[]);

#endif
