#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

main(){
       
       float num1, num2, num3, mediaA, mediaH;
       
        printf("Digite o primeiro valor \n");
        scanf("%f", &num1);
        
        printf("Digite o segundo valor \n");
        scanf("%f", &num2); 
         
        printf("Digite o terceiro valor \n");
        scanf("%f", &num3);
        
        mediaA = (num1 + num2 + num3)/3;
        
        mediaH = 3/((1/num1)+(1/num2)+(1/num3));
        
        printf("Media aritimetica: %f", mediaA);  
        printf("\nMedia harmonica: %f ", mediaH);
        
        system("pause");   


}
