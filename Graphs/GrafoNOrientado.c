#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista ADJ/ListaAdjacencia.h"

void GrafoNaoOrientado(ListaAdj *vet[], ListaAdj *vetSaida[]){
     printf("\nGrafo Nao Orientado:\n");
     int i;
     for (i=0;i<VERTICE;i++){
        ListaAdj *ptr;
        ptr=vet[i];
        int Vetaux[VERTICE];
        while (ptr->next!=NULL){
              ptr=ptr->next;
              Vetaux[ptr->num_vertice]=0;      
        }
        ptr=vet[i];
        while (ptr->next!=NULL){
              ptr=ptr->next;
              if (ptr->num_vertice!=vet[i]->num_vertice 
              && Vetaux[ptr->num_vertice]==0){
                  criarVerticeADJ(vetSaida[i],ptr->num_vertice,0);
                  criarVerticeADJ(vetSaida[ptr->num_vertice],vet[i]->num_vertice,0);     
                  Vetaux[ptr->num_vertice]++;
              }
        }
     }
}

int main(){
    ListaAdj *vet[VERTICE];
    criarVetPtr(vet);
    InserirVertices(vet);
    ImprimirLista(vet);
    
    ListaAdj *vetSaida[VERTICE];
    criarVetPtr(vetSaida);
    GrafoNaoOrientado(vet,vetSaida);
    ImprimirLista(vetSaida);
    
    return 0;
}
