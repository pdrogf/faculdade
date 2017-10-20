/*
Considere uma sala de cinema com cadeiras numeradas. Cada FILA tem uma
letra do alfabeto e em cada fila tem cadeiras de numeros 1 at� N.
Considera-se que qualquer sala, por maior que seja, nunca ter� mais
do que 26 filas (A a Z) e 100 cadeiras em cada fila. Por�m uma sala pode
ter menos filas e em cada fila podem ter menos cadeiras.

Fa�a um programa que gerencie esta sala atrav�s de uma matriz FILAxCADEIRAS.

As filas na matriz ser�o numeradas de 0 a 25, como s�o os �ndices de
uma matriz, mas voc� jamais dever� informar ao usu�rio FILA 0, mas sim
FILA A (A=0, B=1, ... Z=25). Tamb�m n�o diga A0, cadeira 0 da fila A,
mas sim A1, cadeira n�mero 1 da fila A (internamente, na sua matriz,
este assento estar� na matriz [0][0]).

Ao iniciar o sistema pergunte ao usu�rio quantas filas a sala tem,
n�o permitindo ser maior do que o m�ximo (26). Depois pergunte quantos
assentos tem a maior fila (tamMaiorFila), n�o podendo ser maior que 100.

Inicialize a matriz da seguinte forma:

- para cada fila, pergunte quantos assentos tem aquela fila em espec�fico,
n�o ultrapassando o tamMaiorFila. Coloque 0 em todos os assentos
daquela fila e -1 nos assentos que n�o fazem parte.

Exemplo: se a fila A tem 20 assentos, as colunas [0] a [19] desta fila
recebem 0 e as colunas de [20] at� [tamMaiorFila-1] recebem -1.
-1 indica cadeira inixistente.

O sistema dever� automaticamente ignorar os assentos de [tamMaiorFila] at�
[99] porque j� foi dito no in�cio que a maior fila tem tamMaiorFila assentos.

================== FIM DA ETAPA A ================
*/

#include <stdio.h>
#define MFILAS 26
#define MCADEIRAS 100

main(){

    int sala[MFILAS][MCADEIRAS];
    int filas=0;
    int cadeiras=0;
    int maiorFila=0;
    char filaLetras[MCADEIRAS];
    int quantCadeira=0;
    int i=0;



    printf("Digite a quantidade de filas da sala, maximo de 26: ");
    scanf("%i", &filas);
    while(filas>26){
        printf("\nVoce ultrapassou a quantidade de filas, digite novamente: ");
        scanf("%i", &filas);
    }

    printf("\nDigite o tamanho da maior fila, maximo de 100: ");
    scanf("%i", &maiorFila);
    while(maiorFila>100){
        printf("\nVoce ultrapassou o tamanho maximo para a fila, digite novamente: ");
        scanf("%i", &maiorFila);
    }

    for(i=0;i<filas;i++){
        filaLetras[i]= 65+i;
        printf("\nDigite a quantidade de cadeiras da fila %c: (maximo de %i) ", filaLetras[i], maiorFila);
        scanf("%i", &quantCadeira);
        while(quantCadeira>maiorFila){
            printf("\nVoce ultrapassou o limite de cadeiras para a fila, digite novamente: ");
            scanf("%i", &quantCadeira);
        }
        for(i=0;i<)
    }


}


