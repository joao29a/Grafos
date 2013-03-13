#include <stdio.h>
#include <stdlib.h>
#include "Lista ADJ/ListaAdjacencia.h"
#include "Transposto.h"

void grafoTransposto(ListaAdj *vet[], ListaAdj *vetSaida[]){
	criarVetPtr(vetSaida);
	int i;
	for (i=0;i<VERTICE;i++){
		ListaAdj *temp=vet[i];
		while (temp->next!=NULL){
			temp=temp->next;
			criarVerticeADJ(vetSaida[temp->num_vertice],vet[i]->num_vertice,0);
		}
	}
}
