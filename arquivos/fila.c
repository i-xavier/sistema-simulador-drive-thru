#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "fila.h"
#include "estruturas.h"

FILA* fi;

FILA* criarFila() {
    FILA* fi = (FILA*) malloc(sizeof(struct fila));
    if (fi != NULL) {
        fi->in = 0;
        fi->fin = 0;
        fi->qtd = 0;
    }
    return fi;
}

void liberarFila(FILA* fi) {
    free(fi);
}

int insereFila(FILA* fi, comanda c1) {
    if (fi == NULL || fi->qtd == MAX) {
        printf("\nERRO: A fila de espera esta cheia!\n"); getch();
        return 0;
    }
    fi->info[fi->fin] = c1;
    fi->fin = (fi->fin + 1) % MAX;
    fi->qtd++;
    
    printf("\n*******************************************************");
    printf("\nSEU PEDIDO E GRANDE E FOI MOVIDO PARA A FILA DE ESPERA!");
    printf("\n*******************************************************\n");
    getch();
    return 1;
}

int removerPedidoEspecifico(FILA* fi, int numPedido) {
    if (fi == NULL || fi->qtd == 0) return 0; // Fila não existe ou está vazia

    int i, j;
    int pos_encontrado = -1;
    int atual = fi->in;

    // 1. Encontra a posição do pedido a ser removido
    for (i = 0; i < fi->qtd; i++) {
        if (fi->info[atual].numPedido == numPedido) {
            pos_encontrado = atual;
            break;
        }
        atual = (atual + 1) % MAX;
    }

    // Se o pedido não foi encontrado na fila, não faz nada
    if (pos_encontrado == -1) return 0;

    // 2. Reorganiza a fila: move todos os elementos posteriores uma posição para trás
    j = pos_encontrado;
    for (i = 0; i < fi->qtd - 1; i++) {
        int proximo_j = (j + 1) % MAX;
        // Só continua a mover se o ponteiro não alcançar o fim da fila
        if (proximo_j != fi->fin) {
             fi->info[j] = fi->info[proximo_j];
             j = proximo_j;
        } else {
            break;
        }
    }

    // 3. Atualiza os ponteiros da fila
    fi->fin = (fi->fin - 1 + MAX) % MAX; // Move o ponteiro final para trás
    fi->qtd--;

    printf("\nPedido #%d pago e removido da fila de espera automaticamente!\n", numPedido);
    getch();
    return 1;
}

void exibirFila(FILA* fi) {
    system("cls");
    system("color ce");
    printf("\n===================================");
    printf("\n   PEDIDOS NA FILA DE ESPERA   ");
    printf("\n===================================\n\n");
    if (fi == NULL || fi->qtd == 0) {
        printf("  Nenhum pedido em fila de espera no momento.\n");
    } else {
        int i = fi->in;
        int count;
        for (count = 0; count < fi->qtd; count++) {
            printf("  -> Pedido Nro: %d | Itens: %d | Valor Total: R$ %.2f\n",
                   fi->info[i].numPedido, fi->info[i].prodTotal, fi->info[i].valorTotal);
            i = (i + 1) % MAX;
        }
    }
    printf("\n\nPressione qualquer tecla para voltar ao menu...");
    getch();
}

