#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo
{
	int dados;
	struct nodo *prox;
};

int InsereDireita(struct nodo **inicio, int v){
	struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));
	struct nodo *aux = *inicio;

	if (novo != NULL){
		novo->dados = v;
		novo->prox = NULL;

		if (*inicio == NULL){
			*inicio = novo;
		}
		else{
			while (aux->prox != NULL){
				aux = aux->prox;
			}
			aux->prox = novo;
		}
		return 1;
	}
	return 0;
}

int InsereEsquerda(struct nodo **inicio, int v)
{
	struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));

	if (novo != NULL){
		novo->dados = v;
		novo->prox = *inicio;
		*inicio = novo;
		return 1;
	}

	return 0;
}

int Imprime(struct nodo **inicio)
{
	struct nodo *aux = *inicio;

	if (aux != NULL){
		do{
			printf("%i ", aux->dados);
			aux = aux->prox;
		} while (aux != NULL);
		printf("\n");
	}

	return 1;
}

int InsereNodoDepois(struct nodo **inicio, int n, int v)
{
	int inseridos = 0;
	struct nodo *aux = *inicio;
	struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));
	if (*inicio != NULL && novo != NULL){
		do
		{
			if (aux->dados == n){
				novo->dados = v;
				novo->prox = aux->prox;
				aux->prox = novo;
				inseridos++;
			}
			aux = aux->prox;
		} while (aux != NULL);
	}
	return inseridos;
}

int PesquisaValor(struct nodo **inicio, int v){
	int i;
	struct nodo *aux = *inicio;

	for (i = 1; aux != NULL; i++)	{
		if (aux->dados == v)		{
			return i;
		}
		aux = aux->prox;
	}
	return -1;
}

int main(){
	int i;
	struct nodo *ptr = NULL;
	srand(time(NULL));
	int random = rand() % 101;

	for (i = 0; i < 20; i++){
		int rnd = rand() % 101;
		if (rnd % 2 == 0){
			InsereDireita(&ptr, rnd);
		}
		else{
			InsereEsquerda(&ptr, rnd);
		}
	}

	printf("Nodos:\n");
	Imprime(&ptr);
	int val;
	printf("Digite o valor a ser inserido: ");
	scanf("%i", &val);
	int inseridoDepois = InsereNodoDepois(&ptr, (val * val), val);	
	printf("Lista de nodos:\n");
	Imprime(&ptr);	
	int verifica = PesquisaValor(&ptr, random);
	if (verifica == -1){
		printf("Valor sorteado %i, nao encontrado!!.\n", random);
	}
	else{
		printf("Valor sorteado %i foi encontrado na posicao %i.\n", random, verifica);
	}
	printf("Nodos:\n\t");
	Imprime(&ptr);
	return 0;
}
