#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include "estruturas.h"

void clr();
int pagamentoDinheiro(float valorTotal);
int pagamentoPix(float valorTotal);
cartoes* validaCartao(int numPedido);
void gravarCard(cartoes *c);
void gravarPagamento(comanda c1);
void pagarCartao(int numPedido, cartoes *c);
char pagarPedido(int numPedido, float valorTotal);
void menuPagamento (void);


#endif
