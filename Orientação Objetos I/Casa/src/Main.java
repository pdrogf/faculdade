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

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Casa casa = new Casa();
        Porta porta1 = new Porta();
        Porta porta2 = new Porta();

        casa.pinta("Cor Aqui");

        System.out.println(casa.getCor());
        System.out.println("Portas abertas: " + casa.quantasPortasEstaoAbertas());
        System.out.println("Portas instaladas: " + casa.totalDePortasInstaladas());
        
        casa.setPorta1(porta1);
        casa.setPorta3(porta2);
        casa.getPorta1().abre();

        System.out.println("Total   Portas abertas: " + casa.quantasPortasEstaoAbertas());
        System.out.println("Total Portas instaladas: " +casa.totalDePortasInstaladas());
    }

}
