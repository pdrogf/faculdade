#include <iostream>

#define STR 20

using namespace std;
métodos: 
- Para definir a marca e o valor inicial a 
partir de dois valores passados por parâmetros 
(tipos char e float);

- Para definir o número de portas a 
partir de um valor passado por parâmetro (tipo int) – 
considere apenas 2 ou 4 portas; 

- Para definir a cor a 
partir de um valor passado por parâmetro (tipo int) – as 
cores devem ser escolhidas pelo usuário através de um código 
numérico (em torno de 5 cores); 

class Carro{

private:
	char cor[STR];
	char marca[STR];
	int nportas;
	float preco;

public:
	int marcaValor(char marca, float preco){
		strcpy(marca, " ");
		
	}

}