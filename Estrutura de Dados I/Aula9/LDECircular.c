/*
Implemente um programa em Linguagem C, com as seguintes Funções (as mesmas devem ser chamadas pela main – não faça menu, as Funções devem ser executadas na ordem do enunciado – 
exceto a impressão que deverá ser executada a cada modificação das Listas - exceto na inserção de valores): 

a) (1.0 Ponto) Função para armazenar em uma LDE Circular, os 25 valores inteiros sorteados na main e enviados por parâmetro (intervalo de [0-99]; 
b) (0.5 Pontos) Função para imprimir a LDE Circular; 
c) (4.0 Pontos) Função que receba dois valores, o primeiro determina o valor do nodo a ser pesquisado, e o segundo valor deverá ser atribuído em um novo nodo. O novo nodo deverá ser inserido antes do valor pesquisado na LDE Circular, 
caso o valor não exista na lista, o usuário deverá ser comunicado; 
d) (4.0 Pontos) Função que receba um valor e exclua o nodo que contem esse valor na LDE Circular – se o valor não estiver 
presente na lista o usuário deverá ser informado; 
e) (0.5 Pontos) Função que retorne para a main e apresente ao usuário a quantidade de nodos contidos na LDE Circular. 
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


struct nodod{
	int dados;
	struct nodod *prox;
	struct nodod *ant;
};

//LETRA A
int insereCircularLDEUltimo(struct nodod **p, int v){
	/* Retornos:
	0 - Não foi possível alocar
	1 - Inserido com sucesso
	*/
	struct nodod *novo=(struct nodod *)malloc(sizeof(struct nodod));	
	if(novo==NULL){
		return 0;
	}
	novo->dados=v;
	if(*p == NULL){//tratamento da primeira insercao
		novo->prox=novo;
		novo->ant=novo;
	}else{
		novo->prox=(*p)->prox;
		(*p)->prox=novo;
		novo->ant=(*p);
	}
	*p=novo;
	return 1;
}

//LETRA B
int imprimeLDECircular(struct nodod **p){
	/* Retornos:
	0 - Lista Vazia
	1 - Impressão concluída
	*/
	struct nodod *aux=(*p)->prox;
	if(aux==NULL){
		return 0;
	}else{
 		do{
 			printf("%i\t",aux->dados);
 			aux=aux->prox;
 		}while(aux!=(*p)->prox);
 	}
 	return 1;
}


//LETRA C
int insereCircularLDEAntesPesquisa(struct nodod **p, int vPesquisa, int vInsere){
	/* Retornos:
	1 - Inserido com sucesso
	0 - Não foi possível alocar
	-1 - Valor não encontrado
	*/
	struct nodod *novo=(struct nodod *)malloc(sizeof(struct nodod));
	struct nodod *aux=(*p)->prox;	
	aux->ant=(*p);
	if(novo==NULL){
		return 0;
	}
	novo->dados=vInsere;	
		do{
			if(aux->dados == vPesquisa){
				aux->ant->prox=novo;
				novo->prox=aux;
				return 1;
			}
			aux->ant=aux;
			aux=aux->prox;	
		}while(aux!=(*p)->prox);
	return -1;
}

//LETRA D
int excluiNodoLDECircular(struct nodod **p, int vPesquisa){
	/* Retornos:
	0 - Lista Vazia
	1 - Excluido com sucesso
	-1 - Valor nao encontrado
	*/
	struct nodod *aux=NULL;		
	if(*p==NULL){
		return 0;
	}
	aux=(*p)->prox;
	do{
		
		if(aux->dados == vPesquisa){
			if (aux == aux->ant){
				*p = NULL;
				free(aux);
				return 1;
			}
			aux->ant->prox = aux->prox;
			aux->prox->ant = aux->ant;
			free(aux);
			return 1;
		}
		aux=aux->prox;
	}while(aux!=(*p)->prox);
	return -1;
}

//LETRA E
int contaNodos(struct nodod **p){
	/* Retorno:
	retorna a qtd de nodos existentes na lista;
	0 - Lista vazia
	*/
	int i =0;
	struct nodod *aux=(*p)->prox;
	if(aux==NULL){
		return 0;
	}else{
 		do{
 			i++;
 			aux=aux->prox;
 		}while(aux!=(*p)->prox);
 	}
 	return i;	
}

int main(){
	struct nodod **p=NULL;
	
	//LETRA A - INSERCAO
	int i;
	srand(time(NULL)); 
 	for (i = 0; i < 25; i++){
 		int rnd = rand() % 100;
 		int a =	insereCircularLDEUltimo(&p ,rnd);
 		if(a == 0){
 			printf("\nNao foi possivel alocar\n");
		}else if(a == 1){
			printf("\nInserido com sucesso!\n");
		}
	}//FIM DA A
	
	//LETRA B - IMPRESSAO
	printf("\n=====Lista CIRCULAR INSERIDA=====\n");
	int b = imprimeLDECircular(&p);
	if(b == 0){
		printf("\nLista Vazia\n");
	}else if(b == 1){
		printf("\nImpressao concluida\n");
	}//FIM DA B	
	
	//LETRA C - INSERCAO ANTERIOR
	int vInsere=0, vPesquisa=0;
	printf("\nDigite o valor a ser pesquisado: \n");
	scanf("%d", &vPesquisa);
	printf("\nDigite o valor a ser inserido: \n");
	scanf("%d", &vInsere);	
	int c = insereCircularLDEAntesPesquisa(&p, vPesquisa, vInsere);
	if(c == 1){
		printf("\nValor encontrado!\n");	
		printf("\nInserido antes do valor pesquisado!\n");
		printf("\n=====Lista APOS A INSERCAO DO ANTERIOR=====\n");
		imprimeLDECircular(&p); //NOVA IMPRESSAO PARA CONFERIR INSERCAO
	}else if(c == 0){
		printf("\nNão foi possível alocar!\n");
	}else if(c == -1){
		printf("\nValor nao encontrado!\n");
	}//FIM DA LETRA C
	
	//LETRA D - EXCLUSAO DO SELECIONADO
	int val = 0;
	printf("\nDigite o valor a ser excluido:\n");
	scanf("%d",&val);
	int d = excluiNodoLDECircular(&p, val);
	if(d == 1){
		printf("\nValor encontrado!");
		printf("\nNodo excluido da lista\n");
		printf("\n=====Lista APOS EXCLUSAO=====\n");
		imprimeLDECircular(&p); //NOVA IMPRESSAO PARA CONFERIR EXCLUSAO
	}else if(d == 0){
		printf("\nLista passada esta vazia\n");
	}else if(d == -1){
		printf("\nValor nao encontrado na lista\n");
	}//FIM DA D
	
	//LETA E
	printf("\n[Contando NODOS DA LISTA...]\n");
	//int e = contaNodos(&pUltimo);
	int e = contaNodos(&p);
	if(e == 0){
		printf("\nLista Vazia\n");
	}else{
		printf("\nQuantidade de NODOS = %d\n", e);
	}//FIM DA E
}
