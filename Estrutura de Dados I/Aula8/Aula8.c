/*
Implemente um programa em Linguagem C, com as seguintes Funções (as mesmas devem ser chamadas
pela main – não faça menu, as Funções devem ser executadas na ordem do enunciado – exceto a
impressão que deverá ser executada a cada modificação das Listas - exceto na inserção de valores):
a) (1.0 Ponto) Função para armazenar em uma LSE Circular, os 25 valores inteiros sorteados na main e
enviados por parâmetro (intervalo de [0-99];
b) (0.5 Pontos) Função para imprimir a LSE Circular;
c) (4.0 Pontos) Função que receba dois valores, o primeiro determina o valor do nodo a ser pesquisado,
e o segundo valor deverá ser atribuído em um novo nodo. O novo nodo deverá ser inserido antes do
valor pesquisado na LSE Circular, caso o valor não exista na lista, o usuário deverá ser comunicado;
d) (4.0 Pontos) Função que receba um valor e exclua o nodo que contem esse valor na LSE Circular – se
o valor não estiver presente na lista o usuário deverá ser informado;
e) (0.5 Pontos) Função que retorne para a main e apresente ao usuário a quantidade de nodos contidos
na LSE Circular.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct nodo{
	int dados;
	struct nodo *prox;
};

//LETRA A
int insereCircularLSEUltimo(struct nodo **p, int v){
	/* Retornos:
	0 - Não foi possível alocar
	1 - Inserido com sucesso
	*/
	struct nodo *novo=(struct nodo *)malloc(sizeof(struct nodo));	
	if(novo==NULL){
		return 0;
	}
	novo->dados=v;
	if(*p == NULL){//tratamento da primeira insercao
		novo->prox=novo;
	}else{
		novo->prox=(*p)->prox;
		(*p)->prox=novo;
	}
	*p=novo;
	return 1;
}

//LETRA B
int imprimeLSECircular(struct nodo **p){
	/* Retornos:
	0 - Lista Vazia
	1 - Impressão concluída
	*/
	struct nodo *aux=(*p)->prox;
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
int insereCircularLSEAntesPesquisa(struct nodo **p, int vPesquisa, int vInsere){
	/* Retornos:
	1 - Inserido com sucesso
	0 - Não foi possível alocar
	-1 - Valor não encontrado
	*/
	struct nodo *novo=(struct nodo *)malloc(sizeof(struct nodo));
	struct nodo *aux=(*p)->prox;	
	struct nodo *ant=(*p);
	if(novo==NULL){
		return 0;
	}
	novo->dados=vInsere;	
		do{
			if(aux->dados == vPesquisa){
				ant->prox=novo;
				novo->prox=aux;
				return 1;
			}
			ant=aux;
			aux=aux->prox;	
		}while(aux!=(*p)->prox);
	return -1;
}

//LETRA D
int excluiNodoLSECircular(struct nodo **p, int vPesquisa){
	/* Retornos:
	0 - Lista Vazia
	1 - Excluido com sucesso
	-1 - Valor nao encontrado
	*/
	struct nodo *aux=(*p)->prox;
	struct nodo *ant=(*p);
	struct nodo *del=NULL;
	
	if(aux==NULL){
		return 0;
	}
	do{
		if(aux->dados == vPesquisa){
			del=aux;
			aux=aux->prox;
			ant->prox=aux;
			free(del);
			(*p)=ant;
			return 1;
		}
		ant=aux;
		aux=aux->prox;
	}while(aux!=(*p)->prox);
	return -1;
}

//LETRA E
int contaNodos(struct nodo **p){
	/* Retorno:
	retorna a qtd de nodos existentes na lista;
	0 - Lista vazia
	*/
	int i =0;
	struct nodo *aux=(*p)->prox;
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
	struct nodo *pUltimo=NULL;	
	
	//LETRA A - INSERCAO
	int i;
	srand(time(NULL)); 
 	for (i = 0; i < 25; i++){
 		int rnd = rand() % 100;
 		int a =	insereCircularLSEUltimo(&pUltimo ,rnd);
 		if(a == 0){
 			printf("\nNao foi possivel alocar\n");
		}else if(a == 1){
			printf("\nInserido com sucesso!\n");
		}
	}//FIM DA A
	
	//LETRA B - IMPRESSAO
	printf("\n=====Lista CIRCULAR INSERIDA=====\n");
	int b = imprimeLSECircular(&pUltimo);
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
	int c = insereCircularLSEAntesPesquisa(&pUltimo, vPesquisa, vInsere);
	if(c == 1){
		printf("\nValor encontrado!\n");	
		printf("\nInserido antes do valor pesquisado!\n");
		printf("\n=====Lista APOS A INSERCAO DO ANTERIOR=====\n");
		imprimeLSECircular(&pUltimo); //NOVA IMPRESSAO PARA CONFERIR INSERCAO
	}else if(c == 0){
		printf("\nNão foi possível alocar!\n");
	}else if(c == -1){
		printf("\nValor nao encontrado!\n");
	}//FIM DA LETRA C
	
	//LETRA D - EXCLUSAO DO SELECIONADO
	int val = 0;
	printf("\nDigite o valor a ser excluido:\n");
	scanf("%d",&val);
	int d = excluiNodoLSECircular(&pUltimo, val);
	if(d == 1){
		printf("\nValor encontrado!");
		printf("\nNodo excluido da lista\n");
		printf("\n=====Lista APOS EXCLUSAO=====\n");
		imprimeLSECircular(&pUltimo); //NOVA IMPRESSAO PARA CONFERIR EXCLUSAO
	}else if(d == 0){
		printf("\nLista passada esta vazia\n");
	}else if(d == -1){
		printf("\nValor nao encontrado na lista\n");
	}//FIM DA D
	
	//LETA E
	printf("\n[Contando NODOS DA LISTA...]\n");
	//int e = contaNodos(&pUltimo);
	int e = contaNodos(&pUltimo);
	if(e == 0){
		printf("\nLista Vazia\n");
	}else{
		printf("\nQuantidade de NODOS = %d\n", e);
	}//FIM DA E
}
