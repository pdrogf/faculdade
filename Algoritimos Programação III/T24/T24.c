// T23 do Elgio, implementacao T24

#include <stdio.h>
#include <stdlib.h>

#define STRNOME 100
#define STRNUM  20

struct ALUNOS {
    char mat[STRNUM];
    char nome[STRNOME];
    double g1, g2, g3;
    double media;
    double mediaFinal;
};

struct TURMAS {
    char nturma[STRNUM];
    char disciplina[STRNOME];
    char professor[STRNOME];
    int qa;
    struct ALUNOS *a;
};

/* Prototypes das funções */
/* Funcoes alteradas para manipular arquivo */
int lestring(char[], int, FILE *);
int cadastraturma(struct TURMAS *, int, FILE *);
int cadastraalunos(struct TURMAS *, int, FILE *);
double lenota(FILE *);

/* Funcoes mantidas */
int ordenaTurmas(struct TURMAS *, int);
int ordenaAlunos(struct ALUNOS *, int);
int tamanho(char *);
int relatorio(struct TURMAS *, int, FILE *out);

int main(int argc, char *argv[])
{
    struct TURMAS *turma;
    int qt = 0;
    int i, j;
    FILE *arqdados, *arqRelatorio, *arqConformeEntradas;
    char nomearq[STRNOME];
    int viaTeclado = 0;

    turma = NULL;

    arqdados = NULL;
    /* Parte nova: argv[1] agora é um nome de arquivo de onde deve
     * ser lido os dados */
    if (argc >= 2) {
        arqdados = fopen(argv[1], "r");
        if (arqdados == NULL) {
            fprintf(stderr, "# ERRO: nao pode abrir %s para leitura\n", argv[1]);
            //printf("ERRO %s\n", argv[1]);
            fprintf(stderr, "# Lendo via teclado\n");            
            fprintf(stderr, "# Digite a quantidade de turmas\n");
            arqdados = stdin;
            viaTeclado = 1;
        }
    }

    if (arqdados == NULL) {
        printf("# Digite arquivo com os dados das turmas:\n");
        lestring(nomearq, STRNOME, stdin);
        arqdados = fopen(nomearq, "r");
        if (arqdados == NULL) {
            fprintf(stderr, "# ERRO: nao pode abrir %s para leitura\n", nomearq);
            //printf("ERRO %s\n", nomearq);
            fprintf(stderr, "# Lendo via teclado\n");
            fprintf(stderr, "# Digite a quantidade de turmas\n");            
            arqdados = stdin;
            viaTeclado = 1;
        }
    }
    // arqdados agora é um arquivo aberto para leitura

    /* Ler a quantidade de turmas */
    while ((qt <= 0) || (turma == NULL)) {
        //Se a leitura estiver sendo via teclado, dialogo com usuario
        if(viaTeclado == 1){
            printf("\n# Quantas turmas voce quer cadastrar?\n");
        }
        
        if (fscanf(arqdados, "%i", &qt) < 1) {
            printf("ERRO entrada invalida\n");
            while (fgetc(arqdados) != '\n');
            continue;
        }
        if (qt <= 0) {
            printf("# ERRO Quantidade de turmas deve ser maior que 0\n");
            continue;
        }
        turma = (struct TURMAS *) malloc(qt * sizeof(struct TURMAS));
        if (turma == NULL) {
            printf("ERRO %d\n", qt);
            printf("# ERRO: Nao foi possivel alocar dados para %d disciplinas\n", qt);
        }
    }
    printf("# Alocado com sucesso espaco para %d turmas\n", qt);

    /* Função cadastra turma agora em um parâmetro a mais: de onde */
    qt = cadastraturma(turma, qt, arqdados);

    //printf("\n# FIM DA ETAPA A que era apenas o cadastro\n");

    ordenaTurmas(turma, qt);

    for (i = 0; i < qt; i++) {
        ordenaAlunos(turma[i].a, turma[i].qa);
    }

    //relatorio na tela
    relatorio(turma, qt, stdout);
    
    arqRelatorio = fopen("t24-relatorios.txt", "a");
    //valida se conseguiu criar o arquivo
    if (arqRelatorio == NULL){
        printf("# Nao foi possivel abrir o arquivo de relatorio\n");
        return(1);
    }
    //gera arquivo de saida com append    
    relatorio(turma, qt, arqRelatorio);

    //cria o arquivo conforme qnt de turmas
    sprintf(nomearq, "t24-%04d.txt", qt);
    
    arqConformeEntradas = fopen(nomearq, "w");
    //valida se conseguiu criar o arquivo
    if (arqConformeEntradas == NULL){
        printf("# Nao foi possivel criar o arquivo de saida\n");
        return(1);
    }
    //insere relatorio no arquivo
    fprintf(arqConformeEntradas, "%i\n", qt);
    for (i = 0; i < qt; i++) {
        fprintf(arqConformeEntradas, "%s\n", turma[i].nturma);
        fprintf(arqConformeEntradas, "%s\n", turma[i].disciplina);
        fprintf(arqConformeEntradas, "%s\n", turma[i].professor);
        fprintf(arqConformeEntradas, "%i\n", turma[i].qa);
        for (j = 0; j < turma[i].qa; j++) {
            fprintf(arqConformeEntradas, "%s\n", turma[i].a[j].mat);
            fprintf(arqConformeEntradas, "%s\n", turma[i].a[j].nome);
            fprintf(arqConformeEntradas, "%.1lf\n", turma[i].a[j].g1);
            fprintf(arqConformeEntradas, "%.1lf\n", turma[i].a[j].g2);
            fprintf(arqConformeEntradas, "%.1lf\n", turma[i].a[j].g3);
        }
        free(turma[i].a);
    }    

    for (i = 0; i < qt; i++) {
        if (turma[i].a) {
            free(turma[i].a);
        }
    }
    free(turma);
    fclose(arqRelatorio);
    fclose(arqdados);
    fclose(arqConformeEntradas);

}

