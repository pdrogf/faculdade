/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Pedro Grazziani
 */
public class Telefone {

    int numero;
    private String operadora;

    public Telefone(int numero, String operadora) {
        this.numero = numero;
        this.operadora = operadora;
    }

    public int getNumero() {
        return numero;
    }

    public String getOperadora() {
        return operadora;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public void setOperadora(String operadora) {
        this.operadora = operadora;
    }

    public void ligar(Telefone telefoneDestino) {
        System.out.println("O telefone " + numero + " está ligando para o telefone" + telefoneDestino.getNumero());
    }

    public void enviarSMS(Telefone telefoneDestino, String mensagem) {
        System.out.println("O telefone " + numero + " está enviando um SMS para o telefone " + telefoneDestino.getNumero() + " com o texto " + mensagem);
    }

}
