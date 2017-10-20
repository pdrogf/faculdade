
#include <stdio.h>
#include <stdlib.h>

#define TAM 100

struct ALUNOS {
	char mat[TAM];
	char nome[TAM];
	double g1, g2, g3;
	double media;
	double mediaFinal;
};

struct TURMAS {
	char nturma[TAM];
	char disciplina[TAM];
	char professor[TAM];
	int qa;
	struct ALUNOS *a;
};

int lestring(char[], int, FILE *);
int cadastraturma(struct TURMAS *, int, FILE *);
int cadastraalunos(struct TURMAS *, int, FILE *);
int lenota(char *);
int comparaNome(struct TURMAS *a, struct TURMAS *b);
int comparaNota(struct ALUNOS *a, struct ALUNOS *b);
int relatorio(struct TURMAS *, int);

int main(int argc, char *argv[])
{
	
	FILE *arq = NULL;
	struct TURMAS *turma = NULL;
	char arquivo[TAM];
	int qt = 0;
	int i;

	if (argc >= 2) {
		if (!(arq = fopen(argv[1], "r"))) {
			printf("\n# ERRO: nao pode abrir %s para leitura\n", argv[1]);
			printf("\nERRO %s\n", argv[1]);
		}
	}
	if (!arq) {
		printf("# Digite arquivo com os dados das turmas:\n");
		lestring(arquivo, TAM, stdin);

		if (!(arq = fopen(arquivo, "r"))) {
			printf("# ERRO: nao pode abrir %s para leitura\n", arquivo);
			printf("ERRO %s\n", arquivo);
			printf("\n# Encerrando: sem arquivo de dados\n");

			return 0;
		}
	}

	while (qt <= 0 || !turma) {
		if (fscanf(arq, "%i", &qt) < 1) {
			while (fgetc(arq) != '\n');
			continue;
		}
		if (qt <= 0) {
			continue;
		}
		turma = (struct TURMAS *) malloc(qt * sizeof(struct TURMAS));
	}

	printf("# Lido com sucesso %i turmas no arquivo %s\n", qt, arquivo);
	printf("%s: %i\n", arquivo, qt);

	qt = cadastraturma(turma, qt, arq);
	qsort(turma, qt, sizeof(struct TURMAS), comparaNome);

	printf("\n# FIM DA ETAPA A que era apenas o cadastro\n");

	relatorio(turma, qt);

	for (i = 0; i < qt; i++) {
		if (turma[i].a) {
			free(turma[i].a);
		}
	}
	free(turma);
}

int cadastraturma(struct TURMAS *tur, int qt, FILE *arq)
{
	int i;
	int tent;

	for (i = 0; i < qt; i++) {
		printf("\n# --- Turma [%d] ---\n", i);

		printf("# Codigo da turma:\n");
		lestring(tur[i].nturma, TAM, arq);

		printf("\n# Nome da disciplina:\n");
		lestring(tur[i].disciplina, TAM, arq);

		printf("\n# Nome do professor:\n");
		lestring(tur[i].professor, TAM, arq);

		tur[i].a = NULL;

		tent = 0;

		while (tur[i].a == NULL) {
			printf("\n# Quantos alunos tem a turma %s?\n", tur[i].nturma);
			if (fscanf(arq, "%i", &tur[i].qa) < 1) {
				tur[i].qa = 0;
				while (fgetc(stdin) != '\n');
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
			cadastraalunos(tur, i, arq);
			qsort(tur[i].a, tur[i].qa, sizeof(struct ALUNOS), comparaNota);
			printf("# --- TURMA [%d] FIM DO CADASTRO\n", i);
		}
	}
	return (i);
}

int cadastraalunos(struct TURMAS *t, int n, FILE *arq)
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

		do {
			printf("# Qual o numero da matricula do aluno:\n");
			lestring(a[i].mat, TAM, arq);
			for (j = 0; j < i; j++) {
				if (comparaSemCase(a[i].mat, a[j].mat) == 0) {
					printf("ERRO: matricula %s ja esta na turma\n", a[i].mat);
					a[i].mat[0] = 0;
					break;
				}
			}
		} while (!a[i].mat[0]);

		a[i].nome[0] = 0;

		for (j = 0; j < n; j++) {
			if (t[j].a == NULL)
				continue;
			if (t[j].qa <= 0)
				continue;
			for (k = 0; k < t[j].qa; k++) {
				if (comparaSemCase(t[j].a[k].mat, a[i].mat)) {
					continue;
				}
				copiaseguro(a[i].nome, TAM, t[j].a[k].nome);
				break;
			}
			if (a[i].nome[0])
				break;
		}

		if (a[i].nome[0]) {
			printf("# INFO: encontrado matricula. Nao sera solicitado digitacao do nome\n");
		} else {
			printf("\n# Qual o nome do aluno:\n");
			lestring(a[i].nome, TAM, arq);
		}

		printf("\n# Quais as notas G1, G2 e G3 do aluno\n");
		a[i].g1 = a[i].g2 = a[i].g3 = -1;

		while (a[i].g1 < 0) {
			printf("# Nota G1:");
			if (fscanf(arq, "%lf", &a[i].g1) < 1) {
				while (fgetc(arq) != '\n');
				printf("ERRO entrada invalida\n");
				continue;
			}
			if (a[i].g1 < 0) {
				printf("# ERRO: Nota deve ser maior ou igual a zero\n");
				continue;
			}
			if (a[i].g1 > 10) {
				a[i].g1 = -1;
				printf("# ERRO: Nota deve ser menor ou igual a 10\n");
				continue;
			}
		}
		while (a[i].g2 < 0) {
			printf("# Nota G2:");
			if (fscanf(arq, "%lf", &a[i].g2) < 1) {
				while (fgetc(arq) != '\n');
				printf("ERRO entrada invalida\n");
				continue;
			}
			if (a[i].g2 < 0) {
				printf("# ERRO: Nota deve ser maior ou igual a zero\n");
				continue;
			}
			if (a[i].g2 > 10) {
				a[i].g2 = -1;
				printf("# ERRO: Nota deve ser menor ou igual a 10\n");
				continue;
			}
		}

		a[i].media = ((a[i].g2 * 2) + a[i].g1) / 3.0;

		while (a[i].g3 < 0) {
			printf("# Nota G3:");
			if (fscanf(arq, "%lf", &a[i].g3) < 1) {
				while (fgetc(arq) != '\n');
				printf("ERRO entrada invalida\n");
				continue;
			}
			if (a[i].g3 < 0) {
				printf("# ERRO: Nota deve ser maior ou igual a zero\n");
				continue;
			}
			if (a[i].g3 > 10) {
				a[i].g3 = -1;
				printf("# ERRO: Nota deve ser menor ou igual a 10\n");
				continue;
			}
		}

		a[i].mediaFinal = a[i].media;

		if (a[i].g3 > 0) {
			m1 = ((a[i].g2 * 2) + a[i].g3) / 3.0;
			m2 = ((a[i].g3 * 2) + a[i].g1) / 3.0;

			if (m1 > m2) {
				a[i].mediaFinal = m1;
			} else {
				a[i].mediaFinal = m2;
			}
		}
		printf("\n# ------ ALUNO [%d] FIM DO CADASTRO\n", i);
	}
}

