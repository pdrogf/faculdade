
import java.util.ArrayList;
import java.util.Random;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Lebre extends Thread{
    int distanciaPercorrida;
    int distanciaDoSalto;
    int qtdPulos;
    String nome;    
    Random gerador = new Random();
    ArrayList<String> posicoes = new ArrayList<>();
    

    public Lebre(String nome, ArrayList<String> posicoes) {
        this.nome = nome;
        this.posicoes = posicoes;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
    

    public int getDistanciaPercorrida() {
        return distanciaPercorrida;
    }

    public void setDistanciaPercorrida(int distanciaPercorrida) {
        this.distanciaPercorrida = distanciaPercorrida;
    }

    public int getDistanciaDoSalto() {
        return distanciaDoSalto;
    }

    public void setDistanciaDoSalto(int distanciaDoSalto) {
        this.distanciaDoSalto = distanciaDoSalto;
    }

    public int getQtdPulos() {
        return qtdPulos;
    }

    public void setQtdPulos(int qtdPulos) {
        this.qtdPulos = qtdPulos;
    }

    public int saltar(){
        this.distanciaDoSalto = gerador.nextInt(3)+1;
        this.distanciaPercorrida += distanciaDoSalto;
        this.qtdPulos +=1;
        return distanciaDoSalto;
    }
    
    @Override
    public void run(){
        while(distanciaPercorrida <=22){
            System.out.println(nome + " - Pulo de: "+saltar()+"m");
            yield();
        }
        posicoes.add(nome + " - quantidade de pulos = "+ qtdPulos);
        
    }
}
