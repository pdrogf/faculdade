#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


main(){
       
       int valor1;
       
       printf("Digite o valor1:");
       scanf("%i", &valor1);
       
       if(valor1>=0){
            float calc = valor1%2;
            
            if(valor1 == 0){
                     printf("Numero neutro\n");         
            }
            else if (calc == 0){
                    printf("Numero par\n");     
            }
            else {
                    printf("Numero impar\n");     
            } 
       }
       else {
            printf("Valor negativon\n");     
       }
   
       system("pause");
}
