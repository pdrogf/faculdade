#include <stdio.h>
#include <string.h>
#define TAMP 150001

/* a) Solicite ao usu�rio que digite textos at� uma quebra de linha.
Cada texto poder� ter at� 150000 caracteres. A primeira coisa que ele
ir� digitar ser� uma string de t�rmino que dever� ter 3 letras no m�nimo.
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
