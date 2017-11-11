#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct pilha{
	int dados;
	struct pilha *prox;
};

struct nodo{
	int dados;
	struct nodo *prox;
};

struct nodod{
	struct nodod *ant;
	int dados;
	struct nodod *prox;
};

int empilha(struct pilha **topo, int v){
	struct pilha *novo = (struct pilha *)malloc(sizeof(struct pilha));
	if (novo != NULL)	{
		novo->dados = v;
		if (*topo == NULL){
			novo->prox = NULL;
		}else{
			novo->prox = *topo;
		}

		*topo = novo;
		return 1;
	}
	return 0;
}

int desempilha(struct pilha **topo){
	
	if (*topo != NULL)	{
		struct pilha *del = *topo;
		*topo = (*topo)->prox;
		free(del);
		return 1;
	}
	return 0;
}

int imprimePilha(struct pilha **topo){
	struct pilha *topoAux = NULL;
	while (*topo != NULL)	{
		printf("%i ", (*topo)->dados);
		empilha(&topoAux, (*topo)->dados);
		desempilha(&(*topo));
	}
	while (topoAux != NULL){
		empilha(&(*topo), topoAux->dados);
		desempilha(&topoAux);
	}
}

int imprimeLSE(struct nodo **inicio){
	struct nodo *aux = *inicio;
	if (aux != NULL){
		do{
			printf("%i ", aux->dados);
			aux = aux->prox;
		}while (aux != NULL);
	}
	return 1;
}

int imprimeLDE(struct nodod **inicio){
	struct nodod *aux = *inicio;
	if (aux != NULL)	{
		do{
			printf("%i ", aux->dados);
			aux = aux->prox;
		}while (aux != NULL);
	}
	return 1;
}

int insereEsqLSE(struct nodo **inicio, int v){
	struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));
	if (novo != NULL){
		novo->dados = v;
		novo->prox = *inicio;
		*inicio = novo;
		return 1;
	}
	return 0;
}

int insereDirLDE(struct nodod **inicio, struct nodod **fim, int v){
	struct nodod *novo = (struct nodod *)malloc(sizeof(struct nodod));
	if (novo != NULL){
		novo->ant = *fim;
		novo->dados = v;
		novo->prox = NULL;

		if (*inicio == NULL){
			*inicio = novo;
		}else{
			(*fim)->prox = novo;
		}
		*fim = novo;
		return 1;
	}
	return 0;
}

int insereImpar(struct pilha **pilha, struct nodo **lse){
	struct pilha *topoAux = NULL;
	while (*pilha != NULL){
		if ((*pilha)->dados % 2 != 0){
			insereEsqLSE(&(*lse), (*pilha)->dados);
		}
		empilha(&topoAux, (*pilha)->dados);
		desempilha(&(*pilha));
	}
	while (topoAux != NULL){
		empilha(&(*pilha), topoAux->dados);
		desempilha(&topoAux);
	}
}

int inserePar(struct pilha **pilha, struct nodod **ldeInicio, struct nodod **ldeFim){
	struct pilha *topoAux = NULL;

	while (*pilha != NULL){
		if ((*pilha)->dados % 2 == 0)		{
			insereDirLDE(&(*ldeInicio), &(*ldeFim), (*pilha)->dados);
		}
		empilha(&topoAux, (*pilha)->dados);
		desempilha(&(*pilha));
	}
	while (topoAux != NULL){
		empilha(&(*pilha), topoAux->dados);
		desempilha(&topoAux);
	}
}

int deletaPilha(struct pilha **topo, int v){
	struct pilha *topoAux = NULL;

	while (*topo != NULL)	{
		if ((*topo)->dados == v){
			desempilha(&(*topo));
			break;
		}else{
			empilha(&topoAux, (*topo)->dados);
			desempilha(&(*topo));
		}
	}
	while (topoAux != NULL){
		empilha(&(*topo), topoAux->dados);
		desempilha(&topoAux);
	}
}

int main(){
	int i;
	int del;
	struct pilha *topo = NULL;
	struct nodo *LSE = NULL;
	struct nodod *LDEInicio = NULL;
	struct nodod *LDEFim = NULL;

	srand(time(NULL));
	for (i = 0; i < 25; i++){
		int rnd = rand() % 100;
		empilha(&topo, rnd);
	}

	printf("\n============ Pilha ============\n");
	imprimePilha(&topo);

	insereImpar(&topo, &LSE);
	printf("\n============ LSE ============\n");
	imprimeLSE(&LSE);

	inserePar(&topo, &LDEInicio, &LDEFim);
	printf("\n============ LDE ============\n");
	imprimeLDE(&LDEInicio);

	
	printf("\nInforme o valor a deletar da pilha: \n");
	scanf("%i", &del);
	deletaPilha(&topo, del);
	
	printf("\n============ Pilha ============\n");
	imprimePilha(&topo);
	printf("\n============ LSE ============\n");
	imprimeLSE(&LSE);
	printf("\n============ LDE ============\n");
	imprimeLDE(&LDEInicio);
}
