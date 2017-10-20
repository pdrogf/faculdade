/*
 * TITULO: Resposta do exercicio T14
 * DATA: 09/Setembro/2016
 * 
 * Publicado para PEDRO GRAZZIANI FERNANDES
 *  
*/

#include <stdio.h>
#define TAM 150000

/* Função lestring publicada no artigo do Viva o Linux */
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
    /*
     * LINUX encerra uma linha em texto puro com LF (10)
     * DOS/WINDOWS usa CRLF (13 10), ou seja, DOIS cars. O 13
     *    que é o ENTER e o 10 que é LINE FEED
     * */
}

/* Um strlen local */
int tamanho(char st1[])
{
    int i;
    for (i = 0; st1[i]; i++);
    return (i);
}


/* Retorna quantos cars em st1 estão entre ini e fim
 * Se passar 'A' como ini e 'Z' como fim irá retornar
 * a quantidade de letras maiúsculas. Se passar ini e
 * fim como sendo o mesmo, irá contar apenas aquele
 * caractere (exemplo: ini=' ' e fim=' ' retorna quantos
 * espaços em branco tem em st1.
 * Esta função só permite faixas. Não pode ser usada, por
 * exemplo, para contar vogais AEIOU, pois as vogais não estão
 * em sequencia na tabela ASCII.
 * */
int conta(char st1[], char ini, char fim)
{
    int t, i;
    t = 0;
    for (i = 0; st1[i]; i++) {
        if ((st1[i] >= ini) && (st1[i] <= fim)) {
            t++;
        }
    }
    return (t);
}

/* Função que remove tudo que não é letra de uma string. Deixa ela
 * somente com letras. Se st1 for "Isto , eh 134 um ;..Teste"
 * ao executar a função, st1 será "IstoehumTeste"
 * */
int soletras(char st1[])
{
    int i, j;

    for (i = 0, j = 0; st1[i]; i++) {
        if ((st1[i] >= 'a') && (st1[i] <= 'z')) {
            st1[j] = st1[i];
            j++;
        }
        if ((st1[i] >= 'A') && (st1[i] <= 'Z')) {
            st1[j] = st1[i];
            j++;
        }
    }
    st1[j] = 0;
    return (j);                 // retorna o novo tamanho de str
}

int tudomaiuscula(char st1[])
{
    int i;
    for (i = 0; st1[i]; i++) {
        if ((st1[i] >= 'a') && (st1[i] <= 'z')) {
            st1[i] = st1[i] - 32;
        }
    }
    return (i);
    /* retorna o tamanho de st1. Podia retornar algo mais útil
     * como a quantidade de cars que foram transformados (mas
     * ai teria que colocar um contador dentro do if)
     * */
}

/* Função que verifica que uma string é ou não palindroma
 * ela compara tudo, não apenas letras. Logo se a ideia
 * é comparar apenas letras, necessario passar a string
 * somente com letras, nada mais
 * OVO   => retorna 1 dizendo que é
 * O V O => retorna 1 dizendo que é
 * Ovo   => retorna 0 dizendo que NÃO é (falha no 'o' comparando com o 'O')
 * O VO  => retorna 0 dizendo que NÃO é (falha no 'V' comparando com o ' ')
 * */
int ehpal(char st1[])
{
    int i, f;

    /* obter o tamanho de str.
     * Evitei usar a função tamanho aqui porque é bem simples obter o tamanho
     * e não queria que a função ehpal dependesse da existência de outra
     * função para funcionar. Se pudesse usar a string.h ai sim, por ser uma
     * biblioteca padrão, poderia ter feito f=strlen(st1); */
    for (f = 0; st1[f]; f++);

    /* Minha tecnica foi andar na string do inicio até o fim e do fim
     * até o inicio, comparando o car do início com o car do fim.
     * Evitei realizar cópias desnecessárias ou copiar invertido para
     * depois comparar.
     * 
     * Um grupo apresentou uma solução com estas cópias e a execução
     * para o T1400005.in levou 15 segundos. Ela foi abortada pela
     * ferramenta de teste automático por demorar demais (a ferramenta
     * estava configurada para derrubar o teste após 5 segundos)
     * */


    /* f tem o indice do ultimo car */
    f--;
    i = 0;
    while (i <= f) {
        if (st1[i] != st1[f]) {
            /* Achou dois cars diferentes, já encerra retornando ZERO
             * porque não é palíndromo 
             * */
            return (0);
        }
        i++;
        f--;
    }
    return (1);
}

