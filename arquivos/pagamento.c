#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "fila.h"
#include "estruturas.h"
#include "admin.h"
#include "pedidos.h"
#include "entregas.h"


void clr();
void lerPedido (void);

int pagamentoDinheiro (float valorTotal){
	float din, dif, dif2, troco;
	din = dif = dif2 = troco = 0;

	printf("\nDigite o valor que será pago: ");
	scanf("%f", &din); clr();

	dif = valorTotal - din; /*calcula quanto falta ser pago*/

	if ( din <= 0)
	{
		printf("\nValor inválido.");
		return 0;
	}

	while (din){

		if (din < valorTotal)
		{
			while (dif > 0){

				printf("\nO valor %.2f é menor do que %.2f. Falta %.2f reais!.\nInsira o valor faltante.", din, valorTotal, dif);
				scanf("%f", &dif2); clr();
				dif = dif - dif2;
				din = din + dif2;

				}

				if (din > valorTotal) {
					troco = din - valorTotal;
					printf("\nFoi pago um valor que ultrapassa o total.\nSeu troco é de: %.2f Reais", troco);
					printf("\nPagamento aceito! \nVolte sempre!");
					return 1;
					}

				else {
						printf("\nPagamento aceito! \nVolte sempre!");
					return 1;
				}
		}

		else if (din > valorTotal){
			troco = din - valorTotal;
			printf("\nFoi pago um valor que ultrapassa o total.\nSeu troco é de: %.2f Reais", troco);
			printf("\n\nVolte sempre!");
			return 1;
		}

		else if (din == valorTotal){
			printf("\nPagamento aceito! Volte sempre!");
			return 1;
		}

	}
}

void gravarCard (cartoes *c){
	FILE *arq;

	arq = fopen("CARTOES.DAT", "a");

	if (arq == NULL){

		printf("Erro ao abrir arquivo.");
		getch();
		exit(0);
	}

	fwrite (c, sizeof(cartoes), 1, arq);


	fclose(arq);
	printf("\nCartão gravado com sucesso!");
	Sleep(1000);
	getch();
}

