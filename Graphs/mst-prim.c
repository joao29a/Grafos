#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "hdr/AdjacencyList.h"

typedef struct linkedlist{
	int vertex;
	int key;
	struct linkedlist *next;
}LinkedList;

void initializeList(LinkedList **Q){
	(*Q)=NULL;
}

void insertList(LinkedList **Q, int vertex, int key){
	LinkedList *aux;
	aux=(*Q);
	if (aux==NULL){
		aux=malloc(sizeof(LinkedList));
		aux->vertex=vertex;
		aux->key=key;
		aux->next=NULL;
		(*Q)=aux;
	}
	else{
		while (aux->next!=NULL)
			aux=aux->next;
		aux->next=malloc(sizeof(LinkedList));
		aux=aux->next;
		aux->vertex=vertex;
		aux->key=key;
		aux->next=NULL;
	}
}

int extractMin(LinkedList **Q){
	LinkedList *aux;
	aux=(*Q);
	int min=aux->key;
	int vertex=aux->vertex;
	while (aux->next!=NULL){
		aux=aux->next;
		if (aux->key<min){
			min = aux->key;
			vertex = aux->vertex;
		}
	}
	aux=(*Q);
	if (aux->vertex==vertex){
		(*Q)=aux->next;
		free(aux);
	}
	else{
		while (aux->next->vertex!=vertex)
			aux=aux->next;
		LinkedList *temp;
		temp=aux;
		aux=aux->next;
		temp->next=aux->next;
		aux->next=NULL;
		free(aux);
	}
	return vertex;
}

int verifyList(LinkedList **Q, int vertex){
	LinkedList *aux;
	aux=(*Q);
	while (aux!=NULL){
		if (aux->vertex==vertex)
			return 1;
		aux=aux->next;
	}
	return 0;
}

int keyList(LinkedList **Q, int vertex){
	LinkedList *aux;
	aux=(*Q);
	while (aux!=NULL){
		if (aux->vertex==vertex)
			return aux->key;
		aux=aux->next;
	}
	return 0;
}

void printList(LinkedList **Q){
	LinkedList *aux;
	aux=(*Q);
	while (aux!=NULL){
		printf("%d->%d | ",aux->vertex,aux->key);
		aux=aux->next;
	}
	printf("\n");
}

void insertKey(LinkedList **Q, int vertex, int key){
	LinkedList *aux;
	aux = (*Q);
	while (aux!=NULL){
		if (aux->vertex==vertex){
			aux->key=key;
		}
		aux=aux->next;
	}
}



void mstPrim(AdjacencyList *Graph[], int r){
	int i;
	for (i=0;i<VERTEX;i++){
		Graph[i]->key=INT_MAX;
		Graph[i]->father=NULL;
	}
	Graph[r]->key=0;
	LinkedList *Q;
	initializeList(&Q);
	for (i=0;i<VERTEX;i++)
		insertList(&Q,Graph[i]->vertexNumber,Graph[i]->key);
	while (Q!=NULL){	
		printList(&Q);
		while (getchar()!='\n');
		printFather(Graph);
		int u = extractMin(&Q);
		printf("\nu = %d\n",u);
		while (getchar()!='\n');	
		AdjacencyList *ptr;
		ptr=Graph[u];
		while (ptr->next!=NULL){
			ptr=ptr->next;
			if (verifyList(&Q,ptr->vertexNumber) && (ptr->edge < keyList(&Q,ptr->vertexNumber))){
				Graph[ptr->vertexNumber]->father=Graph[u];
				insertKey(&Q,ptr->vertexNumber,ptr->edge);
			}
		}
	}
}

int main(){
	AdjacencyList *Graph[VERTEX];
	initializeGraph(Graph);
	createGraph(Graph);
	printGraph(Graph);
	while (getchar()!='\n');
	printf("\n#### MST-PRIM ####\n\n");
	mstPrim(Graph,7);
	return 0;
}
