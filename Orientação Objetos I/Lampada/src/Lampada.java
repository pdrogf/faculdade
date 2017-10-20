/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Lampada {
    private boolean acesa;

    public boolean isAcesa() {
        return acesa;
    }

    public void setAcesa(boolean acesa) {
        this.acesa = acesa;
    }
    public void acender(){
        this.acesa = true;
    }
    public void apagar(){
        this.acesa = false;
    }
    public boolean estahLigada(){
        return acesa;
    }
}
