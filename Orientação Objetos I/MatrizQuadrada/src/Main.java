
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
        Scanner teclado = new Scanner(System.in);
        System.out.println("Digite o tamanho da matriz de ordem 2: ");
        MatrizQuadrada qMatriz = new MatrizQuadrada(teclado.nextInt());
        for (int i = 0; i < qMatriz.getMatriz().length; i++) {
            for (int j = 0; j < qMatriz.getMatriz()[i].length; j++) {
                System.out.print("Digite o valor da posição " + (i + 1) + ":" + (j + 1)+ "= ");
                qMatriz.getMatriz()[i][j] = teclado.nextInt();
            }
        }
        System.out.println(qMatriz.calcularDPrincipal());        
        System.out.println(qMatriz.calcularDSecundaria());        
        System.out.println(qMatriz.calcularResto());
    }
}
