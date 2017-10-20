#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

main(){
       
       float valor, soma, media, cont;
       
       printf("Digite o valor:");
       scanf("%f", &valor);
       
       while(valor>=0){
       cont++;   
       soma=soma+valor;
       media=soma/cont;
       
       printf("Digite um valor (negativo para sair): ");
       scanf("%f",&valor);
        
       }
       
       printf("quantidade de repeticoes: %f", cont);
       printf("\nsoma dos valores: %f", soma);
       printf("\nmedia: %f", media);

       system("pause");

}
