#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "fila.h"
#include "admin.h"
#include "pagamento.h"
#define FILA 5

void clr();

int gerarCodPedido (void){
	int codigo, flag;
	produtos p;
	comanda c1;
		
	codigo = 1;
	flag = 0;
	
	FILE *arq;
	arq = fopen("PEDIDOS.DAT", "rb");
	
	if (arq == NULL){
		return codigo;
	}
	
	while(fread(&c1, sizeof(c1), 1, arq) == 1){
		
		flag = 1;
	} 
	
	fclose(arq);
	
	if (flag == 1){
		
		codigo = c1.numPedido + 1;
	}
	
	return codigo;
}

void lerCardapio (void){
	
	produtos p;
	comanda c1;

	
	FILE *arq; /*abre arquivo*/
	arq = fopen ("PRODUTOS.DAT", "rb");
	
	if (arq == NULL){ /*testa para ver se o arquivo esta vazio*/
		
		printf("\nErro ao abrir");
		getch();
		exit(1);
	}
	
	system("color ce");
	printf("\n==============C A R D A P I O=================");
	printf("\n==============================================");
	printf("\n\n%-5s %-40s %-15s\n", "COD", "NOME", "\tPREÇO");
	 while (fread(&p, sizeof(p), 1, arq) == 1) {
        printf("\n%3i\t%-40s\tR$%12.2f", p.codprod, p.nomeprod, p.custoprod);
    }
	printf("\n\nAperte Enter para continuar....");
	
	fclose(arq);
	getchar();
	
}


void fazerPedido(void) {
    comanda c1;
    produtos p;
    int codigoProd, numPedido, qtdProd, i, encontrado;
    char escolha, pagar;

    c1.numPedido = gerarCodPedido();
    c1.qtdProdutos = 0;
    c1.valorTotal = 0;
    c1.fila = 0;
    c1.prodTotal = 0;
    i = 0;
    encontrado = 0;

    do {
        system("cls");
        system("color ce");
        lerCardapio(); // Mostra o cardápio

        printf("\nDigite o código do produto: ");
        scanf("%d", &codigoProd); clr();

        printf("Digite a quantidade desejada: ");
        scanf("%d", &qtdProd); clr();

        FILE *arq = fopen("PRODUTOS.DAT", "rb");
        if (arq == NULL) {
            printf("Erro ao abrir PRODUTOS.DAT.\n");
            getch();
            exit(1);
        }
		
        while (fread(&p, sizeof(produtos), 1, arq) == 1) {
            if (p.codprod == codigoProd) {
                c1.prod[i] = p; //recebe o produto
                c1.prod[i].qtdprod = qtdProd;  // salva quantidade solicitada
                c1.valorTotal += p.custoprod * qtdProd; // multiplica o custo pela quantidade e soma ao valor total
                c1.prodTotal = c1.prodTotal + qtdProd; //soma q quantidade conforme o usuário solicita mais pedidos
				c1.qtdProdutos++; //soma um a cada volta no laço
                i++;
                encontrado = 1; //se encontrar produto recebe um
                break;
            }
        }

        fclose(arq);

        if (!encontrado) {
            printf("Produto não encontrado!\n");
        }

        if (c1.prodTotal >= FILA) {
            c1.fila = 1;
            
        }

        printf("\nDeseja adicionar mais produtos? (s/n): ");
        fflush(stdin);
        scanf(" %c", &escolha); clr();

    } while (escolha != 'n' && escolha != 'N'); //conforme o laço vai girando vai sendo acumulado o pedido do usuário na memória por meio de c1

    if (c1.fila == 1){
    	
    	insereFila(fi, c1);
	}
	
    FILE *fp = fopen("PEDIDOS.DAT", "ab"); //salva o produto no final
    if (fp == NULL) {
        printf("\nErro ao salvar o pedido.\n");
        exit(1);
    }
    fwrite(&c1, sizeof(comanda), 1, fp);
    fclose(fp);

    printf("\nPedido salvo com sucesso!\nNúmero do pedido: %d\nDeseja paga-lo agora? (s = sim)\n", c1.numPedido);
    scanf("%c", &pagar); clr();
    
    	if(pagar == 's' || pagar == 'S' ) {
    		pagarPedido(c1.numPedido, c1.valorTotal);
		}
		
		else return;
		
	getch();
}


void lerPedido (void){
	produtos p;
	comanda c1;
	int i = 0;

	FILE *arq; /*abre arquivo*/
	arq = fopen ("PEDIDOS.DAT", "rb");

	if (arq == NULL){ /*testa para ver se o arquivo esta vazio*/

		printf("\nErro ao abrir");
		getchar();
		exit(1);
	}

	while (fread (&c1, sizeof(c1), 1, arq)== 1){ /*enquanto não chegar no fim do arquivo ele será lido*/

		if (c1.prod[i].codprod == 0){
					break;
				}

		c1.numPedido = 1;
		c1.qtdProdutos = 3;

		if (c1.numPedido == 1 ){
			printf("\nPedido #%d - Total: R$%.2f\n", c1.numPedido, c1.valorTotal);
			for(i = 0; i < c1.qtdProdutos; i++){

				printf ("\n%3i\t%-21s\t\tR$%12.2f\tx%i",
				c1.prod[i].codprod,
				c1.prod[i].nomeprod,
				c1.prod[i].custoprod,
				c1.prod[i].qtdprod);

					}
				}

	}

	fclose(arq);
	getchar();
    return;
}

