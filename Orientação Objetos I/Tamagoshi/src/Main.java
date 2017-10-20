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
        Tamagoshi tama = new Tamagoshi();
        
        tama.setFome(10);
        tama.setIdade(2);
        tama.setNome("Godofredo");
        tama.setSaude(5);
        
        System.out.println("Humor== ??? " + tama.getHumor());
    }
    
}
