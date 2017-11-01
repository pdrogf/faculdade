/*
a) (0.5 Pontos) Função para criar o header da LSE (descritor); 
b) (0.5 Pontos) Função para criar o header da LDE (descritor); 
c) (0.5 Pontos) Função para armazenar em uma LSE com Header à direita (no final da lista), os 50 valores sorteados na main [0-99]
d) (0.5 Pontos) Função para armazenar em uma LDE com Header à esquerda (no início da lista), os 50 valores sorteados na main (os mesmos valores sorteados para a letra c – use o mesmo laço);
e) (0.5 Pontos) Função para imprimir a LSE com Header;
f) (0.5 Pontos) Função para imprimir a LDE com Header; 
g) (2.0 Pontos) Função que receba um novo valor, que deve ser inserido (nodo) antes do nodo que contém o maior elemento da LSE (implemente uma função auxiliar para descobrir o maior elemento da lista); 
h) (2.0 Pontos) Função que receba um valor e exclua o nodo que contém esse valor da LDE – se o valor não estiver presente na lista o usuário deverá ser informado; 
i) (1.0 Ponto) Função que insira um nodo no início da LDE. O valor desse nodo deverá ser o maior valor da LSE; 
j) (0.5 Pontos) Função que retorne para a main a quantidade de nodos de cada uma das Listas, e imprima para o usuário com a devida identificação das listas; 
k) (1.0 Ponto) Função que a partir da escolha do usuário, remove a LSE ou a LDE (não esqueça do descritor).
l) (0.5 Pontos) Função main que sorteia e realiza as chamadas de funções (identação, legibilidade, bons hábitos de programação).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo{
	int dados;
	struct nodo *prox;
};

struct nodod{
	struct nodod *ant;
	int dados;
	struct nodod *prox;
};

struct header{
	struct nodo *inicio;
	int qtd;
	struct nodo *fim;
};

struct headerd{
	struct nodod *inicio;
	int qtd;
	struct nodod *fim;
};

int criaHeaderLSE(struct header **header){
	struct header *novo = (struct header *)malloc(sizeof(struct header));
	if (novo != NULL){
		novo->inicio = NULL;
		novo->qtd = 0;
		novo->fim = NULL;
		*header = novo;
	}
	return 0;
}

int criaHeaderLDE(struct headerd **header){	
	struct headerd *novo = (struct headerd *)malloc(sizeof(struct headerd));
	if (novo != NULL)	{
		novo->inicio = NULL;
		novo->qtd = 0;
		novo->fim = NULL;
		*header = novo;
	}
	return 0;
}

int insereDireiraLSE(struct header **header, int v){
	if (*header != NULL)
	{
		struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));
		if (novo != NULL){
			novo->dados = v;
			novo->prox = NULL;
			if ((*header)->inicio == NULL){
				(*header)->inicio = novo;
			}else{
				(*header)->fim->prox = novo;
			}
			(*header)->fim = novo;
			(*header)->qtd++;
			return 1;
		}
	}
	return 0;
}

int encontraMaiorValorLSE(struct header **header){
	int val = -1;
	if (*header != NULL){
		struct nodo *aux = (*header)->inicio;
		if (aux != NULL){
			do{
				if (aux->dados > val){
					val = aux->dados;
				}
				aux = aux->prox;
			}while (aux != NULL);
		}
	}
	return val;
}

int insereMaior(struct headerd **headerd, struct header **header){
	int psq = encontraMaiorValorLSE(header);
	return insereEsquerdaLDE(headerd, psq);
}

int insereMaiorAntes(struct header **header, int val){
	int psq = encontraMaiorValorLSE(header);
	if (*header != NULL){
		struct nodo *ant = NULL;
		struct nodo *aux = (*header)->inicio;
		if (aux != NULL)
		{
			do{
				if (aux->dados == psq){
					struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));
					if (novo != NULL){
						novo->dados = val;
						if (ant == NULL){
							(*header)->inicio = novo;
						}else{
							ant->prox = novo;
						}
						novo->prox = aux;
						(*header)->qtd++;
						return 1;
					}else{
						return -1;
					}
				}
				ant = aux;
				aux = aux->prox;
			} while (aux != NULL);
		}
	}
	return 0;
}

int insereEsquerdaLDE(struct headerd **header, int v){
	struct nodod *novo = (struct nodod *)malloc(sizeof(struct nodod));
	if (novo != NULL){
		novo->ant = NULL;
		novo->dados = v;
		novo->prox = (*header)->inicio;
		if ((*header)->inicio == NULL)	{
			(*header)->fim = novo;
		}else{
			((*header)->inicio)->ant = novo;
		}
		(*header)->inicio = novo;
		(*header)->qtd++;
		return 1;
	}
	return 0;
}

int imprimeLSE(struct header **header){
	if (*header != NULL){
		struct nodo *aux = (*header)->inicio;
		if (aux != NULL){
			do{
				printf("%i ", aux->dados);
				aux = aux->prox;
			} while (aux != NULL);
			printf("\n");
			return 1;
		}
	}
	return 0;
}

int imprimeLDE(struct headerd **header){
	if (*header != NULL){
		struct nodod *aux = (*header)->inicio;
		if (aux != NULL){
			do{
				printf("%i ", aux->dados);
				aux = aux->prox;
			} while (aux != NULL);
			printf("\n");
			return 1;
		}
	}

	return 0;
}

int excluiNodoLDE(struct headerd **header, int v){
	struct nodod *aux = (*header)->inicio;
	struct nodod *del;
	if (aux != NULL){
		do{
			if (aux->dados == v){
				del = aux;
				if (del->ant == NULL){
					(*header)->inicio = del->prox;
					if (del->prox == NULL){
						(*header)->fim = NULL;
					}else{
						del->prox->ant = NULL;
					}
				}
				else{
					del->ant->prox = del->prox;
					if (del->prox == NULL)	{
						(*header)->fim = del->ant;
					}else{
						del->prox->ant = del->ant;
					}
				}
				free(del);
				(*header)->qtd--;
				return 1;
			}
			aux = aux->prox;
		} while (aux != NULL);
	}
	return 0;
}

int qtdLDE(struct headerd **header){
	return (*header)->qtd;
}

int qtdLSE(struct header **header){
	return (*header)->qtd;
}

int excluiLSE(struct header **header){
	if (header != NULL){
		if ((*header)->inicio != NULL){
			struct nodo *aux = (*header)->inicio;
			struct nodo *del = aux;
			while (aux != NULL){
				free(del);
				del = aux = aux->prox;
			}
			free(*header);
			*header = NULL;
		}
	}
	return 0;
}

int excluiLDE(struct headerd **header){
	if (header != NULL){		
		if ((*header)->inicio != NULL){
			struct nodod *aux = (*header)->inicio;
			struct nodod *del = aux;
			while (aux != NULL){
				free(del);
				del = aux = aux->prox;
			}
			free(*header);
			*header = NULL;
		}
	}
	return 0;
}

int main(){	
	struct header *headerLSE = NULL;
	struct headerd *headerLDE = NULL;
	int i = 0;
	int val=0;
	int deletar=0;

	srand(time(NULL));
	criaHeaderLSE(&headerLSE);
	criaHeaderLDE(&headerLDE);

	for (i = 0; i < 50; i++){
		int rnd = rand() % 100;
		insereDireiraLSE(&headerLSE, i);
		insereEsquerdaLDE(&headerLDE, i);
	}

	printf("\nLSE:\n");
	imprimeLSE(&headerLSE);
	printf("\nLDE:\n");
	imprimeLDE(&headerLDE);
	
	printf("\n=== DIGITE valor a inserir antes do maior -- LSE -- ::\n");
	scanf("%i", &val);
	insereMaiorAntes(&headerLSE, val);

	printf("\n===LSE===\n");
	imprimeLSE(&headerLSE);
	printf("\n====LDE====\n");
	imprimeLDE(&headerLDE);

	
	printf("\n==== DIGITE o valor a deletar da LDE: ");
	scanf("%i", &deletar);
	int statusExcluiNodo = excluiNodoLDE(&headerLDE, deletar);
	if (statusExcluiNodo == 0){
		printf("O valor selecionado não foi encontrado.\n");
	}

	printf("\n===LSE===\n");
	imprimeLSE(&headerLSE);
	printf("\n====LDE====\n");
	imprimeLDE(&headerLDE);

	insereMaior(&headerLDE, &headerLSE);

	printf("\n===LSE===\n");
	imprimeLSE(&headerLSE);
	printf("\n====LDE====\n");
	imprimeLDE(&headerLDE);

	printf("\nQTD Nodos LSE: %i\n", qtdLSE(&headerLSE));
	printf("\nQTD Nodos LDE: %i\n", qtdLDE(&headerLDE));

	printf("=== Digite uma opcao ===");
	printf("\n1 - Excluir LSE\n2 - Excluir LDE\n");
	int opcao;
	scanf("%i", &opcao);

	switch (opcao){
	case 1:
		excluiLSE(&headerLSE);
		break;
	case 2:
		excluiLDE(&headerLDE);
		break;
	default:
		printf("\nOpcao invalida.\n");
	}
	printf("\n===LSE===\n");
	imprimeLSE(&headerLSE);
	printf("\n====LDE====\n");
	imprimeLDE(&headerLDE);
}
