
import java.util.ArrayList;
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
        String nomeEntrada = "";
        ArrayList<String> nomes = new ArrayList();
        
        nomes.add("Pedro");
        nomes.add("Joao");
        nomes.add("Marcos");
        nomes.add("Judas");
        nomes.add("Jose");
        nomes.add("Tiago");
        nomes.add("Marco");
        nomes.add("Lucas");
        nomes.add("Godofredo");

        System.out.println("Digite o nome a ser pesqusiado: ");
        nomeEntrada = sc.nextLine();
        
        if(nomes.contains(nomeEntrada)){
            System.out.println(nomeEntrada + " está na lista");
        }else{
            System.out.println(nomeEntrada + " NÃO está na lista");                  
        }
    }
    
}
