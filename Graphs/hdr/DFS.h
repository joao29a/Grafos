#ifndef DFS_H
#define DFS_H

#include "AdjacencyList.h"

extern int time;

void DFSStack(AdjacencyList *Graph[]);

void DFSvisit(AdjacencyList *Graph[], int selected);

void DFS(AdjacencyList *Graph[]);

#endif
