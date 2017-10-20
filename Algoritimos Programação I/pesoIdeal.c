#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

main (){
	
	int sexo;
	float altura, pesoIdeal;
	char nome[30];
	
	printf("Digite seu nome: ");
	scanf("%s", nome);
	
	printf("Digite 1 - para Masculino e 2 - para Feminino \n");
	scanf("%i", &sexo);
	
	printf("Digite a altura: \n ");
	scanf("%f", &altura);
	
	
		switch (sexo){
			
			
			case 1:
				pesoIdeal = (72.7*altura) - 58;				
			break;
			
				case 2:
					pesoIdeal = (62.1*altura) - 44.7;					
				break;
				
					default:
						printf("Sexo selecionado invalido \n");
					break;
				
		} // fecha switch
	
	printf("Nome: %s \n", nome);
	printf("Peso ideal: %f ", pesoIdeal);
	
	system("pause");
}
