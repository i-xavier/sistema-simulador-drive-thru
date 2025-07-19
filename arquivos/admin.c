#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "estruturas.h"


void clr() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

produtos vet[20] = {
    // --- Lanches Principais ---
    {1, "Gran Pato Donald ", 38.50},
    {2, "Cheddar Mickey Melt ", 42.90},
    {3, "Clubhouse Frango do Pluto", 35.70},
    {4, "Tio Patinhas Bacon", 39.90},
    {5, "Cheeseburger Margarida", 15.00},

    // --- Acompanhamentos ---
    {6, "Batatas do Tico (Cheddar)", 9.50},
    {7, "Batatas do Teco (Bacon)", 16.50},
    {8, "Anéis de Cebola do Bafo-de-Onça", 14.00},
    {9, "Nuggets Mágicos (10 unidades)", 21.00},
    {10, "Salada da Minnie", 25.00},

    // --- Combos (Lanche + Batata Média + Refri) ---
    {11, "Combo Gran Pato Donald", 52.50},
    {12, "Combo Mickey Melt", 56.90},
    {13, "Combo Clubhouse do Pluto", 49.70},

    // --- Sobremesas ---
    {14, "Torta de Maçã da Vovó Donalda", 12.00},
    {15, "Sundae do Gastão (Caramelo e Amendoim)", 14.50},
    {16, "McShake de Morango da Minie", 18.00},

    // --- Bebidas ---
    {17, "Refrigerante Mágico (500ml)", 9.00},
    {18, "Suco de Laranja do Pomar do Pluto", 11.00},
    {19, "Água Mineral do Lago dos Patos", 6.00},
    {20, "Café do Professor Ludovico", 7.50}
};

produtos p;

int gerarCod (void){
	int codigo = 1;
	int flag = 0; 
	
	FILE *arq;
	arq = fopen("PRODUTOS.DAT", "rb");
	
	if (arq == NULL){
		return codigo; // Se tiver vazia retorna 1 
	}
	
	while(fread(&p, sizeof(p), 1, arq) == 1){
		
		flag = 1; // Se achar algum produto flag recebe 1
	}
	
	fclose(arq);
	
	if ( flag == 1) {
		
		codigo = p.codprod + 1; // Pega o código do último produto achado e soma mais um
	
	}
	
	return codigo;
}


void registrarProd (void){
	char esc; 
	
	do {
	
	system("cls");
	p.codprod = gerarCod(); // Recebe o código
	
	printf("\nDigite o nome do produto: ");
	
	setbuf(stdin, NULL); fgets(p.nomeprod, sizeof(p.nomeprod), stdin);
	p.nomeprod[strcspn(p.nomeprod, "\n")] = 0;
	
	printf("\nDigite o custo do produto: ");
	setbuf(stdin, NULL); scanf("%f", &p.custoprod); 
	
	FILE *arq;
	arq = fopen ("PRODUTOS.DAT", "ab");
	
	if (arq == NULL){ /*testa para ver se não há erro*/
		printf("\nErro ao abrir");
		getch();
		exit(1);
	}
	
	fwrite (&p, sizeof(produtos), 1, arq); 
    
	
	fclose(arq);
	printf("\nDados gravados com sucesso. Aperte Enter para continuar...");
	getch();
	
	printf("\n\nDeseja incluir mais um produto? (S/N): ");
	esc = getche();
	
		if (esc == 's' || esc == 'S' ) {
			continue;
		}
	
	} while (esc != 'n' && esc != 'N');
	
}

void cardapioDefault(void) {
    FILE *arq = fopen("PRODUTOS.DAT", "wb"); 
    if (arq == NULL) {
        printf("Erro ao criar o arquivo de dados PRODUTOS.DAT\n");
        getch();
        return;
    }

    printf("\nCarregando cardapio padrao para o sistema, aguarde...\n");

    fwrite(vet, sizeof(produtos), 20, arq);
    
    fclose(arq);
    printf("Dados carregados com sucesso!\n");
    getch();
}

