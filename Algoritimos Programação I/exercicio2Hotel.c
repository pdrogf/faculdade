#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


main(){
       
      float pessoas, dias, valorTotal;
      
      printf("Digite a quantidade de pessoas:");
      scanf("%f", &pessoas); 
      
      printf("Digite a quantidade de dias:");
      scanf("%f", &dias);
      
      
      valorTotal = ((pessoas * dias)*234);
      valorTotal += valorTotal*0.05;
      
      printf("Valor total: %f", valorTotal);
      
      
      system("pause");
       
}
