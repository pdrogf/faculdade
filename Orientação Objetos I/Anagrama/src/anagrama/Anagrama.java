/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package anagrama;

import java.text.Normalizer;
import java.util.Scanner;
import java.util.Arrays;

/**
 *
 * @author pedro.grazziani
 */
public class Anagrama {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String st1;
        String st2;
        
        System.out.println("Digite a primeira palavra: ");
        st1 = sc.nextLine();
        
        System.out.println("Digite a segunda palavra: ");
        st2 = sc.nextLine();
        
        if(st1.length() != st2.length()){
            System.out.println("Não é anagrama!");
            return;
        }
        char[] s1 = st1.toCharArray();
        char[] s2 = st2.toCharArray();
        
        Arrays.sort(s1);
        Arrays.sort(s2);
        
        if(Arrays.equals(s1, s2)){
            System.out.println("é anagrama!");
        }
    }
    
}
