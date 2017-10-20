/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Pedro
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int i =0;
        while(i < 10){
            NovaThread t = new NovaThread();
            t.setI(i);
            t.start();
            i++;
        }
    }
    
}
