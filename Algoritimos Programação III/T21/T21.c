#include <stdio.h>

#define NMAX 20000
#define STRMAX 101

int tamanho(char st1[])
{
    int i;
    for (i = 0; st1[i]; i++);
    return (i);
}

/* Função lestring publicada no artigo do Viva o Linux */
int lestring(char s[], int max)
{
    int i = 0;
    char letra;

    for (i = 0; i < (max - 1); i++) {
        letra = fgetc(stdin);

        /* NOVIDADE: Segurança contra o jeito DOS de se encerrar 
         * uma linha (caso se use a modalidade de arquivos
         * de testes e este arquivo esteja com quebras de linhas
         * padrao DOS
         * */
        if (letra == 13) {      // ENTER. So tem no DOS como quebra de linha
            i--;
            continue;
        }
        if ((letra == 10) && (i == 0)) {
            i = i - 1;
            continue;
        }

        if (letra == 10) {      // Line FEED. Dos e Linux
            break;
        }
        s[i] = letra;
    }
    s[i] = 0;
    return (i);
   
}

struct LIVROS{
	char livro[STRMAX];
	char autor[STRMAX];
	int qntPaginas;
	float valor;
};

void cadastrarLivros(struct LIVROS l[], int t){
    int qntLivros, i;
    qntLivros = t;

    for(i = 0; i < qntLivros; i++){
        printf("\n# --- Livro [%i] ---", i);
        printf("\n# Nome do livro: ");
        lestring(l[i].livro, STRMAX);
        printf("\n# Nome do autor: ");
        lestring(l[i].autor, STRMAX);

        do{
            printf("\n# Quantas páginas: ");
            if(!scanf("%d", &l[i].qntPaginas)){
                printf("\nErro entrada invalida");
                printf("\n# ERRO. Digitou lixo");
                while(fgetc(stdin) != '\n');
                l[i].qntPaginas=-1;
            }
        }while(l[i].qntPaginas < 0);
    
        do{
            printf("\n# Valor em reais: ");
            if(!scanf("%f", &l[i].valor)){
                printf("\nERRO entrada invalida");
                printf("\n# ERRO. Digitou lixo");
                while(fgetc(stdin) != '\n');
                l[i].valor=0;
            }
        }while(l[i].valor ==0 );
    }
}

int contarLivros(int t){
    int qntLivros;
    int cont=0;
    do {

        if(t==1){
            t=0;
            printf("\n# Quantos livros você quer digitar: ");
        }else{
        	if(cont > 0){
        		printf("\nERRO entrada invalida");
        	}
        	cont++;
        	printf("\n# ERRO: quantidade de livros deve estar entre 1 e 20000");
            printf("\n# Quantos livros você quer digitar: ");
        }
     	(!scanf("%d", &qntLivros));
        while(fgetc(stdin) != '\n');
    } while(qntLivros < 1 || qntLivros > NMAX); 
    
    return(qntLivros); 
}

int main(int argc, char *argv[]){

    int nLivros=0, i;
    int maiorTitulo=0, maiorAutor=0;
    struct LIVROS l[NMAX];

    if(argc==1){
        nLivros = contarLivros(argc);
    }
    else if(atoi(argv[1]) >= 1 && atoi(argv[1]) <= NMAX){
        nLivros=atoi(argv[1]);
    }
    else{
        nLivros = atoi(argv[1]);
        printf("\nERRO %s", argv[1]);
        nLivros = contarLivros(nLivros);  
    }


    printf("\n# Digite os dados para %i livros: ", nLivros);
    cadastrarLivros(l, nLivros);

    printf("\n# ---- FIM DO CADASTRO DE %i LIVROS ----\n", nLivros);

	for(i=0; i < nLivros; i++){
		if(tamanho(l[i].livro) > maiorTitulo){
			maiorTitulo = tamanho(l[i].livro);
		}
		if(tamanho(l[i].autor) > maiorAutor){
			maiorAutor = tamanho(l[i].autor)+4;
		}
	}
	
    if(maiorTitulo < 14 ){
        maiorTitulo = 13;
    }
    if(maiorAutor < 14 ){
        maiorAutor = 14;
    }
	
	//imprime cabecalho
	printf("\n%-*s %-*s", maiorTitulo, "Nome do livro", maiorAutor, "Nome do autor");
	printf("%7s %14s", "Paginas", "Valor\n");   
		
	int j;
	j = maiorAutor + maiorTitulo + 23;

	for(i=0; i < j; i++){
		printf("-");
	}
    double totalLivros;
	//imprime livros cadastrados
	for(i=0; i < nLivros; i++){
		printf("\n%-*s %-*s", maiorTitulo, l[i].livro, maiorAutor, l[i].autor);
		printf("%7d R$ %10.2f", l[i].qntPaginas, l[i].valor);
        totalLivros = totalLivros + l[i].valor;
	}

    printf("\n\nTotal de todos os %d livros: R$%10.2lf\n", nLivros, totalLivros);


}

	

	