int ordenaTurmas(struct TURMAS *t, int qt)
{
    struct TURMAS temp;
    int i, j, menor;
    
    for (i = 0; i < qt; i++) {
        menor = i;
        for (j = i + 1; j < qt; j++) {
            if (comparaSemCase(t[menor].disciplina, t[j].disciplina) > 0) {
                menor = j;
            }
        }
        if (menor == i) {
            continue;
        }
        // Troca de posicao t[i] com t[menor]
        temp = t[i];
        t[i] = t[menor];
        t[menor] = temp;
    }
}

int ordenaAlunos(struct ALUNOS *a, int qa)
{
    struct ALUNOS temp;
    int i, j, menor;

    /* Agora vou de select sort (estruturas de dados II) ;-) */
    for (i = 0; i < qa; i++) {
        menor = i;
        for (j = i + 1; j < qa; j++) {
            if (a[menor].media > a[j].media) {
                menor = j;
                continue;
            }
            if (a[menor].media == a[j].media) { //desempate
                if (comparaSemCase(a[menor].mat, a[j].mat) > 0) {
                    menor = j;
                }
            }
        }
        if (menor == i) {
            continue;
        }
        // Troca de posicao a[i] com a[menor]
        temp = a[i];
        a[i] = a[menor];
        a[menor] = temp;
    }
}

int cadastraturma(struct TURMAS *tur, int qt, FILE * onde)
{
    int i;
    int tent;

    for (i = 0; i < qt; i++) {
        printf("\n# --- Turma [%d] ---\n", i);

        printf("# Codigo da turma:\n");
        lestring(tur[i].nturma, STRNUM, onde);

        printf("\n# Nome da disciplina:\n");
        lestring(tur[i].disciplina, STRNOME, onde);

        printf("\n# Nome do professor:\n");
        lestring(tur[i].professor, STRNOME, onde);

        tur[i].a = NULL;

        tent = 0;

        while (tur[i].a == NULL) {
            printf("\n# Quantos alunos tem a turma %s?\n", tur[i].nturma);
            if (fscanf(onde, "%i", &tur[i].qa) < 1) {
                tur[i].qa = 0;
                while (fgetc(onde) != '\n');
                printf("ERRO entrada invalida\n");
                continue;
            }
            if (tur[i].qa < 0) {
                printf("ERRO %d\n", tur[i].qa);
                printf("# Quantidade de alunos deve ser maior ou igual a 0\n");
                continue;
            }

            tur[i].a = (struct ALUNOS *) malloc(tur[i].qa * sizeof(struct ALUNOS));
            if (tur[i].a == NULL) {
                printf("ERRO %d\n", tur[i].qa);
                printf("# ERRO: Nao foi possivel alocar dados para %d alunos\n", tur[i].qa);
                tur[i].qa = 0;
                tent++;
                if (tent >= 3) {
                    printf("# ERRO: Falhou nas 3 tentativas de alocar alunos\n");
                    printf("# ERRO: assumindo 0 turmas\n");
                    break;
                }
                continue;
            }
        }
        if (tur[i].qa > 0) {
            printf("\n# Alocado com suceso espaco para %d alunos na turma %s\n", tur[i].qa, tur[i].nturma);
            cadastraalunos(tur, i, onde);

            printf("# --- TURMA [%d] FIM DO CADASTRO\n", i);
        }
    }
    return (i);
}

