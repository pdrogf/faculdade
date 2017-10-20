/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sobrenome;

import java.util.Scanner;

/**
 *
 * @author pedro.grazziani
 */
public class Sobrenome {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String nome;
        
        System.out.println("Digite o nome: ");
        nome = sc.nextLine();
        String array[] = nome.split(" ");
        if(array.length < 2){
            System.out.println("Sobrenome não informado");
        }else{
            System.out.println(array[array.length-1]);
        }
        
    }
    
}
