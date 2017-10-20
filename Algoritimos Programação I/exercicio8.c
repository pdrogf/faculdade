#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

main(){
       
       float salario, aumento, total;
       
       printf("Digite o salario atual:");
       scanf("%f", &salario);
       
       if(salario>=100 && salario<=500){
            aumento = salario*0.10;
            total = aumento+salario;                
       }
       else if(salario>500 && salario<=1000){
            aumento = salario*0.08;
            total = aumento+salario;  
       }
       else if(salario>1000 && salario<=2000){
             aumento = salario*0.04,8;
             total = aumento+salario;      
        }
         else if(salario>2000){
             aumento = salario*0.03,2;
             total = aumento+salario;      
        }
        else{
        printf("salario menor que 100, nao recebe aumento");    
        }
        
        printf("Salario atual: %f", salario);
        printf("\nAumento do salario: %f", aumento);
        printf("\nSalario com Aumento: %f\n", total);
       

       system("pause");
}
