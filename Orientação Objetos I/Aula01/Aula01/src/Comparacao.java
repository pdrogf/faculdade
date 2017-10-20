
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
public class Comparacao {
    public static void main(String[] args) {
        int n1=0, n2=0;
        Scanner teclado = new Scanner(System.in);
        
        System.out.println("Digite o primeiro número: ");
        n1 = teclado.nextInt();
        System.out.println("Digite o segundo número: ");
        n2 = teclado.nextInt();
        
        if(n1 > n2){
            System.out.println("Primeiro número é maior!");
        }else if(n2 > n1){
            System.out.println("Segundo número é maior!");
        }else{
                System.out.println("Números são iguais!");
         }
    }
 
}
