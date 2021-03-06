#include <stdio.h>
#define TAM 60000
//t13v2 alteracao do tipo de dado do vetor de int para unsigned long, fatorial ateh 20

//LETRA A, entrada da quantidade de elementos tratando entrada inesperada
int quantosElementos(){
	int valida;
	int qntElementos;
	printf("# Quantos n�meros quer digitar? (1 a 60000)\n\n");
	valida = scanf("%d", &qntElementos);
	while(qntElementos > TAM || qntElementos<1 || valida!=1){
		if(fgetc(stdin)!='\n'){
			continue;
		}
		printf("# Voc� digitou LIXO\n\n");
		valida=scanf("%i", &qntElementos);				
	}
	return(qntElementos);	
}

//LETRA B entrada do vetor de double		
void receberElementos(int qntElementos, double vetDouble[]){	
	int i, j, compara1, compara2, valida;
		for(i=0;i<qntElementos;i++){
		printf("\n# Digite %d numeros positivos que serao colocados no vetor:\n", qntElementos);
		valida = scanf("%lf", &vetDouble[i]);
		for(j=0;j<i;j++){
				compara1=(int)(vetDouble[j]*10000+0.5);
				compara2=(int)(vetDouble[i]*10000+0.5);
				if(compara1==compara2){
					printf("# ERRO: %.4lf j� foi digitado\n\n", compara1);
					i--;
					break;
				}
			}			
		while(vetDouble[i]<1 || vetDouble[i]> 500000 || valida!=1){
			if(fgetc(stdin)!='\n'){
			continue;
			}
			printf("# ERRO: %.6lf fora da faixa (1.000000 a 500000.000000)\n\n", compara1);
			valida = scanf("%lf", &vetDouble[i]);
		}
	}
	/*
	debug manual, descomentar para ver impressao da funcao
	for(i=0;i<qntElementos;i++){
		printf("\nvetor de double na [%i]= %lf", i, vetDouble[i]);
	}
	*/
}
	
//LETRA C, ordenando vetor recebido pelo usu�rio
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
		printf("\nFatorial de %.0lf = ERRO", vetDouble[i]);	
		}else{
		printf("\nFatorial de %.0lf = %lu", vetDouble[i], vetLong[i]);
		}
	}
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
