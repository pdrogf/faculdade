/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Retangulo {
    private double altura;
    private double largura;
    private double vertice;
    
    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    public double getLargura() {
        return largura;
    }

    public void setLargura(double largura) {
        this.largura = largura;
    }

    public double getVertice() {
        return vertice;
    }

    public void setVertice(double vertice) {
        this.vertice = vertice;
    }
    public void calcVertice(Ponto p){
        setVertice(p.getY() + altura);
    }
    public double calcCentroX(Ponto p){
        return p.getX()+(largura/2);
    }
    public double calcCentroY(Ponto p){
        return p.getY() + (altura/2);
    }
    
}
