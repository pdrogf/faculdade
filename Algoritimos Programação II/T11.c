#include <stdio.h>
#include <conio.h>
#include <stlib.h>
#define N1 5
#define N2 4

main(){
       
       int a=N1, b=N2, c=0, i, k,j, dif, cont, prox;
       int v[30];
       
       
       
       if(N1>c){
                c=N1;
       }else{
                c=N2;
       }
       
       if(a<b && a%2==0){
                printf("Par");         
       }
       if(a<b && a%2!=0){
                printf("Impar");         
       }
       if(b<a && b%2==0){
                printf("Par");         
       }
       if(b<a && b%2!=0){
                printf("Impar");         
       }
       
       if(a>b){
               dif=a-b;
       }else{
             dif=b-a;
       }
       
       v[0]=0;
       
       for(i=1;i<30;i++){
                 if(v[i]=v[i-1]+dif>1000 || v[i]=v[i-1]+dif<-1000){
                 v[i]=i;
                 }else{
                       v[i]=v[i-1]+dif;                 
                 }                                  
       }
       
       for(i=0;i<30;i++){
                 if(v[i]%2==0){
                 printf("%i par\n", v[i]);
                 }else{
                 printf("%i impar\n", v[i]);      
                 }
                 
                 for(k=1;k<i;k++){
                      if(v[i]/k==0){
                           cont++; 
                           }
                 }
                 
                 if(cont==2){
                    printf("Numero primo, %i\n", v[i]);
                 }else{
                    for(j=v[i+1];j>0;j--){
                      printf("%i Numero nao e primo. Proximo Primo depois do %i eh o %i\n", vet[i],vet[i],prox);     
                    }
                 }
                 
                                   
       }
       

       system("pause");       
}
