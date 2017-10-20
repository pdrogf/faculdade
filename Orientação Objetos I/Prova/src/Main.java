/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Pedro Grazziani
 */
public class Main {

    public static void main(String[] args) {
        
        Telefone tel1 = new Telefone(123, "Oi");
        Telefone tel2 = new Telefone(456, "Vivo");
        Smartphone sf1 = new Smartphone(789, "Tim", true);
        Smartphone sf2 = new Smartphone(101, "Oi", false);
        
        tel1.ligar(tel2);
        tel1.ligar(sf1);
        
        tel2.enviarSMS(sf2, "Oi SF2");
        
        sf1.enviarSMS(tel2, "Oi TEL2");
        sf2.enviarSMS(tel1, "Oi TEL1");
    }
}
/*
O telefone 123 esta ligando para o telefone 456
O telefone 123 esta ligando para o telefone 789
O telefone 456 esta enviando um SMS para o telefone 101 com o texto: Oi SF2
O telefone 789 esta enviando um Whatsapp para o telefone 456 com o texto: Oi TEL2
O telefone 101 esta enviando um SMS para o telefone 123 com o texto: Oi TEL1
*/