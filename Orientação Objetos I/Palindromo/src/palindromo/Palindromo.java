/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package palindromo;

import java.text.Normalizer;
import java.util.Scanner;

/**
 *
 * @author pedro.grazziani
 */
public class Palindromo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String st1, st2;
        //"Gremio".equalsIgnoreCase("gremio");//true

        System.out.println("Digite a frase: ");
        st1 = sc.nextLine();
        CharSequence cs = new StringBuilder(st1);
        st2 = Normalizer.normalize(cs, Normalizer.Form.NFD).replaceAll("\\p{InCombiningDiacriticalMarks}+", "");
        st2 = st2.replaceAll(" ", "");
        if(st2.equals(new StringBuilder(st2).reverse().toString())){
            System.out.println("É palindromo!");
        }else{
            System.out.println("Não é palindromo!");
        }
    }
}
