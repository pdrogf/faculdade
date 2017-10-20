
import java.util.ArrayList;
import java.util.Collections;
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
        int k =0, n =0;
        ArrayList<Integer> lista = new ArrayList<>();
        
        while(true){
            System.out.println("Digite os números da lista: ");
            k = sc.nextInt();
            if(k >=0){
                lista.add(k);
            }else{
                break;
            }
        }
        System.out.println("Digite o verificador: ");
        n = sc.nextInt();
        lista.remove(n);
        Collections.sort(lista);
        System.out.println("---------- Lista ordenada ----------");
        for(int i =0; i<lista.size();i++){
            System.out.println(lista.get(i));
        }
    }
    
}
