
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
        Scanner scan = new Scanner(System.in);
        FabricaLampadas fabrica = new FabricaLampadas();
        String tipo;
        
        System.out.println("Digite: ");
        System.out.println("L -> para lampda LED");
        System.out.println("F -> para lampada Fluorescente");
        tipo = scan.nextLine();
        
        fabrica.criaLampada(tipo);
        
        
        
    }
    
}
