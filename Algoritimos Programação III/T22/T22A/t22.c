#include <stdio.h>
#include <stdlib.h>

int lestring(char s[], int max)
{
    int i = 0;
    char letra;

    for (i = 0; i < (max - 1); i++) {
        letra = fgetc(stdin);

        /* NOVIDADE: Segurança contra o jeito DOS de se encerrar 
         * uma linha (caso se use a modalidade de arquivos
         * de testes e este arquivo esteja com quebras de linhas
         * padrao DOS
         * */
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

struct TURMAS{

    char numeroTurma[100];
    char disciplina[100];
    char professor[100];
    //qnt de alunos atual
    //lista dos alunos
    int qntAlunos;
    struct ALUNOS *aluno;
    
};

struct ALUNOS{
        char matricula[100];
        char nomeAluno[100];
        float g1, g2, g3;
};

/*
Após ter o vetor de turmas criado, use uma função para cadastrar turmas,
lendo número de turma, nome da disciplina, nome do professor e, finalmente,
quantidade de alunos. Se for digitado um valor inválido, imprima a mensagem
de erro e solicite novamente.
*/
void cadastrar(struct TURMAS *turma, struct ALUNOS *aluno, int qntTurmas){

    int i;
    int valida;
    
    for(i=0; i < qntTurmas; i++){

        //Cadastra o codigo da turma
        printf("\n# --- Turma [%i] ---\n", i);
        printf("\n# Codigo da turma: \n");
        lestring(turma[i].numeroTurma, 100);
        //implementar malloc no tamanho
        //Cadastra o nome da disciplina
        printf("\n# Nome da disciplina: ");
        lestring(turma[i].disciplina, 10000);
        //Cadastra o nome do professor
        printf("\n# Nome do professor: " );
        lestring(turma[i].professor, 10000);
      
        do{
            valida=0;
            printf("\n# Quantos alunos tem a turma %s: ", turma[i].numeroTurma);

            if(!scanf("%d", &turma[i].qntAlunos)){                                            
                    printf("\nERRO entrada invalida");
                    printf("\n# ERRO. Digitou lixo");
                    while(fgetc(stdin) != '\n');
                    valida=-1;                    
            }else if(turma[i].qntAlunos < 0){
                    printf("\nERRO %i", turma[i].qntAlunos );
                    printf("\n# ERRO. Digitou lixo");
                    while(fgetc(stdin) != '\n');
                    valida=-1;
            }
         

        }while(valida < 0 );
            

            //aluno = (struct ALUNOS *) malloc(turma[i].qntAlunos * sizeof(struct ALUNOS));
            
            //if (aluno == NULL) {
             //   printf("\nERRO %i", turma[i].qntAlunos);
               // printf("\n# ERRO: Nao foi possivel alocar dados para %i alunos.", turma[i].qntAlunos);
           // }
        
       // }while(turma[i].qntAlunos < 0 && aluno != NULL);
        //fim do bloco de validacao da quantidade de alunos
    //fim do cadastro de TURMA

    //printf("\n# Alocado com sucesso espaco para %i alunos na turma %s\n", turma[i].qntAlunos, turma[i].numeroTurma);

    //CADASTRO DE ALUNO E SUAS NOTAS
    for(i=0; i <= turma[i].qntAlunos; i++){
        printf("\n# --- ALUNO [%i] ---", i);
        printf("\n# Qual o numero de matricula do aluno: ");
        lestring(aluno[i].matricula, 10000);

       // printf("\n# Nome da disciplina: ");
       // lestring(turma[i].disciplina, 10000);

        printf("\n# Qual o nome do aluno: ");
        lestring(aluno[i].nomeAluno, 10000);

        printf("\n# Quais as notas G1, G2 e G3 do aluno");
        
        do{
            int verifica;

            printf("\n# nota G1: ");
            verifica = scanf("%f", &aluno[i].g1);
            
            if(verifica == 0){
                printf("\nERRO entrada invalida");            
                while(fgetc(stdin) != '\n');
                aluno[i].g1=-1;
                
            }else if(aluno[i].g1 < 0 && aluno[i].g1 >= 10){
                printf("\n# ERRO: Nota deve ser maior ou igual a zero ");
                while(fgetc(stdin) != '\n');
                
            }

        }while(aluno[i].g1 < 0);  
/*
            if(!scanf("%f", &aluno[i].g1)){
            printf("\nERRO entrada invalida");
            //printf("\n# nota G1: "); 
            while(fgetc(stdin) != '\n');
            }else{
                if((aluno[i].g1) < 0){
                    printf("\n# ERRO: Nota deve ser maior ou igual a zero ");
                    //printf("\n# nota G1: ");
                    scanf("%f", aluno[i].g1);
                    while(fgetc(stdin) != '\n');
                }
            }   */
        
        
        //printf("\n# Quais as notas G1, G2 e G3 do aluno");
        do{
            int verifica;

            printf("\n# nota G2: ");
            verifica = scanf("%f", &aluno[i].g2 );
            
            if(verifica == 0){
                printf("\nERRO entrada invalida");            
                while(fgetc(stdin) != '\n');
                aluno[i].g2=-1;
                
            }else if(aluno[i].g2 < 0 && aluno[i].g2 >= 10){
                printf("\n# ERRO: Nota deve ser maior ou igual a zero ");
                while(fgetc(stdin) != '\n');
                
            }

        }while(aluno[i].g2 < 0);
       // printf("\n# Quais as notas G1, G2 e G3 do aluno");
        do{
            int verifica;

            printf("\n# nota G3: ");
            verifica = scanf("%f", &aluno[i].g3);
            
            if(verifica == 0){
                printf("\nERRO entrada invalida");            
                while(fgetc(stdin) != '\n');
                aluno[i].g3=-1;
                
            }else if(aluno[i].g3 < 0 && aluno[i].g3 >= 10){
                printf("\n# ERRO: Nota deve ser maior ou igual a zero ");
                while(fgetc(stdin) != '\n');
                
            }

        }while(aluno[i].g3 < 0);
        }

    }  }  




int main(int argc, char **argv){

    int qntTurmas=0;
    struct TURMAS turma[100];
    struct ALUNOS aluno[100];

    //se for passado somente 1 parametro pelo main
    if(argc == 1){
        
        do{
            printf("\n# Quantas turmas voce quer cadastrar? ");
            if(!scanf("%d", &qntTurmas)){;
            while(fgetc(stdin) != '\n'); 
                printf("\nERRO entrada invalida");
                printf("\n# Quantas turmas voce quer cadastrar? ");
                (!scanf("%d", &qntTurmas));
                while(fgetc(stdin) != '\n');
            }else if(qntTurmas < 0){
                printf("\n# ERRO Quantidade de turmas deve ser maior que 0");
                printf("\n# Quantas turmas voce quer cadastrar? ");
                (!scanf("%d", &qntTurmas));
                while(fgetc(stdin) != '\n');
            }
          
        }while(qntTurmas < 1 );
         
    }
    //se for passado mais de um parametro e o segundo ja seja um inteiro valido para quant de turmas
    else if(atoi(argv[1]) > 0){
        qntTurmas = atoi(argv[1]);
    }
    // se for passado mais de um parametro e o segundo nao for inteiro valido para qnt de turmas
    else{
        qntTurmas = atoi(argv[1]);
        printf("\nERRO %s", argv[1]);
        printf("\n# Quantas turmas voce quer cadastrar? ");
        (!scanf("%d", &qntTurmas));
        while(fgetc(stdin) != '\n');
       
        do{ 

            if(qntTurmas == 0){
                printf("\nERRO entrada invalida");
                printf("\n# Quantas turmas voce quer cadastrar? ");
                (!scanf("%d", &qntTurmas));
                while(fgetc(stdin) != '\n');
            }
            if(qntTurmas < 0){
                printf("\n# ERRO Quantidade de turmas deve ser maior que 0");
                printf("\n# Quantas turmas voce quer cadastrar? ");
                (!scanf("%d", &qntTurmas));
                while(fgetc(stdin) != '\n');
            }
           // turma = (struct TURMAS *) malloc(qntTurmas * sizeof(struct TURMAS));   
           // if (turma == NULL) {
             //   printf("\nERRO %i", qntTurmas);
             //   printf("\n# ERRO: Nao foi possivel alocar dados para %i disciplinas.", qntTurmas);
           // }&& turma !=NULL
        }while(qntTurmas < 1 );      

    }

    printf("\n# Alocado com sucesso espaco para %i turmas", qntTurmas);
    printf("\n# Digite dados para %i turmas", qntTurmas);

    
    cadastrar(turma, aluno, qntTurmas);
}

