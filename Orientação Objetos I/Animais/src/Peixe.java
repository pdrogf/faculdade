/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Peixe extends Animal {

    public Peixe(String nome, int comprimento, int patas, String cor, String ambiente, double velocidade) {
        super(nome, comprimento, patas, "azul", "Agua", velocidade);
    }

    @Override
    public void listaDados() {
        System.out.println("Peixe: ");
        super.listaDados();
    }

}
