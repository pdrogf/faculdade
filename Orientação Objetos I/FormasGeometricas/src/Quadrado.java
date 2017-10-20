/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Quadrado extends Quadrilatero implements FiguraGeometrica {

    public Quadrado(double lado) {
        super(lado, lado, lado, lado);
    }

    public double calculaPerimetro() {
        return super.calculaPerimetro();
    }

    public double calculaArea() {
        return l1 * l2;
    }

    public double asdasdasd() {
        return l1 * l2;
    }
}
