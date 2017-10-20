/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Teste {

    public static void main(String[] args) {
        Mamifero camelo = new Mamifero("Camelo", 150, 4, "Marrom", "Terestre", 12);
        camelo.listaDados(); 
        Peixe tubarao = new Peixe("Tubarao Martelo", 520, 0, "Bracno", "Agua salgada", 15);
        tubarao.listaDados();
        Mamifero urso = new Mamifero("Urso-Canadense", 230, 4, "BrancoMarronzado", "TerraAgua", 30);
        urso.listaDados();
    }
}
