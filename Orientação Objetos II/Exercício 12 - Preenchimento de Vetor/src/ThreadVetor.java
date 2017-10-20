/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class ThreadVetor extends Thread{
    int vet[];
    int indiceA;

    public ThreadVetor(int[] vet, int indiceA) {
        this.vet = vet;
        this.indiceA = indiceA+1;
    }

    public int[] getVet() {
        return vet;
    }

    public void setVet(int[] vet) {
        this.vet = vet;
    }

    public int getIndiceA() {
        return indiceA;
    }

    public void setIndiceA(int indiceA) {
        this.indiceA = indiceA;
    }       
    
    @Override
    public void run(){
        for(int i=0;i<100;i++){         
            vet[indiceA] = i+1;   
        }
    }
}
