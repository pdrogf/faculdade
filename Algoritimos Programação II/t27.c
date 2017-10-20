#include <stdio.h>
#include <string.h>

#define MAX 100

main(){

char nome[MAX];
char *p;
char a;
int i;

strncpy(nome, "ABCDEFGHIJKLM", MAX);

p = nome;
printf("%p\n", p);

// o que imprimi?
// imprime 0028FEA8

for (i=0;i<MAX;i++){
    a=*p;
    //o que imprime
    //imprime o texto passado a variavel nome "ABCDEFGHIJKLM"
    printf("%c\n", a);
    p=p+1;
    //p=p+1 esta adicionando +1 no endereco da variavel p
}

}
