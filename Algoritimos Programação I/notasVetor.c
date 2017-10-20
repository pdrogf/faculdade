#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAM 10
/*
Faça um programa que leia 10 notas e ao final apresente
- a maior nota
- a menor nota
- a media das notas
*/

main(){
    
    int i;
    float nota[TAM], soma=0, media, maiorNota=0, menorNota=0;
    
    for(i=0;i<TAM;i++){
        printf("Digite a nota: ");
        scanf("%f", &nota[i]);    
    }
    
    for(i=0;i<TAM;i++){
        if(i==0){
            maiorNota = nota[i];
        }
        if(nota[i]>maiorNota){
            maiorNota = nota[i];
        }           
    }
    
    for(i=0;i<TAM;i++){
        if(i==0){
            menorNota = nota[i];
        }
        if(nota[i]<menorNota){
            menorNota = nota[i];                   
        }        
    }
    
    for(i=0;i<TAM;i++){
        soma = soma+nota[i];    
    }
    
    media = soma/(float)TAM;
    
    printf("Media: %f", media);
    printf("Maior nota: %f", maiorNota);
    printf("Menor nota: %f", menorNota);
    
    
        
    system("pause");    
}
