/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Retangulo extends Quadrilatero implements FiguraGeometrica {

    public Retangulo(double base, double altura) {
        super(base, altura, base, altura);
    }

    public double calculaPerimetro() {
        return super.calculaPerimetro();
    }

    public double calculaArea() {
        return l1 * l2;
    }
}
