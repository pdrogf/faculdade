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
        Lampada lamp = new Lampada();
        
        lamp.acender();
        lamp.apagar();
        
        if(lamp.estahLigada() == true){
            System.out.println("Lampada esta ligada");
        }else{
            System.out.println("Lampada esta apagada");
        }
    }
    
}
