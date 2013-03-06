#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha/Pilha.h"
#include "Lista ADJ/ListaAdjacencia.h"

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

//Depth-first search recursive
void DFSR(ListaAdj *vet[], int selecionado){
     vet[selecionado]->visitado='c';
     ListaAdj *ptr=vet[selecionado];
     printf("%d ",selecionado);
     while (ptr->next!=NULL){
           ptr=ptr->next;
           if (vet[ptr->num_vertice]->visitado=='b'){
              DFSR(vet,ptr->num_vertice);             
           }
     }
}

int main(){
     ListaAdj *vet[VERTICE];
     criarVetPtr(vet);
     InserirVertices(vet);
     ImprimirLista(vet);
     DFS(vet,INICIO);
     zerarVisita(vet);
     printf("Depth-first search recursive: ");
     DFSR(vet,INICIO);
     return 0;
}
