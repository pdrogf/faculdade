/*I – Implemente um Programa em Linguagem C que sorteie 20 valores inteiros [0-99] na Função main e
implemente as seguintes Funções:
1. (1.0 Ponto) A partir dos valores sorteados verifique: se o valor for par insira à direita na LDE – Função
InsereDireita, mas se o valor for ímpar insira à esquerda na LDE – Função InsereEsquerda (deverá
existir apenas uma lista);
2. (1.5 Pontos) A partir de um valor escolhido pelo usuário, verifique se o mesmo encontra-se na LDE e
informe ao usuário a sua posição; caso contrário informe que o valor não está inserido na LDE;
3. (3.0 Pontos) A partir de um valor escolhido pelo usuário, exclua o nodo anterior ao que contém esse
valor da LDE, se o valor não existir na lista informe ao usuário;
4. (3.0 Pontos) A partir de um valor escolhido pelo usuário, insira um nodo antes desse nodo que contém
o valor informado pelo usuário. O campo <dados> deve ser preenchido com o seu quadrado; caso o
valor não exista na LDE informe ao usuário;
5. (0.5 Pontos) Função para imprimir a LDE do início para o final.
6. (0.5 Pontos) Função para imprimir a LDE do final para o início.
7. (0.5 Pontos) Função que retorne à quantidade de nodos existentes na LDE.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct nodo{
	int dados;
	struct nodo *prox;
};

struct nodod{
	int dados;
	struct nodod *prox;
	struct nodod *ant;
};

int insereDireita(struct nodod **inicio, struct nodod **fim, int val){
	struct nodod *novo=(struct nodod *)malloc(sizeof(struct nodod));
	if(novo == NULL){
		printf("Nao foi possivel alocar a struct");
	}else{
		novo->dados=val;
		novo->ant=*fim;
		novo->prox=NULL;
		if(*inicio==NULL){
			*inicio=novo;
		}else{
			(*fim)->prox=novo;
		}
		*fim=novo;
	}
}
int insereEsquerda(struct nodod **inicio, struct nodod **fim, int val){
	struct nodod *novo=(struct nodod *)malloc(sizeof(struct nodod));
	if(novo == NULL){
		printf("Nao foi possivel alocar a struct");
	}else{
		novo->dados=val;
		novo->ant=NULL;
		novo->prox=*inicio;
		if(*inicio==NULL){
			*fim=novo;
		}else{
			(*inicio)->ant=novo;
		}
		*inicio=novo;
	}
}
int pesquisaValor(struct nodod **inicio, int v){
	int i;
	struct nodod *aux = *inicio;
	for (i = 1; aux != NULL; i++){
		if (aux->dados == v){
			return i;
		}
		aux = aux->prox;
	}
	return -1;
}

int excluiAnterior(struct nodod **inicio, int v){
	int i;
	struct nodod *aux = *inicio;
	struct nodod *ant = NULL;
	struct nodod *antant = NULL;
	for (i = 1; aux != NULL; i++){
		if(aux->dados == v && i==1){
			return 0;
		}				
		if (aux->dados == v){
			antant->prox = aux;
			free(ant);
			return 1;
		}
		antant = ant;
		ant = aux;
		aux = aux->prox;
	}
	return -1;
}
int insereAnterior(struct nodod **inicio, int val){
	int i;
	struct nodod *aux = *inicio;
	struct nodod *ant = NULL;
	struct nodod *novo=(struct nodod *)malloc(sizeof(struct nodod));
	if(novo == NULL){//nao foi possivel alocar a struct
		return 0;
	}
	if((*inicio)->dados == val){//valor eh o primeiro da lista, nao eh possivel inserir anterior
		return -1;
	}
	for(i=0; aux->dados != val; i++){
		if(aux->prox == NULL){
			return -2;
		}
		ant = aux;
		aux = aux->prox;
	}
	novo->dados=val*val;
	ant->prox = novo;
	novo->prox = aux;
	return 1;
}
int imprime(struct nodod **inicio){
	struct nodod *aux = *inicio;
  	if (aux != NULL){
 		do{
 			printf("%i ", aux->dados);
 			aux = aux->prox;
 		}while (aux != NULL);
 	} 
 	return 1;
 }
 
 int imprimeDesc(struct nodod **inicio){
	struct nodod *aux = *inicio;
	int i=0;
	int vet[21];
	if(aux!=NULL){
		do{
			vet[i]=aux->dados;
			aux = aux->prox;
			i++;	
		}while(aux!=NULL);
		
		while(i){
			i--;
			printf("%i ", vet[i]);			
		}		
	}
 	
 	return 1;
 }
 
 int calculaQtdNodos(struct nodod **inicio){
 	int i;
 	for(i=1;(*inicio)->prox!=NULL;i++){
 		*inicio=(*inicio)->prox;
	}
	return i;
 }

main(){
	struct nodod **inicio= NULL;
	struct nodod **fim = NULL;
	int i;
	
	srand(time(NULL)); 
 	for (i = 0; i < 20; i++){
 		int rnd = rand() % 101;
 		if(rnd%2==0){//par
 			insereDireita(&inicio, &fim,rnd);
		}else{//impar
			insereEsquerda(&inicio, &fim,rnd);
		}	
 	}
 	/*
 	for(i=0;i<10;i++){
 		insereDireita(&inicio, &fim,i);
	}
	*/
	
 	printf("\nImpressao da lista antes da pesquisa.\n");
 	imprime(&inicio); 	
 	int verifica = pesquisaValor(&inicio, 5);
 	if(verifica != -1){
 		printf("\nValor encontrado na posicao %i.\n", verifica);
	}else{
		printf("\nValor nao encontrado na lista.\n");
	}
	
	printf("\nImpressao da lista antes de excluir.\n");
	imprime(&inicio);	
	int exclui = excluiAnterior(&inicio, 4);
	if(exclui == -1){
		printf("\nValor nao encontrado para ser excluido.\n");	
	}else if(exclui ==0){
		printf("\nValor informado eh o primeiro da lista, nao possui anterior para exclusao.\n");
	}else{
		printf("\nValor excluido com sucesso.");
	}	
	printf("\nImpressao da lista apos tentativa de excluir anterior.\n");	
 	imprime(&inicio);
 	printf("\n");
	int anterior = insereAnterior(&inicio, 7);
	if(anterior == 0){
		printf("\nNao foi possivel alocar a struct.\n");
	}else if(anterior == -1){
		printf("\nValor eh o primeiro da lista, nao eh possivel inserir anterior.\n");
	}else if(anterior == -2){
		printf("\nValor nao encontrado na lista para inserir anterior.\n");
	}
	else{
		printf("\nValor inserido anteriormente com sucesso.");
	}
	printf("\nImpressao da lista depois de tentar inserir anterior.\n");	
 	imprime(&inicio);
 	printf("\n");
 	
 	printf("\nImpressao da lista descendente.\n");	
 	imprimeDesc(&inicio);
 	printf("\n");
 	
 	
 	printf("\nQuantidade de nodos = %i.\n", calculaQtdNodos(&inicio));
 	
 	
}
