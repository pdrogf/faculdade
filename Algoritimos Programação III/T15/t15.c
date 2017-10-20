#include <stdio.h>


int ehpalin(char st1[]){
    upperCase(st1);
   	int i, f;
    for (f = 0; st1[f]; f++); 
       	f--;
   		i=0;
   	
   			while(!(st1[i] >= 65 && st1[i] <= 90)){
				i++;
			} 		
				
			while(!(st1[f] >= 65 && st1[f] <= 90)){
				f--;
			}
			while (i < f) {
   						
        	if (st1[i] != st1[f]){           
            	return (0);
        	}
      	
        i++;
        f--;
        }
    	
    return (1);
}
//trasnforma em maiscula
int upperCase(char st1[]){
   int i;
   for(i=0;st1[i];i++)
   st1[i]=st1[i]>='a'&&st1[i]<='z'?st1[i]-32:st1[i];
}

int main(int argc, char *argv[]){
	int cont, p=0;

	if(argc<1){
		printf("ERRO");
		printf("\n# Faltou passar parametros");
		printf("\n# FIM");1
	}

	
    for(cont=1; cont < argc; cont++){
    	if(ehpalin(argv[cont])==1){
       	printf("\n       PALINDROMO = ");
       	printf("\"%s\"", argv[cont]);
       	p++;
	   }else{
	   		printf("\nNAO EH PALINDROMO = ");
	   		printf("\"%s\"", argv[cont]);
	   }
	}
	if(cont-1<1){
		return(printf("ERRO"));
	}else{
	printf("\n%i FRASES", cont-1);
	printf("\n%i PALINDROMOS", p);	
	printf("\n# FIM");	   	
    }
}
