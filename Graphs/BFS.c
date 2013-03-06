#include <stdio.h>
#include <stdlib.h>
#include "Fila/Fila.h"
#include "Lista ADJ/ListaAdjacencia.h"

void BFS(ListaAdj *vet[], int selecionado){
     zerarVisita(vet);
     vet[selecionado]->visitado='c';
     vet[selecionado]->distancia=0;     
     Fila *lista;
     lista=NULL;
     EnfileirarFila(&lista,selecionado);
     while (lista!=NULL){
           int elemento=RetirarFila(&lista);
           ListaAdj *ptr=vet[elemento];
           while (ptr->next!=NULL){
                 ptr=ptr->next;
                 if (vet[ptr->num_vertice]->visitado=='b'){
                    vet[ptr->num_vertice]->visitado='c';
                    vet[ptr->num_vertice]->distancia=vet[elemento]->distancia+1;
                    EnfileirarFila(&lista,ptr->num_vertice);
                 }
           }
     }
}

void imprimirDistancia(ListaAdj *vet[]){
     printf("\n\nBreadth-first search VERTICE %d:\n",INICIO);
     int i;
     for (i=0;i<VERTICE;i++)
         printf("Vertice %d: %d\n",i,vet[i]->distancia);
     printf("\n");
}

int main(){
    ListaAdj *vet[VERTICE];
    criarVetPtr(vet);
    InserirVertices(vet);
    ImprimirLista(vet);
    BFS(vet,INICIO);
    imprimirDistancia(vet);
    return 0;
}
