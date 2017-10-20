#include<iostream>

#include<stdio.h>


using namespace std;

class Circulo{
	private:
		float AreaCirculo(float r);
		float Perimetro(float r);
		int MostrarAreaCirculo();
		int MostrarPerimetro();

		float calcularAreaCirculo(float r){
			return 3.14*(r*r);
			
		}
		float calcularPerimetroCirculo(float r){
			return 2*3.14*r;
			
		}
		int imprimirAreaCiruclo(){
			cout << "\nArea do Circulo: " << calcularAreaCirculo;
		}
		int imprimirPerimetroCirculo(){
			cout << "Perimetro do Circulo: " << calcularPerimetroCirculo;
		}
};

class Retangulo{
	public:
		float AreaRetangulo(float l1, float l2);
		int MostrarAreaRetangulo();

		float calcularAreaRetangulo(float l1, float l2){
			return l1*l2;
		}
		int imprimirAreaRetangulo(){
			cout << "Area do retangulo: " << calcularAreaRetangulo;
		}
};

class Cilindro: public Circulo, public Retangulo{
	public:
		int AreaCilindro(float raio, float altura);
		int VolumeCilindro(float raio, float altura);
		int MostraAreaCilindro();
		int MostraVolumeCilindro();

		cl.calcular_area_cilindro(b,a);
		cl.calcular_volume_cilindro(b,a);
		cl.mostrar_area_cilindro();
		cl.mostrar_volume_cilindro();

		int calcular_area_cilindro(float calcularAreaCirculo, float calcularAreaRetangulo){
			return (calcularAreaCirculo*2) + calcularAreaRetangulo;
		}
		int calcular_volume_cilindro(float calcularAreaCirculo, float l2){
			return 3.14 * (calcularAreaCirculo*calcularAreaRetangulo) * l2;
		}
		int mostrar_area_cilindro(){
			cout << "\nArea do Cilindro: " << calcular_area_cilindro;
		}
		int mostrar_volume_cilindro(){
			cout << "\nVolume do Cilindro: " << calcular_volume_cilindro;
		}

};
