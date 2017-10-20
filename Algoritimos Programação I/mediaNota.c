#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

main (){
     
     float n1, n2, media;
     
     printf("Digite a primeira nota: \n");
     scanf("%f", &n1);
     
     printf("Digite a segunda nota: \n");
     scanf("%f", &n2);
     
     media = (n1+n2)/2;
     
     if (media>=6){
        printf("aprovado, media: %f", media);               
          }
     
     else{
        printf("reprovado, media: %f", media);
        }   
     
     system("pause");
}
