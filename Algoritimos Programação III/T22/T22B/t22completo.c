#include <stdio.h>
#include <stdlib.h>


int lestring(char s[], int max)
{
    int i = 0;
    char letra;

    for (i = 0; i < (max - 1); i++) {
        letra = fgetc(stdin);

        if (letra == 13) {      // ENTER. So tem no DOS como quebra de linha
            i--;
            continue;
        }
        if ((letra == 10) && (i == 0)) {
            i = i - 1;
            continue;
        }

        if (letra == 10) {      // Line FEED. Dos e Linux
            break;
        }
        s[i] = letra;
    }
    s[i] = 0;
    return (i);
   
}
int copiaN(char d[], char s[], int max)
{
    int i;
    max--;
    for (i = 0; (i < max) && s[i]; i++) {
        d[i] = s[i];
    }
    d[i] = 0;
    return (i);                 // retorna quantos cars copiou. 
}

struct TURMAS{
    char numeroTurma[101];
    char disciplina[101];
    char professor[101];
    int qntAlunos;
    struct ALUNOS *aluno;
    
};

struct ALUNOS{
        char matricula[101];
        char nomeAluno[101];
        double g1, g2, g3;
        double media1;
};

void cadastrar(struct TURMAS *turma, int qntTurmas){
    int q, w, s;
    int i, k, j, t;
    int valida;
    int thunay=0;
    int jaspion=0;
    int xispirito=0;
    int cont=0;
    
    for(i=0; i < qntTurmas; i++){
        turma[i].qntAlunos = 0;
        //Cadastra o codigo da turma
        printf("\n# --- Turma [%i] ---\n", i);
        /*Ao cadastrar codigo de turma, recusar se esta turma já foi cadastrada
        antes. Pedir um novo numero.*/
        
        do{
            thunay = 0;
            printf("\n# Codigo da turma: \n");
            lestring(turma[i].numeroTurma, 101);
            if(jaspion != 0){
            for(t = 0; t < i; t++){
                int teste;
                char st1[101];
                char st2[101];


               copiaN(st1, turma[t].numeroTurma, 101);
               copiaN(st2, turma[i].numeroTurma, 101);
               teste = compcasestr(st1, st2);
               // printf("\n%i", teste);
               // printf("%s\n", st1 );
               // printf("%s\n", st2 );
                if(teste == 0){
                    printf("\n# Codigo da turma ja cadastrada\n");
                    thunay = 1;
                }
            }
            }jaspion++;
        }while(thunay != 0);
        
        //Cadastra o nome da disciplina
        printf("\n# Nome da disciplina: \n");
        lestring(turma[i].disciplina, 101);
        //Cadastra o nome do professor
        printf("\n# Nome do professor: \n" );
        lestring(turma[i].professor, 101);
      	
      	
        //Cadastra a quantidade de alunos na turma e valida
        do{
            valida=0;
            printf("\n# Quantos alunos tem a turma %s: \n", turma[i].numeroTurma);

            if(!scanf("%i", &turma[i].qntAlunos)){

                    printf("\nERRO entrada invalida\n");
                    while(fgetc(stdin) != '\n');
                    valida=-1;                    
            }else if(turma[i].qntAlunos < 0){
                    printf("\nERRO %i\n", turma[i].qntAlunos );
                    
                   // while(fgetc(stdin) != '\n');
                    valida=-1;
            }//fim da validacao quantidade alunos na turma

        	//Verifica se pode alocar a quantidade de alunos e aloca
        	if(valida >= 0){
        		turma[i].aluno = (struct ALUNOS *) malloc(turma[i].qntAlunos * sizeof(struct ALUNOS));
            	if(turma[i].aluno == NULL) {
                	printf("\nERRO %i\n", turma[i].qntAlunos);
                	printf("\n# ERRO: Nao foi possivel alocar dados para %i alunos.\n", turma[i].qntAlunos);
                	valida=-1;
                	cont++;
                	//while(fgetc(stdin) != '\n');
            	}//fim da alocacao quantidade alunos
        	}
        	if(cont == 3){
        		while(fgetc(stdin) != '\n');
        		printf("\n# Terceira tentativa de alocar alunos, inserindo 0 alunos\n");
        		turma[i].qntAlunos = 0;
        		valida = 0;
        		cont = 0;
        		//while(fgetc(stdin) != '\n');
        	}
        }while(valida < 0);
        //fim do cadastro da STRUCT TURMA

        printf("\n# Alocado com sucesso espaco para %i alunos na turma %s\n", turma[i].qntAlunos, turma[i].numeroTurma);

        //CADASTRO DE ALUNO E SUAS NOTAS
        jaspion = 0;
        for(j=0; j < turma[i].qntAlunos; j++){
        	int verificador;
            verificador = 0;
            int m, n, o;
            //jaspion = 0;
            printf("\n# --- ALUNO [%i] ---\n", j);
            //desafio 
            /*
            ao cadastrar matricula de um aluno, recusar se
            ela já foi cadastrada dentro desta mesma turma (aluno repetido).
            }*/
                 
            do{
                verificador = 0;
                printf("\n# Qual o numero de matricula do aluno: \n");
                lestring(turma[i].aluno[j].matricula, 101);   

            if(jaspion != 0){   
                for(m = 0; m < j; m++){
                    xispirito=0;
                    char st1[101];
                    char st2[101];

                    copiaN(st1, turma[i].aluno[m].matricula, 101);
                    copiaN(st2, turma[i].aluno[j].matricula, 101);

                    //compcasestr(turma[i].aluno[m].matricula, turma[i].aluno[j].matricula)
                    xispirito = compcasestr(st1, st2);
                    if( xispirito == 0){
                        printf("\nERRO: matricula %s ja esta na turma\n", turma[i].aluno[j].matricula );
                        verificador = 1;
                    }
                }
            }jaspion++;            
            }while(verificador != 0);

            /*Se a matricula do aluno já existir em outra turma previamente cadastrada,
            não pedir nome do aluno, mas pegar o nome digitado para esta mesma
            matricula (ainda assim pedir notas, pois é relativo a esta turma).*/
                  
            
            for(q = 0; q < i; q++){//percorre as turmas
                for(w = 0; w < turma[w].qntAlunos; w++){//percorre os alunos em cada turma
                    if(compcasestr(turma[q].aluno[w].matricula, turma[i].aluno[j].matricula) == 0){
                        copiaN(turma[q].aluno[w].nomeAluno, turma[i].aluno[j].nomeAluno, 101);
                        
                        printf("\n#ASSUMIU\n");
                        s = 8;
                    }

                }
            }
            if(s != 8){            
                printf("\n# Qual o nome do aluno: \n");
                lestring(turma[i].aluno[j].nomeAluno, 101);
                s = 0;
                
            }
            


            printf("\n# Quais as notas G1, G2 e G3 do aluno\n");
        
            //Nota G1, cadastra e valida entrada
            do{
               //while(fgetc(stdin) != '\n');
                printf("\n# nota G1:\n");                           
                if(!scanf("%lf", &turma[i].aluno[j].g1)){
                    printf("\nERRO entrada invalida\n");            
                    while(fgetc(stdin) != '\n');
                    turma[i].aluno[j].g1=-1;                                  
                }else if(turma[i].aluno[j].g1 < 0){
                	printf("\nERRO %.0lf", turma[i].aluno[j].g1);
                    printf("\n# ERRO: Nota deve ser maior ou igual a zero \n");
                    //while(fgetc(stdin) != '\n');                                 
               	}else if(turma[i].aluno[j].g1 > 10){
                	printf("\nERRO entrada invalida\n");
                  	printf("\n# ERRO: Nota deve ser maior ou igual a zero \n");
                    turma[i].aluno[j].g1=-1;                                  
                }
                while(fgetc(stdin) != '\n');
            }while(turma[i].aluno[j].g1 < 0);  

            //Nota G2, cadastra e valida entrada
            do{
              	
                printf("\n# nota G2:\n");                         
                if(!scanf("%lf", &turma[i].aluno[j].g2 )){
                    printf("\nERRO entrada invalida\n");            
                    while(fgetc(stdin) != '\n');
                    turma[i].aluno[j].g2=-1;                
                }else if(turma[i].aluno[j].g2 < 0){
                	printf("\nERRO %.0lf", turma[i].aluno[j].g2);
                    printf("\n# ERRO: Nota deve ser maior ou igual a zero \n");
                                                
               	}else if(turma[i].aluno[j].g2 > 10){
                	printf("\nERRO entrada invalida\n");
                  	printf("\n# ERRO: Nota deve ser maior ou igual a zero \n");
                    while(fgetc(stdin) != '\n');
                  turma[i].aluno[j].g2=-1;                                    
                }
                while(fgetc(stdin) != '\n');
            }while(turma[i].aluno[j].g2 < 0);

            //Nota G3, cadastra e valida entrada
            do{
               	//while(fgetc(stdin) != '\n');
                printf("\n# nota G3:\n");                         
                if(!scanf("%lf", &turma[i].aluno[j].g3)){
                    printf("\nERRO entrada invalida\n");            
                    while(fgetc(stdin) != '\n');
                    turma[i].aluno[j].g3=-1;                
                }else if(turma[i].aluno[j].g3 < 0){
                	printf("\nERRO %.0lf", turma[i].aluno[j].g3);
                    printf("\n# ERRO: Nota deve ser maior ou igual a zero \n");
                                                    
               }else if(turma[i].aluno[j].g3 > 10){
                printf("\nERRO entrada invalida\n");
                   printf("\n# ERRO: Nota deve ser maior ou igual a zero \n");
                   while(fgetc(stdin) != '\n');
                   turma[i].aluno[j].g3=-1;                                  
                }
                while(fgetc(stdin) != '\n');
            }while(turma[i].aluno[j].g3 < 0);
           
        }//Fim cadastro de aluno e suas notas

    }//fim do laço de cadastro 

}//fim da função cadastro




    int compcasestr(char st1[], char st2[]) {
	char l1, l2;
	int i;

	for (i = 0; st1[i]; i++) {
		l1 = st1[i];
		l2 = st2[i];

		if ((l1 >= 'a') && (l1 <= 'z')) {
			l1 = l1 - 32;
		}
		if ((l2 >= 'a') && (l2 <= 'z')) {
			l2 = l2 - 32;
		}
		if (l1 != l2) {
			return (l1 - l2);
		}
	}

	return (st1[i] - st2[i]);
}
	int comparaNome(struct TURMAS *a, struct TURMAS *b) {
	return compcasestr(a->disciplina, b->disciplina);
}
	int comparaNota(struct ALUNOS *a, struct ALUNOS *b) {
	if (((a->g1 + a->g2 * 2) / 3) > ((b->g1 + b->g2 * 2) / 3)) {
		return 1;
	} else {
		return -1;
	}
	return 0;
}


