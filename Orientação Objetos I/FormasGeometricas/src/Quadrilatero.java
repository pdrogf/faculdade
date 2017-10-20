/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public abstract class Quadrilatero {

    protected double l1;
    protected double l2;
    protected double l3;
    protected double l4;

    public Quadrilatero(double l1, double l2, double l3, double l4) {
        this.l1 = l1;
        this.l2 = l2;
        this.l3 = l3;
        this.l4 = l4;
    }

    public double calculaPerimetro() {
        return (l1 + l2 + l3 + l4);
    }

    public double getL1() {
        return l1;
    }

    public double getL2() {
        return l2;
    }

    public double getL3() {
        return l3;
    }

    public double getL4() {
        return l4;
    }
}
