#ifndef DFS_H
#define DFS_H

#include "AdjacencyList.h"
#include "Stack.h"

extern int time;

extern Stack *topologicalSort;

void DFSStack(AdjacencyList *Graph[]);

void DFSvisit(AdjacencyList *Graph[], int selected);

void DFS(AdjacencyList *Graph[]);

void printTopologicalSort(AdjacencyList *Graph[]);

#endif
