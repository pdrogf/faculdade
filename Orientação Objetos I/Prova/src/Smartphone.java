/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Pedro Grazziani
 */
public class Smartphone extends Telefone {

    public Smartphone(int numero, String operadora, boolean whatsAppIinstalado) {
        super(numero, operadora);
        this.whatsAppInstalado = false;
    }
    
    private boolean whatsAppInstalado;

    public boolean isWhatsAppInstalado() {
        return whatsAppInstalado;
    }

    public void setWhatsAppInstalado(boolean whatsAppInstalado) {
        this.whatsAppInstalado = whatsAppInstalado;
    }
    
    @Override
    public void enviarSMS(Telefone telefoneDestino, String mensagem){
        if(whatsAppInstalado){
            System.out.println("O telefone "+  numero +  " está enviando um Whatsapp para o telefone "+ telefoneDestino.getNumero() + " com o texto " + mensagem);
        }else{
            super.enviarSMS(telefoneDestino, mensagem);
        }
    }
}
