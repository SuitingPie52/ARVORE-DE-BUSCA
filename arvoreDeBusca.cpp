//////////////////////
// Árvore de busca //
////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no {
	
	int numero;
	struct no *esquerda;
	struct no *direita;
	
};



struct no *inserir(struct no *raiz, int numero) {
	
	if (raiz ==  NULL) {
	
		raiz = (struct no *) malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
		
	
	} else {
		
		if (raiz -> numero > numero) {
			
			raiz -> esquerda = inserir(raiz -> esquerda, numero);
			
		} else if (raiz -> numero < numero) {
			
			raiz -> direita = inserir(raiz -> direita, numero);
			
		}
		
	}
	
	return raiz;
	
}

void buscar(struct no *raiz, int numero) {
	
	if (raiz == NULL) {
		
		printf("NAO ACHEI !!!");
		
	} else if (raiz -> numero == numero) {
		
		printf("ACHEI !!!");
		
	} else if (raiz -> numero > numero) {
		
		buscar(raiz -> esquerda, numero);
		
	} else {
		
		buscar(raiz -> direita, numero);
		
	}
	
}

void navegar(struct no*raiz) { // em- ordem
	
	if (raiz != NULL) {
		
		navegar(raiz -> esquerda);
		printf("%d\t", raiz -> numero);
		navegar(raiz -> direita);
		
	}
	
}

int main() {
	
	struct no *raiz = NULL;
	int i = 0;
	int opcao = 0;
	int numero = 0;
	
	time_t t;
	srand((unsigned) time(&t));
	
	while (opcao != 5) {
		
		printf("\n+=======================================+\n|		Menu de opcoes		|\n+=======================================+\n");
		printf("|	1 - Criar Arvore Aleatoria	|\n");
		printf("|	2 - Inserir No na Arvore	|\n");
		printf("|	3 - Buscar no na Arvore		|\n");
		printf("|	4 - Navegar a Arvore		|\n");
		printf("|	5 - Sair			|\n");
		printf("+=======================================+\n");
		
		printf("Digite sua opcao: ");
		scanf("%d", &opcao);
		
		switch (opcao) {
			
			case 1:
				for (i = 0; i < 100; i++) {
					
					raiz = inserir(raiz, rand());
					
				}
				break;
			
			case 2:
				printf("Digite numero: ");
				scanf("%d", &numero);
				raiz = inserir(raiz, numero);
				break;
			
			case 3:
				printf("Digite numero: ");
				scanf("%d", &numero);
				buscar(raiz, numero);
				break;
				
			case 4:
				navegar(raiz);
				break;
				
		}
	}
	
	
}