int cadastraalunos(struct TURMAS *t, int n, FILE * onde)
{
    int i, j, k;
    int qa;
    double m1, m2;
    struct ALUNOS *a;

    qa = t[n].qa;

    if (qa <= 0) {
        return (0);
    }

    a = t[n].a;
    if (a == NULL) {
        printf("ERRO alunos nao alocados em turma[%d]\n", i);
        return (0);
    }
    for (i = 0; i < qa; i++) {
        printf("\n# ------- ALUNO [%i] da turma %s\n", i, t[n].nturma);

        /* Vendo se mat ja tem nesta turma */
        do {
            printf("# Qual o numero da matricula do aluno:\n");
            lestring(a[i].mat, STRNUM, onde);
            for (j = 0; j < i; j++) {
                if (comparaSemCase(a[i].mat, a[j].mat) == 0) {
                    printf("ERRO: matricula %s ja esta na turma\n", a[i].mat);
                    /* Veja que colocar 0 no inicio de uma string signfica
                     * zerar a string. Não ter NADA nela. Pois a primeira
                     * posição já é o fim de string! Usei isso para não depender
                     * de um flag do tipo achou. while (achou==0)...
                     * */
                    a[i].mat[0] = 0;    // anula a matricula digitada
                    break;
                }
            }
        } while (!a[i].mat[0]);

        /* Concordo com voce: uma funcao para isso seria melhor ;-) */
        a[i].nome[0] = 0;
        /* Agora vamos procurar esta matricula em outras turmas anteriores */
        for (j = 0; j < n; j++) {
            if (t[j].a == NULL)
                continue;
            if (t[j].qa <= 0)
                continue;
            for (k = 0; k < t[j].qa; k++) {
                if (comparaSemCase(t[j].a[k].mat, a[i].mat)) {
                    continue;
                }
                // ACHOU
                copiaseguro(a[i].nome, STRNOME, t[j].a[k].nome);
                break;
            }
            if (a[i].nome[0])
                break;
        }

        if (a[i].nome[0]) {
            printf("# INFO: encontrado matricula. Nao sera solicitado digitacao do nome\n");
        } else {
            printf("\n# Qual o nome do aluno:\n");
            lestring(a[i].nome, STRNOME, onde);
        }

        printf("\n# Quais as notas G1, G2 e G3 do aluno\n");
        a[i].g1 = a[i].g2 = a[i].g3 = -1;

        a[i].g1 = lenota(onde);
        a[i].g2 = lenota(onde);

        a[i].media = ((a[i].g2 * 2) + a[i].g1) / 3.0;

        a[i].g3 = lenota(onde);

        a[i].mediaFinal = a[i].media;

        if (a[i].g3 > 0) {
            m1 = ((a[i].g2 * 2) + a[i].g3) / 3.0;
            m2 = ((a[i].g3 * 2) + a[i].g1) / 3.0;

            /* Media final deve ter o melhor caso, se g3 entra
             * como g1 ou como g2 */
            if (m1 > m2) {
                a[i].mediaFinal = m1;
            } else {
                a[i].mediaFinal = m2;
            }
        }
        printf("\n# ------ ALUNO [%d] FIM DO CADASTRO\n", i);
    }
}

int tamanho(char *o)
{
    int i;
    for (i = 0; o[i]; i++);
    return (i);
}

