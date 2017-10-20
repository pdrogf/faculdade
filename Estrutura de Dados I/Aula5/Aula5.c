#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo{
	int dados;
	struct nodo *prox;
};

int insereOrdenado(struct nodo **inicio, int v){
struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));
struct nodo *aux = *inicio;
struct nodo *ant = NULL;

	if (novo != NULL){
		novo->dados = v;
		novo->prox = NULL;
 		if (*inicio == NULL){
			*inicio = novo;
		}else{
  			  while (aux != NULL && aux->dados<v){
			  		ant=aux;
			  		aux = aux->prox;
					}
					novo->prox = aux;
  				   if(ant == NULL){
				   		  *inicio = novo;
	               }else{
				   		 ant->prox=novo;
				    }
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

main(){
	struct nodo *listaOriginal = NULL;
	int i;
	
	srand(time(NULL)); 
 	for (i = 0; i < 20; i++){
 		int rnd = rand() % 101; 
 		insereOrdenado(&listaOriginal, rnd);
 	}
 	printf("Lista Ordenada:\n");
 	imprime(&listaOriginal); 
}
