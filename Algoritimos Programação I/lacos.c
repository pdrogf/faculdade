#include <stdlib.h>
#include <stdio.h>

main(){
	
	float valor, contador;
	
	contador=0;
	
	while(contador<3500){
		printf("Digite um valor");
		scanf("%f", &valor);
		
		contador++;
	}
	
	
	system("pause");
}
