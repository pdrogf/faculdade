#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>


/*
9. Um posto está vendendo combustíveis com a seguinte tabela de descontos:
o  Álcool : 
Até 20 litros, desconto de 3% por litro.
Acima de 20 litros, desconto de 5% por litro.


o  Gasolina:
Até 15 litros, desconto de 3,5 % por litro.
Acima de 15 litros, desconto de 6% por litro. 
o  Diesel:
Até 30 litros, desconto de 4% por litro.
Acima de 30 litros, desconto de 7% por litro. 
Escreva um programa em C que lê o número de litros vendidos, o tipo de combustível
 (codificado da seguinte forma: 1 para álcool, 2 para gasolina e 3 para diesel), 
 calcula e escreve na tela o valor a ser pago pelo cliente, considerando os descontos 
 mencionados e que o preço do litro da gasolina neste posto é R$ 2,749, do álcool é R$ 2,099 
 e do diesel R$ 1,589. Use switch e faça consistência dos dados de   entrada (exiba mensagens de 
 erro quando dados incorretos forem digitados e só faça os cálculos quando todos os dados digitados forem válidos).


*/

main(){
    
    float litros, calculo, total;
    int combustivel;
    
    printf("Digite o combustivel:"
            "\n1- Etanol"
            "\n2- Gasolina"
            "\n3- Disel\n");
    scanf("%i", &combustivel);
    
    printf("Digite quantos litros:");
    scanf("%f", &litros);

    
    
        if(litros >0 && combustivel==1 || combustivel==2 || combustivel==3){
            switch(combustivel){
                
                case 1:
                    if(litros >=20){
                        calculo = (litros*2.099)*0.03;
                        total = (litros*2.099)-calculo;
                    }
                    else{
                        calculo = (litros*2.099)*0.05;
                        total = (litros*2.099)-calculo;
                    }
                break;
                
                case 2:
                    if(litros >=15){
                        calculo = (litros*2.749)*0.3,5;
                        total = (litros*2.749)-calculo;
                    }
                    else{
                        calculo = (litros*2.749)*0.06;
                        total = (litros*2.749)-calculo;
                    }
                break;
                
                case 3:
                    if(litros >=30){
                        calculo = (litros*1.589)*0.04;
                        total = (litros*1.589)-calculo;
                    }
                    else{
                        calculo = (litros*1.589)*0.07;
                        total = (litros*1.589)-calculo;
                    }
                break;
                                
                }//fecha switch
        }//fecha if
        else {
        printf("Dados incorretos\n");
        }
        
        printf("Total a ser pago: %f\n", total);
    
    system("pause");
    
}
