/*
TITULO: Definição do Exercício T25
DATA: 11/Nov/2016

Vale no máximo 0,5 pontos em recuperação em algum exercício anterior.

Habilidades: argumentos do main, abertura leitura de arquivo,
abertura leitura/escrita de arquivo, reposicionamento dento de um arquivo,
manipulação de strings (sem string.h!!!)

Faça um programa em C que para cada argumento do main,
tente abrir o argumento como um arquivo. Se não conseguir,
continue para o próximo.

Para cada arquivo aberto, colete:

- o tamanho, em bytes, deste arquivo
- Se a extensão for .txt:
  - a quantidade de letras minusculas
  - a quantidade de letras maiusculas
- Se a extensão for .txt e o nome começar com _ (underscore):
  - altere o arquivo nele mesmo transformando as letras minusculas em maiúsculas 
  (não vale fazer cópia para outro aquivo e nem baixar o arquivo todo para a 
  memória e depois gerar um novo. Tem que ir lendo e já alterando se for 
  necessário. dica: terá que usar fseek)
 
Ao final do processamento de todos os arquivos, informe:
- Quantos NÃO ERAM txt e a soma, em bytes, destes
- Total de letras maiusculas e minusculas de todos os TXTs
- Total GERAL de bytes de todos os arquivos

Crie arquivos de qualquer nome usando editores de texto. Cuidado para
não usar arquivos IMPORTANTES como teste, pois o programa poderá
danificá-los.*/

#include <stdio.h>

int tamanho(char st[])
{
    int c;
    for (c = 0; st[c]; c++);
    return (c);
}

int main (int argc, char **argv){
	int i;
	int tamanhoBytes = 0, tamanhoBytesNTXT = 0;	
	int qtdMinuscula = 0, qtdMaiscula = 0;
	int totalMinuscula = 0, totalMaiscula = 0;
	int tamanhoNomeArq = 0;
	int ehTXT = 0, nTXT = 0;
	int totalBytesNTXT = 0, totalBytes = 0, totalBytesTXT = 0;
	int qtdnTXT = 0;
	char letra;
	FILE *arq;

	if(argc == 1){
		printf("# Faltou passar arquivo\n");
		printf("# [Finalizando sistema...]\n");
		return(0);
	}	
	for(i = 1; i < argc; i++){
		//Tenta abrir o arquivo, se nÃ£o conseguiu passa para o prÃ³ximo
		arq = fopen(argv[i], "r+w");
		if (!arq){
			fprintf(stderr, "ERRO ao Abrir %s\n", argv[i]);
			continue;
		}else{
			//Verificando se eh .txt
			ehTXT = 0, nTXT = 0;
			tamanhoNomeArq = tamanho(argv[i]);
			if((argv[i][tamanhoNomeArq -1] == 't') && 
					(argv[i][tamanhoNomeArq -2] == 'x') &&
						(argv[i][tamanhoNomeArq -3] == 't') &&
							(argv[i][tamanhoNomeArq -4] == '.')){
				fseek(arq, 0, SEEK_END);
				tamanhoBytes = ftell(arq);			
				totalBytesTXT += tamanhoBytes;		 	
				//Verifica se o nome do arquivo comeÃ§a com "_"
        		if(argv[i][0] == '_'){
        			fseek(arq, 0, SEEK_SET);
        			do{
        				letra = fgetc(arq);
            			if (feof(arq)) {
                			break;
            			}
        				if((letra > 96) && (letra < 123)){
        					fseek(arq, -1, SEEK_CUR);
                			fprintf(arq, "%c", letra-32);
                		}            		
        			}while (!feof(arq));
        			fclose(arq);  	
        		}else{//Se nao comecar com _
    				//Lendo os caracteres do arquivo e contando maisculas e minusculas
    				qtdMinuscula = 0;
    				qtdMaiscula = 0;
    				fseek(arq, 0, SEEK_SET);
					do{
            		fscanf(arq, "%c", &letra);
            			if(feof(arq)) {
                			break;
            			}
            			if(letra > 96 && letra < 123){
        					qtdMinuscula++;
        				}
        				if(letra > 64 && letra < 91){
        					qtdMaiscula++;
        				}            		
        			}while(!feof(arq)); 
        			totalMaiscula += qtdMaiscula;
        			totalMinuscula += qtdMinuscula;
        			fclose(arq);
    			}    			
    		}else{//Se nao for .txt
    			fseek(arq, 0, SEEK_END);
    			tamanhoBytesNTXT = ftell(arq);
    			totalBytesNTXT += tamanhoBytesNTXT;
    			qtdnTXT++;
    			fclose(arq); 
    		}
		}
	}
	totalBytes = totalBytesNTXT + totalBytesTXT;

	printf("# Total de letras maisculas: %i\n", totalMaiscula);
	printf("# Total de letras minusculas: %i\n", totalMinuscula);
	
	printf("# Quantidade de arquivos NTXT: %i\n", qtdnTXT);
	printf("# Total geral de bytes dos arquivos NTXT: %i\n", totalBytesNTXT);

	printf("# Total geral de bytes de todos arquivos: %i\n", totalBytes);
}
