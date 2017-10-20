#include <stdio.h>
#define TAM 60000

//LETRA A, entrada da quantidade de elementos tratando entrada inesperada
int quantosElementos(){
	int qntElementos;
	do {
		printf("# Quantos números quer digitar? (1 a 60000)\n");
		if (!scanf("%d", &qntElementos)) {
			printf("# Você digitou LIXO\n\n");
		} else if (qntElementos < 1 || qntElementos > TAM) {
			printf("# ERRO: %d é um valor inválido\n\n", qntElementos);
		}
		while(fgetc(stdin) != '\n');
	} while(qntElementos < 1 || qntElementos > TAM);	
}

int validarEntrada(double num, double vetDouble[TAM], int qntElementos) {
	int i;
	for (i = 0; i < qntElementos; i++) {
		if ((int)(num * 10000) == (int)(vetDouble[i] * 10000)) {
			return 1;
		}
	}return 0;
}

//LETRA B entrada do vetor de double		
void receberElementos(int qntElementos, double vetDouble[]){	
	int cont = 0; 
	double elementos; 

	printf("\n# Digite numeros positivos para inserir no vetor :\n");
	do {
		printf("# Digite elementos vetor: \n");
		scanf("%lf", &elementos);

		if (0) {
			printf("# Você digitou LIXO\n\n");
		} else if (elementos < 1 || elementos > TAM) {
			printf("# ERRO: %.6lf fora da faixa (1000000 a 500000)\n\n", elementos);
		} else if (validarEntrada(elementos, vetDouble, cont)) {
			printf("# ERRO: %.4lf já foi digitado\n\n", elementos);
		} else {
			vetDouble[cont] = elementos;
			cont++;
		}
		while(fgetc(stdin) != '\n');
	//	printf("\n");
	} while(cont < qntElementos);
}
	

	
//LETRA C, ordenando vetor recebido pelo usuário
void ordenarVetor(double vetDouble[], int qntElementos){
	int i, j, aux=0;	
	for(i=0;i<qntElementos;i++){
        for(j=i+1;j<qntElementos;j++){
            if(vetDouble[i] > vetDouble[j] ){
            	aux = vetDouble[i]; 
            	vetDouble[i] = vetDouble[j];
            	vetDouble[j] = aux;
            }
        }
    }
	//printf("\nOrdenado com sucesso!"); 
	/*
	debug manual, descomentar para ver impressao da funcao
	for(i=0;i<qntElementos;i++){
		printf("\nvetor ordenado %lf", vetDouble[i]);
	}
	*/
}

//LETRA D, gerando vetor de long a partir do fatorial de cada elemento do vetor de double, sendo arredondado ou truncado
void gerarFatorial(double vetDouble[], unsigned long vetLong[], int qntElementos){
	int i, j, y;
	unsigned long fatorial;
	for(i=0;i<qntElementos;i++){
		y=(vetDouble[i]+0.5);
		fatorial=y;
		for(j=1;j<y;j++){
			fatorial*=j;		
		}
		vetLong[i]=fatorial;
		if(fatorial==0){
			vetLong[i]=-1;
		}			
	}
	
	/*debug manual, descomentar para ver impressao da funcao
	for(i=0;i<qntElementos;i++){
		printf("\nvetor de fatorial na [%i]= %lu", i, vetLong[i]);
	}
	*/
}

//LETRA E, imprimindo vetor de double com o seu fatorial que eh o vetor de long
void imprime(int qntElementos, double vetDouble[], unsigned long vetLong[]){
	int i;
	printf("# Voce digitou os seguintes elementos:\n"); 
	for(i=0;i<qntElementos;i++){
		printf("%.3lf\n", vetDouble[i]);
	}
	for(i=0;i<qntElementos;i++){
		if(vetLong[i]==-1){
		printf("Fatorial de %.0lf = ERRO\n", vetDouble[i]);	
		}else{
		printf("Fatorial de %.0lf = %lu\n", vetDouble[i], vetLong[i]);
		}
	}
	printf("\n# FIM\n");
}


main(){
	
	int qntElementos, i; 
	unsigned long vetLong[TAM];
	double vetDouble[TAM];
		
	qntElementos=quantosElementos();
	receberElementos(qntElementos, vetDouble);
	ordenarVetor(vetDouble, qntElementos);
	gerarFatorial(vetDouble, vetLong, qntElementos);
	imprime(qntElementos, vetDouble, vetLong);
	
}
