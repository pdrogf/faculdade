/*
TITULO: Definição do Exercício T12
DATA: 19/Agosto/2016

Pode ser feito no máximo em TRIOS, desde de que iniciados na aula do dia 
19/Agosto. Quem faltar a esta aula deverá, necessariamente, realizar 
individualmente. Este exercício deve ser postado na página de exercícios 
antes do início da aula do dia 26/Agosto. Página para postar soluções em

http://gravatai.ulbra.tche.br/~elgio/corrige.php

Em caso de cópia de trabalhos, todos os envolvidos terão a nota deste 
exercício ZERADA e não será concedida chance de recuperar.


Objetivo deste exercício: lembrar da sintaxe desenvolvida nas disciplinas
de algoritmos 1 e 2, manipulação de vetores estáticos e laços. Já exercitar
a forma mais "hacker" de programar.


Definição:

Faça um programa em C ANSI que solicite que o usuário digite N elementos
inteiros, positivos ou negativos. N não pode ser maior que 50000. 

Usuário deve dizer qual o tamanho de N no início (deve ler do teclado).
(simplesmente encerrar a execução se for um valor de N inválido)

Armazene todos os elementos digitados em um vetor de inteiros antes de 
realizar qualquer operação com eles.

Após a digitação e armazenamento de todos os inteiros, para cada inteiro 
armazenado no vetor, faça:

a) Ordene o vetor de inteiros
b) Informe se o número é par ou impar. Ignore repetidos.
b) informe se o número é primo e se não for imprima todos os seus divisores (ignore repetidos)
c) calcule um vetor de doubles com a média dos elementos do vetor de inteiros,
   da seguinte forma (exemplo para um vetor com N==10, dez elementos):
   
   - vetDouble[0] terá a média entre vetINT[0], vetINT[1], vetINT[2], vetINT[3] e vetINT[4]
   - vetDouble[1] terá a média entre vetINT[1], vetINT[2], vetINT[3], vetINT[4] e vetINT[5]
   ...
   - vetDouble[6] terá a média entre vetINT[6], vetINT[7], vetINT[8], vetINT[9] e vetINT[0]
   - vetDouble[7] terá a média entre vetINT[7], vetINT[8], vetINT[9], vetINT[0] e vetINT[1]
   - vetDouble[8] terá a média entre vetINT[8], vetINT[9], vetINT[0], vetINT[1] e vetINT[2]
   (exemplos acima considerando um vetor no qual exista os elementos [1], [2], [3] e [4])

(ou seja, após o último elemento sucedem-se o [0] e [1] como se fosse circular.
CUIDADO PARA VETORES PEQUENOS. Se N for 3 haverá apenas [0], [1] e [2]. A média 
de [0] será,  neste caso, entre [0], [1], [2] e, novamente [0], [1]

Observe atentamente um exemplo de uso deste programa:

C:\> exercT12.exe <ENTER>
Quantos elementos você quer? (1 a 50000)
0<ENTER>
Erro. Valor 0 inválido
ENCERRADO

C:\> exercT12.exe <ENTER>
Quantos elementos você quer? (1 a 50000)
-5<ENTER>
Erro. Valor -5 inválido
ENCERRADO

C:\> exercT12.exe <ENTER>
Quantos elementos você quer? (1 a 50000)
534000<ENTER>
Erro. Valor 534000 inválido
ENCERRADO

C:\> exercT12.exe <ENTER>
Quantos elementos você quer? (1 a 50000)
6<ENTER>

Digite 6 números inteiros positivos ou negativos:
1199993 10 55 -7 10 8921<ENTER>

Lido com sucesso 6 inteiros

        -7 => IMPAR  DIVISORES: PRIMO
        10 => PAR    DIVISORES: 2, 5
        55 => IMPAR  DIVISORES: 5, 11
      8921 => IMPAR  DIVISORES: 11, 811
   1199993 => IMPAR  DIVISORES: PRIMO

vetDouble[0] = 1797.80
vetDouble[1] = 241797.80
vetDouble[2] = 241794.40
vetDouble[3] = 241794.40
vetDouble[4] = 241785.40
vetDouble[5] = 240012.20

FIM
C:\> 

Ao informar se é par ou impar e os divisores, foi ignorado o segundo valor 10
(ignorar repetidos). Mas não foi ignorado no cálculo do vetor de Doubles.
vetDouble[0] = (-7+10+10+55+8921)/5

C:\> exercT12.exe <ENTER>
Quantos elementos você quer (1 a 50000):
11<ENTER>

Digite  números inteiros positivos ou negativos
123 12490 23 25 12 65309 12 25 123 12490 843371<ENTER>

Lido com sucesso 11 inteiros
        12 => PAR    DIVISORES: 2, 3, 4, 6
        23 => IMPAR  DIVISORES: PRIMO
        25 => IMPAR  DIVISORES: 5
       123 => IMPAR  DIVISORES: 3, 41
     12490 => PAR    DIVISORES: 2, 5, 10, 1249, 2498, 6245
     65309 => IMPAR  DIVISORES: PRIMO
    843371 => IMPAR  DIVISORES: PRIMO

vetDouble[0] = 19.40
vetDouble[1] = 41.60
vetDouble[2] = 63.80
vetDouble[3] = 2557.20
vetDouble[4] = 5050.20
vetDouble[5] = 18107.00
vetDouble[6] = 186756.60
vetDouble[7] = 186734.40
vetDouble[8] = 184238.80
vetDouble[9] = 181745.40
vetDouble[10] = 168688.60

FIM


d) DESAFIO: ao inves de calcular a media entre CINCO elementos, fazer a 
media entre os K elementos, sendo K = (tam/20)+1, ou seja, K tem um vigesimo 
mais um o tamanho do vetor. Se o vetor tiver 311 elementos, será a media 
sobre 15+1=16 elementos. Se o vetor tiver miseros 5 elementos, será a média
entre (5/20)=0+1=1 apenas 1 elemento. Ou seja, dele mesmo.

O teu programa é seguro contra entradas inesperadas?
(digite uma string quando ele espera um inteiro do vetor)
*/

