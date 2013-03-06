#ifndef FILA_H_GUARD
#define FILE_H_GUARD
typedef struct queue{
        int num;
        struct queue *prox;
}Fila;

void EnfileirarFila(Fila **lista, int valor);

int RetirarFila(Fila **lista);

#endif
