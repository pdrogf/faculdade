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
        BombaCombustivel bomba = new BombaCombustivel();
        
        bomba.setQuantidadeDeCombustivel(10);
        bomba.setTipoDeCombustivel("Gasolina Comum");
        bomba.setValorPorLitro(3.555);
        System.out.println("Valor a ser pago: " + bomba.abastecePorLitro(5));
        System.out.println("Quant litros abastecidosd " + bomba.abastecePorValor(100));
        
    }
    
}
