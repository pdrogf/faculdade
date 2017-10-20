/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Mamifero extends Animal {

    public Mamifero(String nome, int comprimento, int patas, String cor, String ambiente, double velocidade) {
        super(nome, comprimento, patas, cor, ambiente, velocidade);
    }

    @Override
    public void listaDados() {
        System.out.println("Mamífero: ");
        super.listaDados();
    }
}
