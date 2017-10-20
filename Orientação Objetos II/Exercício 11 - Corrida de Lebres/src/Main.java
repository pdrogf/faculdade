
import java.lang.reflect.Array;
import java.util.ArrayList;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 * Cinco lebres disputarão uma corrida. Cada lebre pode dar um salto que varia de 1 a 3 metros de distância. 

A distancia percorrida é de 20 metros. 

Na corrida, cada lebre dará um salto, e o programa deverá informar quantos metros ela pulou a cada salto realizado. 
Em seguida, a lebre pára para descansar (yield()). 

Escreva um programa, utilizando threads (uma para cada lebre), 
* que informe a lebre vencedora e a colocação de cada uma delas no final da corrida. 
* Informar também quantos pulos cada uma delas deu.
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ArrayList<String> posicoes = new ArrayList<>();
        
        Lebre lebre1 = new Lebre("godofredo", posicoes);
        Lebre lebre2 = new Lebre("juquinha", posicoes);
        Lebre lebre3 = new Lebre("astropholdo", posicoes);
        Lebre lebre4 = new Lebre("clapaucius", posicoes);
        Lebre lebre5 = new Lebre("Perna Longa", posicoes);
        
        
        lebre1.start();
        lebre2.start();
        lebre3.start();
        lebre4.start();
        lebre5.start();
        
        
        try {
            lebre1.join();
            lebre2.join();
            lebre3.join();
            lebre4.join();
            lebre5.join();
        } catch (Exception e) {
        }
        System.out.println("Lebre vencedora: "+posicoes.get(0));
        int i;
        for(i=1;i<5;i++){
            System.out.println("Posicao - "+i+ " "+posicoes.get(i));
        }
    }    
}
