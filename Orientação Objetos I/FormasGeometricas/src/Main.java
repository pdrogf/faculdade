
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author pedro.grazziani
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        FiguraGeometrica[] figuras;
        System.out.print("Digite a quantidade de formas: ");
        int qtdFormas = sc.nextInt();
        figuras = new FiguraGeometrica[qtdFormas];

        for (int i = 0; i < qtdFormas; i++) {
            System.out.println("Selecione qual a fórmula deseja criar: ");
            System.out.println("1- Círculo \n2- Quadrado \n3- Retângulo");
            int tipoForma = sc.nextInt();

            if (tipoForma == 1) {
                System.out.print("Digite o raio do círculo: ");
                figuras[i] = new Circulo(sc.nextDouble());
            } else if (tipoForma == 2) {
                System.out.print("Digite o lado do quadrado: ");
                figuras[i] = new Quadrado(sc.nextDouble());
            } else if (tipoForma == 3) {
                System.out.print("Digite a base e altura: ");
                figuras[i] = new Retangulo(sc.nextDouble(), sc.nextDouble());
            } else {
                System.out.println("Forma inválida!");
            }
        }                
    }
}
