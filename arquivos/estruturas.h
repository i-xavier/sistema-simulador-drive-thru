#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#define MAX_PRODUTOS 10


extern const char* formasPagamento[];

typedef enum {
    DINHEIRO,
    DEBITO,
    CREDITO,
    PIX
} formapgto;

typedef struct {
    int     codprod;
    char    nomeprod[60 + 1];
    float   custoprod;
    int     qtdprod;
} produtos;

typedef struct {
    produtos prod[MAX_PRODUTOS];
    int     qtdProdutos;
    int     numPedido;
    float   valorTotal;
    formapgto tipoPgto;
    int     fila;
    int     prodTotal;
} comanda;

typedef struct {
    comanda coma;
    char numCartao[16 + 1];
} cartoes;

#endif