int relatorio(struct TURMAS *t, int qt, FILE *out)
{
    int i, j;
    int mtur, mmat, mnome, mprof, mdisc, mqa;
    int temp;

    mtur = mmat = mnome = mprof = mdisc = 5;
    mqa = 10;
    /* catando os maiores nomes */
    for (i = 0; i < qt; i++) {
        temp = tamanho(t[i].nturma);
        mtur = mtur > temp ? mtur : temp;

        temp = tamanho(t[i].disciplina);
        mdisc = mdisc > temp ? mdisc : temp;

        temp = tamanho(t[i].professor);
        mprof = mprof > temp ? mprof : temp;

        for (j = 0; j < t[i].qa; j++) {
            if (t[i].a == NULL) {
                break;
            }
            temp = tamanho(t[i].a[j].mat);
            mmat = mmat > temp ? mmat : temp;

            temp = tamanho(t[i].a[j].nome);
            mnome = mnome > temp ? mnome : temp;
        }
    }
    /* Impressao do relatorio propriamente dito */
    fprintf("# RELATORIO PARA %d turmas\n\n", qt);

    fprintf(out, "%-*s %-*s %-*s %*s\n", mtur, "TURMA", mdisc, "DISCIPLINA", mprof, "PROFESSOR", mqa, "QTDALUNOS");
    for (i = 0; i < qt; i++) {
        fprintf(out,"%*s %-*s %-*s %*d\n", mtur, t[i].nturma, mdisc, t[i].disciplina, mprof, t[i].professor, mqa, t[i].qa);
    }
    fprintf(out,"\n");

    fprintf(out,"# RELATORIO DOS ALUNOS EM CADA TURMA\n");
    for (i = 0; i < qt; i++) {
        fprintf(out,"\nTURMA %s - %s - %d alunos\n", t[i].nturma, t[i].disciplina, t[i].qa);

        if (t[i].qa > 0) {
            fprintf(out,"%5s %-*s %-*s ", " ", mmat, "MAT", mnome, "ALUNO");
            fprintf(out,"%5s %5s %5s %5s  %10s\n", "G1", "G2", "MEDIA", "G3", "MEDIAFINAL");
        }

        for (j = 0; j < t[i].qa; j++) {
            if (t[i].a == NULL)
                break;
            fprintf(out,"%5s %-*s %-*s ", " ", mmat, t[i].a[j].mat, mnome, t[i].a[j].nome);
            fprintf(out,"%5.1lf %5.1lf %5.1lf %5.1lf %5.1lf", t[i].a[j].g1, t[i].a[j].g2, t[i].a[j].media, t[i].a[j].g3, t[i].a[j].mediaFinal);
            if ((t[i].a[j].mediaFinal + 0.05) >= 6.0) {
                fprintf(out,"%10s\n", "APROVADO");
            } else {
                fprintf(out,"%10s\n", "REPROVADO");
            }
        }
    }
}

double lenota(FILE * onde)
{
    double nota = -1;

    while (nota < 0) {
        //printf("%s\n", msg);
        if (fscanf(onde, "%lf", &nota) < 1) {
            while (fgetc(onde) != '\n');
            printf("ERRO entrada invalida\n");
            continue;
        }
        if (nota < 0) {
            printf("# ERRO: Nota deve ser maior ou igual a zero\n");
            continue;
        }
        if (nota > 10) {
            nota = -1;
            printf("# ERRO: Nota deve ser menor ou igual a 10\n");
            continue;
        }
    }
    return (nota);
}

int comparaSemCase(char *s1, char *s2)
{
    char l1, l2;

    while (*s1) {
        l1 = *s1;
        l2 = *s2;
        if ((l1 >= 'a') && (l1 <= 'z')) {
            l1 = l1 - 32;
        }
        if ((l2 >= 'a') && (l2 <= 'z')) {
            l2 = l2 - 32;
        }
        if (l1 != l2) {
            return (l1 - l2);
        }
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

int copiaseguro(char *d, int max, char *o)
{
    max--;
    while ((max > 0) && (*o)) {
        *d++ = *o++;
        max--;
        *d = 0;
    }
    return (max);
}

/* Funcao lestring alterada para ler de arquivos */
int lestring(char s[], int max, FILE * onde)
{
    int i = 0;
    char letra;

    if (onde == NULL) {
        fprintf(stderr, "# ERRO lestring. Recebi arquivo não aberto\n");
        return (0);
    }
    for (i = 0; i < (max - 1); i++) {
        letra = fgetc(onde);
        if (feof(onde)) {
            s[i] = 0;
            return (i);
        }


        if (letra == 13) {
            i--;
            continue;
        }
        if ((letra == 10) && (i == 0)) {
            i = i - 1;
            continue;
        }

        if (letra == 10) {
            break;
        }
        s[i] = letra;
    }
    s[i] = 0;
    return (i);
}
