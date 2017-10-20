/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Fruta {

    private double gramas;
    private double caloriasPorGrama;

    public Fruta() {
    }

    public Fruta(double gramas, double caloriasPorGrama) {
        this.gramas = gramas;
        this.caloriasPorGrama = caloriasPorGrama;
    }
    public double getGramas() {
        return gramas;
    }
    public void setGramas(double gramas) {
        this.gramas = gramas;
    }
    public double getCaloriasPorGrama() {
        return caloriasPorGrama;
    }
    public void setCaloriasPorGrama(double caloriasPorGrama) {
        this.caloriasPorGrama = caloriasPorGrama;
    }
}
