#include <stdio.h>
#define TAM 900
//FALTOU O TAMANHO NA DEFINICAO!!! 

//Lixo de memoria
int inicializa(int *Vet){
	int i;
	for(i=0; i < TAM; i++){
		Vet[i] = -1;
	}
}
int Sorteia(int *Vet){
	int i;	
	for(i=0; i < TAM; i++){
		Vet[i] = rand()%900;
	}	
}
int VerificaPar(int *Vet, int *VetPar){
	int i, j=0;
	for(i=0; i < TAM; i++){
		if(Vet[i]%2 == 0){
			VetPar[j] = Vet[i];
			j++;
		}
	}
}
int VerificaImpar(int *Vet, int *VetImpar){
	int i, j=0;
	for(i=0; i < TAM; i++){
		if(Vet[i]%2 != 0){
			VetImpar[j] = Vet[i];
			j++;
		}
	}
}
int VerificaPrimo(int *Vet, int *VetPrimo){
	int i, k, j=0, div=0;
	for(i=0; i< TAM; i++){
		for(k=1; k<=Vet[i]; k++){
			if(Vet[i]%k == 0){
				div++;
			}
		}
		if(div == 2){
			VetPrimo[j] = Vet[i];
			j++;
		}
		div=0;
	}	
}
int VerificaIntervalo(int *Vet, int *VetIntervalo){
	int i, j=0;
	for(i=0; i < TAM; i++){
		if(Vet[i]>=250 && Vet[i]<=650 ){
			VetIntervalo[j] = Vet[i];
			j++;
		}
	}
}
int Imprime(int *Vet){
	int i;
	for(i=0; i < TAM; i++){
		printf("%i \n", Vet[i]);
	}
}

main(){
	int Vet[TAM];
	int VetPar[TAM];
	int VetImpar[TAM];
	int VetPrimo[TAM];
	int VetIntervalo[TAM];	
	
	inicializa(Vet);
	inicializa(VetPar);
	inicializa(VetImpar);
	inicializa(VetPrimo);
	inicializa(VetIntervalo);
		
	Sorteia(Vet);
	VerificaPar(Vet, VetPar);
	VerificaImpar(Vet, VetImpar);
	VerificaPrimo(Vet, VetPrimo);
	VerificaIntervalo(Vet, VetIntervalo);
	printf("\nVetor Vet\n");
	Imprime(Vet);
	printf("\nVetor VetPar\n");
	Imprime(VetPar);
	printf("\nVetor VetImpar\n");
	Imprime(VetImpar);
	printf("\nVetor VetPrimo\n");
	Imprime(VetPrimo);
	printf("\nVetor VetIntervalo\n");
	Imprime(VetIntervalo);
	
}
