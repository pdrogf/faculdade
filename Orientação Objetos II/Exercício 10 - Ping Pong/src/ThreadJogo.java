/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class ThreadJogo extends Thread{
    String p;
    Thread t;

    public ThreadJogo(String p){
        this.p=p;
    }
    public ThreadJogo(String p, ThreadJogo t){
        this.p = p;
        this.t = t;
    }
    
    public String getP() {
        return p;
    }

    public void setP(String p) {
        this.p = p;
    }    
    @Override
    public void run(){
        /*try {
            t.join();
        } catch (Exception e) {
        }
        System.out.println(p); 
    }*/
        System.out.println(p);
    }    
}
