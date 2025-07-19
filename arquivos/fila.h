#ifndef FILA_H
#define FILA_H

#include "estruturas.h"

#define MAX 5

typedef struct fila {
    int in;
    int fin;
    int qtd;
    comanda info[MAX];
} FILA;

extern FILA* fi;

FILA* criarFila();
void liberarFila(FILA* fi);
int insereFila(FILA* fi, comanda c);
void exibirFila(FILA* fi);
int removerPedidoEspecifico(FILA* fi, int numPedido);

#endif

