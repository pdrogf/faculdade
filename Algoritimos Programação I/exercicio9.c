#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>


/*
9. Um posto est� vendendo combust�veis com a seguinte tabela de descontos:
o  �lcool : 
At� 20 litros, desconto de 3% por litro.
Acima de 20 litros, desconto de 5% por litro.


o  Gasolina:
At� 15 litros, desconto de 3,5 % por litro.
Acima de 15 litros, desconto de 6% por litro. 
o  Diesel:
At� 30 litros, desconto de 4% por litro.
Acima de 30 litros, desconto de 7% por litro. 
Escreva um programa em C que l� o n�mero de litros vendidos, o tipo de combust�vel
 (codificado da seguinte forma: 1 para �lcool, 2 para gasolina e 3 para diesel), 
 calcula e escreve na tela o valor a ser pago pelo cliente, considerando os descontos 
 mencionados e que o pre�o do litro da gasolina neste posto � R$ 2,749, do �lcool � R$ 2,099 
 e do diesel R$ 1,589. Use switch e fa�a consist�ncia dos dados de   entrada (exiba mensagens de 
 erro quando dados incorretos forem digitados e s� fa�a os c�lculos quando todos os dados digitados forem v�lidos).


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
