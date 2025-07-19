#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "estruturas.h"

void entregaPedido(int numPedido) {
    comanda c1;
    int pedidoEncontrado = 0; // Flag para controlar se o pedido foi encontrado e pago

    FILE* arq = fopen("PAGAMENTOS.DAT", "rb");
    if (arq == NULL) {
        printf("Nenhum pagamento registrado ainda.\n");
        getch();
        return;
    }
	
    // Loop para ler o arquivo inteiro
    while (fread(&c1, sizeof(comanda), 1, arq) == 1) {
        if (numPedido == c1.numPedido) {
            pedidoEncontrado = 1; // Encontrou o pedido
            system("cls");

            // Define a cor baseada no tipo de pagamento
            if (c1.tipoPgto == DINHEIRO) system("color f2");      // Verde [cite: 66]
            else if (c1.tipoPgto == PIX) system("color f1");          // Azul [cite: 67]
            else if (c1.tipoPgto == DEBITO || c1.tipoPgto == CREDITO) system("color fD"); // Lilás [cite: 67]

            system("cls");
    		printf("\n===================================================");
    		printf("\nPEDIDO #%d PAGO COM: %s ", numPedido, formasPagamento[c1.tipoPgto]); // [cite: 66]
            printf("\n===================================================");
    		printf("\t\n\nOBRIGADO E VOLTE SEMPRE!!");
            break; // Pode parar o loop, pois já achou e processou
        }
    }

    fclose(arq);

    // Verifica a flag DEPOIS de fechar o arquivo
    if (!pedidoEncontrado) {
        printf("\nO pedido #%d nao foi encontrado na lista de pagamentos!\n", numPedido);
    }

    getch();
}

