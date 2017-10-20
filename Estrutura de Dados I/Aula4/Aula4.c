#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo{
	int dados;
	struct nodo *prox;
};

int insereD(struct nodo **inicio, int v){
struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));
struct nodo *aux = *inicio;
	if (novo != NULL){
		novo->dados = v;
		novo->prox = NULL;
 		if (*inicio == NULL){
			*inicio = novo;
		}else{
			while (aux->prox != NULL){
				aux = aux->prox;
			}
			aux->prox = novo;
 		} 
 		return 1;
 	} 
 	return 0;
 }
 
 int imprime(struct nodo **inicio){
	struct nodo *aux = *inicio;
  	if (aux != NULL){
 		do{
 			printf("%i ", aux->dados);
 			aux = aux->prox;
 		}while (aux != NULL);
 	} 
 	return 1;
 }
 
 int insereParImpar(struct nodo **par, struct nodo **impar, struct nodo **original){
 	struct nodo *aux = *original; 
 	if(*original != NULL){
 		do{
 			if (aux->dados % 2 == 0){
 				insereD(par, aux->dados);
 			}
 			else{
 				insereD(impar, aux->dados);
 			} 
 			aux = aux->prox;
 		}while (aux != NULL); 
 		return 1;
 	} 
 	return 0;
 } 
 int excluiNodo(struct nodo **inicio, int v){
 	int nodosExluidos = 0;
 	struct nodo *ant = NULL;
 	struct nodo *aux = *inicio; 	
 		if (*inicio != NULL){
 			do{
 				if (aux->dados == v){
 					if (ant == NULL){
 						*inicio = aux->prox;
 						free(aux);
 						aux = *inicio;
 					}
 					else{
 						ant->prox = aux->prox;
 						free(aux);
 						aux = ant;
 					} 
 					nodosExluidos++;
 				}else{
 					ant = aux;
 					aux = aux->prox;
 				}
 			}while(aux != NULL); 			
 			return nodosExluidos;
 		}
 		return nodosExluidos;
 }
 
 int excluiMultiplo(struct nodo **inicio){
 	int nodosExluidos = 0;
 	struct nodo *ant = NULL;
 	struct nodo *aux = *inicio; 	
 		if (*inicio != NULL){
 			do{
 				if (aux->dados % 3 == 0){
 					if (ant == NULL){
 						*inicio = aux->prox;
 						free(aux);
 						aux = *inicio;
					}else{
 						ant->prox = aux->prox;
 						free(aux);
 						aux = ant;
 					}
				nodosExluidos++;
 				}else{
 					ant = aux;
 					aux = aux->prox;
 				}
 			}while(aux != NULL); 			
 			return nodosExluidos;
 		} 	
 		return nodosExluidos;
 }
 
 int main(){ 	
 	struct nodo *listaPar = NULL;
 	struct nodo *listaImpar = NULL; 
 	struct nodo *listaOriginal = NULL;
 	int i;
 	
 	srand(time(NULL)); 
 	for (i = 0; i < 20; i++){
 		int rnd = rand() % 101; 
 		insereD(&listaOriginal, rnd);
 	} 
 	printf("Lista original:\n");
 	imprime(&listaOriginal); 
 	
 	insereParImpar(&listaOriginal, &listaPar, &listaImpar); 
 	
 	printf("Lista par:\n");
 	imprime(&listaPar);
 	
 	printf("Lista impar:\n");
 	imprime(&listaImpar); 
 	
 	int num;
 
 	printf("Digite o num PAR a ser excluido: ");
 	scanf("%i", &num);
 	int ret = excluiNodo(&listaPar, num);
 
 	if (ret == 0){
 		printf("Nao foi encontrado nenhum nodo PAR\n");
 	} 
 	printf("Lista PAR\n");
 	imprime(&listaPar);
 
 	int nExcluidos = excluiMultiplo(&listaImpar);
 
 	printf("QTD de multiplos de 3 excluidos= %i \n", nExcluidos);
 
 	printf("Lista IMPAR\n");
 	imprime(&listaImpar);
 
 	return 0;
 }
