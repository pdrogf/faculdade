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
        Ponto p = new Ponto();
        Retangulo r = new Retangulo();
        
        p.setX(2);
        p.setY(1);
        r.setAltura(2);
        r.setLargura(1);
        r.calcVertice(p);
                
        System.out.println("Vértice = " + r.getVertice());
        System.out.println("Centro = (" + r.calcCentroX(p) + ", " + r.calcCentroY(p) + ")");
        
    }
    
}
