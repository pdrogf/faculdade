/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Pedro Grazziani
 * Classe: Porta
 * Atributos: aberta (boolean), cor (String)
 * Métodos:
 *
 * void abre()
 * void fecha()
 * void pinta(String s)
 * boolean estaAberta()
 * String getCor()
 * Para testar, crie uma porta, abra e feche a
 * mesma, pinte-a de diversas cores e use o método
 * estaAberta para verificar se ela está aberta
 */
public class Porta {

    private boolean aberto;
    private String cor;

    public Porta() {
        aberto = false;
    }

    public void abre() {
        aberto = true;
    }

    public void fecha() {
        aberto = false;
    }

    public boolean estaAberta() {
        return aberto;
    }

    public void pinta(String cor) {
        this.cor = cor;
    }

    public String getCor() {
        return cor;
    }
}
