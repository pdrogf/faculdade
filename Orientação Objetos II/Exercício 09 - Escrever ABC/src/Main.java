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
        ThreadEscreve a = new ThreadEscreve('a');
        ThreadEscreve b = new ThreadEscreve('b', a);
        ThreadEscreve c = new ThreadEscreve('c', b);
                
        a.start();        
        b.start();        
        c.start();
        
    }
    
}
