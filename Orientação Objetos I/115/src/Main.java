
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
        int posicao =0;
        Vetor v = new Vetor();
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Digite a posicao a ser encontrada: ");
        posicao = sc.nextInt();
        v.populaVetor();
        
        try {
            System.out.println(v.getByPosition(posicao));
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(e);
        }
    }
    
}
