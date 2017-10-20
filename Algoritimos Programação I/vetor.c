#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define TAM 3

main(){
    
    int i;
    float nota[TAM], soma=0, media;
    
    for(i=0;i<TAM;i++){
        
        printf("Digite a nota: %i ", i+1);
        scanf("%f", &nota[i]);    
    
    }
    
    for(i=0;i<TAM;i++){
    
        soma = soma + nota[i];
    }
    
    for(i=0;i<TAM;i++){
        
        printf("%f\n", nota[i]);
    }
    
    media = soma/(float)TAM;
    
    printf("Media: %f", media);
    
    system("pause");    
}
