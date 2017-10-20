
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
public class ParImpar {
    public static void main(String[] args) {
        int n1=0,n2=0, result=0;        
        Scanner teclado = new Scanner(System.in);
        
        System.out.println("Digite o número do primeiro usuario: ");
        n1 = teclado.nextInt();
        System.out.println("Digite o número do segundo usuario");
        n2 = teclado.nextInt();
        
        result = (n1+n2)%2;
        
        if(result != 0){
            System.out.println("IMPAR");
        }else{
            System.out.println("PAR");
        }
        
    }
}
