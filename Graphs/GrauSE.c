#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista ADJ/ListaAdjacencia.h"
#include "GrauSE.h"

//Complexidade O(V+E)
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

//Complexidade O(V+E)
void GrauEntrada(ListaAdj *origem[]){
     ListaAdj *pont;
     int i;
     for (i=0;i<VERTICE;i++){
         pont=origem[i];
         while (pont->next!=NULL){
         	pont=pont->next;
         	origem[pont->num_vertice]->grau_entrada += 1;
         }
    }   
}

void ImprimirGrauEntrada(ListaAdj *origem[]){
     int i;
     printf("\nGrau de Entrada:\n");
     for (i=0;i<VERTICE;i++)
         printf("Vertice %d: %d\n",i,origem[i]->grau_entrada);
}
