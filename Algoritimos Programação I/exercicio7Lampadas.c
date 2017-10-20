#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>


main(){
       
       int tipoComodo;
       float largura, comprimento, metroQuadrado, watts;
       
       printf("Informe o tipo de comodo:"
	   			"\n 1- Quarto"
				"\n 2- Cozinha"
				"\n 3- Banheiro"
				"\n 4- Escritorio"
				"\n 5- Sala\n");
       scanf("%i", &tipoComodo);
       
       printf("\nInforme a largura: ");
       scanf("%f", &largura);
       
       printf("\nInforme o comprimento: ");
       scanf("%f", &comprimento);
       
       switch(tipoComodo){
       	
       		case 1:
       			metroQuadrado = largura*comprimento;
       			watts = (metroQuadrado*15)/60;       		
       		break;
       		      	   
	   		case 2:
       			metroQuadrado = largura*comprimento;
       			watts = (metroQuadrado*20)/60;
       		break;
	   
	   		case 3:
       			metroQuadrado = largura*comprimento;
       			watts = (metroQuadrado*18)/60;
       		break;
       		      
	   		case 4:
       			metroQuadrado = largura*comprimento;
       			watts = (metroQuadrado*20)/60;
       		break;
       		
	   		case 5:
       			metroQuadrado = largura*comprimento;
       			watts = (metroQuadrado*18)/60;
       		break;     		
       	
	   		default:
	   			printf("Comodo selecionado invalido:\n");
					
	   		}
       
 		printf("Quantidade de lampadas: %2.f\n", ceil (watts));
   
       system("pause");
       
}

