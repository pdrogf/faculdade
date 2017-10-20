/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Fruteira {

    private Fruta[] frutas;

    public Fruteira(int qtdFrutas) {
        this.frutas = new Fruta[qtdFrutas];
    }

    public void adiciona(Fruta fruta) {
        int l = -1;

        for (int i = 0; i < frutas.length; i++) {
            if (frutas[i] == fruta) {
                break;
            }
            if (l == -1 && frutas[i] == null) {
                l = i;
            }
            if (l != -1 && i == (frutas.length - 1)) {
                frutas[l] = fruta;
            }
        }
    }
    public void remove(Fruta fruta) {
        for (int i = 0; i < frutas.length; i++) {
            if (frutas[i] == fruta) {
                frutas[i] = null;
                break;
            }
        }
    }
    public void listaFrutas() {
        int k = 1;
        for (int i = 0; i < frutas.length; i++) {
            if (frutas[i] != null){
                System.out.println(String.format("Fruta %d:  - Gramas: %f - kcal por grama: %f",k,frutas[i].getGramas(),frutas[i].getCaloriasPorGrama()));
                k++;
            }
        }
    }
}
