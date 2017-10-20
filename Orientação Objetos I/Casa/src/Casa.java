/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Pedro Grazziani
 */
public class Casa {

    private String cor;
    private Porta porta1;
    private Porta porta2;
    private Porta porta3;

    public void pinta(String cor) {
        this.cor = cor;
    }

    public String getCor() {
        return cor;
    }

    public int quantasPortasEstaoAbertas() {
        int cont1=0;
        if (porta1 != null && porta1.estaAberta()) {
            cont1++;
        }
        if (porta2 != null && porta2.estaAberta()) {
            cont1++;
        }
        if (porta3 != null && porta3.estaAberta()) {
            cont1++;
        }
        return cont1;
    }
    public int totalDePortasInstaladas() {
        int cont2 = 0;
        if (porta1 != null) {
            cont2++;
        }
        if (porta2 != null) {
            cont2++;
        }
        if (porta3 != null) {
            cont2++;
        }
        return cont2;
    }
    public Porta getPorta1() {
        return porta1;
    }

    public void setPorta1(Porta porta1) {
        this.porta1 = porta1;
    }

    public Porta getPorta2() {
        return porta2;
    }

    public void setPorta2(Porta porta2) {
        this.porta2 = porta2;
    }

    public Porta getPorta3() {
        return porta3;
    }

    public void setPorta3(Porta porta3) {
        this.porta3 = porta3;
    }
}
