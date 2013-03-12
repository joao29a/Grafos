#ifndef LISTAADJ_H_GUARD
#define LISTAADJ_H_GUARD

#define VERTICE 6
#define INICIO 0

typedef struct ListaVertice {
	int num_vertice;
	int grau_saida;
	int grau_entrada;
	int distancia;
	int aresta;
	char visitado;
	int pai;
	int carimboSaida;
	int carimboEntrada;
	struct ListaVertice *next;
}ListaAdj;

void criarVerticeADJ(ListaAdj *origem, int vertice, int aresta);

void ImprimirLista(ListaAdj *origem[]);

void criarVetPtr(ListaAdj *origem[]);

void zerarVisita(ListaAdj *vet[]);

void InserirVertices(ListaAdj *vet[]);

#endif