int main(int argc, char **argv){

    int qntTurmas=0;
    int i, j;
    struct TURMAS *turma;
    double mediaFinal;
    //struct ALUNOS *aluno;

    //VALIDACAO QUANTIDADE DE TURMAS
    //se for passado somente 1 parametro pelo main
    if(argc == 1){        
    do{

        do{
            printf("\n# Quantas turmas voce quer cadastrar? \n");
            if(!scanf("%i", &qntTurmas)){;
            while(fgetc(stdin) != '\n'); 
                printf("\nERRO entrada invalida\n");
                printf("\n# Quantas turmas voce quer cadastrar? \n");
                (!scanf("%i", &qntTurmas));
               // while(fgetc(stdin) != '\n');
            }else if(qntTurmas < 0){
                printf("\n# ERRO Quantidade de turmas deve ser maior que 0\n");
                printf("\n# Quantas turmas voce quer cadastrar? \n");
                (!scanf("%i", &qntTurmas));
               // while(fgetc(stdin) != '\n');
            }             
        }while(qntTurmas < 1 );

        turma = (struct TURMAS *) malloc(qntTurmas * sizeof(struct TURMAS));   
        if(turma == NULL){
            printf("\nERRO %i", qntTurmas);
            printf("\n# ERRO: Nao foi possivel alocar dados para %i disciplinas.\n", qntTurmas);
        }        
        }while(qntTurmas < 1 || turma == NULL);
    }
    //se for passado mais de um parametro e o segundo ja seja um inteiro valido para quant de turmas
    else if(atoi(argv[1]) > 0){
        qntTurmas = atoi(argv[1]);
    }
    //se for passado mais de um parametro e o segundo nao for inteiro valido para qnt de turmas
    else{
        //qntTurmas = atoi(argv[1]);
        printf("\nERRO %s", argv[1]);
        do{

        do{
            printf("\n# Quantas turmas voce quer cadastrar? \n");
            if(!scanf("%i", &qntTurmas)){;
            while(fgetc(stdin) != '\n'); 
                printf("\nERRO entrada invalida\n");
                printf("\n# Quantas turmas voce quer cadastrar? \n");
                (!scanf("%i", &qntTurmas));
               //while(fgetc(stdin) != '\n');
            }else if(qntTurmas < 0){
                printf("\n# ERRO Quantidade de turmas deve ser maior que 0\n");
                printf("\n# Quantas turmas voce quer cadastrar? \n");
                (!scanf("%i", &qntTurmas));
               // while(fgetc(stdin) != '\n');
            }             
        }while(qntTurmas < 1 );

        turma = (struct TURMAS *) malloc(qntTurmas * sizeof(struct TURMAS));   
        if(turma == NULL){
            printf("\nERRO %i\n", qntTurmas);
            printf("\n# ERRO: Nao foi possivel alocar dados para %i disciplinas.\n", qntTurmas);
        }        
        }while(qntTurmas < 1 || turma == NULL);         
       
    }//FIM DA VALIDACAO QUANTIDADE DE TURMAS

    printf("\n# Alocado com sucesso espaco para %i turmas\n", qntTurmas);
    printf("\n# Digite dados para %i turmas\n", qntTurmas);    
    cadastrar(turma, qntTurmas);

    printf("\n# FIM DOS CADASTROS\n");


	qsort(turma, qntTurmas, sizeof(struct TURMAS), comparaNome);

	for(i=0; i < qntTurmas; i++){
	qsort(turma[i].aluno, turma[i].qntAlunos, sizeof(struct ALUNOS), comparaNota);
	}

    printf("\n# RELATORIO PARA %i turmas\n", qntTurmas);

    //impressao relatorio turma
    printf("\nTURMA DISCIPLINA PROFESSOR QTDALUNOS \n");
    for(i=0; i < qntTurmas; i++){
    	
    	printf("%s", turma[i].numeroTurma);
    	printf("  %s", turma[i].disciplina);    	
    	printf("  %s", turma[i].professor);
    	printf("  %i\n", turma[i].qntAlunos);
    }

    printf("\n# RELATORIO DOS ALUNOS EM CADA TURMA\n");
    for(i=0; i < qntTurmas; i++){
    	printf("\nTURMA %s - %s - %i alunos\n", turma[i].numeroTurma, turma[i].disciplina, turma[i].qntAlunos);
    	
    	if(turma[i].qntAlunos > 0){
    		printf("\nMAT    ALUNO     G1   G2   MEDIA     G3       MEDIAFINAL   \n");
    		for(j=0; j < turma[i].qntAlunos; j++){
    			
    			printf("\n%s", turma[i].aluno[j].matricula);
    			printf(" %s ", turma[i].aluno[j].nomeAluno);
    			printf("  %.1lf", turma[i].aluno[j].g1);  
    			printf("  %.1lf", turma[i].aluno[j].g2);
    			printf("  %.1lf", (turma[i].aluno[j].g1+ (turma[i].aluno[j].g2*2))/3);
    			printf("  %.1lf", turma[i].aluno[j].g3);

    			//calculo da media final
    			if(turma[i].aluno[j].g3 != 0){
    				//if(turma[i].aluno[j].g1 < turma[i].aluno[j].g2){
    				//	mediaFinal = (turma[i].aluno[j].g3 + (turma[i].aluno[j].g2 * 2))/3;
    				//}else{
    				//	mediaFinal = (turma[i].aluno[j].g1 + (turma[i].aluno[j].g3 * 2))/3;
    				//}
    				if (((turma[i].aluno[j].g3 + (turma[i].aluno[j].g2 * 2)) / 3) > ((turma[i].aluno[j].g1 + (turma[i].aluno[j].g3 * 2)) / 3)) {
					mediaFinal = (turma[i].aluno[j].g3 + (turma[i].aluno[j].g2 * 2)) / 3;
				} else {
					mediaFinal = (turma[i].aluno[j].g1 + (turma[i].aluno[j].g3 * 2)) / 3;
				}
    			}else{
    				mediaFinal = (turma[i].aluno[j].g1+ (turma[i].aluno[j].g2*2))/3;
    			}
    			printf("   %.1lf", mediaFinal);
    			if(mediaFinal >= 5.96){
    				printf("  APROVADO\n");
    			}else{
    				printf("  REPROVADO\n");
    			}

    			


    		}
    	}

    }






}