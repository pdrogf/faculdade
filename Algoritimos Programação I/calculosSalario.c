#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


main(){
	
	float salario, tempoTrab, abono, salarioTotal;
	int cargo;
	
	printf("Digite o codigo referente ao cargo: \n" 
	"1001 - Gerente\n" 
	"1002 - Engenheiro\n"	
	"1003 - Tecnico\n"
	"1004 - Programador\n"	
	"1005 - Desenvolvedor\n"
	"1006 - Analista\n");
	scanf("%i", &cargo);
	
	printf("Digite o salario: ");
	scanf("%f", &salario);
	
	printf("Digite o tempo de trabalho em anos: ");
	scanf("%f", &tempoTrab);

	
	
			
			switch(cargo){
				case 1001:
					if(tempoTrab>=4){
						abono = salario * 0.12;
						salarioTotal = abono + salario;
												
					}
					else{
						abono = salario * 0.085;
						salarioTotal = abono + salario;	
					}
				break;
				
				case 1002:
						abono = salario * 0.11,2;
						salarioTotal = abono + salario;
				break;
				
				case 1003:
					if(tempoTrab>=6){
						abono = salario * 0.18;
						salarioTotal = abono + salario;
												
					}
					else{
						abono = salario * 0.15;
						salarioTotal = abono + salario;	
					}
				break;
				
				case 1004:
					if(tempoTrab>=3){
						abono = salario * 0.18,1;
						salarioTotal = abono + salario;
												
					}
					else{
						abono = salario * 0.16,4;
						salarioTotal = abono + salario;	
					}
				break;
				
				case 1005:
						abono = salario * 0.17;
						salarioTotal = abono + salario;					
				break;
				
				case 1006:
						abono = salario * 0.21;
						salarioTotal = abono + salario;					
				break;
				
				default:
					abono = salario * 0.03,5;
					salarioTotal = abono + salario;	
				break;
			}//fecha switch	
		
		printf("\n Valor do Salario antigo: %f", salario);
		printf("\n Valor do abono: %f", abono);
		printf("\n Valor do Salario Total: %f", salarioTotal);
			
	system("pause");
		
}
