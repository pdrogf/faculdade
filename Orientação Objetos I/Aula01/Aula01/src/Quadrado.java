
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 * 
 */
public class Quadrado {
    public static void main(String[] args) {
        int l=0, a=0;
        Scanner teclado = new Scanner(System.in);
        
        System.out.println("Digite a altura do quadrado: ");
        a = teclado.nextInt();
        System.out.println("Digite a largura do quadrado: ");
        l = teclado.nextInt();
        
        for(int j=0; j < a; j++){
            for(int i=0; i < l; i++){
                System.out.print("X");
            }
            System.out.println("");            
        }
    }
}
