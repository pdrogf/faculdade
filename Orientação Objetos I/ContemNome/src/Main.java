
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
       ArrayList<String> nomes = new ArrayList<>();
       int i =0;
       while(i<=10){
           System.out.println("Digite um nome: ");
           nomes.add(sc.nextLine());
           i++;
       }
        System.out.println("Nomes incluidos com sucesso!");
        System.out.println("Qual nome deseja pesquisar?");
        if(nomes.contains(sc.nextLine())){
            System.out.println("Nome existente!");
        }else{
            System.out.println("Nome não existe");
        }
    }
    
}
