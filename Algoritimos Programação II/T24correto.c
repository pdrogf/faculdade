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

	//variaveis etapa A
    int sala[MFILAS][MCADEIRAS];
    int filas=0;
    int cadeiras=0;
    int maiorFila=0;
    char filaLetras[MCADEIRAS];
    int quantCadeira=0;
    int i,j;
    
    //variaveis etapa B
    int idClient=0;
	int cadeirasReserva=0;

	//input numero filas
    printf("Digite a quantidade de filas da sala, maximo de 26: ");
    scanf("%i", &filas);
    while(filas>26){
        printf("\nVoce ultrapassou a quantidade de filas, digite novamente: ");
        scanf("%i", &filas);
    }
	//input tamanho maior fila
    printf("\nDigite o tamanho da maior fila, maximo de 100: ");
    scanf("%i", &maiorFila);
    while(maiorFila>100){
        printf("\nVoce ultrapassou o tamanho maximo para a fila, digite novamente: ");
        scanf("%i", &maiorFila);
    }
	//inicializando matriz
	//input numero cadeiras fila
    for(i=0;i<filas;i++){
        filaLetras[i]= 65+i;
        printf("\nDigite a quantidade de cadeiras da fila %c: (maximo de %i) ", filaLetras[i], maiorFila);
        scanf("%i", &quantCadeira);
        while(quantCadeira>maiorFila){
            printf("\nVoce ultrapassou o limite de cadeiras para a fila, digite novamente: ");
            scanf("%i", &quantCadeira);
        }//fecha while
        //inicializa cadeiras validas com 0
        for(j=0;j<quantCadeira;j++){
        	sala[i][j]=0;
		}
		//inicializa cadeiras nao validas com -1
		for(j=quantCadeira;j<MCADEIRAS;j++){
			sala[i][j]=-1;
		}
	}//fecha for
	
//fim da etepa A

/*
 Depois de inicializada a sala, assentos dispon�veis tem 0. Permita ao usu�rio
que fa�a reservas de salas. Cada "cliente" ter� um n�mero, come�ando 
em 1. A reserva de salas do cinema dever� ser nesta ordem:
  - Sistema pergunta quantos assentos ele quer (0 ou negativo ENCERRA 
    ESTA PARTE).
  - Se o cliente disser que quer 5 acentos, o sistema dever� procurar
    cinco cadeiras em sequencia para ele e colocar nestes assentos o
    o seu ID (os assentos devem devem estar em ZERO)
    
  - Se o sistema n�o encontrar a quantidade de assentos em sequencia
    que o cliente solicitou, deve pegar o m�ximo possivel e tentar os
    demais na fila de cima ou de baixo. 
    Exemplo: cliente 23 pediu cinco lugares, mas n�o tem nenhuma fila 
    com cinco lugares em sequencia. Mas o sistema encontrou na fila 
    F tres lugares nas cadeiras 3,4,5 e na fileira G, acima, as 
    cadeiras 3,4. Reserva estes.
    
  - Se o pedido do cliente n�o for poss�vel de atender em sequencia
    e nem pr�ximos, ent�o ser� com cadeiras, lugares, bem dispersos.
    
  - Por fim, se realmente n�o tiver tantos lugares dispon�veis, o sistema
    deve informar ao cliente que a sala est� lotada e dizer quantos
    lugares ainda est�o dispon�veis em toda a sala.

- Feita a reserva para o cliente, o sistema dever� informar quais cadeiras
o cliente 'comprou' e pedir para que o pr�ximo cliente fa�a a sua compra.

Lembrando: o primeiro cliente tem seu n�mero sendo 1, depois 2, 3, e assim
por diante. Ao solicitar quantidade de salas, se for digitado 0 ou negativo
o sistema de reservas ENCERRA.

======= FIM DA RESERVA DE SALAS. FINALIZA QUANDO CLIENTE INFORMAR 0 OU
======= NEGATIVO PARA QUANTIDADE DE LUGARES
*/	
	//input quantidade de cadeiras a reservar
	printf("\nInforme a quantidade de cadeiras a reservar: ");
	scanf("%i", &cadeirasReserva);
	if(cadeirasReserva<1){
		printf("\nvalor invalido, encerrando programa");
	}else{
		for(i=0;i)
	}
	
		
}//main