int DefaultCheck (void){
	int cardapio;
			system("cls");
			printf("\n\n\n");
			printf ("\n\t=================A L E R T A===================="); //Alerta o ADM sobre a possibilidade de perder Produtos.Dat
			printf ("\n\tO que foi cadastrado até o momento será apagado,");
			printf ("\n\tDeseja carregar o menu padrão mesmo assim? (S/N)");
			printf ("\n\t================================================");
			printf("\n\n");
			
			
			cardapio = getche();
			
				if(cardapio == 's' || cardapio == 'S') {
				return 1;
				}
				
				else return 0;
}

void ConsultarProd(void){
	produtos p;
	char comando[100]; //cria um array grande o suficiente para chamar o sprintf
	
	FILE *arq;
	FILE *ret;
	
	
	
	arq = fopen("PRODUTOS.DAT", "rb"); //Abre produtos só para leitura
	if (arq == NULL){
		
		printf("\nERRO: Arquivo PRODUTOS.DAT nao encontrado ou vazio.\n");
		getch();
		return;
	}
	
	ret = fopen("RelatorioProd.txt", "w"); //Abre relatório para escrever
	if (ret == NULL){
		
		printf("\nErro ao criar arquivo RelatorioProd.txt.");
		fclose(ret);
		getch();
		return;
	}
	
	fprintf(ret, "%-6s | %-60s | %s\n", "CODIGO", "NOME DO PRODUTO", "PREÇO");
    fprintf(ret, "-------+--------------------------------------------------------------+------------\n");
	
	while (fread(&p, sizeof(produtos), 1, arq) == 1) {
		
		fprintf(ret, "%-6d | %-60s | R$ %8.2f\n",
                p.codprod,
                p.nomeprod,
                p.custoprod);
                
   
	}
	
	
	fclose(arq);
	fclose(ret);
	
	printf("\nRelatorio gerado com sucesso!\n");
    printf("Abrindo o relatorio para visualizacao...\n");
    
    sprintf(comando, "start %s", "RelatorioProd.txt"); //Imprime uma string direto num array
    
    // Executa o comando
    system(comando); 
    

    printf("\nPressione qualquer tecla para voltar ao menu.");
    getch();
    
    
	getch();
}

void ConsultarPagamentos(void) {
    int i;
    comanda c1;
    FILE *arq, *ret;

    arq = fopen("PAGAMENTOS.DAT", "rb");
    if (arq == NULL) {
        printf("\nERRO: Arquivo PAGAMENTOS.DAT nao encontrado ou vazio.\n");
        getch();
        return;
    }

    ret = fopen("RelatorioPagamentos.txt", "w");
    if (ret == NULL) {
        printf("\nErro ao criar arquivo RelatorioPagamentos.txt.\n");
        fclose(arq);
        getch();
        return;
    }

    // Cabeçalho
    fprintf(ret, "%-6s | %-60s | %-12s | %-6s | %-12s\n", "COD", "NOME DO PRODUTO", "PREÇO UND", "QTD", "TOTAL");
    fprintf(ret, "-------+--------------------------------------------------------------+--------------+--------+--------------\n");
    

    // Leitura dos pedidos
    while (fread(&c1, sizeof(comanda), 1, arq) == 1) {
        for (i = 0; i < c1.qtdProdutos; i++) {
            fprintf(ret, "%-6d | %-60s | R$ %10.2f | %-6d | R$ %10.2f\n",
                c1.prod[i].codprod,
                c1.prod[i].nomeprod,
                c1.prod[i].custoprod,
                c1.prod[i].qtdprod,
                c1.prod[i].custoprod * c1.prod[i].qtdprod
            );
        }

        fprintf(ret, "\nTOTAL DO PEDIDO #%d: R$ %.2f\t\t\t\t\t\tPAGAMENTO: %s\n", c1.numPedido, c1.valorTotal, formasPagamento[c1.tipoPgto]);
        fprintf(ret, "\n========================================================================================================\n");
    }

    fclose(arq);
    fclose(ret);

    printf("\nRelatorio gerado com sucesso!\nAbrindo o relatorio...\n");

    system("start RelatorioPagamentos.txt");
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getch();
}


