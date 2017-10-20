
import java.util.ArrayList;

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
              
        ThreadDataHora threadData = new ThreadDataHora();
        ThreadNoticia threadNoticia = new ThreadNoticia();
        threadData.start();
        threadNoticia.start();       
    }
    
}
