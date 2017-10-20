#include <stdio.h>
#include <string.h>
#define TAMP 150001

/* a) Solicite ao usuário que digite textos até uma quebra de linha.
Cada texto poderá ter até 150000 caracteres. A primeira coisa que ele
irá digitar será uma string de término que deverá ter 3 letras no mínimo.
*/

//Receebe chave e texto
//Valida se o texto eh a chave, caso sim encerra o sistema
void receberChaveTexto(){
	int valida, cont=0;
	char strFinaliza[TAMP];
	char strTexto[TAMP];
	int i, length, flag=0;
		
	if(cont==0){
	printf("# Digite a string de saida: \n");
	fgets(strFinaliza, TAMP, stdin);
	}
	
	do{	
		printf("# Digite seu texto: \n");
		fgets(strTexto, TAMP, stdin);
		valida=strncmp(strFinaliza, strTexto, TAMP);
		length = strlen(strTexto);
	    	for(i=0;i < length ;i++){
    	    	if(strTexto[i] != strTexto[length-i-1]){
        	    	flag = 1;
            		break;
	   			}
			}
    
    	if (flag!=1) {
        	printf("# Nao eh palindrome\n");
    	}else {
        	printf("# eh palindrome\n");
    	}
	}
	while(valida!=0);
	
	printf("# Chave de saida inserida, encerrando sistema...");
}

main(){
	receberChaveTexto();
	
}
