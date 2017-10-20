/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Vetor {
    int[] vet = null;
    int posicao =0;
    
    public void populaVetor(){
        for(int i=0; i<10; i++){
            vet[i] = i;
        }
    }

    public int[] getVet() {
        return vet;
    }

    public void setVet(int[] vet) {
        this.vet = vet;
    }

    public int getPosicao() {
        return posicao;
    }

    public void setPosicao(int posicao) {
        this.posicao = posicao;
    }
    
    public int getByPosition(int a){
        return vet[a];
    }
    
}
