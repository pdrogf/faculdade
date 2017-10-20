#include <stdio.h>
#define TAM 60000

//LETRA A, entrada da quantidade de elementos tratando entrada inesperada
int quantosElementos(){
	int valida;
	int qntElementos;
	printf("Digite a quantidade de elementos: (positivo < 60000) ");
	valida = scanf("%d", &qntElementos);
	while(qntElementos > TAM || qntElementos<1 || valida!=1){
		if(fgetc(stdin)!='\n'){
			continue;
		}
		printf("\nVoce digitou valor invalido cabecao, digite novamente: ");
		valida=scanf("%i", &qntElementos);				
	}
	return(qntElementos);	
}

//LETRA B entrada do vetor de double		
void receberElementos(int qntElementos, double vetDouble[]){	
	int i, j, compara1, compara2, valida;
		for(i=0;i<qntElementos;i++){
		printf("\nDigite os elementos do vetor: entre 1 e 500000: ");
		valida = scanf("%lf", &vetDouble[i]);
		for(j=0;j<i;j++){
				compara1=(int)(vetDouble[j]*10000+0.5);
				compara2=(int)(vetDouble[i]*10000+0.5);
				if(compara1==compara2){
					printf("\nElemento ja existente, digite novamente: ");
					i--;
					break;
				}
			}			
		while(vetDouble[i]<1 || vetDouble[i]> 500000 || valida!=1){
			if(fgetc(stdin)!='\n'){
			continue;
			}
			printf("\nValor digitado invalido, digite novamente: ");
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
	printf("\nOrdenado com sucesso!"); 
	/*
	debug manual, descomentar para ver impressao da funcao
	for(i=0;i<qntElementos;i++){
		printf("\nvetor ordenado %lf", vetDouble[i]);
	}
	*/
}

//LETRA D, gerando vetor de interiros a partir do fatorial de cada elemento do vetor de double, sendo arredondado ou truncado
void gerarFatorial(double vetDouble[], int vetInt[], int qntElementos){
	int i, j, y, fatorial;
	for(i=0;i<qntElementos;i++){
		y = (int)(vetDouble[i]+0.5);
		fatorial=y;
		for(j=1;j<y;j++){
			fatorial*=j;		
		}
		vetInt[i]=fatorial;
		if(fatorial==0){
			vetInt[i]=-1;
		}			
	}
	/*
	debug manual, descomentar para ver impressao da funcao
	for(i=0;i<qntElementos;i++){
		printf("\nvetor de fatorial na [%i]= %i", i, vetInt[i]);
	}
	*/
}

//LETRA E, imprimindo vetor de double com o seu fatorial que eh o vetor de inteiros
void imprime(int qntElementos, double vetDouble[], int vetInt[]){
	int i;
	for(i=0;i<qntElementos;i++){
		printf("\nVoce digitou os seguintes elementos %.3lf", vetDouble[i]);
	}
	for(i=0;i<qntElementos;i++){
		if(vetInt[i]==-1){
		printf("\nFatorial de %.0lf = ERRO", vetDouble[i]);	
		}else{
		printf("\nFatorial de %.0lf = %i", vetDouble[i], vetInt[i]);
		}
	}
}


main(){
	
	int qntElementos, i; 
	int vetInt[TAM];
	double vetDouble[TAM];
		
	qntElementos=quantosElementos();
	receberElementos(qntElementos, vetDouble);
	ordenarVetor(vetDouble, qntElementos);
	gerarFatorial(vetDouble, vetInt, qntElementos);
	imprime(qntElementos, vetDouble, vetInt);
	
}
