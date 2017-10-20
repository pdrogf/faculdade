/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 * 
 */
public class QuadradoPerfeito {
    public static void main(String[] args) {
        int cont=0, j=1, quadrado=0;
        
        while(j <= 10){
           quadrado = j*j;
           System.out.println("Quadrado perfeito: " + quadrado);
           j++;
        }
    }
}
