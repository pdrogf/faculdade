#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


main (){
     
     float num1, num2, conta;
     char op;
     
     printf("Digite o primeiro valor \n");
     scanf("%f", &num1);
     
     printf("Digite o segundo valor \n");
     scanf("%f", &num2);
     
     printf("Digite a operacao matematica: (+,-,/,*) \n");
     scanf("%s", &op);
     
     switch (op){
            
            case '+':
                 conta = (num1+num2);
                 printf("Resultado da soma: %f", conta);
            break;
            
            case '-':
                 conta = (num1-num2);
                 printf("Resultado da subtracao:  %f", conta);
            break;
            
            case '*':
                 conta = (num1*num2);
                 printf("Resultado da multiplicacao: %f", conta);
            break;
            
            case '/':
                 conta = (num1/num2);
                 printf("Resultado da divisao: %f", conta);
            break;
            
            default:
                 printf("Operacao aritimetica invalida ");
     }

      system("pause");
     
     
     
}
