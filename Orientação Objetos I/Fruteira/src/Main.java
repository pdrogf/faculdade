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
        
        Fruteira frut = new Fruteira(5);

        Fruta fruta1 = new Fruta(1, 1);
        Fruta fruta2 = new Fruta(2, 2);
        Fruta fruta3 = new Fruta(3, 3);
        
        frut.listaFrutas();
        frut.adiciona(fruta1);
        frut.listaFrutas();
        frut.adiciona(fruta2);
        frut.listaFrutas();
        frut.adiciona(fruta3);
        frut.listaFrutas();
        
        frut.remove(fruta1);
        frut.listaFrutas();
        frut.remove(fruta2);
        frut.listaFrutas();
        frut.remove(fruta3);
        frut.listaFrutas();
    }
}
