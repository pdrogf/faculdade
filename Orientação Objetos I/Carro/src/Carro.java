/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Pedro Grazziani
 */
public class Carro {

    private String cor;
    private double capacidadeMotor;
    private double velocidade;

    public Carro(String cor, double capacidadeMotor) {
        this.cor = cor;
        this.capacidadeMotor = capacidadeMotor;
    }

    public void aumentarVelocidade(double quantidade) {
        if (quantidade < 0) {
            System.out.println("Nao eh permitido acelerar menos que 0");
            return;
        }
        if ((quantidade + velocidade) > (capacidadeMotor * 110)) {
            System.out.println("Valor informado ultrapassa a capacidade do motor");
            return;
        }
        velocidade += quantidade;
    }
    public void reduzirVelocidade(double quantidade) {
        if (quantidade < 0) {
            System.out.println("Nao eh permitido reduzir menos que 0");
            return;
        }

        if ((velocidade - quantidade) < 0) {
            System.out.println("A velocidade informada deve ser <= que: " + velocidade);
            return;
        }
        if (quantidade >= 60) {
            System.out.println("brekou muito rápido, acionou o air-bag");
        }
        velocidade -= quantidade;
    }

    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }

    public double getCapacidadeMotor() {
        return capacidadeMotor;
    }

    public double getVelocidade() {
        return velocidade;
    }
}
