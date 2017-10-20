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
        int [][]matriz = new int[4][4];
        int i=0, l1, l2, l3, l4, total=0;
        
        matriz[0][0] = 2;
        matriz[0][1] = 2;
        matriz[0][2] = 2;
        matriz[0][3] = 2;
               
        matriz[1][0] = 4;
        matriz[1][1] = 4;
        matriz[1][2] = 4;
        matriz[1][3] = 4;
        
        matriz[2][0] = 6;
        matriz[2][1] = 6;
        matriz[2][2] = 6;
        matriz[2][3] = 6;
        
        matriz[3][0] = 10;
        matriz[3][1] = 10;
        matriz[3][2] = 10;
        matriz[3][3] = 10;
    
        NovaThread t1 = new NovaThread();
        t1.setV1(matriz[0][0]);
        t1.setV2(matriz[0][1]);
        t1.setV3(matriz[0][2]);
        t1.setV4(matriz[0][3]);
        t1.start();
        l1 = t1.calculaLinha();
        
        NovaThread t2 = new NovaThread();
        t2.setV1(matriz[1][0]);
        t2.setV2(matriz[1][1]);
        t2.setV3(matriz[1][2]);
        t2.setV4(matriz[1][3]);
        t2.start();
        l2 = t2.calculaLinha();
        
        NovaThread t3 = new NovaThread();
        t3.setV1(matriz[2][0]);
        t3.setV2(matriz[2][1]);
        t3.setV3(matriz[2][2]);
        t3.setV4(matriz[2][3]);
        t3.start();
        l3 = t3.calculaLinha();
        
        NovaThread t4 = new NovaThread();
        t4.setV1(matriz[3][0]);
        t4.setV2(matriz[3][1]);
        t4.setV3(matriz[3][2]);
        t4.setV4(matriz[3][3]);
        t4.start();
        l4 = t4.calculaLinha();
        
        System.out.println("Primeira linha: " + l1);
        System.out.println("Segunda linha: " + l2);
        System.out.println("Terceira linha: " + l3);
        System.out.println("Quarta linha: " + l4);
        System.out.println("Total: "+ (l1+l2+l3+l4));
        
        
    }    
    
}
