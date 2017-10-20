#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

main(){
       
       float num1, num2, num3, mediaA, mediaP;
       int i;
       
        printf("Digite 1 - para calular a media aritimetica:"
                       "\nDigite 2 - para calcular a media ponderada:\n");
        scanf("%i", &i);
        
        printf("Digite a primeira nota \n");
        scanf("%f", &num1);
        
        printf("Digite a segunda nota \n");
        scanf("%f", &num2); 
         
        printf("Digite a terceira nota \n");
        scanf("%f", &num3);
        
        if(i == 1){
             mediaA = (num1 + num2 + num3)/3;
             printf("Media aritimetica: %f", mediaA); 
             
        }
        else {
             mediaP = ((num1*2) + (num2*3) + (num3*5))/10;      
             printf("\nMedia ponderada: %f ", mediaP);
        }
        
       
        
        
        
        system("pause");   


}