#include <stdio.h>
#define K 50000



main(){
	
	int vet[K];
	int n, i, j, k, aux, cont, prox, temp=0, quant;
	double vetDouble[K];
	
	//validando se quant elementos do vetor eh valido
	printf("\nDigite a quantidade de elementos do vetor: ");
	scanf("%i", &n);
	if(n<1 || n>K){
		return(0);
	}
	
	//recebendo valores para o vetor de inteiros
	for(i=0;i<n;i++){
		printf("\nDigite os elementos do vetor: ");
		scanf("%i", &vet[i]);
	}
 	//ordernar vetor
    for( i=0; i<n; i++ ){
        for( j=i+1; j<n; j++ ){
            if( vet[i] > vet[j] ){
            	aux = vet[i]; 
            	vet[i] = vet[j];
            	vet[j] = aux;
            }
        }
    }
	printf("\nOrdenado com sucesso!"); 
    
	//imprime vetor ordenado    
	//trata impressao repetido
    for(i=0;i<n;i++){
    	if(vet[i]%2==0 && vet[i]!=temp){
		    printf("\n%i eh par", vet[i]);
		    temp=vet[i];
		}else if(vet[i]!=temp){
			printf("\n%i eh impar", vet[i]);
			
			temp=vet[i];
		}
	}
	temp=0;
	 //validar se eh primo  
	for(i=0;i<n;i++){           
    	for(k=1;k<=vet[i];k++){
        	if(vet[i]%k==0){
        		cont++; 
       		}
    	}                 
    	if(cont==2 && vet[i]!=temp){
        	printf("\n%i, eh primo\n", vet[i]);
        	temp=vet[i];
    	}
		else if(cont!=2 && vet[i]!=temp){
			printf("\n%i Nao eh primo", vet[i]);
        	for(j=1;j<=vet[i];j++){
        		if(vet[i]%j==0){
				 	printf("\nDivisores %i", j);
				 	
				}     
			}
		temp=vet[i]; 	
    	}
    }
    
	quant =  5;
	for (i = 0; i < n; i++) {
		temp = i;
		for (j = quant; j > 0; j--) {
			vetDouble[i] += vet[aux];
			if (aux + 1 < n) {
				aux++;
			} else {
				aux = 0;
			}
		}

		vetDouble[i] = vetDouble[i] / quant;
	}
	for (i = 0; i < quant; i++) {
		printf("\nvetDouble[%i] = %.2lf\n", i, vetDouble[i]);
	}


	
	
	
	
}
