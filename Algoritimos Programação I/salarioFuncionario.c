#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

main (){
     
     float codOperario, numHoras, salario, extra;
     
     printf("Digite o codigo do Operario: ");
     scanf("%f", &codOperario);
     
     printf("Digite o numero de horas trabalhadas: ");
     scanf("%f", &numHoras);
     
     if(numHoras <=50){
                 salario = (numHoras*10);
                 printf("salario: %.2f ", salario);            
     }   
     
     else{
                 extra = ((numHoras - 50)*20);
                 salario = (extra + (10*50));
                 
                 printf("salario total: %.2f \n ", salario);
                 printf("extra: %.2f \n ", extra);
     }
     
     
    system("pause");            
     

}
