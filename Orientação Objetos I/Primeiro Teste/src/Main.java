
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
        double v1,v2;
        
        System.out.println("Digite primeiro valor: ");
        v1 = sc.nextDouble();
        System.out.println("Digite segundo valor: ");
        v2 = sc.nextDouble();
        
        try {
            double v3 = v1/v2;
            System.out.println("Divisao:" + v3);
        } catch (ArithmeticException e) {
            System.out.println("Erro ao efetuar divisao!");
        }
    }
    
}
