#include <stdio.h>
#include <string.h>

#define N1 10
#define N2 5
#define STR 100

//constante para array letra C
#define K 53

main(){


	//variaveis letra a
	int a=N1, b=N2, c;
	char st1[STR], st2[STR], st3[STR];

	//variaveis letra b
	int maior, menor;

    //variaveis letra c
	int v[K], diferenca, j;

	//variaveis letra d
	int i, h, cont, aprimo;

	//variaveis letra e
	int t;

/*
a) Defina duas constantes N1 e N2 com valores inteiros quaisquer.
Defina três variáveis inteiras. Duas delas deverão receber as
duas constantes. A terceira variável deverá receber o maior número
armazenado nas outras duas variáveis (que vieram das constantes)
(compile várias vezes com valores diferentes para N1 e N2, incluindo
ambas serem iguais, negativos, etc).
Peça que o usuário digite seu nome completo, sem acentos, bem como
o nome de seu pai e de sua mãe. Todos os nomes devem caber em 100 posições
(crie variáveis strings para receber estes nomes).
*/

	printf("Digite seu nome completo, sem acentos \n");
	fgets(st1, STR, stdin);

	printf("Digite o nome o seu pai completo, sem acentos \n");
	fgets(st2, STR, stdin);

	printf("Digite o nome da sua mae completo, sem acentos \n");
	fgets(st3, STR, stdin);



//fim da letra a

/*
 Imprima mensagens completas para estes números, dizendo qual o
valor de N1, qual o valor de N2, qual é o menor e qual é o maior entre
eles. Se forem iguais, imprima que são iguais. Diga se o menor entre
eles é PAR ou IMPAR (ou para ambas, se forem iguais).
*/

	printf("Valor de N1 eh %i \n", a);
	printf("Valor de N2 eh %i \n", b);

	if(a>b){
		printf("N1 eh o maior %i \n", a);
		printf("N2 eh o menor %i \n", b);
		if(b%2==0){
			printf("N2 eh par\n");
		}else{
			printf("N2 eh impar\n");
		}
	}else if(a==b){
		printf("Sao iguais %i, %i \n", a,b);
		if(b%2==0){
			printf("Os dois sao par\n");
		}else{
			printf("Os dois sao impar\n");
		}
	}else{
		printf("N2 eh o menor %i \n", b);
		printf("N1 eh o menor %i \n", a);
		if(a%2==0){
			printf("N1 eh par\n");
		}else{
			printf("N1 eh impar\n");
		}
	}

	//fim da letra b
/*
c) Defina um vetor com 53 números inteiros. Peça que o usuário digite
os três primeiros elementos (vet[0], vet[1] e vet[2]) e não permita
que ele digite números negativos e nem duas entradas iguais.
Se ele digitar isso, peça que digite novamente e leia novamente.
Pegue a diferença entre o maior e o menor valor digitado para vet[0] e
vet[1] e use este valor para alimentar as demais posições
(vet[3] em diante).
Cada posição seguinte (a partir do vet[3]) será a soma do anterior com
esta diferença.

Exemplo: digamos que o usuário digite 33 para vet[0], 19 para vet[1] e
5 para vet[2] (que serão aceitos, pois não são negativos e nem iguais).
A diferença entre eles é 14 (33 - 19, maior - menor).

Os vetores ficarão assim:
vet[0] = 33 (o que o usuário digitou)
vet[1] = 19 (o que o usuário digitou)
vet[2] = 5  (o que o usuário digitou)
vet[3] = 19 (vet[2] + 14, ou seja, 5+14= 19)
vet[4] = 33 (vet[3] + 14, ou seja, 19+14= 33)

E assim por diante até o vet[52]. vet[4] ter dado igual ao que o usuário
digitou para vet[0] foi apenas uma coincidência aqui.
*/
	printf("\nDigite o primeiro valor, positivo: ");
	scanf("%i", &v[0]);
	while(v[0]<0){
        printf("\nVoce digitou valor negativo, digite novamente: ");
        scanf("%i", &v[0]);
	}

	printf("\nDigite o segundo valor, sem repetir e positivo: ");
	scanf("%i", &v[1]);
	while((v[1]<0) || (v[1]==v[0])){
        printf("\nVoce digitou valor invalido, digite novamente: ");
        scanf("%i", &v[1]);
	}

	printf("\nDigite o terceiro valor, diferente dos outros e positivo: ");
    scanf("%i", &v[2]);
    while((v[2]<0) || (v[2]==v[1]) || (v[2]==v[0])){
        printf("\nVoce digitou valor invalido, digite novamente: ");
        scanf("%i", &v[2]);
    }


    if(v[0]>v[1]){
        diferenca = v[0]-v[1];
    }else{
        diferenca = v[1]-v[0];
    }
    for(j=3;j<K;j++){
        v[j]=v[j-1]+diferenca;
    }
//fim da letra c

/*
d) Após a geração do vetor, e somente após, percorra o vetor e, para
cada elemento, verifique se o número é PAR ou IMPAR.
Imprima a palavra PAR ou IMPAR para cada número do elemento.
Informe também se aquele número é um número PRIMO (se não for PRIMO,
imprima o próximo PRIMO depois dele.

Exemplo: se o elemento for 8, oito não é primo. Então deve imprimir
a mensagem

"8 não é primo. O próximo primo depois do 8 é o 11",

porque 11 realmente é o próximo primo depois do 8.

(O ITEM D ACIMA NÃO SOFREU NENHUMA ALTERAÇÃO, EXCETO QUE O TAMANHO
DO VETOR É 53 agora)

*/

    for(j=0;j<K;j++){
        if(v[j]%2==0){
            printf("\n valor: %i numero PAR", v[j]);
        }else{
            printf("\n valor: %i numero IMPAR", v[j]);
        }

        for(i=1;i<=v[j];i++){
            if(v[j]%i==0){
                cont++;
            }
        }
        if(cont==2){
            printf("\n %i e primo", v[j]);
        }else{

            aprimo=v[j];
            while(cont!=2){
                cont=0;
                aprimo++;
                for(h=1;h<=aprimo;h++){
                    if(aprimo%h==0){
                        cont++;
                    }
                }//for
            }//while
            printf(". o proximo primo e: %i ", aprimo);
        }
    }

//fim da letra d

/*
E) Imprima na tela o nome digitado (no item A), junto com a
quantidade de letras que ele possui. Idem para o nome do pai e da mãe.
*/

    printf("\nSeu nome: %s ", st1);
    t = strlen(strtok(st1,"\n"));
    printf("\nQuantidade de caracters: %d", t);


    printf("\nNome do seu pai: %s ", st2);
    t = strlen(strtok(st2,"\n"));
    printf("\nQuantidade de caracters: %d", t);

    printf("\nNome da sua mae:: %s ", st3);
    t = strlen(strtok(st3,"\n"));
    printf("\nQuantidade de caracters: %d", t);


}
