/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class MatrizQuadrada extends Matriz {

    public MatrizQuadrada(int ordem) {
        super(ordem, ordem);
    }
    public int calcularDPrincipal() {
        int result = 0;
        for (int i = 0; i < matriz.length; i++) {
            result += matriz[i][i];
        }
        return result;
    }
    public int calcularDSecundaria() {
        int result = 0;
        for (int i = 0; i < matriz.length; i++) {
            result *= matriz[i][matriz.length - i - 1];
        }
        return result;
    }
    public int calcularResto() {
        int result = 0;
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[i].length; j++) {
                if ((i != j) && ((i + j) != matriz.length - 1)) {
                    result += matriz[i][j];
                }
            }
        }
        return result;
    }
}
