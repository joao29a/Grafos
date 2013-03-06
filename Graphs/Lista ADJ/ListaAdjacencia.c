#include <stdio.h>
#include <stdlib.h>
#include "ListaAdjacencia.h"

void InserirVertices(ListaAdj *vet[]){
     criarVerticeADJ(vet[0],1,5); //(saida,entrada,aresta);
     criarVerticeADJ(vet[0],2,10);
     criarVerticeADJ(vet[1],0,5);
     criarVerticeADJ(vet[1],2,8);
     criarVerticeADJ(vet[2],0,10);
     criarVerticeADJ(vet[2],1,8);
     criarVerticeADJ(vet[2],3,1);
     criarVerticeADJ(vet[2],4,3);
     criarVerticeADJ(vet[3],2,1);
     criarVerticeADJ(vet[4],2,3);
     /*criarVerticeADJ(vet[3],8);
     criarVerticeADJ(vet[4],1);
     criarVerticeADJ(vet[4],3);
     criarVerticeADJ(vet[5],6);
     criarVerticeADJ(vet[6],3);
     criarVerticeADJ(vet[6],5);
     criarVerticeADJ(vet[6],7);
     criarVerticeADJ(vet[7],6);
     criarVerticeADJ(vet[8],3);
     criarVerticeADJ(vet[8],9);
     criarVerticeADJ(vet[9],2);
     criarVerticeADJ(vet[9],8);
     criarVerticeADJ(vet[10],11);
     criarVerticeADJ(vet[11],10);
     criarVerticeADJ(vet[11],12);
     criarVerticeADJ(vet[12],2);
     criarVerticeADJ(vet[12],11);*/
}

void criarVerticeADJ(ListaAdj *origem, int vertice, int aresta){
     
     ListaAdj *apont;
     
     apont=origem;
     while (apont->next!=NULL)
           apont=apont->next;      
     apont->next=malloc(sizeof(ListaAdj));
     apont=apont->next;
     apont->num_vertice=vertice;
     apont->aresta=aresta;
     apont->next=NULL;
}

void ImprimirLista(ListaAdj *origem[]){
     ListaAdj *pont;
     int i;
     for (i=0;i<VERTICE;i++){
         pont=origem[i];
         printf("Vertice %d: ",origem[i]->num_vertice);
         while (pont->next!=NULL){
               pont=pont->next;
               printf("%d->%d| ",pont->num_vertice,pont->aresta);
         }
         printf("\n");
     }
}

void criarVetPtr(ListaAdj *origem[]){
     int i;
     for (i=0;i<VERTICE;i++){
        origem[i]=malloc(sizeof(ListaAdj));
        origem[i]->num_vertice=i;
        origem[i]->next=NULL;
     }
}

void zerarVisita(ListaAdj *vet[]){
     int i;
     for (i=0;i<VERTICE;i++){
         vet[i]->visitado='b';
         vet[i]->distancia=-1;
     }
}
