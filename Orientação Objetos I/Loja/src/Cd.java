/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Cd extends Produto {

    private int nFaixas;

    public Cd(String nome, double preco, int nFaixas) {
        super(nome, preco);
        this.nFaixas = nFaixas;
    }

    public int getNFaixas() {
        return nFaixas;
    }

    public void setNFaixas(int nFaixas) {
        this.nFaixas = nFaixas;
    }

    @Override
    public String toString() {
        return super.toString() + "Nº de faixas: " + nFaixas;
    }
}
