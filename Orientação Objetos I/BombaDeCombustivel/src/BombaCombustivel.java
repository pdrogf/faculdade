/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class BombaCombustivel {
    private String tipoDeCombustivel;
    private double valorPorLitro;
    private double quantidadeDeCombustivel;
    private double encerrante;

    public String getTipoDeCombustivel() {
        return tipoDeCombustivel;
    }

    public void setTipoDeCombustivel(String tipoDeCombustivel) {
        this.tipoDeCombustivel = tipoDeCombustivel;
    }

    public double getValorPorLitro() {
        return valorPorLitro;
    }

    public void setValorPorLitro(double valorPorLitro) {
        if(valorPorLitro < 0){
            System.out.println("Valor por litro não pode ser negativo");
        }
        this.valorPorLitro = valorPorLitro;
    }

    public double getQuantidadeDeCombustivel() {
        return quantidadeDeCombustivel;
    }

    public void setQuantidadeDeCombustivel(double quantidadeDeCombustivel) {
        if(quantidadeDeCombustivel < 0){
            System.out.println("Quantidade de combustivel não pode ser negativa");
        }
        this.quantidadeDeCombustivel = quantidadeDeCombustivel;
    }
    public double abastecePorValor(double valor){
        if(valor < 0){
            System.out.println("Valor informado inválido");
            return valor;
        }else{
            encerrante += valor/valorPorLitro;
            return valor/valorPorLitro;
        }
    }
    public double abastecePorLitro(double quantidade){
        if(quantidade < 0){
            System.out.println("Valor digitado inválido");
            return quantidade;
        }else{
            encerrante +=quantidade;
            return quantidade*valorPorLitro;
        }
        
    }
}
