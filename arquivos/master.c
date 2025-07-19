#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "estruturas.h"
#include "admin.h"
#include "pedidos.h"
#include "pagamento.h"
#include "entregas.h"
#include "fila.h"
#include <locale.h>

char menuMaster(void) {
    char escolha;
    do {
        system("cls");
        system("color ce");
        printf("\n=========================");
		printf("\n  MICKEY & DONALD  ");
		printf("\n    [DRIVE THRU]    ");
        printf("\n=========================");
        printf("\n  1. ADMINISTRAÇÃO");
        printf("\n  2. CLIENTE");
        printf("\n  0. ENCERRAR");
        printf("\n=========================");
        printf("\n  Escolha: ");
        fflush(stdin); escolha = getche();
    } while (escolha < '0' || escolha > '2');
    return escolha;
}

void adminMenu() {
    char esc;
    do {
        system("cls");
        system("color ce");
        printf("\n*** MENU ADMINISTRATIVO ***");
        printf("\n===========================");
        printf("\n1 - CONSULTAR RELATÓRIOS");
        printf("\n2 - CADASTRAR PRODUTOS");
        printf("\n3 - RESTAURAR CARDÁPIO PADRÃO");
        printf("\n0 - VOLTAR");
        printf("\n===========================");
        printf("\nEscolha: ");
        fflush(stdin); esc = getche();

        switch (esc) {
            case '1': {
                char submenu = menuConsulta();
                if (submenu != '0') menuSelect(submenu);
            } break;
            case '2': registrarProd(); break;
            case '3': cardapioDefault(); break;
        }
    } while (esc != '0');
}

void clienteMenu() {
    char escolha;
    int numPedido;

    do {
        system("cls");
        system("color ce");
        printf("\n====================");
        printf("\n  SEJA BEM-VINDO AO ");
        printf("\n  MICKEY & DONALD!  ");
        printf("\n====================");
        printf("\n====================");
        printf("\n       M E N U      ");
        printf("\n====================");
        printf("\n0. SAIR");
        printf("\n1. FAZER PEDIDO");
        printf("\n2. PAGAR PEDIDO");
        printf("\n3. VER FILA DE ESPERA");
        printf("\n   Escolha: ");
        fflush(stdin); escolha = getche();

        switch (escolha) {
            case '1': fazerPedido(); break;
            case '2': {
                printf("\n\nDigite o numero do pedido: ");
                scanf("%d", &numPedido);
                clr();
                pagarPedido(numPedido, 0);
            } break;
            case '3':
                exibirFila(fi);
                break;
        }
    } while (escolha != '0');
}

void loginAdm(void) {
	char senhaADM[9], i, flag;
	char senha [9] = {"Quack123"};  
	
	system("cls");
	printf("Senha: ");
	flag = 0;
	
	do {
		getch();
		fgets(senhaADM, sizeof(senhaADM), stdin);

		
		if (strcmp(senhaADM, senha) == 0) {
			flag = 1;
		}
		
		
		if (flag == 1) {
			adminMenu(); 
			break;
		}
		
		else {
			printf("Senha incorreta.");
			Sleep(1000);
			return;
		}
		
	} while (1);
}

int main() {
    // CONFIGURA A LOCALIDADE PARA EXIBIR ACENTOS CORRETAMENTE
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    // Cria a fila quando o programa começa
    fi = criarFila();
    if (fi == NULL) {
        printf("Erro fatal: Nao foi possivel alocar memoria para a fila.\n");
        return 1;
    }

    char opcao;
    do {
        opcao = menuMaster();
        switch (opcao) {
            case '1': loginAdm(); break;
            case '2': clienteMenu(); break;
            case '0': printf("\nEncerrando o sistema...\n"); break;
        }
    } while (opcao != '0');

    // Libera a memória da fila antes de encerrar
    liberarFila(fi);
    return 0;
}
