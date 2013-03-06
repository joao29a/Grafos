#include <stdlib.h>
#include <stdio.h>
#include "Lista ADJ\ListaAdjacencia.c"

int main(){
    ListaAdj *vet[VERTICE];
    criarVetPtr(vet);
    InserirVertices(vet);
    ImprimirLista(vet);
    system("PAUSE");
    return 0;
}
