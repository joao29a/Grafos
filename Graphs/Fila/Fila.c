#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

void EnfileirarFila(Fila **lista, int valor){
     Fila *listaAux;
     
     listaAux=(*lista);
     
     if (listaAux==NULL){
        listaAux=malloc(sizeof(Fila));
        listaAux->num=valor;
        listaAux->prox=NULL;
        (*lista)=listaAux;
     }
     else{
          while (listaAux->prox!=NULL){
              listaAux=listaAux->prox;
          }
          listaAux->prox=malloc(sizeof(Fila));
          listaAux=listaAux->prox;
          listaAux->num=valor;
          listaAux->prox=NULL;
     }                                  
}

int RetirarFila(Fila **lista){
     Fila *listaAux;
     listaAux=(*lista);
     int valor=listaAux->num;
     (*lista)=(*lista)->prox;
     free(listaAux);
     return valor;
}
