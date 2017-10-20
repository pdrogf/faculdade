
import java.util.logging.Level;
import java.util.logging.Logger;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class ThreadEscreve extends Thread{
    private char letra;
    private ThreadEscreve p;
    
    public ThreadEscreve(char a){
        this.letra = a;        
    }
    
    public ThreadEscreve(char letra, ThreadEscreve p){
        this.letra = letra;
        this.p = p;
    }
    public char getLetra() {
        return letra;
    }

    public void setLetra(char letra) {
        this.letra = letra;
    }
        
    @Override
    public void run(){
        try {        
            p.join();
        } catch (Exception e) {
        }
        System.out.println(letra);  
    }
}
