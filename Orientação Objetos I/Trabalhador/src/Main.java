/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Main {

    /**
     * @param args the command line arguments
     */    
    public static void main(String[] args) {
        Horista horista1 = new Horista("Telmo", 100, 10);
        Assalariado assalariado1 = new Assalariado("Paulo", 100);
        double salarioHorista = horista1.calculaPagamento();
        double salarioAssalariado = assalariado1.calculaPagamento();
        assalariado1.setSalarioPorHora(130);
        System.out.println(salarioHorista);
        System.out.println(salarioAssalariado);
    }
}
