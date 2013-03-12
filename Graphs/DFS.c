#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha/Pilha.h"
#include "Lista ADJ/ListaAdjacencia.h"

int tempo;

//Depth-first search non-recursive
void DFS(ListaAdj *vet[], int selecionado){
	zerarVisita(vet);
	printf("\nDepth-first search: ");
	Pilha *track;
	track=NULL;
	Empilhar(&track,selecionado);
	while(track!=NULL){
		int elemento;
		do{
			elemento=Desempilhar(&track);
		}while (vet[elemento]->visitado=='c' && track!=NULL);
		if (vet[elemento]->visitado=='c')
			break;
		printf("%d ",elemento);
		ListaAdj *ptr=vet[elemento];
		vet[elemento]->visitado='c';
		while (ptr->next!=NULL){
			ptr=ptr->next;
			if (vet[ptr->num_vertice]->visitado=='b'){
				Empilhar(&track,ptr->num_vertice);             
			}
		}
	}
	printf("\n");
}

void DFSvisit(ListaAdj *vet[], int selecionado){
	vet[selecionado]->visitado='c';
	tempo++;
	vet[selecionado]->carimboEntrada=tempo;
	ListaAdj *ptr=vet[selecionado];
	while (ptr->next!=NULL){
		ptr=ptr->next;
		if (vet[ptr->num_vertice]->visitado=='b'){
			vet[ptr->num_vertice]->pai=selecionado;
			DFSvisit(vet,ptr->num_vertice);             
		}
	}
	vet[selecionado]->visitado='p';
	tempo=tempo+1;
	vet[selecionado]->carimboSaida=tempo;
	printf("Vertice: %2d | Pai: %2d | Entrada: %2d | Saida: %2d\n",vet[selecionado]->num_vertice,vet[selecionado]->pai,
					vet[selecionado]->carimboEntrada,vet[selecionado]->carimboSaida);	
}

//Depth-first search recursive
void DFSR(ListaAdj *vet[]){
	int i;
	for (i=0;i<VERTICE;i++){
		vet[i]->visitado='b';
		vet[i]->pai=-1;
	}
	tempo=0;
	for (i=0;i<VERTICE;i++)
		if (vet[i]->visitado=='b'){
			DFSvisit(vet,vet[i]->num_vertice);
		}
}

int main(){
	ListaAdj *vet[VERTICE];
	criarVetPtr(vet);
	InserirVertices(vet);
	ImprimirLista(vet);
	/*DFS(vet,INICIO);
	zerarVisita(vet);*/
	printf("Depth-first search recursive:\n");
	DFSR(vet);
	return 0;
}
