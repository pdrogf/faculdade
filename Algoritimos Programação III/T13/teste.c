#include <stdio.h>

#define MAXELEMS 60000
#define MAXNUM 500000

// Limpa o buffer sempre que necess�rio.
cleanBuff() {
	while(fgetc(stdin) != '\n');
}
// Checa se o elemento j� foi digitado nas regras.
int checkInputRepeated(double input, double vec[MAXELEMS], int elems) {
	int i;

	for (i = 0; i < elems; i++) {
		if ((int)(input * 10000) == (int)(vec[i] * 10000)) {
			return 1;
		}
	}

	return 0;
}
// L� os n�meros e faz as checagens necess�rias.
pushElems(double vec[MAXELEMS], int elems) {
	int count = 0; // Contador para saber quantos foram.
	double elem; // O elemento que foi lido do usu�rio.

	printf("\n# Digite %d numeros positivos que serao colocados no vetor:\n", elems);
	do {
		printf("# Digite vet[%d]\n", count);
		scanf("%lf", &elem);

		if (0) {
			printf("# Voc� digitou LIXO\n\n");
		} else if (elem < 1 || elem > MAXNUM) {
			printf("# ERRO: %.6lf fora da faixa (1.000000 a 500000.000000)\n\n", elem);
		} else if (checkInputRepeated(elem, vec, count)) {
			printf("# ERRO: %.4lf j� foi digitado\n\n", elem);
		} else {
			vec[count] = elem;
			count++;
		}

		cleanBuff();
		printf("\n");
	} while(count < elems);
}
// Ordena um vetor de doubles em ordem crescente.
orderVector(double vec[MAXELEMS], int elems) {
	int i, j;
	double temp;

	for(i = 0; i < elems; i++) {
		for(j = 0; j < elems - 1; j++) {
			if(vec[j] > vec[j + 1]) {
				temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}
	}
}
// Recebe um array de double, um de int e vai calculando index por index o fatorial.
pushFactorial(double vecDouble[MAXELEMS], unsigned long vecLong[MAXELEMS], int elems) {
	int i, j;

	for (i = 0; i < elems; i++) {
		vecLong[i] = vecDouble[i] + 0.5;
		for (j = 1; j < (int)(vecDouble[i] + 0.5); j++) {
			vecLong[i] *= j;
		}
	}
}

main () {
	int i,
		elems = 0; // Quantidade de elementos que ele tem que digitar/percorrer.
	unsigned long vecLong[MAXELEMS]; // Vetor com o fatorial da parte inteira de cada elemento do vetor de double.
	double vecDouble[MAXELEMS]; // Vetor com os elementos digitados pelo usu�rio.

	do {
		printf("# Quantos n�meros quer digitar? (1 a 60000)\n");
		if (!scanf("%d", &elems)) {
			printf("# Voc� digitou LIXO\n\n");
		} else if (elems < 1 || elems > MAXELEMS) {
			printf("# ERRO: %d � um valor inv�lido\n\n", elems);
		}
		cleanBuff();
	} while(elems < 1 || elems > MAXELEMS);

	pushElems(vecDouble, elems);
	orderVector(vecDouble, elems);
	pushFactorial(vecDouble, vecLong, elems);

	printf("# Voce digitou os seguintes elementos:\n");
	for (i = 0; i < elems; i ++) {
		printf("%.3lf\n", vecDouble[i]);
	}

	printf("\n\n");

	for (i = 0; i < elems; i ++) {
		printf("Fatorial de %-2d = ", (int)(vecDouble[i] + 0.5));
		if (vecLong[i] <= 0 || (int)(vecDouble[i] + 0.5) > 20) {
			printf("ERRO\n");
		} else {
			printf("%lu\n", vecLong[i]);
		}
	}

	printf("\n# FIM\n");
}
