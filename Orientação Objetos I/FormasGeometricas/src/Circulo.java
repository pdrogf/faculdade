/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Circulo implements FiguraGeometrica {

    private double raio;

    public Circulo(double raio) {
        this.raio = raio;
    }

    public double calculaPerimetro() {
        return (2 * (Math.PI * raio));
    }

    public double calculaArea() {
        return (Math.PI * Math.pow(raio, 2));
    }

    public double getRaio() {
        return raio;
    }
}
