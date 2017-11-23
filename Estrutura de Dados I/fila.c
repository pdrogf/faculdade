#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct fila{
	int dados;
	struct fila *prox;
};

struct pilha{
	int dados;
	struct pilha *prox;
};

int empilha(struct pilha **topo, int v){
	struct pilha *novo = (struct pilha *)malloc(sizeof(struct pilha));
	if (novo != NULL){
		novo->dados = v;

		if (*topo == NULL)
		{
			novo->prox = NULL;
		}
		else
		{
			novo->prox = *topo;
		}

		*topo = novo;

		return 1;
	}

	return 0;
}

int desempilha(struct pilha **topo)
{
	if (*topo != NULL){
		struct pilha *del = *topo;
		*topo = (*topo)->prox;
		free(del);
		return 1;
	}
	return 0;
}

int enfileirar(struct fila **inicio, struct fila **fim, int v){
	struct fila *novo = (struct fila *)malloc(sizeof(struct fila));
	if (novo != NULL){
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
int desenfileirar(struct fila **inicio, struct fila **fim){
	if (*inicio != NULL){
		struct fila *del = *inicio;
		if ((*inicio)->prox == NULL){
			*fim = NULL;
		}
		*inicio = (*inicio)->prox;
		free(del);
		return 1;
	}
	return 0;
}

int imprimeFila(struct fila **inicio){
	struct fila *aux = *inicio;
	if (aux != NULL){
		do{
			printf("%i ", aux->dados);
			aux = aux->prox;
		}while (aux != NULL);
	}
	return 1;
}

int imprimePilha(struct pilha **topo){
	struct pilha *aux = *topo;
	if (aux != NULL){
		do{
			printf("%i ", aux->dados);
			aux = aux->prox;
		}while (aux != NULL);
	}
	return 1;
}

int insereFilaImpar(struct fila **inicio, struct fila **fim, struct pilha **topo){
	struct fila *filaAuxInicio = NULL;
	struct fila *filaAuxFim = NULL;
	while (*inicio != NULL){
		if ((*inicio)->dados % 2 != 0){
			empilha(&(*topo), (*inicio)->dados);
		}
		enfileirar(&filaAuxInicio, &filaAuxFim, (*inicio)->dados);
		desenfileirar(&(*inicio), &(*fim));
	}
	*inicio = filaAuxInicio;
	*fim = filaAuxFim;
}

int insereFilaPar(struct fila **inicio, struct fila **fim, struct pilha **topo){
	struct fila *filaAuxInicio = NULL;
	struct fila *filaAuxFim = NULL;

	while (*inicio != NULL){
		if ((*inicio)->dados % 2 == 0){
			empilha(&(*topo), (*inicio)->dados);
		}
		enfileirar(&filaAuxInicio, &filaAuxFim, (*inicio)->dados);
		desenfileirar(&(*inicio), &(*fim));
	}
	*inicio = filaAuxInicio;
	*fim = filaAuxFim;
	return 1;
}

int insereValorMenor(struct pilha **topo, struct fila **inicio, struct fila **fim){
	struct pilha *topoAux = NULL;

	while (*topo != NULL){
		if ((*topo)->dados < 50){
			enfileirar(&(*inicio), &(*fim), (*topo)->dados);
		}
		empilha(&topoAux, (*topo)->dados);
		desempilha(&(*topo));
	}
	while (topoAux != NULL){
		empilha(&(*topo), topoAux->dados);
		desempilha(&topoAux);
	}
	return 1;
}

int deletaFila(struct fila **inicio, struct fila **fim, int v){
	int cont = 0;

	struct fila *filaAuxInicio = NULL;
	struct fila *filaAuxFim = NULL;

	while (*inicio != NULL){
		if ((*inicio)->dados == v){
			cont++;
		}else{
			enfileirar(&filaAuxInicio, &filaAuxFim, (*inicio)->dados);
		}
		desenfileirar(&(*inicio), &(*fim));
	}
	*inicio = filaAuxInicio;
	*fim = filaAuxFim;
	return cont;
}

int main(){	
	
	struct fila *inicioFila = NULL;
	struct fila *fimFila = NULL;
	struct pilha *pilhaImpar = NULL;
	struct pilha *pilhaPar = NULL;
	struct fila *filaMenor = NULL;
	struct fila *fimFilaMenor = NULL;
	int del =0;
	int i=0;

	srand(time(NULL));
	
	for (i = 0; i < 30; i++){
		int rnd = rand() % 100;
		enfileirar(&inicioFila, &fimFila, rnd);
	}

	printf("\n ====== Fila ====== \n");
	imprimeFila(&inicioFila);
	printf("\n====== PILHA IMPAR ======\n");
	imprimePilha(&pilhaImpar);
	printf("\n======PILHA PAR ======\n");
	imprimePilha(&pilhaPar);
	printf("\n======MENOR FILA ======\n");
	imprimeFila(&filaMenor);
	
	insereFilaImpar(&inicioFila, &fimFila, &pilhaImpar);
	
	printf("\n ====== Fila ====== \n");
	imprimeFila(&inicioFila);
	printf("\n====== PILHA IMPAR ======\n");
	imprimePilha(&pilhaImpar);
	printf("\n======PILHA PAR ======\n");
	imprimePilha(&pilhaPar);
	printf("\n======MENOR FILA ======\n");
	imprimeFila(&filaMenor);

	insereFilaPar(&inicioFila, &fimFila, &pilhaPar);

	printf("\n ====== Fila ====== \n");
	imprimeFila(&inicioFila);
	printf("\n====== PILHA IMPAR ======\n");
	imprimePilha(&pilhaImpar);
	printf("\n======PILHA PAR ======\n");
	imprimePilha(&pilhaPar);
	printf("\n======MENOR FILA ======\n");
	imprimeFila(&filaMenor);

	insereValorMenor(&pilhaImpar, &filaMenor, &fimFilaMenor);

	printf("\n ====== Fila ====== \n");
	imprimeFila(&inicioFila);
	printf("\n====== PILHA IMPAR ======\n");
	imprimePilha(&pilhaImpar);
	printf("\n======PILHA PAR ======\n");
	imprimePilha(&pilhaPar);
	printf("\n======MENOR FILA ======\n");
	imprimeFila(&filaMenor);

	
	printf("\nDigite um valor a deletar da FILA: \n");
	scanf("%i", &del);
	int statusExcluiNodo = deletaFila(&inicioFila, &fimFila, del);
	if (statusExcluiNodo == 0){
		printf("\nVALOR NAO EXISTE NA FILA\n");
	}

	printf("\n ====== Fila ====== \n");
	imprimeFila(&inicioFila);
	printf("\n====== PILHA IMPAR ======\n");
	imprimePilha(&pilhaImpar);
	printf("\n======PILHA PAR ======\n");
	imprimePilha(&pilhaPar);
	printf("\n======MENOR FILA ======\n");
	imprimeFila(&filaMenor);
}
