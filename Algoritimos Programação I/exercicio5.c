#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

main(){
       
       int valor1, valor2, calc;
       
       printf("Digite o valor1:");
       scanf("%i", &valor1);
       
       printf("Digite o valor2:");
       scanf("%i", &valor2);
       
       calc = valor1%valor2;
       
       if(calc == 0){
       printf("Sao multiplos");        
       }
       else{
       printf("Nao sao multiplos");
       }


       system("pause");
}
