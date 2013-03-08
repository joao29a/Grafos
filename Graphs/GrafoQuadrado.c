#include <stdio.h>
#include <stdlib.h>
#include "Lista ADJ/ListaAdjacencia.h"
#include "GrauSE.h"

void GrafoQuadrado(ListaAdj *vet[], ListaAdj *vetSaida[]){
	printf("\nGrafo Quadrado:\n");
	int i;
	for (i=0;i<VERTICE;i++){
		ListaAdj *ptr;
		ptr=vet[i];
		while (ptr->next!=NULL){
			ptr=ptr->next;
			ListaAdj *ptr2;
			ptr2=vet[ptr->num_vertice];
			while (ptr2->next!=NULL){
				ptr2=ptr2->next;
				if (ptr->num_vertice!=ptr2->num_vertice)
					criarVerticeADJ(vetSaida[i],ptr2->num_vertice,0);
			}
		}
	}
}

int main(){
	ListaAdj *vet[VERTICE];
	criarVetPtr(vet);
	InserirVertices(vet);
	ImprimirLista(vet);
	GrauSaida(vet);
	ImprimirGrauSaida(vet);
	GrauEntrada(vet);
	ImprimirGrauEntrada(vet);

	ListaAdj *vetSaida[VERTICE];
	criarVetPtr(vetSaida);
	GrafoQuadrado(vet,vetSaida);
	ImprimirLista(vetSaida);

	return 0;
}