int pagamentoPix(float valorTotal) { 
	int seg, min;
	char esc;

	min = 0;
	seg = 30;
	esc = 0;

	do {
        Sleep(1000);
        system("cls");
        system("color ce");

    printf("¦¦¦¦      MMMMMMMMMMMMMMMMMMMMM...MMMMMMMMMMMMMMM...MMMMMMMMMMMMMMMMMMMMM       ¦¦¦¦\n");
    printf("¦¦¦¦      MMMMMMMMMMMMMMMMMMMMM...MMMMMMMMMMMMMMM...MMMMMMMMMMMMMMMMMMMMM       ¦¦¦¦\n");
    printf("¦¦¦¦      MMM...............MMM...MMM...MMM...MMM...MMM...............MMM       ¦¦¦¦\n");
    printf("¦¦¦¦      MMM...MMMMMMMMM...MMM...MMM...............MMM...MMMMMMMMM...MMM       ¦¦¦¦\n");
    printf("¦¦¦¦      MMM...MMMMMMMMM...MMM...MMM...............MMM...MMMMMMMMM...MMM       ¦¦¦¦\n");
    printf("¦¦¦¦      MMM...MMMMMMMMM...MMM...MMMMMMMMMMMM......MMM...MMMMMMMMM...MMM       ¦¦¦¦\n");
    printf("¦¦¦¦      MMM...MMMMMMMMM...MMM...............MMM...MMM...MMMMMMMMM...MMM       ¦¦¦¦\n");
    printf("¦¦¦¦      MMM...MMMMMMMMM...MMM...............MMM...MMM...MMMMMMMMM...MMM       ¦¦¦¦\n");
    printf("¦¦¦¦      MMM...............MMM...MMMMMM...MMM......MMM...............MMM       ¦¦¦¦\n");
    printf("¦¦¦¦      MMMMMMMMMMMMMMMMMMMMM...MMM...MMM...MMM...MMMMMMMMMMMMMMMMMMMMM       ¦¦¦¦\n");
    printf("¦¦¦¦      MMMMMMMMMMMMMMMMMMMMM...MMM..MMMMM..MMM...MMMMMMMMMMMMMMMMMMMMM       ¦¦¦¦\n");
    printf("¦¦¦¦      ...........................MMMMMMMMMMMM........................       ¦¦¦¦\n");
    printf("¦¦¦¦      MMMMMM......MMMMMMMMM......MMM...MMM.........MMM...MMMMMMMMMMMM       ¦¦¦¦\n");
    printf("¦¦¦¦      MMMMM.......MMMMMMMM.......MMM...MMMM.........MM...MMMMMMMMMMMM       ¦¦¦¦\n");
    printf("¦¦¦¦      MMM......MMM...MMM............MMMMMMMMM.........MMMMMMMMMMMM...       ¦¦¦¦\n");
    printf("¦¦¦¦      ...MMMMMMMMM......MMM...MMMMMM...MMM......MMMMMMMMM......MMM...       ¦¦¦¦\n");
    printf("¦¦¦¦      ...MMMMMMMMM......MM....MMMMMM...MMM......MMMMMMMMM......MMM...       ¦¦¦¦\n");
    printf("¦¦¦¦      ......MMM...MMMMMM.........MMMMMM......MMM...............MMM...       ¦¦¦¦\n");
    printf("¦¦¦¦      MMMMMMMMM......MMMMMM...MMM...MMM...MMMMMM.........MMM.........       ¦¦¦¦\n");
    printf("¦¦¦¦      MMMMMMMM.......MMMMM....MMM...MMM...MMMMMMM........MMMM........       ¦¦¦¦\n");
    printf("¦¦¦¦      ........................MMM...MMM...MMMMMMMMMMMMMMMMMMMMMMMM...       ¦¦¦¦\n");
    printf("¦¦¦¦      MMMMMMMMMMMMMMMMMMMMM......MMM......MMMMMMMMM...MMM...MMMMMM...       ¦¦¦¦\n");
    printf("¦¦¦¦      MMMMMMMMMMMMMMMMMMMMM.....MMMM......MMMMMMMMM...MMM....MMMMMM..       ¦¦¦¦\n");
    printf("¦¦¦¦      MMM...............MMM...MMMMMMMMMMMMMMMMMM......MMM......MMMMMM       ¦¦¦¦\n");
    printf("¦¦¦¦      MMM...MMMMMMMMM...MMM...MMMMMM...MMM...MMM...MMM.........MMM...       ¦¦¦¦\n");
    printf("¦¦¦¦      MMM...MMMMMMMMM...MMM...MMMMMM...MMM...MMM....MM.........MMMM..       ¦¦¦¦\n");
    printf("¦¦¦¦      MMM...MMMMMMMMM...MMM.........MMM...MMM.........MMM...MMMMMMMMM       ¦¦¦¦\n");
    printf("¦¦¦¦      MMM...MMMMMMMMM...MMM............MMM...MMMMMM...MMMMMMMMM......       ¦¦¦¦\n");
    printf("¦¦¦¦      MMM...MMMMMMMMM...MMM............MMM...MMMMMM...MMMMMMMMM......       ¦¦¦¦\n");
    printf("¦¦¦¦      MMM...............MMM...MMMMMMMMM......MMM......MMM............       ¦¦¦¦\n");
    printf("¦¦¦¦      MMMMMMMMMMMMMMMMMMMMM...MMM...MMMMMM...MMM......MMM.........MMM       ¦¦¦¦\n");
    printf("¦¦¦¦      MMMMMMMMMMMMMMMMMMMMM...MMM...MMMMMM...MMM......MMM.........MMM       ¦¦¦¦\n");
    printf("\n[ SIMULAÇÃO QR CODE PIX ]\n");
    printf("Total a pagar: R$ %.2f\n", valorTotal);

    printf("\nTempo restante:\t%dm:%ds", min, seg);
    printf("\t\t\t\tFazer pix? s/n \n");

        seg--;
        if (seg < 0) {
            seg = 59;
            min--;
        }

        if (_kbhit()) { //Identifica se foi digitado algo
			esc = getche(); //Recebe o que foi digirado
            if (esc == 's' || esc == 'S') {
                printf("\n\n\t\t\t\tPIX realizado com sucesso!\n");
                Sleep(1500);
                return 1;
            } else if (esc == 'n' || esc == 'N') {
                printf("\n\n\t\t\t\tPagamento cancelado.\n");
                Sleep(1500);
                return 0;
            }
        }

        if (min < 0) {
            printf("\n\t\t\t\tTempo limite alcançado, código do pix expirado.");
            Sleep(1500);
            return 0;
        }
    } while (1);
}


cartoes* validaCartao(int numPedido) {
    comanda c1;
    char num[17]; // 16 dígitos + 1 para o terminador nulo '\0'
    int tipo, i, j, flag;

    cartoes *c = (cartoes*) malloc(sizeof(cartoes));
    if (c == NULL) {
        printf("\nFalha na alocação de memória!");
        exit(1);
    }

    printf("\nO cartão é Débito(1) ou Crédito(2)? ");
    scanf("%i", &tipo);
    clr();

    // Loop para garantir que um número válido de 16 dígitos seja inserido
    while (1) {
        printf("\nDigite o numero do seu cartao (16 digitos, sem espacos): ");
        scanf("%16s", num);
        clr();

        j = strlen(num);
        flag = 0; // Reseta a flag a cada tentativa

        // Verifica se todos os caracteres são dígitos
        for (i = 0; i < j; i++) {
            if (num[i] < '0' || num[i] > '9') {
                flag = 1;
                break;
            }
        }

        // Se o tamanho for 16 e não houver não-dígitos, o cartão é válido.
        if (j == 16 && flag == 0) {
            break; // Sai do loop while
        } else {
            // Mensagem de erro conforme solicitado no documento do projeto
            printf("\nCartao invalido, digite novamente! ");
        }
    }


    //Copia o número completo e válido para a estrutura.
    strcpy(c->numCartao, num);

    for (i = 4; i < 12; i++) {
        c->numCartao[i] = '*';
    }

    // Define o tipo de pagamento e o número do pedido na estrutura
    if (tipo == 1) {
        c1.tipoPgto = DEBITO;
    } else { 
        c1.tipoPgto = CREDITO;
    }

    c1.numPedido = numPedido;
    c->coma = c1; // Associa a comanda com os dados do cartão

    return c;
}



