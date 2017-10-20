/*

I – Faça um Programa em C que sorteie 50 valores inteiros [0-999] na Função main e implemente as
seguintes Funções:
1. (0.5 Pontos) main: Cria a LDE com inserção à direita e realiza as chamadas de funções;
2. (4.0 Pontos) A partir de um valor escolhido pelo usuário, verifique se os múltiplos desse valor estão
presentes na LDE, se estiverem insira em ordem crescente em uma LSE;
3. (2.0 Pontos) A partir de um intervalo escolhido pelo usuário, verifique se os valores estão presentes
na LDE e os exclua. Antes da exclusão dos valores estes devem ser enviados para uma LSE auxiliar,
com o intuito de não perder os dados existentes;
4. (2.5 Pontos) A partir de um valor escolhido pelo usuário verifique se o mesmo encontra-se na LSE
auxiliar, se sim, crie uma LDE com os valores contidos na lista multiplicados pelo valor escolhido.
5. (0.5 Pontos) Função para imprimir a LDE.
6. (0.5 Pontos) Função para imprimir a LSE.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct nodo{
	int dados;
	struct nodo *prox;
};

struct nodod{
	struct nodod *ant;
	int dados;
	struct nodod *prox;
};
/* Cria LDE inserindo a direita */
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

/* Função para inserir os dados ordenadamente asc */
int insereOrdenada(struct nodo **inicio,int v){
	struct nodo *novo=NULL,*aux=*inicio,*ant;
	novo=(struct nodo *)malloc(sizeof(struct nodo));
	if(novo==NULL) printf("Nao foi possivel alocar!\n");
 	else{	
 		novo->dados=v;
 		if(*inicio==NULL){
 			*inicio=novo;
			(*inicio)->prox=NULL;
 		}else{
 			while(aux!=NULL){
 				if(aux->dados>=v){
 					if(*inicio==aux){
 						*inicio=novo;
 						novo->prox=aux;
 						return 0;
 					}else{
 						ant->prox=novo;
 						novo->prox=aux;
 						return 0;
 					}
 				}
 				ant=aux;
 				aux=aux->prox;
 				}
 				ant->prox=novo;
 				novo->prox=aux;
 				return 0;
		}
 	}
}

/* Cria uma LSE com os múltiplos do numero informado, que existirem na LDE */
int insereMultiplos(struct nodod **inicio, struct nodod **fim, struct nodo **ptri, int v){	
	int i=1;		
	struct nodod *aux = *inicio;
	for (i; aux != NULL; i++){
		if (aux->dados%v == 0){
			insereOrdenada(ptri, aux->dados);
		}
		aux = aux->prox;
	}
	return -1;
}

/* Exclui os valores entre o intervalo passado e cria uma LSE a partir dos mesmos */
int excluiIntervalo(struct nodod **inicio, struct nodod **fim, struct nodo **LSEAuxiliar, int iIntervalo, int fIntervalo){
	struct nodod *aux=*inicio,*del=NULL;
	if(aux==NULL){
		printf("\nLista Vazia!\n");
		return 0;	
	}
	while(aux != NULL){
		if(aux->dados >= iIntervalo && aux->dados <= fIntervalo){
			insereOrdenada(LSEAuxiliar, aux->dados);
			del=aux;
			if(aux==*inicio){
				*inicio=aux->prox;
				aux->prox->ant=NULL;
			}else{
				aux->ant->prox=aux->prox;
				aux->prox->ant=aux->ant->ant;
			}		
			free(del);		
		}
		aux=aux->prox;
	}
	return 1;
}
/* Verifica se o valor existe na LSE e cria uma LDE com os valores da LSE multiplicados pelo valor passado
Chama funcao insereDireita */
int pesquisaLSECriaLDE(struct nodo **LSEAuxiliar, struct nodod **LDEAuxiliar, struct nodod **fim, int v){
	struct nodo *aux=*LSEAuxiliar;	
	if(aux==NULL){
		printf("\Lista Vazia\n");
		return 0;
	}
	while(aux!=NULL){
		if(aux->dados == v){
			printf("\nValor encontrado, criando a LDE AUXILIAR\n");
			struct nodo *aux2=*LSEAuxiliar;			
			while(aux2!=NULL){
				insereDireita(LDEAuxiliar, fim, (aux2->dados)*v);
				aux2=aux2->prox;
			}
			return -1;
		}
		aux=aux->prox;
	}
	return 1;
}

/* Imprime LDE passada */
int imprimeLDE(struct nodod **inicio, struct nodod **fim){
	struct nodod *aux = *inicio;
  	if (aux == NULL) printf("\nLista Vazia!\n");
  	else{
		do{
 			printf("%i\t", aux->dados);
 			aux = aux->prox;
 		}while (aux != NULL);
	} 
 	return 1;
 }
/* Imprime LSE passada */
int imprimeLSE(struct nodo **inicio){
	struct nodo *aux=*inicio;
	if(*inicio==NULL) printf("Lista Vazia!\n");
 	else{
 		do{
 			printf("%i\t",aux->dados);
 			aux=aux->prox;
 		}while(aux!=NULL);
 	}
 	return 1;
}


int main(){
	struct nodod **inicio= NULL;
	struct nodod **fim = NULL;
	struct nodod **LDEAuxiliar=NULL;
	
	struct nodo **ptri=NULL;
	struct nodo **LSEAuxiliar=NULL;
		
	int i;
	int valorInsereMultiplos = 0;
	int iIntervalo = 0;
	int fIntervalo = 0;
	int vPesquisa = 0;
	
	srand(time(NULL)); 
 	for (i = 0; i < 50; i++){
 		int rnd = rand() % 999;
 		insereDireita(&inicio, &fim,rnd);
	}
	printf("\n==========LDE==========\n");
	imprimeLDE(&inicio, &fim);
	
	printf("\nDigite o valor a ser inseridos seus multiplos na LSE: \n");
	scanf("%d", &valorInsereMultiplos);
	insereMultiplos(&inicio, &fim, &ptri, valorInsereMultiplos);
	printf("\n==========LSE==========\n");
	imprimeLSE(&ptri);
	
	printf("\nDigite o intervalo entre 0 e 999:\n");
	scanf("%d", &iIntervalo);
	scanf("%d", &fIntervalo);
	
	excluiIntervalo(&inicio, &fim, &LSEAuxiliar, iIntervalo, fIntervalo);
	printf("\n==========LDE APOS EXCLUSAO DO INTERVALO==========\n");
	imprimeLDE(&inicio, &fim);
	printf("\n==========LSE AUXILIAR==========\n");
	imprimeLSE(&LSEAuxiliar);
	
	printf("\nDigite o valor a ser pesquisado na LSE AUXILIAR: ");
	scanf("%d", &vPesquisa);
	pesquisaLSECriaLDE(&LSEAuxiliar, &LDEAuxiliar, &fim, vPesquisa);
	printf("\n=========LDE AUXILIAR============\n");
	imprimeLDE(&LDEAuxiliar, &fim);	
	
}

