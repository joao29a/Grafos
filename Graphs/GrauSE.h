#ifndef GRAUSE_H
#define GRAUSE_H
#include "Lista ADJ/ListaAdjacencia.h"

//Complexidade O(V+E)
void GrauSaida(ListaAdj *origem[]);

void ImprimirGrauSaida(ListaAdj *origem[]);

//Complexidade O(V.E)
void GrauEntrada(ListaAdj *origem[]);

void ImprimirGrauEntrada(ListaAdj *origem[]);

#endif