int lenota(char *o)
{
	int i;
	for (i = 0; o[i]; i++);
	return (i);
}

int relatorio(struct TURMAS *t, int qt)
{
	int i, j;
	int mtur, mmat, mnome, mprof, mdisc, mqa;
	int temp;

	mtur = mmat = mnome = mprof = mdisc = 5;
	mqa = 10;

	for (i = 0; i < qt; i++) {
		temp = lenota(t[i].nturma);
		mtur = mtur > temp ? mtur : temp;

		temp = lenota(t[i].disciplina);
		mdisc = mdisc > temp ? mdisc : temp;

		temp = lenota(t[i].professor);
		mprof = mprof > temp ? mprof : temp;

		for (j = 0; j < t[i].qa; j++) {
			if (t[i].a == NULL) {
				break;
			}
			temp = lenota(t[i].a[j].mat);
			mmat = mmat > temp ? mmat : temp;

			temp = lenota(t[i].a[j].nome);
			mnome = mnome > temp ? mnome : temp;
		}
	}
	printf("# RELATORIO PARA %d turmas\n\n", qt);

	printf("%-*s %-*s %-*s %*s\n", mtur, "TURMA", mdisc, "DISCIPLINA", mprof, "PROFESSOR", mqa, "QTDALUNOS");
	for (i = 0; i < qt; i++) {
		printf("%*s %-*s %-*s %*d\n", mtur, t[i].nturma, mdisc, t[i].disciplina, mprof, t[i].professor, mqa, t[i].qa);
	}
	printf("\n");

	printf("# RELATORIO DOS ALUNOS EM CADA TURMA\n");
	for (i = 0; i < qt; i++) {
		printf("\nTURMA %s - %s - %d alunos\n", t[i].nturma, t[i].disciplina, t[i].qa);

		if (t[i].qa > 0) {
			printf("%5s %-*s %-*s ", " ", mmat, "MAT", mnome, "ALUNO");
			printf("%5s %5s %5s %5s  %10s\n", "G1", "G2", "MEDIA", "G3", "MEDIAFINAL");
		}

		for (j = 0; j < t[i].qa; j++) {
			if (t[i].a == NULL)
				break;
			printf("%5s %-*s %-*s ", " ", mmat, t[i].a[j].mat, mnome, t[i].a[j].nome);
			printf("%5.1lf %5.1lf %5.1lf %5.1lf %5.1lf", t[i].a[j].g1, t[i].a[j].g2, t[i].a[j].media, t[i].a[j].g3, t[i].a[j].mediaFinal);
			if ((t[i].a[j].mediaFinal + 0.05) >= 6.0) {
				printf("%10s\n", "APROVADO");
			} else {
				printf("%10s\n", "REPROVADO");
			}
		}
	}
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

int lestring(char s[], int max, FILE *arq)
{
	int i = 0;
	char letra;

	for (i = 0; i < (max - 1); i++) {
		letra = fgetc(arq);


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
int comparaNome(struct TURMAS *a, struct TURMAS *b) {
	return comparaSemCase(a->disciplina, b->disciplina);
}
int comparaNota(struct ALUNOS *a, struct ALUNOS *b) {
	if (((a->g1 + a->g2 * 2) / 3) > ((b->g1 + b->g2 * 2) / 3)) {
		return 1;
	} else {
		return -1;
	}
	return 0;
}