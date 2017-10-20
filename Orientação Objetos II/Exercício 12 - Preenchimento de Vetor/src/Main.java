/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 * Escreva um programa em que duas threads escrevam o valor do índice em um vetor global de inteiros e de tamanho 100. 

Estas threads devem usar um objeto compartilhado para obter o valor que indica a posição a ser preenchida no vetor. 

Este valor começa em -1 e cada thread deve incrementá-lo antes de usá-lo. 
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int vet[] = new int[100];
        int indiceAtual = -1;
        
        ThreadVetor t1 = new ThreadVetor(vet, indiceAtual);
        ThreadVetor t2 = new ThreadVetor(vet, indiceAtual);
        
        t1.start();
        t2.start();
        
        try {
            t1.join();
            t2.join();
        } catch (Exception e) {
        }
        for(int i=0;i<100;i++){
            System.out.println(vet[i]);
        }
    }
    
}
