
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
public class Calculadora {
    public static void main(String[] args) {
        int n1=0, n2=0;
        Scanner teclado = new Scanner(System.in);
        
        System.out.println("Digite o primeiro valor: ");
        n1 = teclado.nextInt();
        System.out.println("Digite o segundo valor: ");
        n2 = teclado.nextInt();
        
        System.out.println("Soma = "+ (n1+n2));
        System.out.println("Subtração = "+ (n1-n2));
        System.out.println("Multiplicação = "+ (n1*n2));
        if(n2 != 0){
            System.out.println("Divisão = "+ ((double)n1/(double)n2));
        }else{
            System.out.println("Impossível dividir por zero!");
        }
        
        
        
        
    }
}
