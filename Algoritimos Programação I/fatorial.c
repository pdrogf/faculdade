#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

main(){
       
      int fatorial=1, cont, valor;
      
      printf("digite o valor:");
      scanf("%i", &valor);
      
      cont = valor;
      
      while(cont>=1){
                     fatorial*=cont;
                     printf("%i\n", fatorial);
                     cont--;                                    
      
      }
       
       printf("%i! = %i",valor , fatorial);     

       system("pause");

}

