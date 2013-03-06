#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista ADJ\ListaAdjacencia.c"

void GrauSaida(ListaAdj *origem[]){
     ListaAdj *pont;
     int i;
     for (i=0;i<VERTICE;i++){
         origem[i]->grau_saida=0;
         pont=origem[i];
         while (pont->next!=NULL){
               origem[i]->grau_saida++;
               pont=pont->next;
         }
     }
}

void ImprimirGrauSaida(ListaAdj *origem[]){
     int i;
     printf("\nGrau de Saida:\n");
     for (i=0;i<VERTICE;i++)
         printf("Vertice %d: %d\n",i,origem[i]->grau_saida);
}

void GrauEntrada(ListaAdj *origem[]){
     ListaAdj *pont;
     int i;
     for (i=0;i<VERTICE;i++){
         origem[i]->grau_entrada=0;
         int j;
         for (j=0;j<VERTICE;j++){         
             pont=origem[j];
             while (pont->next!=NULL){
                   pont=pont->next;
                   if (origem[i]->num_vertice==pont->num_vertice)
                      origem[i]->grau_entrada++;
             }
         }
     }   
}

void ImprimirGrauEntrada(ListaAdj *origem[]){
     int i;
     printf("\nGrau de Entrada:\n");
     for (i=0;i<VERTICE;i++)
         printf("Vertice %d: %d\n",i,origem[i]->grau_entrada);
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
    
    system("PAUSE");
    return 0;
}