void ConsultarCard(void) {
    cartoes c;
    comanda c1;
    FILE *arq;
    FILE *ret;

    arq = fopen("CARTOES.DAT", "rb");
    if (arq == NULL) {
        printf("\nERRO: Arquivo CARTOES.DAT nao encontrado ou vazio.\n");
        getch();
        return;
    }

    ret = fopen("RelatorioCard.txt", "w");
    if (ret == NULL) {
        printf("\nErro ao criar arquivo RelatorioCard.txt.\n");
        fclose(arq);
        getch();
        return;
    }

    fprintf(ret, "%-20s | %s\n", "NUMERO DO CARTAO", "TIPO DE PAGAMENTO");
    fprintf(ret, "---------------------+----------------------\n");

    while (fread(&c, sizeof(cartoes), 1, arq) == 1) {
        // Verifica se o tipoPgto é válido antes de usar como índice
        fprintf(ret, "%-20s | %s (codigo: %d)\n", 
    c.numCartao, 
    (c.coma.tipoPgto >= 0 && c.coma.tipoPgto <= 3) ? formasPagamento[c.coma.tipoPgto] : "Pagamento Desconhecido",
    c.coma.tipoPgto);

    }

    fclose(arq);
    fclose(ret);

    printf("\nRelatorio gerado com sucesso!\n");
    printf("Abrindo o relatorio para visualizacao...\n");

    system("start RelatorioCard.txt");

    printf("\nPressione qualquer tecla para voltar ao menu.");
    getch();
}


char menuConsulta (void) {
	
	char esc;
	
	do {
		system ("cls");
		printf("\n***MENU GERENCIAL***        ");
		printf("\n============================");
		printf("\nO que deseja fazer?         ");
		printf("\n(1) - CONSULTAR CARTOES     ");
		printf("\n(2) - CONSULTAR PRODUTOS    ");
		printf("\n(3) - CONSULTAR PAGAMENTOS  ");
		printf("\n(0) - SAIR                  ");	
		printf("\n============================");
		printf("\nSua escolha: ");
		esc = getche();
		
		
		}while (esc < '0'|| esc > '3'); 
	
	return esc;
}

void menuSelect (char esc){
	
	switch(esc){
			
			case '1': {
			
			ConsultarCard();
			
				
			} break;
			
			case '2': { 
			
			ConsultarProd();
			
			} break;
			
			case '3': {
			ConsultarPagamentos();
			
			} break;
			
			case '0': return; break;
}

}


void menuGerente(void){
	FILE *arq;
	char esc, submenu;
	int check;
	
	do {
		system ("cls");
		printf("\n***MENU GERENCIAL***");
		printf("\n====================");
		printf("\nO que deseja fazer? ");
		printf("\n(1) - CONSULTAR ");
		printf("\n(2) - CADASTRAR");
		printf("\n(3) - CARDAPIO PADRÃO");
		printf("\n(0) - SAIR");	
		printf("\n====================");
		printf("\nSua escolha: ");
		scanf("%c", &esc); clr();
		
		switch(esc){
			
			case '1': {
				submenu = menuConsulta(); 
                if (submenu != '0') {
                    menuSelect(submenu); 
                }
				
			} break;
			
			case '2': { registrarProd();} break;
			
			case '3': { 
			
			check = DefaultCheck();
			
			if (check == 1){cardapioDefault();}
			
			else return;
			
			} break;
			
			case '0': exit(0); break;
			
			default: {
                printf("\nOpcão inválida!");
                getch();
            } break;
		}
		
		}while (esc  != '0'); 
	
	return;
}