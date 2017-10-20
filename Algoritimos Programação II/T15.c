#include <stdio.h>
#include <string.h>

#define N1 2
#define N2 3
#define TAM 30

funcmaior(int x, int y){
    int maior=0;

    if(x>y){
        maior=x;
    }else{
        maior=y;
    }
    return(maior);
}

funcmenor(int x, int y){
    int menor=0;
    if(x<y){
        menor=x;
    }else{
        menor=y;
    }
    return(menor);
}

funcparimpar(menor){
    if((menor%2)==0){
        printf("Numero par\n");
    }else{
        printf("Numero impar\n");
    }
}

//fazeer letra E
funcprimo(int k){
    if(k=0){
        return("O numero que foi passado e um numero Primo");
    }else{
        return("O numero que foi passado nao e PRIMO e o valor retornado do proximo primo depois dele");
    }
}

main(){

    int a=N1, b=N2;
    int v1, v2;
    int vet[TAM];
    int i, diferenca;
    int p;

    printf("Digite um valor: ");
    scanf("%d", &v1);
    printf("Digite um valor: ");
    scanf("%d", &v2);
    funcmaior(v1, v2);
    funcmenor(v1, v2);
    printf("%d", funcparimpar());
    printf("digite um numero inteiro: ");
    scanf("%i", &p);
    funcprimo(p);

    if(a > b){
        diferenca = a - b;
    } else {
        diferenca = b - a;
    }
    vet[0] = 0;
    for (i = 1; i < TAM; i++) {
        vet[i] = vet[i - 1] + diferenca;
        if (vet[i] > 1000) {
            vet[i] = i;
        }
        if (vet[i] < -1000) {
            vet[i] = i;
        }
    }

    for(i=0;i<30;i++){
        funcparimpar(vet[i]);
    }


}