/* A função copiaN é uma implementação local da strncpy existente 
 * na strings.h
 * */
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

/* Esta função é uma implementação local da função strcasecmp existente
 * na strings.h
 * */
int compcasestr(char st1[], char st2[])
{
    char l1, l2;
    int i;

    for (i = 0; st1[i]; i++) {
        /* Como não quero alterar st1 e nem st2, pego o car atual
         * de cada uma e transformo em maiuscula. Isto evita uma
         * série bem longa de ifs ou ifs cheio de &&
         * */
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
    /* Só chega aqui se chegou ao fim de st1. Se também chegou ao final
     * de st2 a diminuição dos dois ultimos cars resultará em ZERO, indicando
     * que são iguais. Não precisa garantir que st2[i] seja maiuscula, pois:
     * - st1[i] é ZERO certamente (fim da string)
     * - se st2[i] não for zero, então são diferentes independente se este
     * car de st2[i] for letra maiuscula ou minúscula. Não importa o que é,
     * será retornado um número NEGATIVO indicando que st2 é maior */
    return (st1[i] - st2[i]);
}

main()
{
    char texto[TAM], tmai[TAM], tmin[TAM], fim[TAM];
    /* E começa a preocular o tamanho dos vetores. As strings
     * acima consumirão aproximadamente 600KB de memória para
     * a definição original de TAM (150000 cars)
     * Alguns grupos criaram tantas outras... Até buffers dentro das
     * funções o que é muito sensivel (todos que fizeram isto fizeram
     * ERRADO com graves problemas de segurança)
     * */
    int maiorf, menorf, totlmin, totlmai, totlpal, t, qtd;

    do {
        printf("# Qual a frase que você usará para encerrar?\n");
        t = lestring(fim, TAM);
        if (t < 3) {
            printf("# ERRO. a frase de termino precisa ser maior\n");
        }
    } while (t < 3);

    qtd = 0;
    maiorf = totlmin = totlmai = totlpal = 0;
    menorf = 0;
    while (1) {
        printf("\n# [%d] Digite frase de até %d caracteres.\n", qtd + 1, TAM);
        printf("# [%d] Digite \"%s\" para encerrar o programa\n", qtd + 1, fim);
        t = lestring(texto, TAM);
        if (compcasestr(texto, fim) == 0) {
            break;
        }
        /* Totalizando quantidade de frases lidas */
        qtd++;

        /* Atualizando total de letras minusculas e maiúsculas lidas */
        totlmin = totlmin + conta(texto, 'a', 'z');
        totlmai = totlmai + conta(texto, 'A', 'Z');

        /* Vendo se esta é a maior frase em tamanho */
        if (t > maiorf) {
            maiorf = t;
            copiaN(tmai, texto, TAM);
            /* Guarda uma cópia da maior string */
        }

        /* Vendo se esta é a menor frase em tamanho */
        if ((t < menorf) || (menorf == 0)) {
            menorf = t;
            copiaN(tmin, texto, TAM);
            /* Guarda uma cópia da menor string */
        }

        /* Deixando apenas letras na frase e transformando em maiusculas */
        tudomaiuscula(texto);
        t = soletras(texto);
        if (ehpal(texto)) {
            printf("%3d => PALINDROMO\n", qtd);
            if (t > totlpal) {
                totlpal = t;
            }
        } else {
            printf("%3d => NAO EH PALINDROMO\n", qtd);
        }
    }
    printf("\n%d frases digitadas\n", qtd);
    printf("Maior frase = \"%s\"\n", tmai);
    printf("Menor frase = \"%s\"\n", tmin);

    printf("%d letras minusculas\n", totlmin);
    printf("%d letras maiusculas\n", totlmai);
    printf("%d letras o maior palindromo digitado\n", totlpal);
}
