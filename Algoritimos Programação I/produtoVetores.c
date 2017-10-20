#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define VET1 3
#define VET2 3
#define VETP 3
/*
Dada duas sequências de 15 (quinze) números quaisquer, 
calcule o produto (Vet1[n]*Vet2[n]) de cada número com o 
seu correspondente. Para isso, utilize três vetores: dois 
para armazenar as duas sequências de números (Vet1 e Vet2) e 
outro para armazenar o produto (VetP). Ao final apresente os 
três vetores devidamente identificados ao usuário.
*/

main(){
    
    int i;
    float valor1[VET1], valor2[VET2], valor3[VETP], calc;
    
    for(i=0;i<VET1;i++){
        printf("Digite um valor para o vetor1: ");
        scanf("%f", &valor1[i]);    
    }
    for(i=0;i<VET2;i++){
        printf("Digite um valor para o vetor2: ");
        scanf("%f", &valor2[i]);    
    }
    for(i=0;i<VETP;i++){
        calc = valor1[i]*valor2[i];
        valor3[i]=calc;    
    }
    
    for(i=0;i<VETP;i++){
        printf("Vetor 1: %f * Vetor2: %f = VetorProduto: %f \n", valor1[i],valor2[i],valor3[i]);        
    }
    
    system("pause");
}