void gravarPagamento (comanda c1){
	
	FILE *arq = fopen("PAGAMENTOS.DAT", "ab");
	
	if(arq == NULL) {
		
		printf("Erro ao abrir arquivo. ");
		getch();
		exit(0);
	}
	
	fwrite(&c1, sizeof(comanda), 1, arq);
	
	fclose(arq);
	getch();
	
}


void pagarCartao(int numPedido, cartoes *c) {
    FILE *arqPedidos = fopen("PEDIDOS.DAT", "rb");
    if (arqPedidos == NULL) {
        printf("\nErro ao abrir arquivo de pedidos para leitura.");
        getch();
        return;
    }

    FILE *arqPagamentos = fopen("PAGAMENTOS.DAT", "ab"); // ab para adicionar
    if (arqPagamentos == NULL) {
        printf("\nErro ao abrir arquivo de pagamentos.");
        fclose(arqPedidos);
        getch();
        return;
    }

    comanda c1;
    int pedidoEncontrado = 0;

    while (fread(&c1, sizeof(comanda), 1, arqPedidos) == 1) {
        if (c1.numPedido == numPedido) {
            pedidoEncontrado = 1;
            break;
        }
    }
    fclose(arqPedidos);

    if (!pedidoEncontrado) {
        printf("\nPedido número %d não encontrado!", numPedido);
        getch();
        fclose(arqPagamentos);
        return;
    }

    // Associa o tipo de pagamento ao pedido
    c1.tipoPgto = (c->numCartao[0] == '*') ? CREDITO : DEBITO;

    // Grava o pedido com tipoPgto no arquivo de pagamentos
    fwrite(&c1, sizeof(comanda), 1, arqPagamentos);

    fclose(arqPagamentos);

    printf("\nPagamento com cartão registrado com sucesso!");
    getch();
}



char pagarPedido(int numPedido, float valorTotal) {
    char escolha;
    int ret, pedidoEncontrado = 0;
    comanda c1;

    FILE *arqPedidos = fopen("PEDIDOS.DAT", "rb");
    if (arqPedidos == NULL) {
        printf("\nErro ao abrir arquivo de pedidos para pagamento."); getch();
        return '0';
    }

    while(fread(&c1, sizeof(comanda), 1, arqPedidos) == 1) {
        if (c1.numPedido == numPedido) {
            pedidoEncontrado = 1;
            break;
        }
    }
    fclose(arqPedidos);

    if (!pedidoEncontrado) {
        printf("\nPedido numero %d nao encontrado!", numPedido); getch();
        return '0';
    }

    valorTotal = c1.valorTotal;

    do {
        system("cls");
        system("color ce");
        printf("\n====================");
        printf("\n  P A G A M E N T O ");
        printf("\n  Pedido Nro: %d", numPedido);
        printf("\n  Total a Pagar: R$ %.2f", valorTotal);
        printf("\n====================");
        printf("\n   1. Dinheiro");
        printf("\n   2. Cartao de Credito/Debito");
        printf("\n   3. PIX");
        printf("\n--------------------");
        printf("\n   0. Cancelar Pagamento");
        printf("\n====================");
        printf("\n   Escolha: ");
        escolha = getche();

        switch (escolha) {
            case '1': {
                ret = pagamentoDinheiro(valorTotal);
                if (ret == 1) {
                    c1.tipoPgto = DINHEIRO;
                    gravarPagamento(c1);
                    if (c1.fila == 1) removerPedidoEspecifico(fi, numPedido); // REMOÇÃO AUTOMÁTICA
                }
                entregaPedido(numPedido);
            } break;

            case '2': {
                cartoes *a = validaCartao(numPedido);
                if (a != NULL) {
                    gravarCard(a);
                    pagarCartao(numPedido, a);
                    if (c1.fila == 1) removerPedidoEspecifico(fi, numPedido); // REMOÇÃO AUTOMÁTICA
                    free(a);
                    a = NULL;
                }
                entregaPedido(numPedido);
            } break;

            case '3': {
                ret = pagamentoPix(valorTotal);
                if (ret == 1) {
                    c1.tipoPgto = PIX;
                    gravarPagamento(c1);
                    if (c1.fila == 1) removerPedidoEspecifico(fi, numPedido); // REMOÇÃO AUTOMÁTICA
                }
                entregaPedido(numPedido);
            } break;

            case '0': return '0'; // Sai da função de pagamento
        }
        // Se o pagamento foi efetuado (escolha válida), sai do loop
        if (escolha >= '1' && escolha <= '3') break;

    } while (1); // Loop infinito até que uma opção válida seja escolhida e processada

    return escolha;
}

