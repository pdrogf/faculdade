#include <stdio.h>
#include <stdlib.h>

struct adjacente
{
	struct adjacente *prox;
	int a;
};
struct vertice{
	struct vertice *proxv;
	int v;
	struct adjacente *proxa;
};
struct vertice *aloca_vertice(int v){
	struct vertice *novo;
	novo = (struct vertice *)malloc(sizeof(struct vertice));
	novo->v = v;
	novo->proxv = NULL;
	novo->proxa = NULL;
	return (novo);
}
struct adjacente *aloca_adjacente(int a){
	struct adjacente *novo;
	novo = (struct adjacente *)malloc(sizeof(struct adjacente));
	novo->a = a;
	novo->prox = NULL;
	return (novo);
}

int conecta(struct vertice **grafo, int v, int a)
{
	struct vertice *vertice = NULL;			
	struct adjacente *adjacente = NULL;	
	struct vertice *vAux = NULL;				 
	struct adjacente *aAux = NULL; 
	
	vAux = *grafo;
	if (vAux != NULL){
		do{
			if (vAux->v == v){
				vertice = vAux;
				break;
			}else{
				vAux = vAux->proxv;
			}
		} while (vAux != NULL);
	}
	vAux = NULL;
	if (vertice == NULL){
		vertice = aloca_vertice(v);
		insereVertice(&(*grafo), &vertice);
	}
	aAux = vertice->proxa;
	if (aAux != NULL){
		do{
			if (aAux->a == a){
				adjacente = aAux;
				break;
			}else{
				aAux = aAux->prox;
			}
		} while (aAux != NULL);
	}
	aAux = NULL;	
	if (adjacente == NULL){
		adjacente = aloca_adjacente(a);
		insereAdjacente(&(vertice->proxa), &adjacente);
	}
}

int insereVertice(struct vertice **inicio, struct vertice **vertice){
	struct vertice *aux = *inicio;
	struct vertice *ant = NULL;

	if (*vertice != NULL){
		if (*inicio == NULL){
			*inicio = *vertice;
		}else{
			while (aux != NULL && aux->v < (*vertice)->v){
				ant = aux;
				aux = aux->proxv;
			}
			(*vertice)->proxv = aux;
			if (ant == NULL){
				*inicio = *vertice;
			}else{
				ant->proxv = *vertice;
			}				
		}
		return 1;
	}
	return 0;
}

int insereAdjacente(struct adjacente **inicio, struct adjacente **adjacente){
	struct adjacente *aux = *inicio;
	struct adjacente *ant = NULL;

	if (*adjacente != NULL){
		if (*inicio == NULL){
			*inicio = *adjacente;
		}else{
			while (aux != NULL && aux->a < (*adjacente)->a){
				ant = aux;
				aux = aux->prox;
			}
			(*adjacente)->prox = aux;
			if (ant == NULL){
				*inicio = *adjacente;
			}else{
				ant->prox = *adjacente;
			}				
		}
		return 1;
	}
	return 0;
}

int imprime(struct vertice **inicio){
	struct vertice *vAux = *inicio;
	struct adjacente *aAux = NULL;
	if (vAux != NULL){
		do
		{
			printf("%i >> ", vAux->v);
			aAux = vAux->proxa;
			if (aAux != NULL)
			{
				do
				{
					printf("%i ", aAux->a);
					aAux = aAux->prox;
				} while (aAux != NULL);
			}
			printf("\n");			
			vAux = vAux->proxv;
		} while (vAux != NULL);
	}
	return 1;
}

struct vertice *localizaVertice(struct vertice **vertices, int v){
	struct vertice *localizacaoVertice = *vertices;
	if (localizacaoVertice == NULL)	{
		return NULL;	
	}	
	do{
		if (localizacaoVertice->v == v){
			return localizacaoVertice;
		}else{
			localizacaoVertice = localizacaoVertice->proxv;
		}
	}while(localizacaoVertice!= NULL);	
}
struct adjacente *localizaAdjacente(struct adjacente **adjacentes, int a){
	struct adjacente *localizacaoAdjacente = *adjacentes;
	if (localizacaoAdjacente == NULL){
		return NULL;
	}
	do{
		if (localizacaoAdjacente->a == a){
			return localizacaoAdjacente;
		}else{
			localizacaoAdjacente = localizacaoAdjacente->prox;
		}
	}while (localizacaoAdjacente != NULL);
}

int desconectaAdjacente(struct vertice **grafo, int v, int a){
	struct vertice *vertice = localizaVertice(&(*grafo), v);
	struct adjacente *aux = NULL;
	struct adjacente *ant = NULL;
		
	if (vertice == NULL){
		return 0;	
	}	
	aux = vertice->proxa;
	while (aux != NULL){
		if (aux->a == a){
			if (ant == NULL){
				(vertice->proxa) = aux->prox;
				free(aux);
				aux = vertice->proxa;
				return 1;
			}else{
				ant->prox = aux->prox;
				free(aux);
				aux = ant->prox;
				return 1;
			}
		}else{
			ant = aux;
			aux = aux->prox;
		}
	}	
}
int existeArco(struct vertice **grafo, int v, int a){
	struct vertice *vertice = localizaVertice(&(*grafo), v);
	struct adjacente *adjacente = NULL; 

	if (vertice == NULL){
		return 0;	
	}	
	adjacente = localizaAdjacente(&(vertice->proxa), a);
	if (adjacente != NULL){
		return 1;
	}	
}

int main(){
	struct vertice *grafo = NULL;
	int v, a;
		
	printf("\n ==== INSERE ARCO ==== \n");
	do{
		printf("\nPara encerrar digite 0 para o vertice e o adjacente\n");
		printf("Digite o Vertice: ");
		scanf("%i", &v);
		printf("Digite o Adjacente: ");
		scanf("%i", &a);
		if ((v != 0) && (a != 0)){
			conecta(&grafo, v, a);
			imprime(&grafo);
		}
	} while ((v != 0) && (a != 0)); //a saída será quando o usuário digitar 0 0

	printf("\n === DELETER ARCO === \n");
	do{
		printf("\nPara encerrar digite 0 para o vertice e o adjacente\n");
		printf("Digite o Vertice: ");
		scanf("%i", &v);
		printf("Digite o Adjacente: ");
		scanf("%i", &a);

		if ((v != 0) && (a != 0)){
			desconectaAdjacente(&grafo, v, a);
			imprime(&grafo);
		}
	}while ((v != 0) && (a != 0)); //a saída será quando o usuário digitar 0 0

	printf("\n === PESQUISA ARCO === \n");
	do{
		printf("\nPara encerrar digite 0 para o vertice e o adjacente\n");
		printf("Digite o Vertice: ");
		scanf("%i", &v);
		printf("Digite o Adjacente: ");
		scanf("%i", &a);

		if ((v != 0) && (a != 0)){
			int e = existeArco(&grafo, v, a);
			if (e){
				printf("\n === ARCO EXISTE === \n");
			}
			else{
				printf("\n === ARCO INEXISTENTE === \n");
			}
		}
	} while ((v != 0) && (a != 0)); //a saída será quando o usuário digitar 0 0
}
