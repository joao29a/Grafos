#include <stdlib.h>
#include <stdio.h>
#include "Lista ADJ/ListaAdjacencia.h"

int main(){
    ListaAdj *vet[VERTICE];
    criarVetPtr(vet);
    InserirVertices(vet);
    ImprimirLista(vet);
    return 0;
}
